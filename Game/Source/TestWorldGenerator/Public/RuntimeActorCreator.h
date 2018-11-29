// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorCreator.h"
#include "RuntimeActorCreator.generated.h"

UCLASS()
class TESTWORLDGENERATOR_API ARuntimeActorCreator : public AActorCreator
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARuntimeActorCreator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
