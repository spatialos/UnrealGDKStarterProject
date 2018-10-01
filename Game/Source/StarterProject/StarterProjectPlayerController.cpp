// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "StarterProjectPlayerController.h"
#include "SpatialNetDriver.h"
#include "EntityRegistry.h"

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

void AStarterProjectPlayerController::ServerTravel_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("!!SERVER TRAVEL!!"));

	UWorld* World = GetWorld();
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(World->GetNetDriver());

	// TOOD: Need a 'done' thingy here
	NetDriver->WipeWorld();

	// Reload snapshot....
	NetDriver->LoadSnapshot();

	FURL NewURL = World->URL;
	NewURL.Map = "/Game/ThirdPersonCPP/Maps/BestMap";
	World->ServerTravel(TEXT("/Game/ThirdPersonCPP/Maps/BestMap"), true);
}

bool AStarterProjectPlayerController::ServerTravel_Validate()
{
	UWorld* World = GetWorld();
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(World->GetNetDriver());
	bool isServer = NetDriver->IsServer();
	return isServer;
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
