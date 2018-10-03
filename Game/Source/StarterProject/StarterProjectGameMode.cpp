// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "StarterProjectGameMode.h"
#include "StarterProjectPlayerController.h"
#include "StarterProjectGameStateBase.h"
#include "StarterProjectPlayerState.h"
#include "EngineClasses/SpatialNetDriver.h"
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
	//bUseSeamlessTravel = true;
}

void AStarterProjectGameMode::ProcessServerTravel(const FString& URL, bool bAbsolute)
{
#if WITH_SERVER_CODE
	StartToLeaveMap();

	// Force an old style load screen if the server has been up for a long time so that TimeSeconds doesn't overflow and break everything
	bool bSeamless = (bUseSeamlessTravel && GetWorld()->TimeSeconds < 172800.0f); // 172800 seconds == 48 hours

	FString NextMap;
	if (URL.ToUpper().Contains(TEXT("?RESTART")))
	{
		NextMap = UWorld::RemovePIEPrefix(GetOutermost()->GetName());
	}
	else
	{
		int32 OptionStart = URL.Find(TEXT("?"));
		if (OptionStart == INDEX_NONE)
		{
			NextMap = URL;
		}
		else
		{
			NextMap = URL.Left(OptionStart);
		}
	}

	FGuid NextMapGuid = UEngine::GetPackageGuid(FName(*NextMap), GetWorld()->IsPlayInEditor());

	// IMPROBABLE-BEGIN - Fucking up server travel
	UE_LOG(LogGameMode, Error, TEXT("Hiacking server travel: %s"), *URL);
	UE_LOG(LogGameMode, Error, TEXT("- Clients told to disconnect"));
	// Notify clients we're switching level and give them time to receive.
	FString URLMod = URL;
	APlayerController* LocalPlayer = ProcessClientTravel(URLMod, NextMapGuid, bSeamless, bAbsolute);

	// Set up delegates. Order of WipeWorld -> LoadSnapshot -> FinishServerTravel.
	UE_LOG(LogGameMode, Error, TEXT("- Wiping the world"), *URL);
	UWorld* World = GetWorld();
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(World->GetNetDriver());
	
	// FinishServerTravel - Allows Unreal to finish it's normal server travel.
	USpatialNetDriver::ServerTravelDelegate FinishServerTravel;
	FinishServerTravel.BindLambda([World, NetDriver, URL, this, bSeamless, bAbsolute] {

		UE_LOG(LogGameMode, Log, TEXT("- ProcessServerTravel: %s"), *URL);
		check(World);
		World->NextURL = URL;
		ENetMode NetMode = GetNetMode();

		if (bSeamless)
		{
			World->SeamlessTravel(World->NextURL, bAbsolute);
			World->NextURL = TEXT("");
		}
		// Switch immediately if not networking.
		else if (NetMode != NM_DedicatedServer && NetMode != NM_ListenServer)
		{
			World->NextSwitchCountdown = 0.0f;
		}
	});

	// Josh - Not being used at the moment, moving to be in the NewServer.
	// LoadSnapshotAfterWorldWipe - Load the snapshot after the deletion commands have been sent.
	USpatialNetDriver::ServerTravelDelegate LoadSnapshotAfterWorldWipe;
	LoadSnapshotAfterWorldWipe.BindLambda([World, NetDriver, URL] {
		UE_LOG(LogGameMode, Log, TEXT("- Loading the snapshot"));
		NetDriver->LoadSnapshot();
	});

	// IMPROBABLE-END
	NetDriver->WipeWorld(FinishServerTravel);
#endif // WITH_SERVER_CODE
}
