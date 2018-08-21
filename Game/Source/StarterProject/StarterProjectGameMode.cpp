// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "StarterProjectGameMode.h"
#include "StarterProjectPlayerController.h"
#include "StarterProjectGameStateBase.h"
#include "StarterProjectPlayerState.h"
#include "UObject/ConstructorHelpers.h"

AStarterProjectGameMode::AStarterProjectGameMode()
{
	//set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/EntityBlueprints/StarterProjectCharacter_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AStarterProjectPlayerController::StaticClass();
	GameStateClass = AStarterProjectGameStateBase::StaticClass();
	PlayerStateClass = AStarterProjectPlayerState::StaticClass();
}
