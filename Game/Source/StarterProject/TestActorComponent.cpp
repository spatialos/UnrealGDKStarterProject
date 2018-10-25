// Fill out your copyright notice in the Description page of Project Settings.
#pragma optimize("", off)

#include "TestActorComponent.h"

#include "UnrealNetwork.h"


UTestActorComponent::UTestActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UTestActorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTestActorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UTestActorComponent, ReplicatedString);
}

#pragma optimize("", on)
