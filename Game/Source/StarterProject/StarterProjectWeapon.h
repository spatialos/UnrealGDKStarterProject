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

UCLASS()
class AStarterProjectWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AStarterProjectWeapon();

	// [client] Starts firing the weapon.
	virtual void StartFire();

	// [client] Stops firing the weapon.
	virtual void StopFire();

	// RPC for telling the server that we fired and hit something.
    UFUNCTION(Server, Reliable, WithValidation)
    void ServerDidHit(const FInstantHitInfo& HitInfo);
    bool ServerDidHit_Validate(const FInstantHitInfo& HitInfo);
    void ServerDidHit_Implementation(const FInstantHitInfo& HitInfo);
	    
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
};
