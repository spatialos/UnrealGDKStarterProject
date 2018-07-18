// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "StarterProjectPlayerController.h"
#include "EntityId.h"
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

void AStarterProjectPlayerController::InitPlayerState()
{
	// TODO: this is a workaround until we can query a replicated UObject*'s UnrealObjRef - UNR-407
	FEntityId EntityId = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver())->GetEntityRegistry()->GetEntityIdFromActor(this);
	UE_LOG(LogTemp, Log, TEXT("PC:InitPlayerState called with entity id %d"), EntityId.ToSpatialEntityId());
	if (EntityId == 0)
	{
		// EntityId is 0, so this is the first time this PC has been init. Allow it to create a new PlayerState.
		Super::InitPlayerState();
	}
}
