#if PLATFORM_ANDROID
#include "AndroidAIHelp.h"
#include "AIHelpForUE.h"
#include "AIHelpFunctionLibrary.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJavaEnv.h"
#include "Android/AndroidPlatform.h"

jmethodID FAndroidAIHelp::AIHelpInit;
jmethodID FAndroidAIHelp::AIHelpShowConversation;
jmethodID FAndroidAIHelp::AIHelpShowAllFAQSections;
jmethodID FAndroidAIHelp::AIHelpShowFAQSection;
jmethodID FAndroidAIHelp::AIHelpShowSingleFAQ;
jmethodID FAndroidAIHelp::AIHelpShowOperation;
jmethodID FAndroidAIHelp::AIHelpUpdateUserInfo;
jmethodID FAndroidAIHelp::AIHelpResetUserInfo;
jmethodID FAndroidAIHelp::AIHelpUpdateSDKLanguage;
jmethodID FAndroidAIHelp::AIHelpSetPushTokenAndPlatform;
jmethodID FAndroidAIHelp::AIHelpSetUploadLogPath;
jmethodID FAndroidAIHelp::AIHelpGetSDKVersion;
jmethodID FAndroidAIHelp::AIHelpIsAIHelpShowing;
jmethodID FAndroidAIHelp::AIHelpEnableLogging;
jmethodID FAndroidAIHelp::AIHelpShowUrl;
jmethodID FAndroidAIHelp::AIHelpAdditionalSupportFor;
jmethodID FAndroidAIHelp::AIHelpSetOnAIHelpInitializedCallback;
jmethodID FAndroidAIHelp::AIHelpStartUnreadMessageCountPolling;
jmethodID FAndroidAIHelp::AIHelpSetOnSpecificFormSubmittedCallback;
jmethodID FAndroidAIHelp::AIHelpSetOnAIHelpSessionOpenCallback;
jmethodID FAndroidAIHelp::AIHelpSetOnAIHelpSessionCloseCallback;
jmethodID FAndroidAIHelp::AIHelpSetOnSpecificUrlClickedCallback;
jmethodID FAndroidAIHelp::AIHelpSetNetworkCheckHostAddress;

JNI_METHOD void Java_com_epicgames_ue4_GameActivity_nativeOnAIHelpInitializedCallback(JNIEnv* jenv, jobject thiz, jboolean bSuccess, jstring msg)
{
	auto message = FJavaHelper::FStringFromParam(jenv, msg);
	AsyncTask(ENamedThreads::GameThread, [bSuccess,message]()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetAIHelpInitializedDelegate().Broadcast();
		UAIHelpFunctionLibrary::InitializedCallback.ExecuteIfBound();
	});
}

JNI_METHOD void Java_com_epicgames_ue4_GameActivity_nativeOnAIHelpUnreadMessageArrivedCallback(JNIEnv* jenv, jobject thiz, jint unreadCount)
{
	AsyncTask(ENamedThreads::GameThread, [unreadCount]()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetUnreadMessageArrivedDelegate().Broadcast(unreadCount);
		UAIHelpFunctionLibrary::UnreadMessageArrivedCallback.ExecuteIfBound(unreadCount);
	});
}

JNI_METHOD void Java_com_epicgames_ue4_GameActivity_nativeOnAIHelpSpecificUrlClickedCallback(JNIEnv* jenv, jobject thiz, jstring jUrl)
{
	auto url = FJavaHelper::FStringFromParam(jenv, jUrl);
	AsyncTask(ENamedThreads::GameThread, [url]()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetSpecificUrlClickedDelegate().Broadcast(url);
		UAIHelpFunctionLibrary::SpecificUrlClickedCallback.ExecuteIfBound(url);
	});
}

JNI_METHOD void Java_com_epicgames_ue4_GameActivity_nativeOnAIHelpSpecificFormSubmittedCallback(JNIEnv* jenv, jobject thiz)
{
	AsyncTask(ENamedThreads::GameThread, []()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetSpecificFormSubmittedDelegate().Broadcast();
		UAIHelpFunctionLibrary::SpecificFormSubmittedCallback.ExecuteIfBound();
	});
}

