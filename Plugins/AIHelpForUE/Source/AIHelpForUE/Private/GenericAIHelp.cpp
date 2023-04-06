#include "GenericAIHelp.h"

FGenericAIHelp::FGenericAIHelp()
{
	
}

FGenericAIHelp::~FGenericAIHelp()
{
	
}

void FGenericAIHelp::Init(FString AppKey, FString Domain, FString AppId, FString Language)
{
	
}

void FGenericAIHelp::ShowConversation(EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
	
}

void FGenericAIHelp::ShowAllFAQSections(EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
	
}

void FGenericAIHelp::ShowSingleFAQ(FString FaqId, EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
	
}

void FGenericAIHelp::ShowFAQSection(FString SectionId, EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
	
}

void FGenericAIHelp::ShowOperation(int32 SelectIndex, FString ConversationTitle, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
	
}

void FGenericAIHelp::UpdateUserInfo(FString UserId, FString UserName, FString ServerId, FString UserTags,
	FString CustomDataInJsonFormat, bool IsSyncCrmInfo)
{
	
}

void FGenericAIHelp::ResetUserInfo()
{
	
}

void FGenericAIHelp::UpdateSDKLanguage(FString Language)
{
	
}

void FGenericAIHelp::SetPushTokenAndPlatform(FString PushToken, EAIHelpPushPlatform Platform)
{
	
}

void FGenericAIHelp::SetUploadLogPath(FString Path)
{
	
}

FString FGenericAIHelp::GetSDKVersion()
{
	return "";
}

bool FGenericAIHelp::IsAIHelpShowing()
{
	return false;
}

void FGenericAIHelp::EnableLogging(bool Enable)
{
	
}

void FGenericAIHelp::ShowUrl(FString url)
{
	
}

void FGenericAIHelp::AdditionalSupportFor(EAIHelpPublishCountryOrRegion CountryOrRegion)
{
	
}

void FGenericAIHelp::SetOnAIHelpInitializedCallback(FOnAIHelpInitializedDelegate Delegate)
{
	InitDelegate = Delegate;
}

void FGenericAIHelp::StartUnreadMessageCountPolling(FOnUnreadMessageArrivedDelegate Delegate)
{
	UnreadMessageDelegate = Delegate;
}

void FGenericAIHelp::SetOnSpecificUrlClickedCallback(FOnSpecificUrlClickedDelegate Delegate)
{
	SpecificUrlClickedDelegate = Delegate;
}

void FGenericAIHelp::SetOnSpecificFormSubmittedCallback(FOnSpecificFormSubmittedDelegate Delegate)
{
	SpecificFormSubmittedDelegate = Delegate;
}

void FGenericAIHelp::SetOnAIHelpSessionOpenCallback(FOnAIHelpSessionOpenDelegate Delegate)
{
	SessionOpenDelegate = Delegate;
}

void FGenericAIHelp::SetOnAIHelpSessionCloseCallback(FOnAIHelpSessionCloseDelegate Delegate)
{
	SessionCloseDelegate = Delegate;
}

void FGenericAIHelp::SetNetworkCheckHostAddress(FString HostAddress, FOnAIHelpNetworkCheckDelegate Delegate)
{
	NetworkCheckDelegate = Delegate;
}

FOnAIHelpInitializedDelegate FGenericAIHelp::GetAIHelpInitializedDelegate()
{
	return InitDelegate;
}

FOnUnreadMessageArrivedDelegate FGenericAIHelp::GetUnreadMessageArrivedDelegate()
{
	return UnreadMessageDelegate;
}

FOnSpecificUrlClickedDelegate FGenericAIHelp::GetSpecificUrlClickedDelegate()
{
	return SpecificUrlClickedDelegate;
}

FOnSpecificFormSubmittedDelegate FGenericAIHelp::GetSpecificFormSubmittedDelegate()
{
	return SpecificFormSubmittedDelegate;
}

FOnAIHelpSessionOpenDelegate FGenericAIHelp::GetAIHelpSessionOpenDelegate()
{
	return SessionOpenDelegate;
}

FOnAIHelpSessionCloseDelegate FGenericAIHelp::GetAIHelpSessionCloseDelegate()
{
	return SessionCloseDelegate;
}

FOnAIHelpNetworkCheckDelegate FGenericAIHelp::GetAIHelpNetworkCheckDelegate()
{
	return NetworkCheckDelegate;
}