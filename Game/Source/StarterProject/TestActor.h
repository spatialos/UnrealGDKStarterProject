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

	UPROPERTY(EditAnywhere, Replicated)
	FString TestString;

	UPROPERTY(EditAnywhere, Replicated)
	int32 TestInt;

	bool bHasRun = false;

private:
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* MyRootComponent;
	
	
};
