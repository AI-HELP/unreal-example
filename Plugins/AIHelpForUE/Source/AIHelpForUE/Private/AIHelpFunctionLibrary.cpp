// Fill out your copyright notice in the Description page of Project Settings.
#include "AIHelpFunctionLibrary.h"
#include "AIHelpForUE.h"
#include "GenericAIHelp.h"

FOnAIHelpInitializedCallback UAIHelpFunctionLibrary::InitializedCallback;
FOnUnreadMessageArrivedCallback UAIHelpFunctionLibrary::UnreadMessageArrivedCallback;
FOnSpecificUrlClickedCallback UAIHelpFunctionLibrary::SpecificUrlClickedCallback;
FOnSpecificFormSubmittedCallback UAIHelpFunctionLibrary::SpecificFormSubmittedCallback;
FOnAIHelpSessionOpenCallback UAIHelpFunctionLibrary::SessionOpenCallback;
FOnAIHelpSessionCloseCallback UAIHelpFunctionLibrary::SessionCloseCallback;

#pragma region AIHelp Function
void UAIHelpFunctionLibrary::Init(FString AppKey, FString Domain, FString AppId, FString Language)
{
	FAIHelpForUEModule::Get().GetAIHelp()->Init(AppKey, Domain, AppId, Language);
}

void UAIHelpFunctionLibrary::Show(FString EntranceId, FString WelcomeMessage)
{
	FAIHelpForUEModule::Get().GetAIHelp()->Show(EntranceId, WelcomeMessage);
}

void UAIHelpFunctionLibrary::UpdateUserInfo(FString UserId, FString UserName, FString ServerId, FString UserTags,
                                            FString CustomDataInJsonFormat, bool IsSyncCrmInfo)
{
	FAIHelpForUEModule::Get().GetAIHelp()->UpdateUserInfo(UserId, UserName, ServerId, UserTags, CustomDataInJsonFormat,
	                                                      IsSyncCrmInfo);
}

void UAIHelpFunctionLibrary::ResetUserInfo()
{
	FAIHelpForUEModule::Get().GetAIHelp()->ResetUserInfo();
}

void UAIHelpFunctionLibrary::UpdateSDKLanguage(FString Language)
{
	FAIHelpForUEModule::Get().GetAIHelp()->UpdateSDKLanguage(Language);
}

void UAIHelpFunctionLibrary::SetPushTokenAndPlatform(FString PushToken, EAIHelpPushPlatform Platform)
{
	FAIHelpForUEModule::Get().GetAIHelp()->SetPushTokenAndPlatform(PushToken, Platform);
}

void UAIHelpFunctionLibrary::SetUploadLogPath(FString Path)
{
	FAIHelpForUEModule::Get().GetAIHelp()->SetUploadLogPath(Path);
}

FString UAIHelpFunctionLibrary::GetSDKVersion()
{
	return FAIHelpForUEModule::Get().GetAIHelp()->GetSDKVersion();
}

bool UAIHelpFunctionLibrary::IsAIHelpShowing()
{
	return FAIHelpForUEModule::Get().GetAIHelp()->IsAIHelpShowing();
}

void UAIHelpFunctionLibrary::EnableLogging(bool Enable)
{
	FAIHelpForUEModule::Get().GetAIHelp()->EnableLogging(Enable);
}

void UAIHelpFunctionLibrary::ShowUrl(FString Url)
{
	FAIHelpForUEModule::Get().GetAIHelp()->ShowUrl(Url);
}

void UAIHelpFunctionLibrary::AdditionalSupportFor(EAIHelpPublishCountryOrRegion CountryOrRegion)
{
	FAIHelpForUEModule::Get().GetAIHelp()->AdditionalSupportFor(CountryOrRegion);
}

void UAIHelpFunctionLibrary::SetOnAIHelpInitializedCallback(FOnAIHelpInitializedCallback Callback)
{
	InitializedCallback = Callback;
	FAIHelpForUEModule::Get().GetAIHelp()->SetOnAIHelpInitializedCallback(FOnAIHelpInitializedDelegate());
}

void UAIHelpFunctionLibrary::StartUnreadMessageCountPolling(FOnUnreadMessageArrivedCallback Callback)
{
	UnreadMessageArrivedCallback = Callback;
	FAIHelpForUEModule::Get().GetAIHelp()->StartUnreadMessageCountPolling(FOnUnreadMessageArrivedDelegate());
}

void UAIHelpFunctionLibrary::SetOnSpecificUrlClickedCallback(FOnSpecificUrlClickedCallback Callback)
{
	SpecificUrlClickedCallback = Callback;
	FAIHelpForUEModule::Get().GetAIHelp()->SetOnSpecificUrlClickedCallback(FOnSpecificUrlClickedDelegate());
}

void UAIHelpFunctionLibrary::SetOnSpecificFormSubmittedCallback(FOnSpecificFormSubmittedCallback Callback)
{
	SpecificFormSubmittedCallback = Callback;
	FAIHelpForUEModule::Get().GetAIHelp()->SetOnSpecificFormSubmittedCallback(FOnSpecificFormSubmittedDelegate());
}

void UAIHelpFunctionLibrary::SetOnAIHelpSessionOpenCallback(FOnAIHelpSessionOpenCallback Callback)
{
	SessionOpenCallback = Callback;
	FAIHelpForUEModule::Get().GetAIHelp()->SetOnAIHelpSessionOpenCallback(FOnAIHelpSessionOpenDelegate());
}

void UAIHelpFunctionLibrary::SetOnAIHelpSessionCloseCallback(FOnAIHelpSessionCloseCallback Callback)
{
	SessionCloseCallback = Callback;
	FAIHelpForUEModule::Get().GetAIHelp()->SetOnAIHelpSessionCloseCallback(FOnAIHelpSessionCloseDelegate());
}

#pragma endregion
