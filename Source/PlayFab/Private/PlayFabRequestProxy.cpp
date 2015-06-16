#include "PlayFabPrivatePCH.h"
#include "PlayFabRequestProxy.h"


// Play Fab API codes and URLs
FString UPlayFabRequestProxy::PlayFabURL(TEXT("https://<AppId>.playfabapi.com/"));
FString UPlayFabRequestProxy::PlayFabLogicURL(TEXT("https://<AppId>.playfablogic.com/"));
FString UPlayFabRequestProxy::PlayFabAppId(TEXT("<AppId>"));
FString UPlayFabRequestProxy::PlayFabApiKey(TEXT("<SecretKey>"));
FString UPlayFabRequestProxy::PhotonRealtimeAppId(TEXT("<SecretKey>"));
FString UPlayFabRequestProxy::PhotonTurnbasedAppId(TEXT("<SecretKey>"));
FString UPlayFabRequestProxy::PhotonChatAppId(TEXT("<SecretKey>"));


UPlayFabRequestProxy* g_proxy = NULL;

UPlayFabRequestProxy::UPlayFabRequestProxy(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
    g_proxy = this;
}

void UPlayFabRequestProxy::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
	RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabRequestProxy::GetResponseObject()
{
	return ResponseJsonObj;
}

FString UPlayFabRequestProxy::PercentEncode(const FString& Text)
{
	FString OutText = Text;

	OutText = OutText.Replace(TEXT("!"), TEXT("%21"));
	OutText = OutText.Replace(TEXT("\""), TEXT("%22"));
	OutText = OutText.Replace(TEXT("#"), TEXT("%23"));
	OutText = OutText.Replace(TEXT("$"), TEXT("%24"));
	//OutText = OutText.Replace(TEXT("&"), TEXT("%26"));
	OutText = OutText.Replace(TEXT("'"), TEXT("%27"));
	OutText = OutText.Replace(TEXT("("), TEXT("%28"));
	OutText = OutText.Replace(TEXT(")"), TEXT("%29"));
	OutText = OutText.Replace(TEXT("*"), TEXT("%2A"));
	OutText = OutText.Replace(TEXT("+"), TEXT("%2B"));
	OutText = OutText.Replace(TEXT(","), TEXT("%2C"));
	//OutText = OutText.Replace(TEXT("/"), TEXT("%2F"));
	OutText = OutText.Replace(TEXT(":"), TEXT("%3A"));
	OutText = OutText.Replace(TEXT(";"), TEXT("%3B"));
	OutText = OutText.Replace(TEXT("="), TEXT("%3D"));
	//OutText = OutText.Replace(TEXT("?"), TEXT("%3F"));
	OutText = OutText.Replace(TEXT("@"), TEXT("%40"));
	OutText = OutText.Replace(TEXT("["), TEXT("%5B"));
	OutText = OutText.Replace(TEXT("]"), TEXT("%5D"));
	OutText = OutText.Replace(TEXT("{"), TEXT("%7B"));
	OutText = OutText.Replace(TEXT("}"), TEXT("%7D"));

	return OutText;
}

//////////////////////////////////////////////////////////////////////////
// Play Fab ion Helpers
//////////////////////////////////////////////////////////////////////////

//// Client
/** Create Login with Play Fab Request */
UPlayFabRequestProxy* UPlayFabRequestProxy::LoginWithPlayFab(const FString& Username, const FString& Password)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	//
	//

	// Setup the request variables based on this request
	manager->PlayFabClass = "LoginWithPlayFab";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("TitleId"), PlayFabAppId);
	OutRestJsonObj->SetStringField(TEXT("Username"), Username);
	OutRestJsonObj->SetStringField(TEXT("Password"), Password);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Register with play fab request */
UPlayFabRequestProxy* UPlayFabRequestProxy::RegisterWithPlayFab(FString Username, FString Password, FString Email)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "RegisterPlayFabUser";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("TitleId"), PlayFabAppId);
	OutRestJsonObj->SetStringField(TEXT("Username"), Username);
	OutRestJsonObj->SetStringField(TEXT("Email"), Email);
	OutRestJsonObj->SetStringField(TEXT("Password"), Password);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Get Photon Authentication Toeken Request */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetPhotonAuthenticationToken(FString SessionTicket, bool PhotonRealtime, bool PhotonTurnbased, bool PhotonChat)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetPhotonAuthenticationToken";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	FString tmpString;
	if (PhotonRealtime)
	{
		tmpString = PhotonRealtimeAppId;
	}
	if (PhotonTurnbased)
	{
		tmpString = PhotonTurnbasedAppId;
	}
	if (PhotonChat)
	{
		tmpString = PhotonChatAppId;
	}
	OutRestJsonObj->SetStringField(TEXT("PhotonApplicationId"), tmpString);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create a Login with Android Device Request */
UPlayFabRequestProxy* UPlayFabRequestProxy::LoginWithAndroidDeviceID(FString AndroidDeviceId, FString OSVersion, FString AndroidDeviceType, bool CreateAccount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LoginWithAndroidDeviceID";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("TitleId"), PlayFabAppId);
	OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), AndroidDeviceId);

	if (OSVersion != "")
	{
		OutRestJsonObj->SetStringField(TEXT("OS"), OSVersion);
	}
	if (AndroidDeviceType != "")
	{
		OutRestJsonObj->SetStringField(TEXT("AndroidDevice"), AndroidDeviceType);
	}
	if (CreateAccount)
	{
		OutRestJsonObj->SetStringField(TEXT("CreateAccount"), "True");
	}

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Login with Play Fab  Email Request */
UPlayFabRequestProxy* UPlayFabRequestProxy::LoginWithEmail(FString Email, FString Password)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LoginWithEmailAddress";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("TitleId"), PlayFabAppId);
	OutRestJsonObj->SetStringField(TEXT("Email"), Email);
	OutRestJsonObj->SetStringField(TEXT("Password"), Password);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Login with Facebook Request */
UPlayFabRequestProxy* UPlayFabRequestProxy::LoginWithFacebook(FString FacebookAccessToken, bool CreateAccount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LoginWithFacebook";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("TitleId"), PlayFabAppId);
	OutRestJsonObj->SetStringField(TEXT("AccessToken"), FacebookAccessToken);

	if (CreateAccount) OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), CreateAccount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Login with Google Request */
UPlayFabRequestProxy* UPlayFabRequestProxy::LoginWithGoogle(FString GoogleAccessToken, bool CreateAccount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LoginWithGoogleAccount";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("TitleId"), PlayFabAppId);
	OutRestJsonObj->SetStringField(TEXT("AccessToken"), GoogleAccessToken);

	if (CreateAccount) OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), CreateAccount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create a Login with IOSDevice Request */
UPlayFabRequestProxy* UPlayFabRequestProxy::LoginWithIOSDeviceID(FString IOSDeviceId, FString OSVersion, FString DeviceModel, bool CreateAccount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LoginWithIOSDeviceID";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("TitleId"), PlayFabAppId);
	OutRestJsonObj->SetStringField(TEXT("DeviceId"), IOSDeviceId);

	if (OSVersion != "") OutRestJsonObj->SetStringField(TEXT("OS"), OSVersion);
	if (DeviceModel != "") OutRestJsonObj->SetStringField(TEXT("DeviceModel"), DeviceModel);
	if (CreateAccount) OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), CreateAccount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Login with Steam Request */
