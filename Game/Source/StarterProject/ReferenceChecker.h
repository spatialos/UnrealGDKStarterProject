// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReferenceChecker.generated.h"

UCLASS()
class STARTERPROJECT_API AReferenceChecker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReferenceChecker();

public:	
	UPROPERTY(EditAnywhere)
	AActor* Reference;
	
};
