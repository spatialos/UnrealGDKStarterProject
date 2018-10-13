// Fill out your copyright notice in the Description page of Project Settings.

#include "ContainerBase.h"

#include "UnrealNetwork.h"


// Sets default values
AContainerBase::AContainerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SetReplicates(true);

}

// Called when the game starts or when spawned
void AContainerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AContainerBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AContainerBase, Items);
}

// Called every frame
void AContainerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AContainerBase::AddItem(class AItemBase* Item)
{
	Items.Add(Item);
}

void AContainerBase::OnRep_Items()
{
	UE_LOG(LogClass, Log, TEXT("OnRep_Items: %s"), *GetName());
}

