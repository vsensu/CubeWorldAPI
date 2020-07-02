// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CubeWorldAPI : ModuleRules
{
	public CubeWorldAPI(ReadOnlyTargetRules Target) : base(Target)
	{
		//PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PCHUsage = PCHUsageMode.NoSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		CppStandard = CppStandardVersion.Cpp17;

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
