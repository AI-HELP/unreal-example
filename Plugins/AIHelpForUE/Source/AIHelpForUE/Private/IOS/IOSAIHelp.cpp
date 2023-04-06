#include "IOSAIHelp.h"
#include "AIHelpForUE.h"
#include "AIHelpFunctionLibrary.h"
#include "Async/Async.h"

#if PLATFORM_IOS
#import <Foundation/Foundation.h>
#import <AIHelpSupportSDK/AIHelpSupportSDK.h>

NSString* FStringToNSString(const FString& str)
{
	return [NSString stringWithUTF8String:TCHAR_TO_UTF8(*str)];
}

FString NSStringToFString(NSString* InNSString)
{
	FString OutFString;
	if (InNSString)
	{
		const char* UTF8String = [InNSString UTF8String];
		OutFString = FString(UTF8String);
	}
	return OutFString;
}

#endif

FIOSAIHelp::FIOSAIHelp()
{
}

FIOSAIHelp::~FIOSAIHelp()
{
}

void FIOSAIHelp::Init(FString AppKey, FString Domain, FString AppId, FString Language)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		[AIHelpSupportSDK initWithApiKey : FStringToNSString(AppKey)
			domainName: FStringToNSString(Domain)
			appId: FStringToNSString(AppId)
			language: FStringToNSString(Language)] ;
	});
#endif
}

void FIOSAIHelp::ShowConversation(EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		AIHelpConversationConfigBuilder *conversationBuilder = [[AIHelpConversationConfigBuilder alloc] init];
		conversationBuilder.conversationIntent = ConversationIntent == 1 ? AIHelpConversationIntentBotSupport : AIHelpConversationIntentHumanSupport;
		conversationBuilder.alwaysShowHumanSupportButtonInBotPage = AlwaysShowHumanSupportButtonInBotPage;
        conversationBuilder.welcomeMessage = FStringToNSString(WelcomeMessage);
        conversationBuilder.storyNode = FStringToNSString(StoryNode);
        [AIHelpSupportSDK showConversation:conversationBuilder.build];
	});
#endif
}

void FIOSAIHelp::ShowAllFAQSections(EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		AIHelpFAQConfigBuilder *faqBuilder = [[AIHelpFAQConfigBuilder alloc] init];
        if (ConversationMoment == 1) {
            faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentAlways;
        } else if (ConversationMoment == 2) {
			faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentOnlyInAnswerPage;
		} else if (ConversationMoment == 3) {
            faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentAfterMarkingUnhelpful;
        }  else {
            faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentNever;
        }
        AIHelpConversationConfigBuilder *conversationBuilder = [[AIHelpConversationConfigBuilder alloc] init];
        conversationBuilder.conversationIntent = ConversationIntent == 1 ? AIHelpConversationIntentBotSupport : AIHelpConversationIntentHumanSupport;
        conversationBuilder.alwaysShowHumanSupportButtonInBotPage = AlwaysShowHumanSupportButtonInBotPage;
        conversationBuilder.storyNode = FStringToNSString(StoryNode);
        conversationBuilder.welcomeMessage = FStringToNSString(WelcomeMessage);
        faqBuilder.conversationConfig = conversationBuilder.build;
        [AIHelpSupportSDK showAllFAQSections:faqBuilder.build];
	});
#endif
}

void FIOSAIHelp::ShowFAQSection(FString SectionId, EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		AIHelpFAQConfigBuilder *faqBuilder = [[AIHelpFAQConfigBuilder alloc] init];
		if (ConversationMoment == 1) {
			faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentAlways;
		} else if (ConversationMoment == 2) {
			faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentOnlyInAnswerPage;
		} else if (ConversationMoment == 3) {
			faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentAfterMarkingUnhelpful;
		}  else {
			faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentNever;
		}
        AIHelpConversationConfigBuilder *conversationBuilder = [[AIHelpConversationConfigBuilder alloc] init];
        conversationBuilder.conversationIntent = ConversationIntent == 1 ? AIHelpConversationIntentBotSupport : AIHelpConversationIntentHumanSupport;
        conversationBuilder.alwaysShowHumanSupportButtonInBotPage = AlwaysShowHumanSupportButtonInBotPage;
        conversationBuilder.storyNode = FStringToNSString(StoryNode);
        conversationBuilder.welcomeMessage = FStringToNSString(WelcomeMessage);
        faqBuilder.conversationConfig = conversationBuilder.build;
        [AIHelpSupportSDK showFAQSection:FStringToNSString(SectionId) config:faqBuilder.build];
	});
