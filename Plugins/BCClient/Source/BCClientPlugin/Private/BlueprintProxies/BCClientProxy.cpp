// Copyright 2018 bitHeads, Inc. All Rights Reserved.

#include "BCClientPluginPrivatePCH.h"
#include "IRTTCallback.h"
#include "ServerCall.h"
#include "BrainCloudWrapper.h"
#include "BCClientProxy.h"

UBCClientProxy::UBCClientProxy(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UBCClientProxy::SoftErrorHandlingMode(const bool isEnabled)
{
	BrainCloudClient::EnableSoftErrorMode = isEnabled;
}

void UBCClientProxy::SingletonMode(const bool isEnabled)
{
	BrainCloudClient::EnableSingletonMode = isEnabled;
}

void UBCClientProxy::Initialize(
	UBrainCloudWrapper *brainCloudWrapper,
	const FString &serverUrl,
	const FString &secretKey,
	const FString &appId,
	const FString &version)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->initialize(serverUrl, secretKey, appId, version);
}

void UBCClientProxy::InitializeIdentity(UBrainCloudWrapper *brainCloudWrapper, const FString &profileId, const FString &anonymousId)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->initializeIdentity(profileId, anonymousId);
}

void UBCClientProxy::RunCallbacks(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->runCallbacks();
}

void UBCClientProxy::EnableLogging(UBrainCloudWrapper *brainCloudWrapper, bool shouldEnable)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->enableLogging(shouldEnable);
}

bool UBCClientProxy::IsAuthenticated(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->isAuthenticated();
}

bool UBCClientProxy::IsInitialized(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->isInitialized();
}

void UBCClientProxy::ResetCommunication(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->resetCommunication();
}

UBCClientProxy *UBCClientProxy::EnableRTT(UBrainCloudWrapper *brainCloudWrapper, eBCRTTConnectionType in_type)
{
	UBCClientProxy *Proxy = NewObject<UBCClientProxy>();
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->enableRTT(in_type, Proxy);
	return Proxy;
}

void UBCClientProxy::DisableRTT(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->disableRTT();
}

void UBCClientProxy::SetRTTHeartBeatSeconds(UBrainCloudWrapper *brainCloudWrapper, int32 in_value)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->setRTTHeartBeatSeconds(in_value);
}

UBCClientProxy *UBCClientProxy::RegisterRTTEventCallback(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCClientProxy *Proxy = NewObject<UBCClientProxy>();
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->registerRTTEventCallback(Proxy);
	return Proxy;
}

UBCClientProxy *UBCClientProxy::RegisterRTTChatCallback(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCClientProxy *Proxy = NewObject<UBCClientProxy>();
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->registerRTTChatCallback(Proxy);
	return Proxy;
}

UBCClientProxy *UBCClientProxy::RegisterRTTMessagingCallback(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCClientProxy *Proxy = NewObject<UBCClientProxy>();
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->registerRTTMessagingCallback(Proxy);
	return Proxy;
}

UBCClientProxy *UBCClientProxy::RegisterRTTLobbyCallback(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCClientProxy *Proxy = NewObject<UBCClientProxy>();
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->registerRTTLobbyCallback(Proxy);
	return Proxy;
}

void UBCClientProxy::DeregisterAllRTTCallbacks(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->deregisterAllRTTCallbacks();
}

void UBCClientProxy::Heartbeat(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->heartbeat();
}

//Setters
void UBCClientProxy::SetHeartbeatInterval(UBrainCloudWrapper *brainCloudWrapper, int32 intervalInMilliseconds)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->setHeartbeatInterval(intervalInMilliseconds);
}

void UBCClientProxy::SetPacketTimeouts(UBrainCloudWrapper *brainCloudWrapper, const TArray<int32> &timeouts)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->setPacketTimeouts(timeouts);
}

void UBCClientProxy::SetPacketTimeoutsToDefault(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->setPacketTimeoutsToDefault();
}

