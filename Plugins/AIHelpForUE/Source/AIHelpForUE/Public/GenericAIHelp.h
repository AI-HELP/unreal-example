#pragma once
#include "AIHelpDefine.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnAIHelpInitializedDelegate, bool, FString);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnUnreadMessageArrivedDelegate, int32);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnSpecificUrlClickedDelegate, FString);
DECLARE_MULTICAST_DELEGATE(FOnSpecificFormSubmittedDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAIHelpSessionOpenDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAIHelpSessionCloseDelegate);

class FGenericAIHelp
{
public:
	FGenericAIHelp();
	virtual ~FGenericAIHelp();

	virtual void Init(FString AppKey, FString Domain, FString AppId, FString Language);
	virtual void SetOnAIHelpInitializedCallback(FOnAIHelpInitializedDelegate Delegate);
	virtual void Show(FString EntranceId, FString WelcomeMessage);
	virtual void ShowSingleFaq(FString faqId, EAIHelpConversationMoment ConversationMoment);
	virtual void UpdateUserInfo(FString UserId, FString UserName, FString ServerId, FString UserTags, FString CustomDataInJsonFormat, bool IsSyncCrmInfo);
	virtual void ResetUserInfo();
	virtual void UpdateSDKLanguage(FString Language);
	virtual void StartUnreadMessageCountPolling(FOnUnreadMessageArrivedDelegate Delegate);
	virtual void SetPushTokenAndPlatform(FString PushToken, EAIHelpPushPlatform Platform);
	virtual void SetUploadLogPath(FString Path);
	virtual FString GetSDKVersion();
	virtual bool IsAIHelpShowing();
	virtual void EnableLogging(bool Enable);
	virtual void ShowUrl(FString Url);
	virtual void AdditionalSupportFor(EAIHelpPublishCountryOrRegion CountryOrRegion);
	virtual void SetOnSpecificUrlClickedCallback(FOnSpecificUrlClickedDelegate Delegate);
	virtual void SetOnSpecificFormSubmittedCallback(FOnSpecificFormSubmittedDelegate Delegate);
	virtual void SetOnAIHelpSessionOpenCallback(FOnAIHelpSessionOpenDelegate Delegate);
	virtual void SetOnAIHelpSessionCloseCallback(FOnAIHelpSessionCloseDelegate Delegate);

	FOnAIHelpInitializedDelegate GetAIHelpInitializedDelegate();
	FOnUnreadMessageArrivedDelegate GetUnreadMessageArrivedDelegate();
	FOnSpecificUrlClickedDelegate GetSpecificUrlClickedDelegate();
	FOnSpecificFormSubmittedDelegate GetSpecificFormSubmittedDelegate();
	FOnAIHelpSessionOpenDelegate GetAIHelpSessionOpenDelegate();
	FOnAIHelpSessionCloseDelegate GetAIHelpSessionCloseDelegate();

protected:
	FOnAIHelpInitializedDelegate InitDelegate;
	FOnUnreadMessageArrivedDelegate UnreadMessageDelegate;
	FOnSpecificUrlClickedDelegate SpecificUrlClickedDelegate;
	FOnSpecificFormSubmittedDelegate SpecificFormSubmittedDelegate;
	FOnAIHelpSessionOpenDelegate SessionOpenDelegate;
	FOnAIHelpSessionCloseDelegate SessionCloseDelegate;
};
