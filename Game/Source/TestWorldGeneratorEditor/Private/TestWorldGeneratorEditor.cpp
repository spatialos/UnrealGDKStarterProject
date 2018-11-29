// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestWorldGeneratorEditor.h"

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"


IMPLEMENT_GAME_MODULE(FTestWorldGeneratorEditorModule, TestWorldGeneratorEditor);

DEFINE_LOG_CATEGORY(LogTestWorldGeneratorEditor);

#define LOCTEXT_NAMESPACE "TestWorldGeneratorEditor"

void FTestWorldGeneratorEditorModule::StartupModule()
{
	UE_LOG(LogTestWorldGeneratorEditor, Log, TEXT("TestWorldGeneratorEditor Module Start"));
}

void FTestWorldGeneratorEditorModule::ShutdownModule()
{
	UE_LOG(LogTestWorldGeneratorEditor, Log, TEXT("TestWorldGeneratorEditor Module Shutdown"));
}

#undef LOCTEXT_NAMESPACE
