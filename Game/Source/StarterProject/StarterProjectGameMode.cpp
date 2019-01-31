// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "StarterProjectGameMode.h"
#include "UObject/ConstructorHelpers.h"

AStarterProjectGameMode::AStarterProjectGameMode()
{
	//set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/StarterProject/Characters/PlayerCharacter_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
