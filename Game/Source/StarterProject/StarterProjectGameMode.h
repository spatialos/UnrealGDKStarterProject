// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StarterProjectGameMode.generated.h"

UCLASS(minimalapi, SpatialType=(Singleton, ServerOnly))
class AStarterProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AStarterProjectGameMode();

	//virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly, Category = "Spatial Networking")
	int32 MaxActorsToReplicate;

private:
	bool bHasUpdatedMaxActorsToReplicate = false;
};
