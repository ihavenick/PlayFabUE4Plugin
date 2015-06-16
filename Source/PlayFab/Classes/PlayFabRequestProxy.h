#pragma once

#include "OnlineBlueprintCallProxyBase.h"
#include "PlayFabRequestProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayFabRequestCompleted, FString, response, bool, successful);

UCLASS()
class UPlayFabRequestProxy : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintAssignable)
	FOnPlayFabRequestCompleted OnPlayFabResponse;

	UFUNCTION(BlueprintCallable, Category = "GameSparks", meta = (BlueprintInternalUseOnly = "true"))
	static UPlayFabRequestProxy* SendPlayFabRequest(const FString& UserName, const FString& Password);

	/** UOnlineBlueprintCallProxyBase interface */
	virtual void Activate() override;

protected:

	/** Name of the game that we're querying about */
	FString UserName;
	FString Password;
};