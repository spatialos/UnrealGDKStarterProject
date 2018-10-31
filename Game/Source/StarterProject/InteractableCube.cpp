// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableCube.h"

#include "Components/StaticMeshComponent.h"
#include "UnrealNetwork.h"


AInteractableCube::AInteractableCube()
	: bUseOtherMaterial(false)
{
	PrimaryActorTick.bCanEverTick = false;

	SetReplicates(true);

	MyRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(MyRootComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(MyRootComponent);
}

void AInteractableCube::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AInteractableCube, bUseOtherMaterial);
}

void AInteractableCube::BeginPlay()
{
	Super::BeginPlay();

	OnRep_UseOtherMaterial();
}

void AInteractableCube::Interact_Implementation()
{
	ServerSwapMaterials();
}

void AInteractableCube::ServerSwapMaterials_Implementation()
{
	bUseOtherMaterial = !bUseOtherMaterial;
}

bool AInteractableCube::ServerSwapMaterials_Validate()
{
	return true;
}

void AInteractableCube::OnRep_UseOtherMaterial()
{
	UMaterialInterface* SwitchToMaterial = bUseOtherMaterial ? Material2 : Material1;
	if (SwitchToMaterial)
	{
		StaticMeshComponent->SetMaterial(0, SwitchToMaterial);
	}
}

