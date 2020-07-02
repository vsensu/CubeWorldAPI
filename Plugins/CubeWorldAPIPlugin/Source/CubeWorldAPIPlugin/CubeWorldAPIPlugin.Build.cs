// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CubeWorldAPIPlugin : ModuleRules
{
	public CubeWorldAPIPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		//bUsePrecompiled = true;
		PrecompileForTargets = PrecompileTargetsType.Any;

		// PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PCHUsage = ModuleRules.PCHUsageMode.NoSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

		CppStandard = CppStandardVersion.Cpp17;
	}
}
