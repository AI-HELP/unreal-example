#pragma once
#include "GenericAIHelp.h"
#include "CoreMinimal.h"
#include "Async/Async.h"
#include "Android/AndroidApplication.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJavaEnv.h"
#endif

class FAndroidAIHelp : public FGenericAIHelp
{
public:
	FAndroidAIHelp();
	virtual ~FAndroidAIHelp() override;

	virtual void Init(FString AppKey, FString Domain, FString AppId, FString Language) override;

	virtual void ShowConversation(EAIHelpConversationIntent ConversationIntent,
	                              bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage,
	                              FString StoryNode) override;
	virtual void ShowAllFAQSections(EAIHelpConversationMoment ConversationMoment,
	                                EAIHelpConversationIntent ConversationIntent,
	                                bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage,
	                                FString StoryNode) override;
	virtual void ShowSingleFAQ(FString FaqId, EAIHelpConversationMoment ConversationMoment,
	                           EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage,
	                           FString WelcomeMessage, FString StoryNode) override;
	virtual void ShowFAQSection(FString SectionId, EAIHelpConversationMoment ConversationMoment,
	                            EAIHelpConversationIntent ConversationIntent,
	                            bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode) override;
	virtual void ShowOperation(int32 SelectIndex, FString ConversationTitle,
	                           EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage,
	                           FString WelcomeMessage, FString StoryNode) override;

	virtual void UpdateUserInfo(FString UserId, FString UserName, FString ServerId, FString UserTags,
	                            FString CustomDataInJsonFormat, bool IsSyncCrmInfo) override;
	virtual void ResetUserInfo() override;
	virtual void UpdateSDKLanguage(FString Language) override;
	virtual void SetPushTokenAndPlatform(FString PushToken, EAIHelpPushPlatform Platform) override;
	virtual void SetUploadLogPath(FString LogPath) override;
	virtual FString GetSDKVersion() override;
	virtual bool IsAIHelpShowing() override;
	virtual void EnableLogging(bool Enable) override;
	virtual void ShowUrl(FString Url) override;
	virtual void AdditionalSupportFor(EAIHelpPublishCountryOrRegion CountryOrRegion) override;
	virtual void SetOnAIHelpInitializedCallback(FOnAIHelpInitializedDelegate Callback) override;
	virtual void StartUnreadMessageCountPolling(FOnUnreadMessageArrivedDelegate Callback) override;
	virtual void SetOnSpecificUrlClickedCallback(FOnSpecificUrlClickedDelegate Callback) override;
	virtual void SetOnSpecificFormSubmittedCallback(FOnSpecificFormSubmittedDelegate Callback) override;
	virtual void SetOnAIHelpSessionOpenCallback(FOnAIHelpSessionOpenDelegate Callback) override;
	virtual void SetOnAIHelpSessionCloseCallback(FOnAIHelpSessionCloseDelegate Callback) override;
	virtual void SetNetworkCheckHostAddress(FString HostAddress, FOnAIHelpNetworkCheckDelegate Delegate) override;

protected:
#if PLATFORM_ANDROID
	// JNI Methods
	static jmethodID AIHelpInit;
	static jmethodID AIHelpRegisterCallbacks;
	static jmethodID AIHelpShow;
	static jmethodID AIHelpShowConversation;
	static jmethodID AIHelpShowAllFAQSections;
	static jmethodID AIHelpShowFAQSection;
	static jmethodID AIHelpShowSingleFAQ;
	static jmethodID AIHelpShowOperation;
	static jmethodID AIHelpUpdateUserInfo;
	static jmethodID AIHelpResetUserInfo;
	static jmethodID AIHelpUpdateSDKLanguage;
	static jmethodID AIHelpSetPushTokenAndPlatform;
	static jmethodID AIHelpSetUploadLogPath;
	static jmethodID AIHelpGetSDKVersion;
	static jmethodID AIHelpIsAIHelpShowing;
	static jmethodID AIHelpEnableLogging;
	static jmethodID AIHelpShowUrl;
	static jmethodID AIHelpAdditionalSupportFor;
	static jmethodID AIHelpSetOnAIHelpInitializedCallback;
	static jmethodID AIHelpStartUnreadMessageCountPolling;
	static jmethodID AIHelpSetOnSpecificFormSubmittedCallback;
	static jmethodID AIHelpSetOnAIHelpSessionOpenCallback;
	static jmethodID AIHelpSetOnAIHelpSessionCloseCallback;
	static jmethodID AIHelpSetOnSpecificUrlClickedCallback;
	static jmethodID AIHelpSetNetworkCheckHostAddress;
#endif
};
