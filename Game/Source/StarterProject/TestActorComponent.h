// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TestActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARTERPROJECT_API UTestActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTestActorComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	FString ReplicatedString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NonReplicatedString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NonReplicatedInt;

protected:
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};