#endif
}

void FIOSAIHelp::ShowSingleFAQ(FString FaqId, EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		AIHelpFAQConfigBuilder *faqBuilder = [[AIHelpFAQConfigBuilder alloc] init];
		if (ConversationMoment == 1) {
			faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentAlways;
		} else if (ConversationMoment == 2) {
			faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentOnlyInAnswerPage;
		} else if (ConversationMoment == 3) {
			faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentAfterMarkingUnhelpful;
		}  else {
			faqBuilder.showConversationMoment = AIHelpFAQShowConversationMomentNever;
		}
        AIHelpConversationConfigBuilder *conversationBuilder = [[AIHelpConversationConfigBuilder alloc] init];
        conversationBuilder.conversationIntent = ConversationIntent == 1 ? AIHelpConversationIntentBotSupport : AIHelpConversationIntentHumanSupport;
        conversationBuilder.alwaysShowHumanSupportButtonInBotPage = AlwaysShowHumanSupportButtonInBotPage;
        conversationBuilder.storyNode = FStringToNSString(StoryNode);
        conversationBuilder.welcomeMessage = FStringToNSString(WelcomeMessage);
        faqBuilder.conversationConfig = conversationBuilder.build;
        [AIHelpSupportSDK showSingleFAQ:FStringToNSString(FaqId) config:faqBuilder.build];
	});
#endif
}

void FIOSAIHelp::ShowOperation(int32 SelectIndex, FString ConversationTitle, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		AIHelpOperationConfigBuilder *operationBuiler = [[AIHelpOperationConfigBuilder alloc] init];
        operationBuiler.selectIndex = SelectIndex;
        operationBuiler.conversationTitle = FStringToNSString(ConversationTitle);
        AIHelpConversationConfigBuilder *conversationBuilder = [[AIHelpConversationConfigBuilder alloc] init];
        conversationBuilder.conversationIntent = ConversationIntent == 1 ? AIHelpConversationIntentBotSupport : AIHelpConversationIntentHumanSupport;
        conversationBuilder.alwaysShowHumanSupportButtonInBotPage = AlwaysShowHumanSupportButtonInBotPage;
        conversationBuilder.storyNode = FStringToNSString(StoryNode);
        conversationBuilder.welcomeMessage = FStringToNSString(WelcomeMessage);
        operationBuiler.conversationConfig = conversationBuilder.build;
        [AIHelpSupportSDK showOperation:operationBuiler.build];
	});
#endif
}


// void FIOSAIHelp::Show(FString EntranceId, FString WelcomeMessage)
// {
// #if PLATFORM_IOS
// 	dispatch_async(dispatch_get_main_queue(), ^ {
// 		AIHelpApiConfigBuilder *configBuilder = [[AIHelpApiConfigBuilder alloc] init];
// 		configBuilder.entranceId = FStringToNSString(EntranceId);
// 		configBuilder.welcomeMessage = FStringToNSString(WelcomeMessage);
// 		[AIHelpSupportSDK showWithApiConfig:configBuilder.build];
// 	});
// #endif
// }

void FIOSAIHelp::UpdateUserInfo(FString UserId, FString UserName, FString ServerId, FString UserTags,
                                FString CustomDataInJsonFormat, bool IsSyncCrmInfo)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		AIHelpUserConfigBuilder *userBuilder = [[AIHelpUserConfigBuilder alloc] init];
		userBuilder.userId = FStringToNSString(UserId);
		userBuilder.userName = FStringToNSString(UserName);
		userBuilder.serverId = FStringToNSString(ServerId);

		NSString *_userTags = FStringToNSString(UserTags);
		NSString *_customData = FStringToNSString(CustomDataInJsonFormat);
		if ([_userTags componentsSeparatedByString:@","]) {
			userBuilder.userTags = [_userTags componentsSeparatedByString:@","];
		}
		if (_customData && _customData.length) {
			NSData *jsonData = [_customData dataUsingEncoding:NSUTF8StringEncoding];
			NSError *error;
			NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:&error];
			if (dic) {
				userBuilder.customData = dic;
			}
		}

		userBuilder.isSyncCrmInfo = IsSyncCrmInfo;
		[AIHelpSupportSDK updateUserInfo:userBuilder.build];
	});
