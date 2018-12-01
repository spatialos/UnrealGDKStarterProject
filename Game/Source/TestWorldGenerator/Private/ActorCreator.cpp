// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorCreator.h"

#include "Engine/World.h"
#include "Net/UnrealNetwork.h"


// Sets default values
AActorCreator::AActorCreator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetReplicates(true);
}

// Called when the game starts or when spawned
void AActorCreator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorCreator::CreateActors()
{
	UE_LOG(LogTemp, Log, TEXT("Creating actors..."));

	if (Width <= 0.0f || Depth <= 0.0f || Height <= 0.0f || Columns <= 0 || Rows < 0 || Planes <= 0 || ActorTemplate == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("%s check your actor creator settings."), *GetName());
		return;
	}

	float XStep = Width / FMath::Max(1, Columns-1);
	float YStep = Depth / FMath::Max(1, Rows-1);
	float ZStep = Height / FMath::Max(1, Planes-1);

	FActorSpawnParameters SpawnParams;

	for (int X = 0; X < Columns; ++X)
	{
		for (int Y = 0; Y < Rows; ++Y)
		{
			for (int Z = 0; Z < Planes; ++Z)
			{
				FVector Location(XStep * X, YStep * Y, ZStep * Z);
				Location += GetActorLocation() + SpawnOffset;
				CreatedActors.Add(GetWorld()->SpawnActor(ActorTemplate, &Location, &FRotator::ZeroRotator, SpawnParams));
			}
		}
	}
	CreatedActorCount = CreatedActors.Num();
}

void AActorCreator::ClearActors()
{
	for (AActor* A : CreatedActors)
	{
		if (A && A->IsValidLowLevel() && !A->IsPendingKill())
		{
			A->Destroy();
		}
	}
	CreatedActors.Empty();
	CreatedActorCount = CreatedActors.Num();
}

void AActorCreator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AActorCreator, CreatedActorCount);
}

