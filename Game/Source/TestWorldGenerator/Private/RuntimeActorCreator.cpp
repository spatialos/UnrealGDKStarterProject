// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeActorCreator.h"


// Sets default values
ARuntimeActorCreator::ARuntimeActorCreator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARuntimeActorCreator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARuntimeActorCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

