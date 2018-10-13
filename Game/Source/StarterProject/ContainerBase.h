// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ContainerBase.generated.h"

UCLASS()
class STARTERPROJECT_API AContainerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AContainerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Item Container")
	void AddItem(class AItemBase* Item);

	UPROPERTY(ReplicatedUsing = OnRep_Items)
	TArray<class AItemBase*> Items;

	UFUNCTION()
	void OnRep_Items();
	
	
};
