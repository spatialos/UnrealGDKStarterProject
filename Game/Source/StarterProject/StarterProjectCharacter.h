// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "StarterProjectCharacter.generated.h"

UCLASS(config=Game, SpatialType)
class AStarterProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AStarterProjectCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// [client] Triggers the equipped weapon to start firing.
	void StartFire();

	// [client] Triggers the equipped weapon to stop firing.
	void StopFire();

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	void Interact();

	UFUNCTION(Server, Reliable, WithValidation)
	void TestRPC();

	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void TestMulticast();
		   
    // [server] Spawns a starter weapon and attaches it to the character.
    void SpawnWeapon();

    // [server] Tells this player that it's time to die.
    void Die();

	// [client + server] Puts the player in ragdoll mode.
	void StartRagdoll();

	// [owning client + server] Updates the aim variables to be sync-ed out to clients, or updates the values locally
	// if we're executing on the owning client.
	// Will only update the angles if they differ from the current stored value by more than AngleUpdateThreshold.
	void UpdateAimRotation(float AngleUpdateThreshold);

	// Current health of the character, can be at most MaxHealth.
    UPROPERTY(ReplicatedUsing = OnRep_CurrentHealth)
    int32 CurrentHealth;

	UPROPERTY(Replicated)
	float AimYaw;

	UPROPERTY(Replicated)
	float AimPitch;

	// Max health this character can have.
	UPROPERTY(EditDefaultsOnly, Category = "Health", meta = (ClampMin = "1"))
	int32 MaxHealth;

	UPROPERTY(VisibleAnywhere, Replicated)
    class AStarterProjectWeapon* EquippedWeapon;

	UPROPERTY(ReplicatedUsing = OnRep_IsRagdoll)
	bool bIsRagdoll;
	
	UFUNCTION()
	void OnRep_CurrentHealth();

	UFUNCTION()
	void OnRep_IsRagdoll();

	// If the aim offset angles change more than this threshold, update our local aim offset values (only applies on the owning client).
	// Value is in degrees.
	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float LocalAimUpdateThreshold;

	// If the aim offset angles change more than this threshold, update our replicated aim offset values.
	// Value is in degrees.
	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float RemoteAimUpdateThreshold;

	// Weapon to spawn the player with initially.
    UPROPERTY(EditDefaultsOnly, Category = "Weapons")
    TSubclassOf<class AStarterProjectWeapon> WeaponTemplate;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// Returns a position from which to start a line trace.
	// Use this so your line trace doesn't collide with the player character.
	FVector GetLineTraceStart() const;

	// Returns the direction in which to perform a line trace so it lines up with the center of the crosshair.
	FVector GetLineTraceDirection() const;

	UFUNCTION(CrossServer, Reliable)
	void TakeGunDamage(float Damage, const struct FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
};