JNI_METHOD void Java_com_epicgames_ue4_GameActivity_nativeOnAIHelpSessionOpenCallback(JNIEnv* jenv, jobject thiz)
{
	AsyncTask(ENamedThreads::GameThread, []()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetAIHelpSessionOpenDelegate().Broadcast();
		UAIHelpFunctionLibrary::SessionOpenCallback.ExecuteIfBound();
	});
}

JNI_METHOD void Java_com_epicgames_ue4_GameActivity_nativeOnAIHelpSessionCloseCallback(JNIEnv* jenv, jobject thiz)
{
	AsyncTask(ENamedThreads::GameThread, []()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetAIHelpSessionCloseDelegate().Broadcast();
		UAIHelpFunctionLibrary::SessionCloseCallback.ExecuteIfBound();
	});
}

JNI_METHOD void Java_com_epicgames_ue4_GameActivity_nativeSetNetworkCheckHostAddress(JNIEnv* jenv, jobject thiz, jstring jNetLog)
{
	auto netLog = FJavaHelper::FStringFromParam(jenv, jNetLog);
	AsyncTask(ENamedThreads::GameThread, [netLog]()
	{
		FAIHelpForUEModule::Get().GetAIHelp()->GetAIHelpNetworkCheckDelegate().Broadcast(netLog);
		UAIHelpFunctionLibrary::NetworkCheckCallback.ExecuteIfBound(netLog);
	});
}

FAndroidAIHelp::FAndroidAIHelp()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		AIHelpInit = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpInit", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);

		AIHelpShowConversation = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpShowConversation", "(IZLjava/lang/String;Ljava/lang/String;)V", false);
		AIHelpShowAllFAQSections = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpShowAllFAQSections", "(IIZLjava/lang/String;Ljava/lang/String;)V", false);
		AIHelpShowFAQSection = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpShowFAQSection", "(Ljava/lang/String;IIZLjava/lang/String;Ljava/lang/String;)V", false);
		AIHelpShowSingleFAQ = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpShowSingleFAQ", "(Ljava/lang/String;IIZLjava/lang/String;Ljava/lang/String;)V", false);
		AIHelpShowOperation = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpShowOperation", "(ILjava/lang/String;IZLjava/lang/String;Ljava/lang/String;)V", false);
		
		AIHelpUpdateUserInfo = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpUpdateUserInfo", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V", false);
		AIHelpResetUserInfo = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpResetUserInfo", "()V", false);
		AIHelpUpdateSDKLanguage = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpUpdateSDKLanguage", "(Ljava/lang/String;)V", false);
		AIHelpSetPushTokenAndPlatform = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpSetPushTokenAndPlatform", "(Ljava/lang/String;I)V", false);
		AIHelpSetUploadLogPath = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpSetUploadLogPath", "(Ljava/lang/String;)V", false);
		AIHelpGetSDKVersion = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpGetSDKVersion", "()Ljava/lang/String;", false);
		AIHelpIsAIHelpShowing = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpIsAIHelpShowing", "()Z", false);
		AIHelpEnableLogging = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpEnableLogging", "(Z)V", false);
		AIHelpShowUrl = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpShowUrl", "(Ljava/lang/String;)V", false);
		AIHelpAdditionalSupportFor = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpAdditionalSupportFor", "(I)V", false);
		AIHelpSetOnAIHelpInitializedCallback = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpSetOnAIHelpInitializedCallback", "()V", false);
		AIHelpStartUnreadMessageCountPolling = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpStartUnreadMessageCountPolling", "()V", false);
		AIHelpSetOnSpecificFormSubmittedCallback = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpSetOnSpecificFormSubmittedCallback", "()V", false);
		AIHelpSetOnAIHelpSessionOpenCallback = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpSetOnAIHelpSessionOpenCallback", "()V", false);
		AIHelpSetOnAIHelpSessionCloseCallback = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpSetOnAIHelpSessionCloseCallback", "()V", false);
		AIHelpSetOnSpecificUrlClickedCallback = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpSetOnSpecificUrlClickedCallback", "()V", false);
		AIHelpSetNetworkCheckHostAddress = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AIHelpSetNetworkCheckHostAddress", "(Ljava/lang/String;)V", false);
	}
}

