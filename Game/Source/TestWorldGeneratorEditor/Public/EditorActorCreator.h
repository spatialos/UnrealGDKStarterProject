// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorCreator.h"
#include "EditorActorCreator.generated.h"

UCLASS()
class TESTWORLDGENERATOREDITOR_API AEditorActorCreator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEditorActorCreator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Level Creator")
	void CreateSublevels();

private:
	UPROPERTY(VisibleAnywhere, Category = "World Creator")
	TArray<FString> CreatedSublevelPackageNames;
	
};