void UBCClientProxy::SetAuthenticationPacketTimeout(UBrainCloudWrapper *brainCloudWrapper, int32 timeoutSecs)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->setAuthenticationPacketTimeout(timeoutSecs);
}

void UBCClientProxy::SetOldStyleStatusMessageErrorCallback(UBrainCloudWrapper *brainCloudWrapper, bool enabled)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->setOldStyleStatusMessageErrorCallback(enabled);
}

void UBCClientProxy::SetErrorCallbackOn202Status(UBrainCloudWrapper *brainCloudWrapper, bool isError)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->setErrorCallbackOn202Status(isError);
}

void UBCClientProxy::SetUploadLowTransferRateTimeout(UBrainCloudWrapper *brainCloudWrapper, int32 timeoutSecs)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->setUploadLowTransferRateTimeout(timeoutSecs);
}

void UBCClientProxy::SetUploadLowTransferRateThreshold(UBrainCloudWrapper *brainCloudWrapper, int32 bytesPerSec)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->setUploadLowTransferRateThreshold(bytesPerSec);
}

//Getters
const FString &UBCClientProxy::GetGameId(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getAppId();
}

const FString &UBCClientProxy::GetAppId(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getAppId();
}

const FString &UBCClientProxy::GetSessionId(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getSessionId();
}

const FString &UBCClientProxy::GetReleasePlatform(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getReleasePlatform();
}

const FString &UBCClientProxy::GetGameVersion(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getAppVersion();
}

const FString &UBCClientProxy::GetBrainCloudClientVersion(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getBrainCloudClientVersion();
}

const FString &UBCClientProxy::GetProfileId(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getProfileId();
}

const FString &UBCClientProxy::GetRTTConnectionId(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getRTTConnectionId();
}

const FString &UBCClientProxy::GetEventServer(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getEventServer();
}

const TArray<int32> &UBCClientProxy::GetPacketTimeouts(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getPacketTimeouts();
}

int32 UBCClientProxy::GetAuthenticationPacketTimeout(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getAuthenticationPacketTimeout();
}

int32 UBCClientProxy::GetUploadLowTransferRateTimeout(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getUploadLowTransferRateTimeout();
}

int32 UBCClientProxy::GetUploadLowTransferRateThreshold(UBrainCloudWrapper *brainCloudWrapper)
{
	return UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->getUploadLowTransferRateThreshold();
}

void UBCClientProxy::EnableNetworkErrorMessageCaching(UBrainCloudWrapper *brainCloudWrapper, bool enabled)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->enableNetworkErrorMessageCaching(enabled);
}

void UBCClientProxy::RetryCachedMessages(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->retryCachedMessages();
}

void UBCClientProxy::FlushCachedMessages(UBrainCloudWrapper *brainCloudWrapper, bool sendApiErrorCallbacks)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->flushCachedMessages(sendApiErrorCallbacks);
}

void UBCClientProxy::InsertEndOfMessageBundleMarker(UBrainCloudWrapper *brainCloudWrapper)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->insertEndOfMessageBundleMarker();
}

void UBCClientProxy::OverrideCountryCode(UBrainCloudWrapper *brainCloudWrapper, const FString &countryCode)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->overrideCountryCode(countryCode);
}

void UBCClientProxy::OverrideLanguageCode(UBrainCloudWrapper *brainCloudWrapper, const FString &languageCode)
{
	UBCWrapperProxy::GetBrainCloudInstance(brainCloudWrapper)->getBCClient()->overrideLanguageCode(languageCode);
}

void UBCClientProxy::rttCallback(const FString &jsonData)
{
	OnRTTEventCallback.Broadcast(jsonData);
	OnRTTChatCallback.Broadcast(jsonData);
	OnRTTMessagingCallback.Broadcast(jsonData);
	OnRTTLobbyCallback.Broadcast(jsonData);
}
