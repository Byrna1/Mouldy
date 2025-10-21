// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Mouldy : ModuleRules
{
	public Mouldy(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Mouldy",
			"Mouldy/Variant_Platforming",
			"Mouldy/Variant_Platforming/Animation",
			"Mouldy/Variant_Combat",
			"Mouldy/Variant_Combat/AI",
			"Mouldy/Variant_Combat/Animation",
			"Mouldy/Variant_Combat/Gameplay",
			"Mouldy/Variant_Combat/Interfaces",
			"Mouldy/Variant_Combat/UI",
			"Mouldy/Variant_SideScrolling",
			"Mouldy/Variant_SideScrolling/AI",
			"Mouldy/Variant_SideScrolling/Gameplay",
			"Mouldy/Variant_SideScrolling/Interfaces",
			"Mouldy/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
