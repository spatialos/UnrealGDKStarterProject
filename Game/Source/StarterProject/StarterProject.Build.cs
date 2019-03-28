// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

using UnrealBuildTool;

public class StarterProject : ModuleRules
{
	public StarterProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[] 
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Sockets",
				"OnlineSubsystemUtils",
				"PhysXVehicles",
        "UMG",
//#if UE_EDITOR
//        "TestWorldGenerator",
//#endif
                "SpatialGDK"
			});
	}
}
