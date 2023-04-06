// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class AIHelpForUE : ModuleRules
{
	public AIHelpForUE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
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

		AddIOSLib(Target);
		AddAndroidLib(Target);
	}

	void AddIOSLib(ReadOnlyTargetRules Target)
	{
		if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			// var projectDir = Target.ProjectFile.Directory;
			// var configFilePath = projectDir + "/Config/DefaultUnLuaEditor.ini";
			// PublicAdditionalFrameworks.Add(new Framework("AIHelpSupportSDK", 
			// 	Path.Combine(Target.UEThirdPartyBinariesDirectory, "AIHelpSupportSDK.framework.zip"),
			// 	"AIHelpSupportSDK.bundle"));

			PublicAdditionalFrameworks.Add(new Framework("AIHelpSupportSDK", 
				"../ThirdParty/AIHelpSupportSDK.framework.zip", "AIHelpSupportSDK.bundle"));
			
			PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"ApplicationCore"
			}
			);
			//bEnableObjCExceptions = true;
		}
	}

	void AddAndroidLib(ReadOnlyTargetRules Target)
	{
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateDependencyModuleNames.AddRange(new string[]
			{
				"Launch",
			});

			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "AIHelp_UPL.xml"));
		}
		
	}
}
