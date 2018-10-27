// Fill out your copyright notice in the Description page of Project Settings.
#pragma optimize("", off)

#include "ActorCloner.h"

#include "Engine/World.h"
#include "GameFramework/Actor.h"


// Sets default values
AActorCloner::AActorCloner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AActorCloner::Interact_Implementation()
{
	ServerCloneActor();
}

void AActorCloner::ServerCloneActor_Implementation()
{
	AActor* TemplateActor = nullptr;

	if (SpawnTemplate)
	{
		TemplateActor = SpawnTemplate;
	}
	else if (!SpawnTemplatePath.IsEmpty())
	{
		// If this actor has a stable path, attempt to load the object from the map file to grab its initial data.
		UObject* FoundObject = StaticLoadObject(AActor::StaticClass(), nullptr, *SpawnTemplatePath);
		if (AActor* FoundActor = Cast<AActor>(FoundObject))
		{
			// Pass the actor from the map package in as a template so all instance-modified values are retained.
			TemplateActor = FoundActor;
		}
	}

	if (TemplateActor)
	{
		AActor* DuplicatedActor = Cast<AActor>(StaticDuplicateObject(TemplateActor, GetWorld()->PersistentLevel));

		if (!DuplicatedActor->HasActorBegunPlay())
		{
			DuplicatedActor->DispatchBeginPlay();
		}
		DuplicatedActor->UpdateOverlaps();
		return;

		FActorSpawnParameters SpawnParams;
		SpawnParams.Template = TemplateActor;
		SpawnParams.bDeferConstruction = true;

		FTransform SpawnTransform(GetActorLocation() + SpawnOffset);

		FTransform SpawnTransformOffset = FTransform::Identity;
		USceneComponent* TemplateRootComponent = TemplateActor->GetRootComponent();
		if(TemplateRootComponent)
		{
			TemplateRootComponent->UpdateComponentToWorld();
			SpawnTransformOffset = TemplateRootComponent->GetComponentToWorld().Inverse() * SpawnTransform;
		}

		AActor* NewActor = GetWorld()->SpawnActorAbsolute(TemplateActor->GetClass(), SpawnTransform, SpawnParams);

		if (NewActor)
		{
			auto FixUpInitialValues = [&]() {
				TMap<FString, UActorComponent*> SourceComponentMap;
				const TSet<UActorComponent*>& SourceComponents = TemplateActor->GetComponents();
				for (auto SourceComponent : SourceComponents)
				{
					SourceComponentMap.Emplace(SourceComponent->GetName(), SourceComponent);
				}

				const TSet<UActorComponent*>& DestComponents = NewActor->GetComponents();
				for (auto DestComponent : DestComponents)
				{
					UActorComponent** SourceComponentPtr = SourceComponentMap.Find(DestComponent->GetName());
					if (SourceComponentPtr == nullptr || *SourceComponentPtr == nullptr) continue;
					UActorComponent* SourceComponent = *SourceComponentPtr;

					for (TFieldIterator<UProperty> PropertyIter(DestComponent->GetClass()); PropertyIter; ++PropertyIter)
					{
						UProperty* Property = *PropertyIter;
						void* Dest = Property->ContainerPtrToValuePtr<void>(Cast<UObject>(DestComponent));

						//if (UObjectProperty* ObjectProperty = Cast<UObjectProperty>(Property))
						//{
						//	if (!ObjectProperty->IsNameStableForNetworking())
						//	{
						//		continue;
						//	}

						//	UObject* ObjectRef = StaticFindObject(UObject::StaticClass(), nullptr, *ObjectProperty->GetName());
						//	if (ObjectRef == nullptr)
						//	{
						//		continue;
						//	}

						//	ObjectProperty->SetObjectPropertyValue(Dest, ObjectRef);
						//}
						//else
						{
							if (//Property->IsA<UObjectProperty>() ||
								Property->HasAnyPropertyFlags(CPF_Transient))  // ||
								//!Property->HasAllPropertyFlags(CPF_Edit))
							{
								continue;
							}

							void* Src = Property->ContainerPtrToValuePtr<void>(Cast<UObject>(SourceComponent));
							Property->CopyCompleteValue(Dest, Src);
						}
					}
				}
			};




			{  // FinishSpawning
				//NewActor->ExecuteConstruction(SpawnTransform, nullptr, /*InstanceDataCache*/ nullptr, /*bIsDefaultTransform*/ false);

				FixUpInitialValues();

				//NewActor->PostActorConstruction();
			}  // FinishSpawning

			{  // Taken from PostNetInit
				if (!NewActor->HasActorBegunPlay())
				{
					NewActor->DispatchBeginPlay();
				}
				NewActor->UpdateOverlaps();
			}  // PostNetInit

		}
	}
}

bool AActorCloner::ServerCloneActor_Validate()
{
	return true;
}

#pragma optimize("", on)
