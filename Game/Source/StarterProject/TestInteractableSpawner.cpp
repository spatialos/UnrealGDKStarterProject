// Fill out your copyright notice in the Description page of Project Settings.

#include "TestInteractableSpawner.h"

#include "Engine/World.h"
#include "UnrealNetwork.h"


ATestInteractableSpawner::ATestInteractableSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
	SetReplicates(true);
}

void ATestInteractableSpawner::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME(ATestInteractableSpawner, SpawnTemplate);
}

void ATestInteractableSpawner::Interact_Implementation()
{
	if (Role != ROLE_Authority)
	{
		UE_LOG(LogClass, Error, TEXT("%s: tried to call Interact on non-authoritative copy"), *GetName());
		return;
	}

	if (SpawnTemplate)
	{
		FTransform SpawnPosition(GetActorLocation() + SpawnOffset);
		GetWorld()->SpawnActor<AActor>(SpawnTemplate, SpawnPosition);
	}
}
