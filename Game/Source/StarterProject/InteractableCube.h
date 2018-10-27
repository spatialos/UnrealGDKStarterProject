// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "InteractableCube.generated.h"

UCLASS(SpatialType)
class STARTERPROJECT_API AInteractableCube : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableCube();

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	void Interact();

	virtual void Interact_Implementation() override;

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSwapMaterials();

	UPROPERTY(EditAnywhere, ReplicatedUsing = OnRep_UseOtherMaterial)
	bool bUseOtherMaterial;

	UPROPERTY(EditAnywhere, Category = "Testing")
	class UMaterialInterface* Material1;

	UPROPERTY(EditAnywhere, Category = "Testing")
	class UMaterialInterface* Material2;

private:
	UFUNCTION(BlueprintCallable, Category = "Testing")
	void OnRep_UseOtherMaterial();

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* MyRootComponent;
	
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMeshComponent;
	
};
