#pragma once

#include "CoreMinimal.h"
#include "Engine.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAIHelp, Log, All);

UENUM()
enum EAIHelpConversationIntent
{
	Bot = 1,
	Human = 2,
};

UENUM()
enum EAIHelpConversationMoment
{
	Never = 0,
	Always = 1,
	OnlyInAnswerPage = 2,
	AfterMarkUnhelpful = 3,
};

UENUM()
enum EAIHelpPushPlatform
{
	Apns = 1,
	Firebase = 2,
	JPush = 3,
	GeTui = 4,
	HUAWEI = 6,
};

UENUM()
enum EAIHelpPublishCountryOrRegion
{
	China = 1,
	India = 2
};