UPlayFabRequestProxy* UPlayFabRequestProxy::LoginWithSteam(FString SteamAccessToken, bool CreateAccount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LoginWithSteam";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("TitleId"), PlayFabAppId);
	OutRestJsonObj->SetStringField(TEXT("SteamTicket"), SteamAccessToken);
	if (CreateAccount) OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), CreateAccount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Add Username Password Request */
UPlayFabRequestProxy* UPlayFabRequestProxy::AddUsernamePassword(FString SessionTicket, FString Email, FString Username, FString Password)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "AddUsernamePassword";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("Username"), Username);
	OutRestJsonObj->SetStringField(TEXT("Email"), Email);
	OutRestJsonObj->SetStringField(TEXT("Password"), Password);


	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Account Info Request */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetAccountInfo(FString SessionTicket, FString PlayFabId, FString Username, FString Email, FString TitleDisplayName)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetAccountInfo";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);

	if (Username != "")
	{
		OutRestJsonObj->SetStringField(TEXT("Username"), Username);
	}
	if (Email != "")
	{
		OutRestJsonObj->SetStringField(TEXT("Email"), Email);
	}
	if (TitleDisplayName != "")
	{
		OutRestJsonObj->SetStringField(TEXT("TitleDisplayName"), TitleDisplayName);
	}

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get PlayFabIds from Facebook Ids */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetPlayFabIDsFromFacebookIDs(FString SessionTicket, TArray<FString> FacebookIDs)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetPlayFabIDsFromFacebookIDs";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringArrayField(TEXT("FacebookIDs"), FacebookIDs);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Retrieves the unique PlayFab identifiers for the given set of Game Center identifiers (referenced in the Game Center Programming Guide as the Player Identifier) */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetPlayFabIDsFromGameCenterIDs(FString SessionTicket, TArray<FString> GameCenterIDs)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetPlayFabIDsFromGameCenterIDs";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringArrayField(TEXT("GameCenterIDs"), GameCenterIDs);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Retrieves the unique PlayFab identifiers for the given set of PlayStation Network identifiers */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetPlayFabIDsFromPSNAccountIDs(FString SessionTicket, TArray<FString> PSNAccountIDs)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetPlayFabIDsFromPSNAccountIDs";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringArrayField(TEXT("PSNAccountIDs"), PSNAccountIDs);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers are the profile IDs for the user accounts, available as SteamId in the Steamworks Community API calls */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetPlayFabIDsFromSteamIDs(FString SessionTicket, TArray<FString> SteamIDs)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetPlayFabIDsFromSteamIDs";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringArrayField(TEXT("SteamIDs"), SteamIDs);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User combined info all inputs are optional except the session ticket.*/
UPlayFabRequestProxy* UPlayFabRequestProxy::GetUserCombinedInfo(FString SessionTicket, TArray<FString> UserDataKeys,
	TArray<FString> ReadOnlyDataKey, FString PlayFabId, FString Username,
	FString Email, FString TitleDisplayName, bool GetAccountInfo, bool GetInventory, bool GetVirtualCurrency,
	bool GetUserData, bool GetReadOnlyData)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserCombinedInfo";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	if (PlayFabId != "") OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	if (Username != "") OutRestJsonObj->SetStringField(TEXT("Username"), Username);
	if (Email != "") OutRestJsonObj->SetStringField(TEXT("Email"), Email);
	if (TitleDisplayName != "") OutRestJsonObj->SetStringField(TEXT("TitleDisplayName"), TitleDisplayName);
	if (GetAccountInfo) OutRestJsonObj->SetBoolField(TEXT("GetAccountInfo"), GetAccountInfo);
	if (GetInventory) OutRestJsonObj->SetBoolField(TEXT("GetInventory"), GetInventory);
	if (GetVirtualCurrency) OutRestJsonObj->SetBoolField(TEXT("GetVirtualCurrency"), GetVirtualCurrency);
	if (GetUserData) OutRestJsonObj->SetBoolField(TEXT("GetUserData"), GetUserData);
	if (UserDataKeys.Num() > 0) OutRestJsonObj->SetStringArrayField(TEXT("UserDataKeys"), UserDataKeys);
	if (GetReadOnlyData) OutRestJsonObj->SetBoolField(TEXT("GetReadOnlyData"), GetReadOnlyData);
	if (ReadOnlyDataKey.Num() > 0) OutRestJsonObj->SetStringArrayField(TEXT("ReadOnlyDataKeys"), ReadOnlyDataKey);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Link android device ID */
UPlayFabRequestProxy* UPlayFabRequestProxy::LinkAndroidDeviceID(FString SessionTicket, FString AndroidDeviceId, FString OSVersion, FString AndroidDeviceType)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LinkAndroidDeviceID";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), AndroidDeviceId);

	if (OSVersion != "") OutRestJsonObj->SetStringField(TEXT("OS"), OSVersion);
	if (AndroidDeviceType != "") OutRestJsonObj->SetStringField(TEXT("AndroidDevice"), AndroidDeviceType);


	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Link FacebookAccount */
