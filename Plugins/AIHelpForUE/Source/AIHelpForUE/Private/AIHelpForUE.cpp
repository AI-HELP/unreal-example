// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIHelpForUE.h"

#if PLATFORM_ANDROID
#include "AIHelpDefine.h"
#include "Android/AndroidAIHelp.h"
#endif
#if PLATFORM_IOS
#include "IOS/IOSAIHelp.h"
#endif

#define LOCTEXT_NAMESPACE "FAIHelpForUEModule"

#if PLATFORM_IOS
#include "IOSAppDelegate.h"
#import <AIHelpSupportSDK/AIHelpSupportSDK.h>
#endif

void FAIHelpForUEModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

#if PLATFORM_IOS
	AIHelp = MakeShared<FIOSAIHelp>();
#elif PLATFORM_ANDROID
	AIHelp = MakeShared<FAndroidAIHelp>();
#else
	AIHelp = MakeShared<FGenericAIHelp>();
#endif
}

void FAIHelpForUEModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	AIHelp.Reset();
}

FAIHelpPtr FAIHelpForUEModule::GetAIHelp()
{
	return AIHelp;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAIHelpForUEModule, AIHelpForUE)