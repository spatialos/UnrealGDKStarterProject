// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "StarterProjectPlayerController.h"
#include "StarterProjectGameMode.h"
#include "SpatialNetDriver.h"
#include "EntityRegistry.h"

AStarterProjectPlayerController::AStarterProjectPlayerController()
	: RespawnCharacterDelay(5.0f)
	, DeleteCharacterDelay(15.0f)
	, PawnToDelete(nullptr)
{

}

bool AStarterProjectPlayerController::TestRPC_Validate()
{
	return true;
}

void AStarterProjectPlayerController::TestRPC_Implementation()
{

}

bool AStarterProjectPlayerController::TestMulticast_Validate()
{
	return true;
}

void AStarterProjectPlayerController::TestMulticast_Implementation()
{
}

void AStarterProjectPlayerController::InitPlayerState()
{
	// TODO: this is a workaround until we can query a replicated UObject*'s UnrealObjRef - UNR-407
	UWorld* World = GetWorld();
	check(World);
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(World->GetNetDriver());
	if (NetDriver)
	{
		const Worker_EntityId EntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(this);
		UE_LOG(LogTemp, Log, TEXT("PC:InitPlayerState called with entity id %lld"), EntityId);
		if (EntityId != 0)
		{
			// EntityId is not 0, which means that this PC has already been initialized.
			return;
		}
	}

	Super::InitPlayerState();
}

void AStarterProjectPlayerController::KillCharacter()
{
	check(GetNetMode() == NM_DedicatedServer);

	if (!HasAuthority())
	{
		return;
	}
	
	PawnToDelete = GetPawn();
	DeadPawnTransform = PawnToDelete->GetActorTransform();
	UnPossess();

	// TODO: timers won't persist across worker boundary migrations, and neither will PawnToDelete
	GetWorldTimerManager().SetTimer(DeleteCharacterTimerHandle, this, &AStarterProjectPlayerController::DeleteCharacter, DeleteCharacterDelay);
	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &AStarterProjectPlayerController::RespawnCharacter, RespawnCharacterDelay);
}

void AStarterProjectPlayerController::RespawnCharacter()
{
	check(GetNetMode() == NM_DedicatedServer);
	if (AGameModeBase* GameMode = GetWorld()->GetAuthGameMode())
	{
		APawn* NewPawn = GameMode->SpawnDefaultPawnAtTransform(this, DeadPawnTransform);

		Possess(NewPawn);
	}
}

void AStarterProjectPlayerController::DeleteCharacter()
{
	check(GetNetMode() == NM_DedicatedServer);
	if (PawnToDelete != nullptr)
	{
		// TODO: what if the character is on a different worker?
		GetWorld()->DestroyActor(PawnToDelete);
		PawnToDelete = nullptr;
	}
}

void AStarterProjectPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);	
}
