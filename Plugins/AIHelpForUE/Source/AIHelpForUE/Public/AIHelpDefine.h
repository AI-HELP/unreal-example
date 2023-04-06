#pragma once

#include "CoreMinimal.h"
#include "Engine.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAIHelp, Log, All);

UENUM()
enum EAIHelpPushPlatform
{
	Apns = 1,
	Firebase = 2,
	JPush = 3,
	GeTui = 4,
	HuaWei = 6,
};

UENUM()
enum EAIHelpPublishCountryOrRegion
{
	China = 1,
	India = 2
};