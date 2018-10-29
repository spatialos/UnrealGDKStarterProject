// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StarterProjectWeapon.generated.h"


enum class EWeaponState : uint8
{
	Idle,
	Firing
};

// Tag for weapon line trace visualization.

USTRUCT()
struct FInstantHitInfo
{
	GENERATED_USTRUCT_BODY()

		// Location of the hit in world space.
		UPROPERTY()
		FVector Location;

	// Actor that was hit, or nullptr if nothing was hit.
	UPROPERTY()
		AActor* HitActor;

	FInstantHitInfo() :
		Location(FVector{ 0,0,0 }),
		HitActor(nullptr)
	{}
};

UCLASS()
class AStarterProjectWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AStarterProjectWeapon();
	
	// [client] Starts firing the weapon.
	void StartFire();
	
	// [client] Runs a line trace and triggers the server RPC for hits.
	void DoFire();

	// [client] Performs a line trace and populates OutHitInfo based on the results.
	// Returns true if it hits anything, false otherwise.
	bool DoLineTrace(FInstantHitInfo& OutHitInfo);

	// [server] Notifies clients of a hit.
	void NotifyClientsOfHit(const FInstantHitInfo& HitInfo);

	// [client] Spawns the hit FX in the world.
	void SpawnHitFX(const FInstantHitInfo& HitInfo);

	// RPC for telling the server that we fired and hit something.
    UFUNCTION(Server, Reliable, WithValidation)
    void ServerDidHit(const FInstantHitInfo& HitInfo);
    bool ServerDidHit_Validate(const FInstantHitInfo& HitInfo);
    void ServerDidHit_Implementation(const FInstantHitInfo& HitInfo);

	// [server] Validates the hit. Returns true if it's valid, false otherwise.
	bool ValidateHit(const FInstantHitInfo& HitInfo);

	// [server] Actually deals damage to the actor we hit.
	void DealDamage(const FInstantHitInfo& HitInfo);

	// [client] Actually stops the weapon firing.
	void StartFiring();
	// [client] Actually stops the weapon firing.
	void StopFiring();

	// Notifies all clients that a shot hit something. Used for visualizing shots on the client.
	UFUNCTION(NetMulticast, Unreliable)
	void MulticastNotifyHit(FInstantHitInfo HitInfo);
	    
	class AStarterProjectCharacter* GetOwningCharacter() const;
	void SetOwningCharacter(class AStarterProjectCharacter* NewCharacter);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	EWeaponState GetWeaponState() const;
	void SetWeaponState(EWeaponState NewState);
	
private:
	EWeaponState CurrentState;

	// Set up a root component so this actor can have a position in the world.
	class USceneComponent* LocationComponent;

	// Character that currently owns this weapon.
	UPROPERTY(Replicated)
	class AStarterProjectCharacter* OwningCharacter;

	// Weapon mesh.
	UPROPERTY(VisibleAnywhere, Category = "Weapons", meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Mesh;	

	// Maximum range of the weapon's hitscan.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float MaxRange;

	// Base damage done to others by a single shot.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float ShotBaseDamage;

	// Tolerance, in world units, to add to the bounding box of an actor when validating hits.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float HitValidationTolerance;

	// Type of damage to send to hit actors.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	TSubclassOf<UDamageType> DamageTypeClass;

	// Template for the particle system to spawn in the world on hits.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	class UParticleSystem* HitFXTemplate;
};
