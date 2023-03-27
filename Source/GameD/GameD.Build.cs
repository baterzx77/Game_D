// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameD : ModuleRules
{
	public GameD(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });

        PublicIncludePaths.AddRange(new string[] { "GameD/Public/Components" });
        PrivateIncludePaths.AddRange(new string[] { "GameD/Private/Components" });
    }
}