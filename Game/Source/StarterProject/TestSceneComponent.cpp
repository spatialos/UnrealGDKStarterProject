// Fill out your copyright notice in the Description page of Project Settings.
#pragma optimize("", off)

#include "TestSceneComponent.h"

#include "UnrealNetwork.h"


UTestSceneComponent::UTestSceneComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UTestSceneComponent::BeginPlay()
{
	Super::BeginPlay();
}

#pragma optimize("", on)
