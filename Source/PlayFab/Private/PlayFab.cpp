// Copyright 2014 Vladimir Alyamkin. All Rights Reserved.

#include "PlayFabPrivatePCH.h"

class FPlayFab : public IPlayFab
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{
		// @HACK Force classes to be compiled on shipping build
		UPlayFabJsonObject::StaticClass();
		UPlayFabJsonValue::StaticClass();
		UPlayFabRequestProxy::StaticClass();
	}

	virtual void ShutdownModule() override
	{

	}
};

IMPLEMENT_MODULE( FPlayFab, PlayFab )

DEFINE_LOG_CATEGORY(LogPlayFab);