UPlayFabRequestProxy* UPlayFabRequestProxy::LinkFacebookAccount(FString SessionTicket, FString FacebookAccessToken)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LinkFacebookAccount";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("AccessToken"), FacebookAccessToken);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Link GameCenterAccount */
UPlayFabRequestProxy* UPlayFabRequestProxy::LinkGameCenterAccount(FString SessionTicket, FString GameCenterId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LinkGameCenterAccount";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("GameCenterId"), GameCenterId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Link GoogleAccount */
UPlayFabRequestProxy* UPlayFabRequestProxy::LinkGoogleAccount(FString SessionTicket, FString GoogleAccessToken)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LinkGoogleAccount";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("AccessToken"), GoogleAccessToken);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Link IOS device ID */
UPlayFabRequestProxy* UPlayFabRequestProxy::LinkIOSDeviceID(FString SessionTicket, FString IOSDeviceId, FString OSVersion, FString IOSDeviceModel)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LinkIOSDeviceID";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("DeviceId"), IOSDeviceId);

	if (OSVersion != "") OutRestJsonObj->SetStringField(TEXT("OS"), OSVersion);
	if (IOSDeviceModel != "") OutRestJsonObj->SetStringField(TEXT("DeviceModel"), IOSDeviceModel);


	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Link SteamAccount */
UPlayFabRequestProxy* UPlayFabRequestProxy::LinkSteamAccount(FString SessionTicket, FString SteamAccessToken)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LinkSteamAccount";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SteamTicket"), SteamAccessToken);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create SendAccountRecoverEmail */
UPlayFabRequestProxy* UPlayFabRequestProxy::SendAccountRecoverEmail(FString Email)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "SendAccountRecoverEmail";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("Email"), Email);
	OutRestJsonObj->SetStringField(TEXT("TitleId"), PlayFabAppId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create UnLink android device ID */
UPlayFabRequestProxy* UPlayFabRequestProxy::UnlinkAndroidDeviceID(FString SessionTicket, FString AndroidDeviceId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UnlinkAndroidDeviceID";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), AndroidDeviceId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create UnLink FacebookAccount */
UPlayFabRequestProxy* UPlayFabRequestProxy::UnlinkFacebookAccount(FString SessionTicket)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UnlinkFacebookAccount";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create UnLink GameCenterAccount */
UPlayFabRequestProxy* UPlayFabRequestProxy::UnlinkGameCenterAccount(FString SessionTicket)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UnlinkGameCenterAccount";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create UnLink GoogleAccount */
UPlayFabRequestProxy* UPlayFabRequestProxy::UnlinkGoogleAccount(FString SessionTicket)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UnlinkGoogleAccount";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create UnLink IOS device ID */
UPlayFabRequestProxy* UPlayFabRequestProxy::UnlinkIOSDeviceID(FString SessionTicket, FString IOSDeviceId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UnlinkIOSDeviceID";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("DeviceId"), IOSDeviceId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create UnLink SteamAccount */
UPlayFabRequestProxy* UPlayFabRequestProxy::UnlinkSteamAccount(FString SessionTicket)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UnlinkSteamAccount";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create UpdateUserTitleDisplayName */
UPlayFabRequestProxy* UPlayFabRequestProxy::UpdateUserTitleDisplayName(FString SessionTicket, FString DisplayName)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserTitleDisplayName";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("DisplayName"), DisplayName);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create GetFriendLeaderboard */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetFriendLeaderboard(FString SessionTicket, FString StatisticName, int32 MaxResultsCount, int32 StartPosition)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetFriendLeaderboard";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	if (StartPosition > 0) OutRestJsonObj->SetNumberField(TEXT("StatisticName"), StartPosition);
	OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), MaxResultsCount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create GetLeaderboard */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetLeaderboard(FString SessionTicket, FString StatisticName, int32 MaxResultsCount, int32 StartPosition)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetLeaderboard";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	if (StartPosition > 0) OutRestJsonObj->SetNumberField(TEXT("StatisticName"), StartPosition);
	OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), MaxResultsCount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create GetLeaderboardAroundCurrentUser */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetLeaderboardAroundCurrentUser(FString SessionTicket, FString StatisticName, int32 MaxResultsCount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetLeaderboardAroundCurrentUser";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), MaxResultsCount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Data*/
UPlayFabRequestProxy* UPlayFabRequestProxy::GetUserData(FString SessionTicket, TArray<FString> Keys, FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	if (Keys.Num() > 0) OutRestJsonObj->SetStringArrayField(TEXT("StatisticName"), Keys);
	if (PlayFabId != "") OutRestJsonObj->SetStringField(TEXT("MaxResultsCount"), PlayFabId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Publisher Data*/
UPlayFabRequestProxy* UPlayFabRequestProxy::GetUserPublisherData(FString SessionTicket, TArray<FString> Keys, FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserPublisherData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	if (Keys.Num() > 0) OutRestJsonObj->SetStringArrayField(TEXT("StatisticName"), Keys);
	if (PlayFabId != "") OutRestJsonObj->SetStringField(TEXT("MaxResultsCount"), PlayFabId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Publisher Read Only Data*/
UPlayFabRequestProxy* UPlayFabRequestProxy::GetUserPublisherReadOnlyData(FString SessionTicket, TArray<FString> Keys, FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserPublisherReadOnlyData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	if (Keys.Num() > 0) OutRestJsonObj->SetStringArrayField(TEXT("StatisticName"), Keys);
	if (PlayFabId != "") OutRestJsonObj->SetStringField(TEXT("MaxResultsCount"), PlayFabId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Read Only Data*/
UPlayFabRequestProxy* UPlayFabRequestProxy::GetUserReadOnlyData(FString SessionTicket, TArray<FString> Keys, FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserReadOnlyData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	if (Keys.Num() > 0) OutRestJsonObj->SetStringArrayField(TEXT("StatisticName"), Keys);
	if (PlayFabId != "") OutRestJsonObj->SetStringField(TEXT("MaxResultsCount"), PlayFabId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Statistics */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetUserStatistics(FString SessionTicket)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update User Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::UpdateUserData(FString SessionTicket, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (PermissionType == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	if (PermissionType == EUserDataPermision::Type::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update User Publisher Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::UpdateUserPublisherData(FString SessionTicket, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserPublisherData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (PermissionType == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	if (PermissionType == EUserDataPermision::Type::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update User Statistics */
UPlayFabRequestProxy* UPlayFabRequestProxy::UpdateUserStatistics(FString SessionTicket, UPlayFabJsonObject* Statistics)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserStatistics";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetObjectField(TEXT("UserStatistics"), Statistics);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Catalog Items */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetCatalogItems(FString SessionTicket, FString CatalogVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCatalogItems";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Store Items */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetStoreItems(FString SessionTicket, FString StoreId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetStoreItems";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("StoreId"), StoreId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Title Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetTitleData(FString SessionTicket, TArray<FString> Keys)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetTitleData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Title News */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetTitleNews(FString SessionTicket, int32 NumberofEntries)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetTitleNews";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetNumberField(TEXT("Count"), NumberofEntries);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Add User Virtual Currency */
UPlayFabRequestProxy* UPlayFabRequestProxy::AddUserVirtualCurrency(FString SessionTicket, FString VirtualCurrency, int32 Amount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "AddUserVirtualCurrency";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), VirtualCurrency);
	OutRestJsonObj->SetNumberField(TEXT("Amount"), Amount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Consume Item */
UPlayFabRequestProxy* UPlayFabRequestProxy::ConsumeItem(FString SessionTicket, FString ItemInstanceId, int32 ConsumeCount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "ConsumeItem";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), ItemInstanceId);
	OutRestJsonObj->SetNumberField(TEXT("ConsumeCount"), ConsumeCount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Character Inventory */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetCharacterInventory(FString SessionTicket, FString PlayFabId, FString CharacterId, FString CatalogVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCharacterInventory";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	if (CatalogVersion != "") OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Inventory */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetUserInventory(FString SessionTicket)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserInventory";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Redeem Coupon */
UPlayFabRequestProxy* UPlayFabRequestProxy::RedeemCoupon(FString SessionTicket, FString CouponCode, FString CatalogVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "RedeemCoupon";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("CouponCode"), CouponCode);
	if (CatalogVersion != "") OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Report Player */
UPlayFabRequestProxy* UPlayFabRequestProxy::ReportPlayer(FString SessionTicket, FString ReportedId, FString Reason)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "ReportPlayer";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("ReporteeId"), ReportedId);
	OutRestJsonObj->SetStringField(TEXT("Comment"), Reason);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Subtract User Virtual Currency */
UPlayFabRequestProxy* UPlayFabRequestProxy::SubtractUserVirtualCurrency(FString SessionTicket, FString VirtualCurrency, int32 Amount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "SubtractUserVirtualCurrency";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), VirtualCurrency);
	OutRestJsonObj->SetNumberField(TEXT("Amount"), Amount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Unlock Container Item */
UPlayFabRequestProxy* UPlayFabRequestProxy::UnlockContainerItem(FString SessionTicket, FString ContainerItemId, FString CatalogVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UnlockContainerItem";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("ContainerItemId"), ContainerItemId);
	if (CatalogVersion != "") OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Start Purchase */
UPlayFabRequestProxy* UPlayFabRequestProxy::StartPurchase(FString SessionTicket, UPlayFabJsonObject* Items, FString CatalogVersion, FString StoreId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "StartPurchase";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	if (CatalogVersion != "") OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);
	if (StoreId != "") OutRestJsonObj->SetStringField(TEXT("StoreId"), StoreId);
	OutRestJsonObj->SetObjectField(TEXT("Items"), Items);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Pay For Purchase */
UPlayFabRequestProxy* UPlayFabRequestProxy::PayForPurchase(FString SessionTicket, FString OrderId, FString ProviderName, FString Currency)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "PayForPurchase";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("OrderId"), OrderId);
	OutRestJsonObj->SetStringField(TEXT("ProviderName"), ProviderName);
	OutRestJsonObj->SetStringField(TEXT("Currency"), Currency);


	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Confirm Purchase */
UPlayFabRequestProxy* UPlayFabRequestProxy::ConfirmPurchase(FString SessionTicket, FString OrderId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "ConfirmPurchase";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("OrderId"), OrderId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** PurchaseItem */
UPlayFabRequestProxy* UPlayFabRequestProxy::PurchaseItem(FString SessionTicket, FString ItemId, FString VirtualCurrency,
	int32 Price, FString CatalogVersion, FString StoreId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "PurchaseItem";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("ItemId"), ItemId);
	OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), VirtualCurrency);
	OutRestJsonObj->SetNumberField(TEXT("Price"), Price);
	if (CatalogVersion != "") OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);
	if (StoreId != "") OutRestJsonObj->SetStringField(TEXT("StoreId"), StoreId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Add Friend */
UPlayFabRequestProxy* UPlayFabRequestProxy::AddFriend(FString SessionTicket, FString FriendPlayFabId, FString FriendUsername,
	FString FriendEmail, FString FriendTitleDisplayName)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "AddFriend";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	if (FriendPlayFabId != "") OutRestJsonObj->SetStringField(TEXT("FrienPlayFabId"), FriendPlayFabId);
	if (FriendUsername != "") OutRestJsonObj->SetStringField(TEXT("FriendUsername"), FriendUsername);
	if (FriendEmail != "") OutRestJsonObj->SetStringField(TEXT("FriendEmail"), FriendEmail);
	if (FriendTitleDisplayName != "") OutRestJsonObj->SetStringField(TEXT("FriendTitleDisplayName"), FriendTitleDisplayName);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Friends List */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetFriendsList(FString SessionTicket, bool IncludeSteamFriends, bool IncludeFacebookFriends)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetFriendsList";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	if (IncludeSteamFriends) OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), IncludeSteamFriends);
	if (IncludeFacebookFriends) OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), IncludeFacebookFriends);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Remove Friend */
UPlayFabRequestProxy* UPlayFabRequestProxy::RemoveFriend(FString SessionTicket, FString FriendPlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "RemoveFriend";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), FriendPlayFabId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Set Friend Tags */
UPlayFabRequestProxy* UPlayFabRequestProxy::SetFriendTags(FString SessionTicket, FString FriendPlayFabId, TArray<FString> Tags)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "SetFriendTags";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), FriendPlayFabId);
	OutRestJsonObj->SetStringArrayField(TEXT("Tags"), Tags);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Register For IOS Push Notifications */
UPlayFabRequestProxy* UPlayFabRequestProxy::RegisterFORIOSPushNotifications(FString SessionTicket, FString DeviceToken, bool SendPushNotificationConfirmation, FString ConfirmationMessage)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "RegisterForIOSPushNotifications";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("DeviceToken"), DeviceToken);
	if (SendPushNotificationConfirmation) OutRestJsonObj->SetBoolField(TEXT("SendPushNotificationConfirmation"), SendPushNotificationConfirmation);
	if (SendPushNotificationConfirmation) OutRestJsonObj->SetStringField(TEXT("ConfirmationMessage"), ConfirmationMessage);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Restore IOS Purchases */
UPlayFabRequestProxy* UPlayFabRequestProxy::RestoreIOSPurchases(FString SessionTicket, FString Base64ReceiptData)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "RestoreIOSPurchases";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("ReceiptData"), Base64ReceiptData);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Validate IOS Reciept */
UPlayFabRequestProxy* UPlayFabRequestProxy::ValidateIOSReceipt(FString SessionTicket, FString Base64ReceiptData, FString CurrencyCode, FString PurchasePrice)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "ValidateIOSReceipt";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("ReceiptData"), Base64ReceiptData);
	OutRestJsonObj->SetStringField(TEXT("CurrencyCode"), CurrencyCode);
	OutRestJsonObj->SetStringField(TEXT("PurchasePrice"), PurchasePrice);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Current Games */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetCurrentGames(FString SessionTicket, ERegion::Type Region, FString BuildVersion, FString GameMode, FString StatisticName)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCurrentGames";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	if (Region != ERegion::Type::ANY)
	{
		if (Region == ERegion::Type::AUSTRALIA) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Australia"));
		if (Region == ERegion::Type::BRAZIL) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Brazil"));
		if (Region == ERegion::Type::EUWEST) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("EUWest"));
		if (Region == ERegion::Type::JAPAN) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Japan"));
		if (Region == ERegion::Type::SINGAPORE) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Singapore"));
		if (Region == ERegion::Type::USCENTRAL) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("USCentral"));
		if (Region == ERegion::Type::USEAST) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("USEast"));
	}
	if (BuildVersion != "") OutRestJsonObj->SetStringField(TEXT("BuildVersion"), BuildVersion);
	if (GameMode != "") OutRestJsonObj->SetStringField(TEXT("GameMode"), GameMode);
	if (StatisticName != "") OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);


	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Game Server Regions */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetGameServerRegions(FString SessionTicket, FString BuildVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetGameServerRegions";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("BuildVersion"), BuildVersion);
	OutRestJsonObj->SetStringField(TEXT("TitleId"), PlayFabAppId);


	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Matchmake */
UPlayFabRequestProxy* UPlayFabRequestProxy::Matchmake(FString SessionTicket, ERegion::Type Region, FString BuildVersion, FString GameMode,
	FString LobbyId, FString StatisticName, FString CharacterId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "Matchmake";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	if (BuildVersion != "") OutRestJsonObj->SetStringField(TEXT("BuildVersion"), BuildVersion);
	if (Region != ERegion::Type::ANY)
	{
		if (Region == ERegion::Type::AUSTRALIA) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Australia"));
		if (Region == ERegion::Type::BRAZIL) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Brazil"));
		if (Region == ERegion::Type::EUWEST) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("EUWest"));
		if (Region == ERegion::Type::JAPAN) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Japan"));
		if (Region == ERegion::Type::SINGAPORE) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Singapore"));
		if (Region == ERegion::Type::USCENTRAL) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("USCentral"));
		if (Region == ERegion::Type::USEAST) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("USEast"));
	}
	if (GameMode != "") OutRestJsonObj->SetStringField(TEXT("GameMode"), GameMode);
	if (LobbyId != "") OutRestJsonObj->SetStringField(TEXT("LobbyId"), BuildVersion);
	if (StatisticName != "") OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	if (CharacterId != "") OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;

}

/** Start Game */
UPlayFabRequestProxy* UPlayFabRequestProxy::StartGame(FString SessionTicket, FString BuildVersion, ERegion::Type Region, FString GameMode, FString StatisticName,
	FString CharacterId, bool PasswordRestricted, FString CustomCommandLineData)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "Matchmake";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("BuildVersion"), BuildVersion);
	if (Region != ERegion::Type::ANY)
	{
		if (Region == ERegion::Type::AUSTRALIA) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Australia"));
		if (Region == ERegion::Type::BRAZIL) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Brazil"));
		if (Region == ERegion::Type::EUWEST) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("EUWest"));
		if (Region == ERegion::Type::JAPAN) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Japan"));
		if (Region == ERegion::Type::SINGAPORE) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("Singapore"));
		if (Region == ERegion::Type::USCENTRAL) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("USCentral"));
		if (Region == ERegion::Type::USEAST) OutRestJsonObj->SetStringField(TEXT("Region"), TEXT("USEast"));
	}
	OutRestJsonObj->SetStringField(TEXT("GameMode"), GameMode);
	if (StatisticName != "") OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	if (CharacterId != "") OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	if (PasswordRestricted) OutRestJsonObj->SetBoolField(TEXT("PasswordRestrcted"), PasswordRestricted);
	if (CustomCommandLineData != "") OutRestJsonObj->SetStringField(TEXT("CustomCommandLineData"), CustomCommandLineData);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Android Device Push Notification Registration */
