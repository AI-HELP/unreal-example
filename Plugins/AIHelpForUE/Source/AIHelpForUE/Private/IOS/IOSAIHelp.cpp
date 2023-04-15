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

void FIOSAIHelp::Show(FString EntranceId, FString WelcomeMessage)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		AIHelpApiConfigBuilder *configBuilder = [[AIHelpApiConfigBuilder alloc] init];
		configBuilder.entranceId = FStringToNSString(EntranceId);
		configBuilder.welcomeMessage = FStringToNSString(WelcomeMessage);
		[AIHelpSupportSDK showWithApiConfig:configBuilder.build];
	});
#endif
}

void FIOSAIHelp::ShowSingleFaq(FString FaqId, EAIHelpConversationMoment ConversationMoment)
{
#if PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^ {
		AIHelpFAQShowConversationMoment moment = AIHelpFAQShowConversationMomentNever;
		switch(ConversationMoment){
			case 1:
				moment = AIHelpFAQShowConversationMomentNever;
				break;
			case 2:
				moment = AIHelpFAQShowConversationMomentAlways;
				break;
			case 3:
				moment = AIHelpFAQShowConversationMomentOnlyInAnswerPage;
				break;
			case 4:
				moment = AIHelpFAQShowConversationMomentAfterMarkingUnhelpful;
				break;
			default:
				break;    
		}
		[AIHelpSupportSDK showSingleFAQ:FStringToNSString(FaqId) showConversationMoment:moment];
	});
#endif
}

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

void AIHelpOnInitializationCallBack(bool isSuccess, const char* message)
{
	AsyncTask(ENamedThreads::GameThread, [isSuccess, message]()
	{
		auto fMessage = FString(UTF8_TO_TCHAR(message));
		FAIHelpForUEModule::Get().GetAIHelp()->GetAIHelpInitializedDelegate().Broadcast(isSuccess, fMessage);
		UAIHelpFunctionLibrary::InitializedCallback.ExecuteIfBound(isSuccess, fMessage);
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