FAndroidAIHelp::~FAndroidAIHelp()
{ 
}

void FAndroidAIHelp::Init(FString appKey, FString domain, FString appId, FString language)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto appKeyJ = FJavaHelper::ToJavaString(Env, appKey);
		auto domainJ = FJavaHelper::ToJavaString(Env, domain);
		auto appIdJ = FJavaHelper::ToJavaString(Env, appId);
		auto languageJ = FJavaHelper::ToJavaString(Env, language);

		FJavaWrapper::CallVoidMethod(
			Env, FJavaWrapper::GameActivityThis, AIHelpInit,
			*appKeyJ, *domainJ, *appIdJ, *languageJ
		);
	}
}

void FAndroidAIHelp::ShowConversation(EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto welcomeMessageJ = FJavaHelper::ToJavaString(Env, WelcomeMessage);
		auto storyNodeJ = FJavaHelper::ToJavaString(Env, StoryNode);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpShowConversation,
			ConversationIntent, AlwaysShowHumanSupportButtonInBotPage, *welcomeMessageJ, *storyNodeJ
		);
	}
}

void FAndroidAIHelp::ShowAllFAQSections(EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto welcomeMessageJ = FJavaHelper::ToJavaString(Env, WelcomeMessage);
		auto storyNodeJ = FJavaHelper::ToJavaString(Env, StoryNode);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpShowAllFAQSections,
			ConversationMoment, ConversationIntent, AlwaysShowHumanSupportButtonInBotPage, *welcomeMessageJ, *storyNodeJ
		);
	}
}

void FAndroidAIHelp::ShowSingleFAQ(FString FaqId, EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto faqIdJ = FJavaHelper::ToJavaString(Env, FaqId);
		auto welcomeMessageJ = FJavaHelper::ToJavaString(Env, WelcomeMessage);
		auto storyNodeJ = FJavaHelper::ToJavaString(Env, StoryNode);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpShowSingleFAQ,
			*faqIdJ, ConversationMoment, ConversationIntent, AlwaysShowHumanSupportButtonInBotPage, *welcomeMessageJ, *storyNodeJ
		);
	}
}

void FAndroidAIHelp::ShowFAQSection(FString SectionId, EAIHelpConversationMoment ConversationMoment, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto sectionIdJ = FJavaHelper::ToJavaString(Env, SectionId);
		auto welcomeMessageJ = FJavaHelper::ToJavaString(Env, WelcomeMessage);
		auto storyNodeJ = FJavaHelper::ToJavaString(Env, StoryNode);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpShowFAQSection,
			*sectionIdJ, ConversationMoment, ConversationIntent, AlwaysShowHumanSupportButtonInBotPage, *welcomeMessageJ, *storyNodeJ
		);
	}
}

void FAndroidAIHelp::ShowOperation(int32 SelectIndex, FString ConversationTitle, EAIHelpConversationIntent ConversationIntent, bool AlwaysShowHumanSupportButtonInBotPage, FString WelcomeMessage, FString StoryNode)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto conversationTitleJ = FJavaHelper::ToJavaString(Env, ConversationTitle);
		auto welcomeMessageJ = FJavaHelper::ToJavaString(Env, WelcomeMessage);
		auto storyNodeJ = FJavaHelper::ToJavaString(Env, StoryNode);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpShowOperation,
			SelectIndex, *conversationTitleJ, ConversationIntent, AlwaysShowHumanSupportButtonInBotPage, *welcomeMessageJ, *storyNodeJ
		);
	}
}