UPlayFabRequestProxy* UPlayFabRequestProxy::AndroidDevicePushNotificationRegistration(FString SessionTicket,
	FString DeviceToken, bool SendPushNotificationConfirmation, FString ConfirmationMessage)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "AndroidDevicePushNotificationRegistration";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("DeviceToken"), DeviceToken);
	if (SendPushNotificationConfirmation) OutRestJsonObj->SetBoolField(TEXT("SendPushNotificationConfirmation"), SendPushNotificationConfirmation);
	if (SendPushNotificationConfirmation) OutRestJsonObj->SetStringField(TEXT("ConfirmationMessage"), ConfirmationMessage);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Validate Google Play Purchase */
UPlayFabRequestProxy* UPlayFabRequestProxy::ValidateGooglePlayPurchase(FString SessionTicket, FString ReceiptJsonString, FString Signature)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "ValidateGooglePlayPurchase";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("ReceiptJson"), ReceiptJsonString);
	OutRestJsonObj->SetStringField(TEXT("Signature"), Signature);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Log Event */
UPlayFabRequestProxy* UPlayFabRequestProxy::LogEvent(FString SessionTicket, FString EventName, UPlayFabJsonObject* Body, bool ProfileSetEvent)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LogEvent";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("EventName"), EventName);
	OutRestJsonObj->SetObjectField(TEXT("Body"), Body);
	if (ProfileSetEvent) OutRestJsonObj->SetBoolField(TEXT("ProfileSetEvent"), ProfileSetEvent);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Add Shared Group Memebers */
