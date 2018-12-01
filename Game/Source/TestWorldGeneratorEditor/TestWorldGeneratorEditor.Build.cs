// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

using UnrealBuildTool;

public class TestWorldGeneratorEditor : ModuleRules
{
    public TestWorldGeneratorEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bFasterWithoutUnity = true;

        PublicIncludePaths.AddRange(
            new string[]
            {
                "TestWorldGeneratorEditor/Public"
            }
        );

        PrivateIncludePaths.AddRange(
            new string[]
            {
                "TestWorldGeneratorEditor/Private",
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "TestWorldGenerator"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "EngineSettings",
                "InputCore",
                "LevelEditor",
                "Projects",
                "Slate",
                "SlateCore",
                "EditorStyle",
                "MessageLog",
                "UnrealEd",
                "WorldBrowser"
            }
        );
    }
}
