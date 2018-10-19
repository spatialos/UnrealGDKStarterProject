// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestWorldGenerator.h"

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"


IMPLEMENT_GAME_MODULE(FTestWorldGeneratorModule, TestWorldGenerator);

DEFINE_LOG_CATEGORY(LogTestWorldGenerator);

#define LOCTEXT_NAMESPACE "TestWorldGenerator"

void FTestWorldGeneratorModule::StartupModule()
{
	UE_LOG(LogTestWorldGenerator, Log, TEXT("TestWorldGenerator Module Start"));
}

void FTestWorldGeneratorModule::ShutdownModule()
{
	UE_LOG(LogTestWorldGenerator, Log, TEXT("TestWorldGenerator Module Shutdown"));
}

#undef LOCTEXT_NAMESPACE