UPlayFabRequestProxy* UPlayFabRequestProxy::AddSharedGroupMembers(FString SessionTicket, FString SharedGroupId, TArray<FString> PlayFabIds)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "AddSharedGroupMembers";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);
	OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIds);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Shared Group */
UPlayFabRequestProxy* UPlayFabRequestProxy::CreateSharedGroup(FString SessionTicket, FString SharedGroupId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "CreateSharedGroup";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Publisher Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetPublisherData(FString SessionTicket, TArray<FString> Keys)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetPublisherData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Shared Group Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetSharedGroupData(FString SessionTicket, FString SharedGroupId, TArray<FString> Keys, bool GetMembers)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetSharedGroupData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);
	OutRestJsonObj->SetBoolField(TEXT("ProfileSetEvent"), GetMembers);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Remove Shared Group Memebers */
UPlayFabRequestProxy* UPlayFabRequestProxy::RemoveSharedGroupMembers(FString SessionTicket, FString SharedGroupId, TArray<FString> PlayFabIds)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "RemoveSharedGroupMembers";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);
	OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIds);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update Shared Group Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::UpdateSharedGroupData(FString SessionTicket, FString SharedGroupId, UPlayFabJsonObject* Data, EUserDataPermision::Type Permission)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateSharedGroupData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (Permission == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	if (Permission == EUserDataPermision::Type::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** RefreshPSNAuthToken */
UPlayFabRequestProxy* UPlayFabRequestProxy::RefreshPSNAuthToken(FString SessionTicket, FString PSNAuthCode)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "RefreshPSNAuthToken";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("AuthToken"), PSNAuthCode);


	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Cloud Script Url */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetCloudScriptUrl(FString SessionTicket, int32 Version, bool Testing)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCloudScriptUrl";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	if (Version > 0) OutRestJsonObj->SetNumberField(TEXT("Version"), Version);
	if (Testing) OutRestJsonObj->SetBoolField(TEXT("Testing"), Testing);


	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Run Cloud Script */
UPlayFabRequestProxy* UPlayFabRequestProxy::RunCloudScript(FString SessionTicket, FString ActionId, UPlayFabJsonObject* Params, FString ParamsEncoded)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "RunCloudScript";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = true;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("ActionId"), ActionId);
	OutRestJsonObj->SetObjectField(TEXT("Params"), Params);
	if (ParamsEncoded != "") OutRestJsonObj->SetStringField(TEXT("ParamsEncoded"), ParamsEncoded);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Content Download Url */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetContentDownloadUrl(FString SessionTicket, FString Key, FString HttpMethod, bool ThruCDN)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetContentDownloadUrl";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("Key"), Key);
	if (HttpMethod != "") OutRestJsonObj->SetStringField(TEXT("HttpMethod"), HttpMethod);
	OutRestJsonObj->SetBoolField(TEXT("ThruCDN"), ThruCDN);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Character Leaderboard */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetCharacterLeaderboard(FString SessionTicket, FString StatisticName, int32 MaxResultsCount,
	FString CharacterType, int32 StartPosition)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCharacterLeaderboard";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), MaxResultsCount);
	if (CharacterType != "") OutRestJsonObj->SetStringField(TEXT("CharacterType"), CharacterType);
	if (StartPosition > 0) OutRestJsonObj->SetNumberField(TEXT("StartPosition"), StartPosition);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Leaderboard Around Character */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetLeaderboardAroundCharacter(FString SessionTicket, FString CharacterId, FString StatisticName,
	int32 MaxResultsCount, FString CharacterType)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetLeaderboardAroundCharacter";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), MaxResultsCount);
	if (CharacterType != "") OutRestJsonObj->SetStringField(TEXT("CharacterType"), CharacterType);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Leaderboard For User Character */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetLeaderboardForUserCharacters(FString SessionTicket, FString StatisticName, int32 MaxResultsCount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetLeaderboardForUserCharacters";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), MaxResultsCount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Grant Character To User */
UPlayFabRequestProxy* UPlayFabRequestProxy::GrantCharacterToUser(FString SessionTicket, FString ItemId, FString CharacterName, FString CatalogVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GrantCharacterToUser";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("ItemId"), ItemId);
	OutRestJsonObj->SetStringField(TEXT("CharacterName"), CharacterName);
	if (CatalogVersion != "") OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Character Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetCharacterData(FString SessionTicket, FString PlayFabId, FString CharacterId, TArray<FString> Keys)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCharacterData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	if (Keys.Num() > 0) OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Character ReadOnly Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetCharacterReadOnlyData(FString SessionTicket, FString PlayFabId, FString CharacterId, TArray<FString> Keys)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCharacterReadOnlyData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	if (Keys.Num() > 0) OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update Character Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::UpdateCharacterData(FString SessionTicket, FString CharacterId, UPlayFabJsonObject* Data, EUserDataPermision::Type Permission)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateCharacterData";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = false;
	manager->isClient = true;
	manager->useSecretKey = false;
	manager->useSessionTicket = true;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (Permission == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	if (Permission == EUserDataPermision::Type::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

//// Server
/** Create AuthenticateSessionTicket Request */
UPlayFabRequestProxy* UPlayFabRequestProxy::AuthenticateSessionTicket(FString SessionTicket)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "AuthenticateSessionTicket";
	manager->PlayFabSessionToken = SessionTicket;
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SessionTicket"), SessionTicket);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Account Info */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetUserAccountInfo(FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserAccountInfo";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Send Push Notification */
UPlayFabRequestProxy* UPlayFabRequestProxy::SendPushNotification(FString RecipientPlayFabId, FString Message, FString Subject)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "SendPushNotification";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("Recipient"), RecipientPlayFabId);
	OutRestJsonObj->SetStringField(TEXT("Message"), Message);
	if (Subject != "") OutRestJsonObj->SetStringField(TEXT("Subject"), Subject);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create GetLeaderboard */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetLeaderboard(FString StatisticName, int32 MaxResultsCount, int32 StartPosition)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetLeaderboard";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	if (StartPosition > 0) OutRestJsonObj->SetNumberField(TEXT("StatisticName"), StartPosition);
	OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), MaxResultsCount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create GetLeaderboardAroundUser */
UPlayFabRequestProxy* UPlayFabRequestProxy::GetLeaderboardAroundUser(FString StatisticName, FString PlayFabId, int32 MaxResultsCount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetLeaderboardAroundUser";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), PlayFabId);
	OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), MaxResultsCount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetUserData(TArray<FString> Keys, FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Internal Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetUserInternalData(TArray<FString> Keys, FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserInternal";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Publisher Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetUserPublisherData(TArray<FString> Keys, FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserPublisherData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Publisher Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetUserPublisherInternalData(TArray<FString> Keys, FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserPublisherInternalData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Publisher Read Only Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetUserPublisherReadOnlyData(TArray<FString> Keys, FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserPublisherReadOnlyData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Read Only Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetUserReadOnlyData(TArray<FString> Keys, FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserReadOnlyData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Statistics */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetUserStatistics(FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserStatistics";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update User Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateUserData(FString PlayFabId, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (PermissionType == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	else OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update User Internal Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateUserInternalData(FString PlayFabId, UPlayFabJsonObject* Data)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserInternalData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	//if (PermissionType == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	//if (Permissiontype == EUserDataPermision::Type::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update User Publisher Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateUserPublisherData(FString PlayFabId, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserPublisherData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (PermissionType == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	else OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update User Publisher Internal Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateUserPublisherInternalData(FString PlayFabId, UPlayFabJsonObject* Data)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserPublisherInternalData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	//if (PermissionType == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	//if (Permissiontype == EUserDataPermision::Type::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update User Publisher ReadOnly Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateUserPublisherReadOnlyData(FString PlayFabId, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserPublisherReadOnlyData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (PermissionType == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	else OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update User ReadOnly Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateUserReadOnlyData(FString PlayFabId, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserReadOnlyData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (PermissionType == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	else OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update User Statistics */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateUserStatistics(FString PlayFabId, UPlayFabJsonObject* Statistics)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserStatistics";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetObjectField(TEXT("UserStatistics"), Statistics);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Catalog Items */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetCatalogItems(FString CatalogVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCatalogItems";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Title Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetTitleData(TArray<FString> Keys)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetTitleData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Title Internal Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetTitleInternalData(TArray<FString> Keys)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetTitleInternalData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Set Title Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerSetTitleData(FString Key, FString Value)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "SetTitleData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("Key"), Key);
	OutRestJsonObj->SetStringField(TEXT("Value"), Value);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Title nternal Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerSetTitleInternalData(FString Key, FString Value)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "SetTitleInternalData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("Key"), Key);
	OutRestJsonObj->SetStringField(TEXT("Value"), Value);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Add Character Virtual Currency */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerAddCharacterVirtualCurrency(FString PlayFabId, FString CharacterId, FString VirtualCurrency, int32 Amount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "AddCharacterVirtualCurrency";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), VirtualCurrency);
	OutRestJsonObj->SetNumberField(TEXT("Amount"), Amount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Add User Virtual Currency */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerAddUserVirtualCurrency(FString PlayFabId, FString VirtualCurrency, int32 Amount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "AddUserVirtualCurrency";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	//OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), VirtualCurrency);
	OutRestJsonObj->SetNumberField(TEXT("Amount"), Amount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Character Inventory */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetCharacterInventory(FString PlayFabId, FString CharacterId, FString CatalogVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCharacterInventory";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	if (CatalogVersion != "") OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get User Inventory */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetUserInventory(FString PlayFabId, FString CatalogVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetUserInventory";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	//OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	if (CatalogVersion != "") OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Grant Items To Character */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGrantItemsToCharacter(FString PlayFabId, FString CharacterId, TArray<FString> ItemIds, FString CatalogVersion,
	FString Annotation)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GrantItemsToCharacter";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	if (CatalogVersion != "") OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);
	if (Annotation != "") OutRestJsonObj->SetStringField(TEXT("Annotation"), Annotation);
	OutRestJsonObj->SetStringArrayField(TEXT("ItemIds"), ItemIds);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Grant Items To User */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGrantItemsToUser(FString PlayFabId, TArray<FString> ItemIds, FString CatalogVersion,
	FString Annotation)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GrantItemsToUser";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	//OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	if (CatalogVersion != "") OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);
	if (Annotation != "") OutRestJsonObj->SetStringField(TEXT("Annotation"), Annotation);
	OutRestJsonObj->SetStringArrayField(TEXT("ItemIds"), ItemIds);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Grant Items To Users */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGrantItemsToUsers(UPlayFabJsonObject* ItemGrants, FString CatalogVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GrantItemsToUsers";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	if (CatalogVersion != "") OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), CatalogVersion);
	OutRestJsonObj->SetObjectField(TEXT("ItemGrants"), ItemGrants);


	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Modify Item Uses */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerModifyItemUses(FString PlayFabId, FString ItemInstanceId, int32 UsesToAdd)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "ModifyItemUses";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), ItemInstanceId);
	OutRestJsonObj->SetNumberField(TEXT("UsesToAdd"), UsesToAdd);


	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Move Item To Character From Character */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerMoveItemToCharacterFromCharacter(FString PlayFabId, FString GivingCharacterId,
	FString ReceivingCharacterId, FString ItemInstanceId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "MoveItemToCharacterFromCharacter";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("GivingCharacterId"), GivingCharacterId);
	OutRestJsonObj->SetStringField(TEXT("ReceivingCharacterId"), ReceivingCharacterId);
	OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), ItemInstanceId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Move Item To Character From User */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerMoveItemToCharacterFromUser(FString PlayFabId, FString CharacterId,
	FString ItemInstanceId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "MoveItemToCharacterFromUser";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), ItemInstanceId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Move Item To User From Character */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerMoveItemToUserFromCharacter(FString PlayFabId, FString CharacterId,
	FString ItemInstanceId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "MoveItemToUserFromCharacter";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), ItemInstanceId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Report Player */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerReportPlayer(FString ReporterPlayFabId, FString ReporteePlayFabId,
	FString TitleId, FString Comment)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "ReportPlayer";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("ReporterPlayFabId"), ReporterPlayFabId);
	OutRestJsonObj->SetStringField(TEXT("ReporteePlayFabId"), ReporteePlayFabId);
	if (TitleId != "") OutRestJsonObj->SetStringField(TEXT("TitleId"), TitleId);
	if (Comment != "") OutRestJsonObj->SetStringField(TEXT("Comment"), Comment);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Subtract Character Virtual Currency */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerSubtractCharacterVirtualCurrency(FString PlayFabId, FString CharacterId, FString VirtualCurrency, int32 Amount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "SubtractCharacterVirtualCurrency";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), VirtualCurrency);
	OutRestJsonObj->SetNumberField(TEXT("Amount"), Amount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Subtract User Virtual Currency */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerSubtractUserVirtualCurrency(FString PlayFabId, FString VirtualCurrency, int32 Amount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "SubtractUserVirtualCurrency";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	//OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), VirtualCurrency);
	OutRestJsonObj->SetNumberField(TEXT("Amount"), Amount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update User Inventory Item Custom Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateUserInventoryItemCustomData(FString PlayFabId, FString ItemInstanceId,
	UPlayFabJsonObject* Data, FString CharacterId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateUserInventoryCustomData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), ItemInstanceId);
	if (CharacterId != "") OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Notify Matchmaker Player Left */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerNotifyMatchmakerPlayerLeft(FString PlayFabId, FString LobbyId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "NotifyMatchmakerPlayerLeft";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("LobbyId"), LobbyId);
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Redeem Matchmaker Ticket */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerRedeemMatchmakerTicket(FString Ticket, FString LobbyId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "RedeemMatchmakerTicket";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("Ticket"), Ticket);
	OutRestJsonObj->SetStringField(TEXT("LobbyId"), LobbyId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Award Steam Achievement */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerAwardSteamAchievement(UPlayFabJsonObject* Achievements)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "AwardSteamAchievement";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetObjectField(TEXT("Achievements"), Achievements);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Log Event */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerLogEvent(FString EventName, UPlayFabJsonObject* Body, FString PlayFabId,
	FString EntityId, FString EntityType, bool PlayerEvent, bool ProfileSetEvent)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "LogEvent";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("EventName"), EventName);
	OutRestJsonObj->SetObjectField(TEXT("Body"), Body);

	if (PlayerEvent) OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	else
	{
		OutRestJsonObj->SetStringField(TEXT("EntityId"), EntityId);
		OutRestJsonObj->SetStringField(TEXT("EntityType"), EntityType);
	}

	if (ProfileSetEvent) OutRestJsonObj->SetBoolField(TEXT("ProfileSetEvent"), ProfileSetEvent);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Add Shared Group Memebers */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerAddSharedGroupMembers(FString SharedGroupId, TArray<FString> PlayFabIds)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "AddSharedGroupMembers";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);
	OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIds);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Create Shared Group */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerCreateSharedGroup(FString SharedGroupId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "CreateSharedGroup";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);
	//OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIds);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Delete Shared Group */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerDeleteSharedGroup(FString SharedGroupId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "DeleteSharedGroup";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);
	//OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIds);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Publisher Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetPublisherData(TArray<FString> Keys)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetPublisherData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	//OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Shared Group Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetSharedGroupData(FString SharedGroupId, TArray<FString> Keys, bool GetMembers)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetSharedGroupData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);
	if (GetMembers) OutRestJsonObj->SetBoolField(TEXT("GetMembers"), GetMembers);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Remove Shared Group Memebers */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerRemoveSharedGroupMembers(FString SharedGroupId, TArray<FString> PlayFabIds)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "RemoveSharedGroupMembers";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);
	OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIds);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Set Publisher Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerSetPublisherData(FString Key, FString Value)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "SetPublisherData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("Key"), Key);
	OutRestJsonObj->SetStringField(TEXT("Value"), Value);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update Shared Group Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateSharedGroupData(FString SharedGroupId, UPlayFabJsonObject* Data, EUserDataPermision::Type Permission)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateSharedGroupData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), SharedGroupId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (Permission == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	else OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Content Download Url */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetContentDownloadUrl(FString Key, FString HttpMethod, bool ThruCDN)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetContentDownloadUrl";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("Key"), Key);
	if (HttpMethod != "") OutRestJsonObj->SetStringField(TEXT("HttpMethod"), HttpMethod);
	OutRestJsonObj->SetBoolField(TEXT("ThruCDN"), ThruCDN);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Delete Character From User */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerDeleteCharacterFromUser(FString PlayFabId, FString CharacterId, bool SaveCharacterInventory)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "DeleteCharacterFromUser";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	if (SaveCharacterInventory) OutRestJsonObj->SetBoolField(TEXT("SaveCharacterInventory"), SaveCharacterInventory);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get All Users Characters */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetAllUsersCharacters(FString PlayFabId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetAllUsersCharacters";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Character Leaderboard */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetCharacterLeaderboard(FString CharacterId, FString StatisticName, int32 MaxResultsCount,
	FString CharacterType, int32 StartPosition)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCharacterLeaderboard";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), MaxResultsCount);
	if (CharacterType != "") OutRestJsonObj->SetStringField(TEXT("CharacterType"), CharacterType);
	if (StartPosition > 0) OutRestJsonObj->SetNumberField(TEXT("StartPosition"), StartPosition);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Character Statistics */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetCharacterStatistics(FString PlayFabId, FString CharacterId)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCharacterStatistics";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Leaderboard Around Character */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetLeaderboardAroundCharacter(FString PlayFabId, FString CharacterId, FString StatisticName, int32 MaxResultsCount,
	FString CharacterType)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetLeaderboardAroundCharacter";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), MaxResultsCount);
	if (CharacterType != "") OutRestJsonObj->SetStringField(TEXT("CharacterType"), CharacterType);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Leaderboard For User Character */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetLeaderboardForUserCharacters(FString PlayFabId, FString StatisticName, int32 MaxResultsCount)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetLeaderboardForUserCharacters";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("StatisticName"), StatisticName);
	OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), MaxResultsCount);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Grant Character To User */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGrantCharacterToUser(FString PlayFabId, FString CharacterType, FString CharacterName)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GrantCharacterToUser";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterName"), CharacterName);
	OutRestJsonObj->SetStringField(TEXT("CharacterType"), CharacterType);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update Character Statistics */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateCharacterStatistics(FString PlayFabId, FString CharacterId, UPlayFabJsonObject* CharacterStatistics)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateCharacterStatistics";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetObjectField(TEXT("CharacterStatistics"), CharacterStatistics);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Character Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetCharacterData(FString PlayFabId, FString CharacterId, TArray<FString> Keys,
	int32 IfChangedFromDataVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCharacterData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);
	if (IfChangedFromDataVersion > 0) OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), IfChangedFromDataVersion);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Character Internal Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetCharacterInternalData(FString PlayFabId, FString CharacterId, TArray<FString> Keys,
	int32 IfChangedFromDataVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCharacterInternalData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);
	if (IfChangedFromDataVersion > 0) OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), IfChangedFromDataVersion);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Get Character ReadOnly Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerGetCharacterReadOnlyData(FString PlayFabId, FString CharacterId, TArray<FString> Keys,
	int32 IfChangedFromDataVersion)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCharacterReadOnlyData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetStringArrayField(TEXT("Keys"), Keys);
	if (IfChangedFromDataVersion > 0) OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), IfChangedFromDataVersion);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update Character Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateCharacterData(FString PlayFabId, FString CharacterId, UPlayFabJsonObject* Data,
	EUserDataPermision::Type Permission)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateCharacterData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (Permission == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	else OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update Character Internal Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateCharacterInternalData(FString PlayFabId, FString CharacterId, UPlayFabJsonObject* Data,
	EUserDataPermision::Type Permission)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateCharacterInternalData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (Permission == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	else OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

/** Update Character ReadOnly Data */
UPlayFabRequestProxy* UPlayFabRequestProxy::ServerUpdateCharacterReadOnlyData(FString PlayFabId, FString CharacterId, UPlayFabJsonObject* Data,
	EUserDataPermision::Type Permission)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "UpdateCharacterReadOnlyData";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = false;
	manager->isServer = true;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("PlayFabId"), PlayFabId);
	OutRestJsonObj->SetStringField(TEXT("CharacterId"), CharacterId);
	OutRestJsonObj->SetObjectField(TEXT("Data"), Data);
	if (Permission == EUserDataPermision::Type::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
	else OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}




//// Admin
UPlayFabRequestProxy* UPlayFabRequestProxy::GetCloudScriptRevision(FString Version, FString Revision)
{
	// Object containing request data
	UPlayFabRequestProxy* manager = NewObject<UPlayFabRequestProxy>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	// Setup request
	
	

	// Setup the request variables based on this request
	manager->PlayFabClass = "GetCloudScriptRevision";
	manager->PlayFabSessionToken = "";
	manager->CloudScriptVersion = "";
	manager->isAdmin = true;
	manager->isServer = false;
	manager->isClient = false;
	manager->useSecretKey = true;
	manager->useSessionTicket = false;
	manager->cloudScript = false;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("Version"), Version);
	OutRestJsonObj->SetStringField(TEXT("Revision"), Revision);


	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	return manager;
}

