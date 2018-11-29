// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactions/InteractionManager.h"

#include "GameFramework/Character.h"
#include "Interactions/InteractAction.h"
#include "Net/UnrealNetwork.h"


UInteractionManager::UInteractionManager()
{
	SetIsReplicated(true);
}

void UInteractionManager::OpenMenu(AActor* Target)
{
	TargetActor = Target;

	if (GetOwner()->Role < ROLE_Authority)
	{
		ServerOpenMenu(Target);
	}

	if (GetNetMode() == NM_Standalone || GetNetMode() > NM_DedicatedServer)
	{
		FName MenuName = Target->GetClass()->GetFName();
		FInteractionMenuData* MenuData = MenuDataTable->FindRow<FInteractionMenuData>(MenuName, TEXT(""));
		if (MenuData == nullptr)
		{
			return;
		}

		APlayerController* PC = Cast<APlayerController>(Cast<ACharacter>(GetOwner())->GetController());
		UUserWidget* Menu = InteractMenuCache.FindRef(MenuName);
		if (Menu == nullptr)
		{
			Menu = CreateWidget(PC, MenuData->MenuType);
			InteractMenuCache.Add(MenuName, Menu);
		}
		Menu->AddToViewport(0);
		CurrentMenu = Menu;
		PC->SetInputMode(FInputModeGameAndUI());
		PC->bShowMouseCursor = true;
	}
}

void UInteractionManager::ServerOpenMenu_Implementation(AActor* Target)
{
	OpenMenu(Target);
}

bool UInteractionManager::ServerOpenMenu_Validate(AActor* Target)
{
	return true;
}

void UInteractionManager::CloseMenu()
{
	if (CurrentMenu != nullptr)
	{
		CurrentMenu->RemoveFromViewport();
		CurrentMenu = nullptr;
		APlayerController* PC = Cast<APlayerController>(Cast<ACharacter>(GetOwner())->GetController());
		PC->SetInputMode(FInputModeGameOnly());
		PC->bShowMouseCursor = false;
	}
}

void UInteractionManager::DoAction(FName ActionName)
{
	FInteractionActionData* ActionData = ActionDataTable->FindRow<FInteractionActionData>(ActionName, TEXT(""));
	if (ActionData == nullptr)
	{
		return;
	}

	if (GetOwner() && GetOwner()->Role < ROLE_Authority && ActionData->bRunOnServer)
	{
		ServerDoAction(ActionName);
		return;
	}

	if (TargetActor == nullptr)
	{
		return;
	}

	AInteractAction* Action = InteractActionCache.FindRef(ActionName);
	if (Action == nullptr)
	{
		FActorSpawnParameters SpawnParams;
		Action = GetWorld()->SpawnActor<AInteractAction>(ActionData->ActionType, FTransform::Identity, SpawnParams);
		InteractActionCache.Add(ActionName, Action);
	}
	Action->DoAction(TargetActor);
}

bool UInteractionManager::IsActorInteractable(AActor* Target)
{
	FName MenuName = Target->GetClass()->GetFName();
	FInteractionMenuData* MenuData = MenuDataTable->FindRow<FInteractionMenuData>(MenuName, TEXT(""));
	return MenuData != nullptr;
}

void UInteractionManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME(UInteractionManager, TargetActor);
}

void UInteractionManager::OnRep_TargetActor()
{
	OpenMenu(TargetActor);
}

void UInteractionManager::ServerDoAction_Implementation(FName ActionName)
{
	DoAction(ActionName);
}

bool UInteractionManager::ServerDoAction_Validate(FName ActionName)
{
	return true;
}
