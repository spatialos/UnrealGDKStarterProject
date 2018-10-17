// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EditorActorCreator.generated.h"

UCLASS()
class STARTERPROJECT_API AEditorActorCreator : public AActor
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

	UFUNCTION(BlueprintCallable, Category = "Actor Creator")
	void CreateActors();

	UFUNCTION(BlueprintCallable, Category = "Actor Creator")
	void ClearActors();

	UFUNCTION(BlueprintCallable, Category = "Actor Creator")
	void CreateSublevels();

	UPROPERTY(VisibleAnywhere, Category = "Actor Creator")
	class UWorld* GeneratedWorld;

private:
	UPROPERTY(EditAnywhere, Category = "Actor Creator")
	TSubclassOf<AActor> ActorTemplate;

	UPROPERTY(EditAnywhere, Category = "Actor Creator")
	int32 Rows;

	UPROPERTY(EditAnywhere, Category = "Actor Creator")
	int32 Columns;

	UPROPERTY(EditAnywhere, Category = "Actor Creator")
	float Width;

	UPROPERTY(EditAnywhere, Category = "Actor Creator")
	float Height;

	UPROPERTY(VisibleAnywhere, Category = "Actor Creator")
	TArray<AActor*> CreatedActors;
	
};