void UPlayFabRequestProxy::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	// Be sure that we have no data from previous response
	ResetResponseData();

	// Check we have result to process futher
	if (!bWasSuccessful)
	{
		UE_LOG(LogPlayFab, Error, TEXT("Request failed: %s"), *Request->GetURL());

		// Broadcast the result event
		ResponseJsonObj->SetNumberField(TEXT("code"), 500);
		g_proxy->OnPlayFabResponse.Broadcast(ResponseJsonObj, false);

		return;
	}

	// Save response data as a string
	ResponseContent = Response->GetContentAsString();

	// Save response code as int32
	ResponseCode = Response->GetResponseCode();

	// Log response state
	UE_LOG(LogPlayFab, Log, TEXT("Response (%d): %s"), Response->GetResponseCode(), *Response->GetContentAsString());

	// Try to deserialize data to JSON
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseContent);
	FJsonSerializer::Deserialize(JsonReader, ResponseJsonObj->GetRootObject());

	// Decide whether the request was successful
	bIsValidJsonResponse = bWasSuccessful && ResponseJsonObj->GetRootObject().IsValid();

	// Log errors
	if (!bIsValidJsonResponse)
	{
		if (!ResponseJsonObj->GetRootObject().IsValid())
		{
			// As we assume it's recommended way to use current class, but not the only one,
			// it will be the warning instead of error
			UE_LOG(LogPlayFab, Warning, TEXT("JSON could not be decoded!"));
		}
	}

	// Broadcast the result event
	g_proxy->OnPlayFabResponse.Broadcast(ResponseJsonObj, true);
}

