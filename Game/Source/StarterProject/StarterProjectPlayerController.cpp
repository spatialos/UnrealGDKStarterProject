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

	// Mod the URL to include a server travel option.
	//FString SnapshotOption = "?snapshot=BestMap";
	//FString ModdedMapName = MapName;
	//ModdedMapName.Append(SnapshotOption);

	UWorld* World = GetWorld();

	World->ServerTravel(MapName, true);
}

bool AStarterProjectPlayerController::ServerTravel_Validate(const FString& MapName)
{
	UWorld* World = GetWorld();
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(World->GetNetDriver());
	if (NetDriver)
	{
		bool isServer = NetDriver->IsServer();
		return isServer;
	}

	return false;
}
