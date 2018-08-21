// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StarterProjectPlayerController.generated.h"

/**
 * 
 */
UCLASS(SpatialType)
class STARTERPROJECT_API AStarterProjectPlayerController : public APlayerController
{
	GENERATED_BODY()

	UFUNCTION(Server, Reliable, WithValidation)
	void TestRPC();

	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void TestMulticast();

public:

	virtual void InitPlayerState() override;
};