void UPlayFabRequestProxy::Activate()
{
	FString RequestUrl = PlayFabURL;

	// Build the full request url
	if (cloudScript)
	{
		RequestUrl = PlayFabLogicURL + CloudScriptVersion + TEXT("/prod/");
	}

	if (isAdmin)
	{
		RequestUrl += TEXT("Admin");
	}
	if (isClient)
	{
		RequestUrl += TEXT("Client");
	}
	if (isServer)
	{
		RequestUrl += TEXT("Server");
	}



	if (!PlayFabClass.IsEmpty())
	{
		RequestUrl += "/" + PlayFabClass;
	}

	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetURL(RequestUrl);

	if (!PlayFabSessionToken.IsEmpty())
	{
		HttpRequest->SetHeader("X-Authentication", PlayFabSessionToken);
	}
	if (useSecretKey)
	{
		HttpRequest->SetHeader("X-SecretKey", PlayFabApiKey);
	}

	// Set verb
	HttpRequest->SetVerb("POST");


	// Set content-type
	HttpRequest->SetHeader("Content-Type", "application/json");

	// Serialize data to json string
	FString OutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(RequestJsonObj->GetRootObject().ToSharedRef(), Writer);

	// Set Json content
	HttpRequest->SetContentAsString(OutputString);

	// Apply additional headers
	for (TMap<FString, FString>::TConstIterator It(RequestHeaders); It; ++It)
	{
		HttpRequest->SetHeader(It.Key(), It.Value());
	}

	// Bind event
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabRequestProxy::OnProcessRequestComplete);

	// Execute the request
	HttpRequest->ProcessRequest();
}

void UPlayFabRequestProxy::ResetResponseData()
{
	if (ResponseJsonObj != NULL)
	{
		ResponseJsonObj->Reset();
	}
	else
	{
		ResponseJsonObj = NewObject<UPlayFabJsonObject>();
	}

	bIsValidJsonResponse = false;
}
