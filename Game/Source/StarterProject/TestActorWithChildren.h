// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActorWithChildren.generated.h"

UCLASS()
class STARTERPROJECT_API ATestActorWithChildren : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActorWithChildren();

private:
	// So it can have a position in the world.
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMesh1;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMesh2;

	UPROPERTY(VisibleAnywhere)
	class UChildActorComponent* ChildActor1;

	UPROPERTY(VisibleAnywhere)
	class UChildActorComponent* ChildActor2;
	
};
