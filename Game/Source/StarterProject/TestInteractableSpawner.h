// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "TestInteractableSpawner.generated.h"

UCLASS()
class STARTERPROJECT_API ATestInteractableSpawner : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestInteractableSpawner();

public:	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	void Interact();

	virtual void Interact_Implementation() override;

	UPROPERTY(Handover, EditAnywhere, Category = "Spawner")
	TSubclassOf<AActor> SpawnTemplate;

	UPROPERTY(Handover, EditAnywhere, Category = "Spawner")
	FVector SpawnOffset;

};
