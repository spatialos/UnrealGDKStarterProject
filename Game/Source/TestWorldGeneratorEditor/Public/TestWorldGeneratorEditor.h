// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestWorldGeneratorEditor, All, All);

class FTestWorldGeneratorEditorModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;
};
