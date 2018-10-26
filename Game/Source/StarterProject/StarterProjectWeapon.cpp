// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "StarterProjectWeapon.h"

#include "StarterProjectCharacter.h"
#include "Engine/World.h"
#include "UnrealNetwork.h"


AStarterProjectWeapon::AStarterProjectWeapon()
	: CurrentState(EWeaponState::Idle)
	, OwningCharacter(nullptr)
{
	PrimaryActorTick.bCanEverTick = false;
	
	bReplicates = true;
	bReplicateMovement = true;

	LocationComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(LocationComponent);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	Mesh->SetupAttachment(RootComponent);
}

AStarterProjectCharacter* AStarterProjectWeapon::GetOwningCharacter() const
{
	return OwningCharacter;
}

void AStarterProjectWeapon::SetOwningCharacter(AStarterProjectCharacter* NewCharacter)
{
	OwningCharacter = NewCharacter;
}

void AStarterProjectWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AStarterProjectWeapon, OwningCharacter);
}

EWeaponState AStarterProjectWeapon::GetWeaponState() const
{
	return CurrentState;
}

void AStarterProjectWeapon::SetWeaponState(EWeaponState NewState)
{
	CurrentState = NewState;
}

void AStarterProjectWeapon::DoFire()
{
    check(GetNetMode() == NM_Client);
		
    FInstantHitInfo HitInfo;
    if (DoLineTrace(HitInfo))
    {
        ServerDidHit(HitInfo);
        SpawnHitFX(HitInfo);  // Spawn the hit fx locally
    }
}

bool AStarterProjectWeapon::DoLineTrace(FInstantHitInfo& OutHitInfo)
{
	if (!GetOwningCharacter() == nullptr)
	{
		return false;
	}

    FCollisionQueryParams TraceParams;
    TraceParams.bTraceComplex = true;
    TraceParams.bTraceAsyncScene = true;
    TraceParams.bReturnPhysicalMaterial = false;
    TraceParams.AddIgnoredActor(this);
    TraceParams.AddIgnoredActor(Character);

    if (bDrawDebugLineTrace)
    {
        TraceParams.TraceTag = kTraceTag;
    }

    FHitResult HitResult(ForceInit);
    FVector TraceStart = Character->GetLineTraceStart();
    FVector TraceEnd = TraceStart + Character->GetLineTraceDirection() * MaxRange;

    bool bDidHit = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd,
                                                        ECC_WorldStatic, TraceParams);

    if (!bDidHit)
    {
        return false;
    }

    OutHitInfo.Location = HitResult.ImpactPoint;
    OutHitInfo.HitActor = HitResult.GetActor();

    return true;
}

void AStarterProjectWeapon::NotifyClientsOfHit(const FInstantHitInfo& HitInfo)
{
    check(GetNetMode() < NM_Client);

    MulticastNotifyHit(HitInfo);
}

void AStarterProjectWeapon::SpawnHitFX(const FInstantHitInfo& HitInfo)
{
    if (GetNetMode() < NM_Client || HitFXTemplate == nullptr)
    {
        return;
    }

    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitFXTemplate, HitInfo.Location,
                                             FRotator::ZeroRotator, true);
}

bool AStarterProjectWeapon::ValidateHit(const FInstantHitInfo& HitInfo)
{
    check(GetNetMode() < NM_Client);

    if (HitInfo.HitActor == nullptr)
    {
        return false;
    }

    // Get the bounding box of the actor we hit.
    const FBox HitBox = HitInfo.HitActor->GetComponentsBoundingBox();

    // Calculate the extent of the box along all 3 axes an add a tolerance factor.
    FVector BoxExtent =
        0.5 * (HitBox.Max - HitBox.Min) + (HitValidationTolerance * FVector::OneVector);
    FVector BoxCenter = (HitBox.Max + HitBox.Min) * 0.5;

    // Avoid precision errors for really thin objects.
    BoxExtent.X = FMath::Max(20.0f, BoxExtent.X);
    BoxExtent.Y = FMath::Max(20.0f, BoxExtent.Y);
    BoxExtent.Z = FMath::Max(20.0f, BoxExtent.Z);

    // Check whether the hit is within the box + tolerance.
    if (FMath::Abs(HitInfo.Location.X - BoxCenter.X) > BoxExtent.X ||
        FMath::Abs(HitInfo.Location.Y - BoxCenter.Y) > BoxExtent.Y ||
        FMath::Abs(HitInfo.Location.Z - BoxCenter.Z) > BoxExtent.Z)
    {
        return false;
    }

    return true;
}

void AStarterProjectWeapon::DealDamage(const FInstantHitInfo& HitInfo)
{
    FPointDamageEvent DmgEvent;
    DmgEvent.DamageTypeClass = DamageTypeClass;
    DmgEvent.HitInfo.ImpactPoint = HitInfo.Location;

    HitInfo.HitActor->TakeDamage(ShotBaseDamage, DmgEvent, GetOwningCharacter()->GetController(),
                                 this);
}

bool AStarterProjectWeapon::ServerDidHit_Validate(const FInstantHitInfo& HitInfo)
{
    return true;
}

void AStarterProjectWeapon::ServerDidHit_Implementation(const FInstantHitInfo& HitInfo)
{
    if (!GetOwningCharacter())
    {
        return;
    }

    bool bDoNotifyHit = false;

    if (HitInfo.HitActor == nullptr)
    {
        bDoNotifyHit = true;
    }
    else
    {
        if (ValidateHit(HitInfo))
        {
            DealDamage(HitInfo);
            bDoNotifyHit = true;
        }
    }

    if (bDoNotifyHit)
    {
        NotifyClientsOfHit(HitInfo);
    }
}

void AStarterProjectWeapon::StopFiring()
{
    check(GetNetMode() == NM_Client);

    SetWeaponState(EWeaponState::Idle);    
}

void AStarterProjectWeapon::MulticastNotifyHit_Implementation(FInstantHitInfo HitInfo)
{
    // Make sure we're a client, and we're not the client that owns this gun (they will have already
    // played the effect locally).
    if (GetNetMode() != NM_DedicatedServer &&
        (GetOwningCharacter() == nullptr || !GetOwningCharacter()->IsLocallyControlled()))
    {
        SpawnHitFX(HitInfo);
    }
}
