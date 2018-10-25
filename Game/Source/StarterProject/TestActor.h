// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS(SpatialType)
class STARTERPROJECT_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnRep_OnRepTestString();

	UPROPERTY(EditAnywhere, ReplicatedUsing = OnRep_OnRepTestString)
	FString OnRepTestString;

	UPROPERTY(EditAnywhere, Replicated)
	FString TestString;

	UPROPERTY(EditAnywhere, Replicated)
	int32 TestInt;

	UPROPERTY(EditAnywhere)
	FString InitialDataStringCPP;

	UPROPERTY(EditAnywhere, Replicated)
	int32 NonReplicatedInt;

	bool bHasRun = false;

private:
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* MyRootComponent;
	
	UPROPERTY(VisibleAnywhere)
	class UTestSceneComponent* TestSceneComponent;

	UPROPERTY(VisibleAnywhere)
	class UTestActorComponent* TestActorComponent;
	
};
