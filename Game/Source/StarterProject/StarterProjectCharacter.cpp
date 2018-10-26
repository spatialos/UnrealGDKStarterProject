// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "StarterProjectCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "StarterProjectGameStateBase.h"
#include "SpatialNetDriver.h"

#include "UnrealNetwork.h"

//////////////////////////////////////////////////////////////////////////
// AStarterProjectCharacter

static const FName kRightGunSocketName("GunSocket_r");

AStarterProjectCharacter::AStarterProjectCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

												// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AStarterProjectCharacter::BeginPlay()
{
	Super::BeginPlay();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AStarterProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AStarterProjectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AStarterProjectCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AStarterProjectCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AStarterProjectCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AStarterProjectCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AStarterProjectCharacter::TouchStopped);
}

void AStarterProjectCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void AStarterProjectCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void AStarterProjectCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AStarterProjectCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AStarterProjectCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AStarterProjectCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

bool AStarterProjectCharacter::TestMulticast_Validate()
{
	return true;
}

void AStarterProjectCharacter::TestMulticast_Implementation()
{
}


bool AStarterProjectCharacter::TestRPC_Validate()
{
	return true;
}

void AStarterProjectCharacter::TestRPC_Implementation()
{

}

void AStarterProjectCharacter::StartFire()
{
    check(GetNetMode() != NM_DedicatedServer);

    if (IgnoreActionInput())
    {
        return;
    }

    AWeapon* Weapon = GetEquippedWeapon();
    if (Weapon != nullptr)
    {
        // Don't allow sprinting and shooting at the same time.
        StopSprinting();

        Weapon->StartFire();
    }
}

void AStarterProjectCharacter::StopFire()
{
    check(GetNetMode() != NM_DedicatedServer);

    if (IgnoreActionInput())
    {
        return;
    }

    AWeapon* Weapon = GetEquippedWeapon();
    if (Weapon != nullptr)
    {
        Weapon->StopFire();
    }
}

bool AStarterProjectCharacter::IgnoreActionInput() const
{
    check(GetNetMode() != NM_DedicatedServer);

    if (AStarterProjectPlayerController* PC = Cast<AStarterProjectPlayerController>(GetController()))
    {
        return PC->IgnoreActionInput();
    }
    return false;
}

void AStarterProjectCharacter::SpawnWeapon()
{
    if (!HasAuthority())
    {
        return;
    }

    if (WeaponTemplate == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("No starter weapon defined."));
        return;
    }

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    AWeapon* StartWeapon =
        GetWorld()->SpawnActor<AWeapon>(WeaponTemplate, GetActorTransform(), SpawnParams);
    StartWeapon->SetOwningCharacter(this);
    StartWeapon->AttachToComponent(
        GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, kRightGunSocketName);

    UE_LOG(LogTPS, Log, TEXT("Set weapon for character %s to %s"), *this->GetName(),
           *StartWeapon->GetName());
    EquippedWeapon = StartWeapon;
}

void AStarterProjectCharacter::UpdateAimRotation(float AngleUpdateThreshold)
{
    FRotator AimDelta = GetControlRotation() - GetActorRotation();
    AimDelta.Normalize();
    float NewAimYaw = FMath::ClampAngle(AimDelta.Yaw, -90.0f, 90.0f);
    float NewAimPitch = FMath::ClampAngle(AimDelta.Pitch, -90.0f, 90.0f);

    if (FMath::Abs(NewAimYaw - AimYaw) > AngleUpdateThreshold)
    {
        AimYaw = FMath::ClampAngle(AimDelta.Yaw, -90.0f, 90.0f);
    }
    if (FMath::Abs(NewAimPitch - AimPitch) > AngleUpdateThreshold)
    {
        AimPitch = FMath::ClampAngle(AimDelta.Pitch, -90.0f, 90.0f);
    }
}

void AStarterProjectCharacter::TakeGunDamage_Implementation(float Damage, const FDamageEvent& DamageEvent)
{
    if (!HasAuthority())
    {
        return;
    }

    const AStarterProjectCharacter* Killer = nullptr;
	    
    int32 DamageDealt = FMath::Min(static_cast<int32>(Damage), CurrentHealth);
    CurrentHealth -= DamageDealt;

    if (CurrentHealth <= 0)
    {
        Die(Killer);
    }
}

FVector AStarterProjectCharacter::GetLineTraceStart() const
{
    return GetFollowCamera()->GetComponentLocation();
}

FVector AStarterProjectCharacter::GetLineTraceDirection() const
{
    return GetFollowCamera()->GetForwardVector();
}

