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

	AStarterProjectPlayerController();

	UFUNCTION(Server, Reliable, WithValidation)
	void TestRPC();

	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void TestMulticast();

public:

	virtual void InitPlayerState() override;

protected:
	// Character respawn delay, in seconds.
	UPROPERTY(EditDefaultsOnly, Category = "Respawn")
	float RespawnCharacterDelay;

	// Time for which to keep the character's body around before deleting it.
	UPROPERTY(EditDefaultsOnly, Category = "Respawn")
	float DeleteCharacterDelay;

	// Pawn to be deleted when the DeletePawn timer expires.
	UPROPERTY()
	class APawn* PawnToDelete;
	// If the pawn dies on a different server from its spawn location, respawn it where it died.
	FTransform DeadPawnTransform;

	FTimerHandle RespawnTimerHandle;
	FTimerHandle DeleteCharacterTimerHandle;
};
