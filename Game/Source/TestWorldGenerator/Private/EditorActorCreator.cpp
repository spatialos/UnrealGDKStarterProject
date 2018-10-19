// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorActorCreator.h"

#include "AssetRegistryModule.h"
#include "Editor.h"
#include "EditorDirectories.h"
#include "Engine/World.h"
#include "Engine/WorldComposition.h"
#include "FileHelpers.h"
#include "GameFramework/Actor.h"
#include "Misc/Paths.h"


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
	//if (GeneratedWorld == nullptr)
	{
		// Save new level to the same directory where selected level/folder is
		UWorld* EditorWorld = GEditor->GetEditorWorldContext().World();
		FName EditorWorldPackageName = EditorWorld->PersistentLevel->GetOutermost()->GetFName();
		check(EditorWorldPackageName != NAME_None);
		//FString Directory = FPackageName::LongPackageNameToFilename(TEXT("/Game/Maps/StreamingGym/StreamingGym"), FPackageName::GetMapPackageExtension());
		//FString Directory = FPackageName::LongPackageNameToFilename(EditorWorldPackageName.ToString(), FPackageName::GetMapPackageExtension())
		FString RootPackageName = EditorWorldPackageName.ToString();
		FString RootDirectoryName = FPaths::GetPath(EditorWorldPackageName.ToString());
				
		// Create a new world - so we can 'borrow' its level
		UWorld* NewGWorld = UWorld::CreateWorld(EWorldType::None, false );
		check(NewGWorld);

		// Save the last directory
		//FString OldLastDirectory = FEditorDirectories::Get().GetLastDirectory(ELastDirectory::UNR);
		// Temporally change last directory to our path	
		//FEditorDirectories::Get().SetLastDirectory(ELastDirectory::UNR, Directory);
		// Save new empty level
		//SaveAssetsAs:SaveLevel(NewGWorld->PersistentLevel);
		FString ProposedFilename = FPackageName::LongPackageNameToFilename(FPaths::Combine(RootDirectoryName, TEXT("Sublevels"), TEXT("Test_1A")), FPackageName::GetMapPackageExtension());
		FString FinalFilename;
		bool bSaved = FEditorFileUtils::SaveLevel(NewGWorld->PersistentLevel, ProposedFilename, &FinalFilename);
		// Restore last directory	
		//FEditorDirectories::Get().SetLastDirectory(ELastDirectory::UNR, OldLastDirectory);

		// Update levels list
		if (bSaved)
		{
			FString FinalPackageName = FPackageName::FilenameToLongPackageName(FinalFilename);
			UE_LOG(LogTemp, Log, TEXT("DEBUGDAVE: saved map %s to %s"), *FinalPackageName, *FinalFilename);
			CreatedSublevelPackageNames.Add(FinalPackageName);
			UWorldComposition* WorldComposition = EditorWorld ? EditorWorld->WorldComposition : nullptr;
			if (WorldComposition)
			{
				//IModuleInterface* WorldBrowserModuleReference = FModuleManager::Get().GetModule(FName(TEXT("WorldBrowser")));
				//if (WorldBrowserModuleReference)
				//{
				//	if (FWorldBrowserModule* WorldBrowserModule = Cast<FWorldBrowserModule>(WorldBrowserModuleReference))
				//	{
				//		WorldBrowserModule->SharedWorldModel(EditorWorld)->PopulateLevelsList();
				//	}
				//}
				//WorldComposition->Rescan();
			}
		}
		
		// Destroy the new world we created and collect the garbage
		NewGWorld->DestroyWorld( false );
		CollectGarbage( GARBAGE_COLLECTION_KEEPFLAGS );

		return;

		const TCHAR* RootPackage = GetWorld()->PersistentLevel->StaticPackage();
		UE_LOG(LogTemp, Log, TEXT("DEBUGDAVE: %s"), RootPackage);

		// TODO: find the package path of the root persistent level.
		FString PackagePath = FString("/Game/Maps/StreamingGym/Sublevels/Test_1A");
		UPackage* Package = CreatePackage(nullptr, *PackagePath);

		FString AssetName = FString("GeneratedLevel");

		// Create new world to steal its level.
		UWorld* NewWorld = UWorld::CreateWorld(EWorldType::None, false);
		check(NewWorld);

		FAssetRegistryModule::AssetCreated(NewWorld);
		NewWorld->MarkPackageDirty();

		FString FilePath = FPackageName::LongPackageNameToFilename(PackagePath, FPackageName::GetAssetPackageExtension());
		bool bSuccess = UPackage::SavePackage(Package, NewWorld, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *FilePath);

		UE_LOG(LogTemp, Log, TEXT("Saved asset: %s %s"), *FilePath, bSuccess ? TEXT("Success") : TEXT("Failure"));

		if (bSuccess)
		{
			// TODO: PopulateLevelsList()
		}

		NewWorld->DestroyWorld(false);
		CollectGarbage(GARBAGE_COLLECTION_KEEPFLAGS);
	}
}

