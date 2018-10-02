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

void AStarterProjectPlayerController::ServerTravel_Implementation(const FString& MapName)
{
	UE_LOG(LogTemp, Warning, TEXT("!!SERVER TRAVEL to %s!!"), *MapName);

	UWorld* World = GetWorld();
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(World->GetNetDriver());

	//// Reload snapshot.... (Currently in the WorldWIpe code)
	//NetDriver->LoadSnapshot();

	//USpatialNetDriver::WorldWipeDelegate ServerTravelAfterWorldWipe;
	//ServerTravelAfterWorldWipe.BindLambda([World, NetDriver] {
	//	World->ServerTravel(TEXT("/Game/ThirdPersonCPP/Maps/BestMap"), true);
	//	NetDriver->LoadSnapshot();
	//});

	//// Delegate is called in USpatialNetDriver::WorldWipe;
	//NetDriver->Delegate = ServerTravelAfterWorldWipe;

	//NetDriver->WipeWorld();

	World->ServerTravel(MapName, true);
	NetDriver->LoadSnapshot();
}

bool AStarterProjectPlayerController::ServerTravel_Validate(const FString& MapName)
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
