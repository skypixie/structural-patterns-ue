// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SructuralPatterns : ModuleRules
{
	public SructuralPatterns(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

        PublicIncludePaths.AddRange(new string[]
        {
            "SructuralPatterns/",
            "SructuralPatterns/Facade",
            "SructuralPatterns/Proxy",
            "SructuralPatterns/Composite",
            "SructuralPatterns/Adapter",
        });
    }
}
