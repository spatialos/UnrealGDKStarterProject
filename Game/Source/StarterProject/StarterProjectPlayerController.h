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

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(Server, Reliable, WithValidation)
	void TestRPC();

	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void TestMulticast();

	// Overrides AController::SetPawn, which should be called on the client and server whenever the controller
	// possesses (or unpossesses) a pawn.
	//virtual void SetPawn(APawn* InPawn) override;
public:

	virtual void InitPlayerState() override;

	// [server] Tells the controller that it's time for the player to die, and sets up conditions for respawn.
	void KillCharacter();

	// [server] Causes the character to respawn.
	void RespawnCharacter();

	// [server] Deletes the character.
	void DeleteCharacter();

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