void FAndroidAIHelp::UpdateUserInfo(FString userId, FString userName, FString serverId, FString userTags,
	FString customDataInJsonFormat, bool IsSyncCrmInfo)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto userIdJ = FJavaHelper::ToJavaString(Env, userId);
		auto userNameJ = FJavaHelper::ToJavaString(Env, userName);
		auto serverIdJ = FJavaHelper::ToJavaString(Env, serverId);
		auto userTagsJ = FJavaHelper::ToJavaString(Env, userTags);
		auto customDataInJsonFormatJ = FJavaHelper::ToJavaString(Env, customDataInJsonFormat);
		// auto isSyncCrmInfoJ = FJavaHelper::ToJavaBoolean(Env, IsSyncCrmInfo);

		FJavaWrapper::CallVoidMethod(
			Env, FJavaWrapper::GameActivityThis, AIHelpUpdateUserInfo,
			*userIdJ, *userNameJ, *serverIdJ, *userTagsJ, *customDataInJsonFormatJ, IsSyncCrmInfo
		);
	}
}

void FAndroidAIHelp::ResetUserInfo()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpResetUserInfo);
	}
}

void FAndroidAIHelp::UpdateSDKLanguage(FString language)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto languageJ = FJavaHelper::ToJavaString(Env, language);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpUpdateSDKLanguage, *languageJ);
	}
}

void FAndroidAIHelp::SetPushTokenAndPlatform(FString pushToken, EAIHelpPushPlatform platform)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jPushToken = FJavaHelper::ToJavaString(Env, pushToken);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
			AIHelpSetPushTokenAndPlatform, *jPushToken, platform);
	}
}

void FAndroidAIHelp::SetUploadLogPath(FString path)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto pathJ = FJavaHelper::ToJavaString(Env, path);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpSetUploadLogPath, *pathJ);
	}
}

FString FAndroidAIHelp::GetSDKVersion()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jobject jSdkVersion = FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, AIHelpGetSDKVersion);
		jstring jstr = (jstring)jSdkVersion;
		return FJavaHelper::FStringFromParam(Env, jstr);
	}
	return "";
}

bool FAndroidAIHelp::IsAIHelpShowing()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, AIHelpIsAIHelpShowing);
	}
	return false;
}

void FAndroidAIHelp::EnableLogging(bool enable)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpEnableLogging, enable);
	}
}

void FAndroidAIHelp::ShowUrl(FString url)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto urlJ = FJavaHelper::ToJavaString(Env, url);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpShowUrl, *urlJ);
	}
}

void FAndroidAIHelp::AdditionalSupportFor(EAIHelpPublishCountryOrRegion countryOrRegion)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis,
			AIHelpAdditionalSupportFor, countryOrRegion);
	}
}

void FAndroidAIHelp::SetOnAIHelpInitializedCallback(FOnAIHelpInitializedDelegate Callback)
{
	InitDelegate = Callback;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpSetOnAIHelpInitializedCallback);
	}
}

void FAndroidAIHelp::StartUnreadMessageCountPolling(FOnUnreadMessageArrivedDelegate Callback)
{
	UnreadMessageDelegate = Callback;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpStartUnreadMessageCountPolling);
	}
}

void FAndroidAIHelp::SetOnSpecificUrlClickedCallback(FOnSpecificUrlClickedDelegate Callback)
{
	SpecificUrlClickedDelegate = Callback;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpSetOnSpecificUrlClickedCallback);
	}
}

void FAndroidAIHelp::SetOnSpecificFormSubmittedCallback(FOnSpecificFormSubmittedDelegate Callback)
{
	SpecificFormSubmittedDelegate = Callback;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpSetOnSpecificFormSubmittedCallback);
	}
}

void FAndroidAIHelp::SetOnAIHelpSessionOpenCallback(FOnAIHelpSessionOpenDelegate Callback)
{
	SessionOpenDelegate = Callback;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpSetOnAIHelpSessionOpenCallback);
	}
}

void FAndroidAIHelp::SetOnAIHelpSessionCloseCallback(FOnAIHelpSessionCloseDelegate Callback)
{
	SessionCloseDelegate = Callback;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpSetOnAIHelpSessionCloseCallback);
	}
}

void FAndroidAIHelp::SetNetworkCheckHostAddress(FString HostAddress, FOnAIHelpNetworkCheckDelegate Delegate)
{
	NetworkCheckDelegate = Delegate;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto jHostAddress = FJavaHelper::ToJavaString(Env, HostAddress);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AIHelpSetNetworkCheckHostAddress, *jHostAddress);
	}
}

#endif 