#endif
}

void FIOSAIHelp::ResetUserInfo()
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		[AIHelpSupportSDK resetUserInfo];
	});
#endif
}

void FIOSAIHelp::UpdateSDKLanguage(FString Language)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		[AIHelpSupportSDK updateSDKLanguage: FStringToNSString(Language)];
	});
#endif
}

void FIOSAIHelp::SetPushTokenAndPlatform(FString PushToken, EAIHelpPushPlatform Platform)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		AIHelpTokenPlatform ePlatform;
		switch (Platform) {
			case 1:
				ePlatform = AIHelpTokenPlatformAPNS;
				break;
			case 2:
				ePlatform = AIHelpTokenPlatformFirebase;
				break;
			case 3:
				ePlatform = AIHelpTokenPlatformJpush;
				break;
			case 4:
				ePlatform = AIHelpTokenPlatformGeTui;
				break;
			case 6:
				ePlatform = AIHelpTokenPlatformHUAWEI;
				break;
			default:
				ePlatform = AIHelpTokenPlatformAPNS;
				break;
		}
		[AIHelpSupportSDK setPushToken:FStringToNSString(PushToken) pushPlatform:ePlatform];
	});
#endif
}

void FIOSAIHelp::SetUploadLogPath(FString Path)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		[AIHelpSupportSDK setUploadLogPath: FStringToNSString(Path)];
	});
#endif
}

FString FIOSAIHelp::GetSDKVersion()
{
#if PLATFORM_IOS
	NSString *version = [AIHelpSupportSDK getSDKVersion];
	return NSStringToFString(version);
#endif
	return "";
}

bool FIOSAIHelp::IsAIHelpShowing()
{
#if PLATFORM_IOS
	return [AIHelpSupportSDK isAIHelpShowing];
#endif
	return false;
}

void FIOSAIHelp::EnableLogging(bool Enable)
{
#if PLATFORM_IOS
	[AIHelpSupportSDK enableLogging:Enable];
#endif
}

void FIOSAIHelp::ShowUrl(FString Url)
{
#if PLATFORM_IOS
	[AIHelpSupportSDK showUrl:FStringToNSString(Url)];
#endif
}

void FIOSAIHelp::AdditionalSupportFor(EAIHelpPublishCountryOrRegion CountryOrRegion)
{
#if PLATFORM_IOS
	AIHelpPublishCountryOrRegion tmpCountryOrRegion = AIHelpCN;
	if (CountryOrRegion == 1) {
		tmpCountryOrRegion = AIHelpCN;
	}
	if (CountryOrRegion == 2) {
		tmpCountryOrRegion = AIHelpIN;
	}
	[AIHelpSupportSDK additionalSupportFor:tmpCountryOrRegion];
#endif
}

void AIHelpOnInitializationCallBack()
{
	AsyncTask(ENamedThreads::GameThread, []()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetAIHelpInitializedDelegate().Broadcast();
		UAIHelpFunctionLibrary::InitializedCallback.ExecuteIfBound();
	});
}

void FIOSAIHelp::SetOnAIHelpInitializedCallback(FOnAIHelpInitializedDelegate Callback)
{
	if (!InitDelegate.IsBound())
	{
		InitDelegate = Callback;
	}
#if PLATFORM_IOS
	[AIHelpSupportSDK setOnInitializedCallback: AIHelpOnInitializationCallBack];
#endif
}

