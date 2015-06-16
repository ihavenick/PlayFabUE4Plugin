#include "PlayFabPrivatePCH.h"
#include "PlayFabRequestProxy.h"
#include "PlayFabModule.h"

// this is a temp fix, because the iOS Version is not supporting std function
// we will put this right 
UPlayFabRequestProxy* g_proxy = NULL;

UPlayFabRequestProxy::UPlayFabRequestProxy(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
    g_proxy = this;
}


UPlayFabRequestProxy* UPlayFabRequestProxy::SendPlayFabRequest(const FString& UserName, const FString& Password)
{
	UPlayFabRequestProxy* Proxy = NewObject<UPlayFabRequestProxy>();
	Proxy->UserName = UserName;
	Proxy->Password = Password;

	return Proxy;
}

void send()
{
    FString unreal_response;
    
    if (response.GetHasErrors())
    {
        g_proxy->OnPlayFabResponse.Broadcast(unreal_response, false);
    }
    else
    {
        g_proxy->OnPlayFabResponse.Broadcast(unreal_response, true);
    }
}



void UPlayFabRequestProxy::Activate()
{
	// Code to run when the call back activates
}
