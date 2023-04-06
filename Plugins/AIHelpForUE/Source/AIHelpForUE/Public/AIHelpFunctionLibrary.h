// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "AIHelpDefine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#if PLATFORM_ANDROID
#include "UObject/Object.h"
#endif
#include "AIHelpFunctionLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOnAIHelpInitializedCallback);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnUnreadMessageArrivedCallback, int32, UnreadCount);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSpecificUrlClickedCallback, FString, Url);
DECLARE_DYNAMIC_DELEGATE(FOnSpecificFormSubmittedCallback);
DECLARE_DYNAMIC_DELEGATE(FOnAIHelpSessionOpenCallback);
DECLARE_DYNAMIC_DELEGATE(FOnAIHelpSessionCloseCallback);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAIHelpNetworkCheckCallback, FString, NetLog);

UCLASS()
class AIHELPFORUE_API UAIHelpFunctionLibrary final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
#pragma region AIHelp Function

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void Init(FString AppKey, FString Domain, FString AppId, FString Language);
	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void SetOnAIHelpInitializedCallback(FOnAIHelpInitializedCallback Callback);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void ShowConversation(EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void ShowAllFAQSections(EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode);
	
	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void ShowSingleFAQ(FString FaqId, EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void ShowFAQSection(FString SectionId, EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode);
	
	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void ShowOperation(int32 SelectIndex, FString ConversationTitle, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void UpdateUserInfo(FString UserId, FString UserName, FString ServerId, FString UserTags,
	                           FString CustomDataInJsonFormat, bool IsSyncCrmInfo);
	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void ResetUserInfo();

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void UpdateSDKLanguage(FString Language);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void StartUnreadMessageCountPolling(FOnUnreadMessageArrivedCallback Callback);
	
	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void SetPushTokenAndPlatform(FString PushToken, EAIHelpPushPlatform Platform);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void SetUploadLogPath(FString Path);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static FString GetSDKVersion();

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static bool IsAIHelpShowing();

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void EnableLogging(bool Enable);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void ShowUrl(FString Url);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void AdditionalSupportFor(EAIHelpPublishCountryOrRegion CountryOrRegion);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void SetOnSpecificUrlClickedCallback(FOnSpecificUrlClickedCallback Callback);
	
	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void SetOnSpecificFormSubmittedCallback(FOnSpecificFormSubmittedCallback Callback);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void SetOnAIHelpSessionOpenCallback(FOnAIHelpSessionOpenCallback Callback);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void SetOnAIHelpSessionCloseCallback(FOnAIHelpSessionCloseCallback Callback);

	UFUNCTION(BlueprintCallable, Category = "AIHelp")
	static void SetNetworkCheckHostAddress(FString HostAddress, FOnAIHelpNetworkCheckCallback Callback);

#pragma endregion

	static FOnAIHelpInitializedCallback InitializedCallback;
	static FOnUnreadMessageArrivedCallback UnreadMessageArrivedCallback;
	static FOnSpecificUrlClickedCallback SpecificUrlClickedCallback;
	static FOnSpecificFormSubmittedCallback SpecificFormSubmittedCallback;
	static FOnAIHelpSessionOpenCallback SessionOpenCallback;
	static FOnAIHelpSessionCloseCallback SessionCloseCallback;
	static FOnAIHelpNetworkCheckCallback NetworkCheckCallback;
	
};