void AIHelpOnUnreadMessageArrived(const int unreadCount)
{
	AsyncTask(ENamedThreads::GameThread, [unreadCount]()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetUnreadMessageArrivedDelegate().Broadcast(unreadCount);
		UAIHelpFunctionLibrary::UnreadMessageArrivedCallback.ExecuteIfBound(unreadCount);
	});
}

void FIOSAIHelp::StartUnreadMessageCountPolling(FOnUnreadMessageArrivedDelegate Callback)
{
	UnreadMessageDelegate = Callback;
#if PLATFORM_IOS
	[AIHelpSupportSDK startUnreadMessageCountPolling: AIHelpOnUnreadMessageArrived];
#endif
}

void AIHelpOnSpecificUrlClickedCallback(const char* url)
{
	auto fUrl = FString(UTF8_TO_TCHAR(url));
	AsyncTask(ENamedThreads::GameThread, [fUrl]()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetSpecificUrlClickedDelegate().Broadcast(fUrl);
		UAIHelpFunctionLibrary::SpecificUrlClickedCallback.ExecuteIfBound(fUrl);
	});
}

void FIOSAIHelp::SetOnSpecificUrlClickedCallback(FOnSpecificUrlClickedDelegate Callback)
{
	SpecificUrlClickedDelegate = Callback;
#if PLATFORM_IOS
	[AIHelpSupportSDK setOnSpecificUrlClickedCallback: AIHelpOnSpecificUrlClickedCallback];
#endif
}

void AIHelpOnSpecificFormSubmittedCallback()
{
	AsyncTask(ENamedThreads::GameThread, []()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetSpecificFormSubmittedDelegate().Broadcast();
		UAIHelpFunctionLibrary::SpecificFormSubmittedCallback.ExecuteIfBound();
	});
}

void FIOSAIHelp::SetOnSpecificFormSubmittedCallback(FOnSpecificFormSubmittedDelegate Callback)
{
	SpecificFormSubmittedDelegate = Callback;
#if PLATFORM_IOS
	[AIHelpSupportSDK setOnSpecificFormSubmittedCallback: AIHelpOnSpecificFormSubmittedCallback];
#endif
}

void AIHelpOnAIHelpSessionOpenCallback()
{
	AsyncTask(ENamedThreads::GameThread, []()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetAIHelpSessionOpenDelegate().Broadcast();
		UAIHelpFunctionLibrary::SessionOpenCallback.ExecuteIfBound();
	});
}

void FIOSAIHelp::SetOnAIHelpSessionOpenCallback(FOnAIHelpSessionOpenDelegate Callback)
{
	SessionOpenDelegate = Callback;
#if PLATFORM_IOS
	[AIHelpSupportSDK setOnAIHelpSessionOpenCallback: AIHelpOnAIHelpSessionOpenCallback];
#endif
}

void AIHelpOnAIHelpSessionCloseCallback()
{
	AsyncTask(ENamedThreads::GameThread, []()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetAIHelpSessionCloseDelegate().Broadcast();
		UAIHelpFunctionLibrary::SessionCloseCallback.ExecuteIfBound();
	});
}

void FIOSAIHelp::SetOnAIHelpSessionCloseCallback(FOnAIHelpSessionCloseDelegate Callback)
{
	SessionCloseDelegate = Callback;
#if PLATFORM_IOS
	[AIHelpSupportSDK setOnAIHelpSessionCloseCallback: AIHelpOnAIHelpSessionCloseCallback];
#endif
}

void AIHelpOnNetworkCheckCallback(const char* netLog)
{
	auto fNetLog = FString(UTF8_TO_TCHAR(netLog));
	AsyncTask(ENamedThreads::GameThread, [fNetLog]()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetAIHelpNetworkCheckDelegate().Broadcast(fNetLog);
		UAIHelpFunctionLibrary::NetworkCheckCallback.ExecuteIfBound(fNetLog);
	});
}

void FIOSAIHelp::SetNetworkCheckHostAddress(FString Address, FOnAIHelpNetworkCheckDelegate Delegate)
{
	NetworkCheckDelegate = Delegate;
#if PLATFORM_IOS
	[AIHelpSupportSDK setNetworkCheckHostAddress:FStringToNSString(Address) callback:AIHelpOnNetworkCheckCallback];
#endif
}
