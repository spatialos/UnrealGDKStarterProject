// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestWorldGenerator, All, All);

class FTestWorldGeneratorModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;
};
