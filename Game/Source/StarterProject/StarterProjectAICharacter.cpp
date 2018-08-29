// Fill out your copyright notice in the Description page of Project Settings.

#include "StarterProjectAICharacter.h"
#include "EntityId.h"
#include "SpatialNetDriver.h"
#include "EntityRegistry.h"

// Sets default values
AStarterProjectAICharacter::AStarterProjectAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStarterProjectAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStarterProjectAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AStarterProjectAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AStarterProjectAICharacter::SpawnDefaultController()
{
	// TODO: this is a workaround until we can query a replicated UObject*'s UnrealObjRef - UNR-407
	// Don't spawn a new AI controller if we're being handed over
	UWorld* World = GetWorld();
	check(World);
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(World->GetNetDriver());
	if (NetDriver)
	{
		const FEntityId EntityId = NetDriver->GetEntityRegistry()->GetEntityIdFromActor(this);
		UE_LOG(LogTemp, Log, TEXT("AIPawn:SpawnDefaultController called with entity id %d"), EntityId.ToSpatialEntityId());
		if (EntityId != 0)
		{
			// EntityId is not 0, which means that this AI pawn has already been initialized.
			return;
		}
	}

	Super::SpawnDefaultController();
}

void AStarterProjectAICharacter::Destroyed()
{
	UE_LOG(LogTemp, Log, TEXT("%s being destroyed"), *this->GetName());
	Super::Destroyed();
}
