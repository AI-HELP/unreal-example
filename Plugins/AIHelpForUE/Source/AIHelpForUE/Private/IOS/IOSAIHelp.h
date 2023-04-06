#pragma once

#include "CoreMinimal.h"
#include "GenericAIHelp.h"

class FIOSAIHelp : public FGenericAIHelp
{
public:
	FIOSAIHelp();
	virtual ~FIOSAIHelp();

	virtual void Init(FString AppKey, FString Domain, FString AppId, FString Language) override;
	virtual void Show(FString EntranceId, FString WelcomeMessage) override;
	virtual void UpdateUserInfo(FString UserId, FString UserName, FString ServerId, FString UserTags, FString CustomDataInJsonFormat, bool IsSyncCrmInfo) override;
	virtual void ResetUserInfo() override;
	virtual void UpdateSDKLanguage(FString Language) override;
	virtual void SetPushTokenAndPlatform(FString PushToken, EAIHelpPushPlatform Platform) override;
	virtual void SetUploadLogPath(FString LogPath) override;
	virtual FString GetSDKVersion() override;
	virtual bool IsAIHelpShowing() override;
	virtual void EnableLogging(bool Enable) override;
	virtual void ShowUrl(FString Url) override;
	virtual void AdditionalSupportFor(EAIHelpPublishCountryOrRegion CountryOrRegion) override;
	virtual void SetOnAIHelpInitializedCallback(FOnAIHelpInitializedDelegate Delegate) override;
	virtual void StartUnreadMessageCountPolling(FOnUnreadMessageArrivedDelegate Delegate) override;
	virtual void SetOnSpecificUrlClickedCallback(FOnSpecificUrlClickedDelegate Delegate) override;
	virtual void SetOnSpecificFormSubmittedCallback(FOnSpecificFormSubmittedDelegate Delegate) override;
	virtual void SetOnAIHelpSessionOpenCallback(FOnAIHelpSessionOpenDelegate Delegate) override;
	virtual void SetOnAIHelpSessionCloseCallback(FOnAIHelpSessionCloseDelegate Delegate) override;
};