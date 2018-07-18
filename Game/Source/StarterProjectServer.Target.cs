// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class StarterProjectServerTarget : TargetRules
{
	public StarterProjectServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		ExtraModuleNames.Add("StarterProject");
	}
}
