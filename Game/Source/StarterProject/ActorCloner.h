// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "ActorCloner.generated.h"

UCLASS()
class STARTERPROJECT_API AActorCloner : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorCloner();

public:	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	void Interact();

	virtual void Interact_Implementation() override;

	UPROPERTY(Handover, EditAnywhere, Category = "Spawner")
	class AActor* SpawnTemplate;

	UPROPERTY(Handover, EditAnywhere, Category = "Spawner")
	FString SpawnTemplatePath;

	UPROPERTY(Handover, EditAnywhere, Category = "Spawner")
	FVector SpawnOffset;
	
	
};
