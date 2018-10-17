// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorActorCreator.h"

#include "AssetRegistryModule.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"


// Sets default values
AEditorActorCreator::AEditorActorCreator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEditorActorCreator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEditorActorCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEditorActorCreator::CreateActors()
{
	UE_LOG(LogTemp, Log, TEXT("Creating actors..."));

	if (Width <= 0.0f || Height <= 0.0f || Columns <= 0 || Rows < 0 || ActorTemplate == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("%s check your actor creator settings."), *GetName());
		return;
	}

	float XStep = Width / Columns;
	float YStep = Height / Rows;
	float XOrigin = -(Width-1) * 0.5f;
	float YOrigin = -(Height-1) * 0.5f;

	FActorSpawnParameters SpawnParams;

	for (int X = 0; X < Columns; ++X)
	{
		for (int Y = 0; Y < Rows; ++Y)
		{
			FVector Location(XOrigin + (XStep * X), YOrigin + (YStep * Y), 0.0f);
			Location += GetActorLocation();
			CreatedActors.Add(GetWorld()->SpawnActor(ActorTemplate, &Location, &FRotator::ZeroRotator, SpawnParams));
		}
	}
}

void AEditorActorCreator::ClearActors()
{
	for (AActor* A : CreatedActors)
	{
		if (A && A->IsValidLowLevel() && !A->IsPendingKill())
		{
			A->Destroy();
		}
	}
	CreatedActors.Empty();
}

void AEditorActorCreator::CreateSublevels()
{
	if (GeneratedWorld == nullptr)
	{
		FString PackagePath = FString("/Game/GeneratedLevel");
		UPackage* Package = CreatePackage(nullptr, *PackagePath);

		FString AssetName = FString("GeneratedLevel");
		GeneratedWorld = UWorld::CreateWorld(EWorldType::Editor, true, FName(*AssetName), Package);
		FAssetRegistryModule::AssetCreated(GeneratedWorld);
		GeneratedWorld->MarkPackageDirty();

		FString FilePath = FPackageName::LongPackageNameToFilename(PackagePath, FPackageName::GetAssetPackageExtension());
		bool bSuccess = UPackage::SavePackage(Package, GeneratedWorld, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *FilePath);

		UE_LOG(LogTemp, Log, TEXT("Saved asset: %s %s"), *FilePath, bSuccess ? TEXT("Success") : TEXT("Failure"));
	}
}

