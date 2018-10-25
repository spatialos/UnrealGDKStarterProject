// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TestSceneComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARTERPROJECT_API UTestSceneComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UTestSceneComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NonReplicatedString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NonReplicatedInt;

protected:
	virtual void BeginPlay() override;

};
