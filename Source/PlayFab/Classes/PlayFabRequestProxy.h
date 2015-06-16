#pragma once

// Enum for the UserDataPermission
UENUM(BlueprintType)
namespace EUserDataPermision
{
	enum Type
	{
		PRIVATE,
		PUBLIC
	};
}

// Enum for Region
UENUM(BlueprintType)
namespace ERegion
{
	enum Type
	{
		ANY,
		USCENTRAL,
		USEAST,
		EUWEST,
		SINGAPORE,
		JAPAN,
		BRAZIL,
		AUSTRALIA
	};
}

#include "OnlineBlueprintCallProxyBase.h"
#include "PlayFabRequestProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayFabRequestCompleted, UPlayFabJsonObject*, response, bool, successful);

UCLASS()
class UPlayFabRequestProxy : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintAssignable)
	FOnPlayFabRequestCompleted OnPlayFabResponse;

	/** Set the Request Json object */
	UFUNCTION(BlueprintCallable, Category = "PlayFab")
		void SetRequestObject(UPlayFabJsonObject* JsonObject);

	/** Get the Response Json object */
	UFUNCTION(BlueprintCallable, Category = "PlayFab")
		UPlayFabJsonObject* GetResponseObject();

	/** Applies percent-encoding to text */
	UFUNCTION(BlueprintCallable, Category = "PlayFab")
		static FString PercentEncode(const FString& Text);

	/** Reset saved response data */
	UFUNCTION(BlueprintCallable, Category = "PlayFab")
		void ResetResponseData();

	/** UOnlineBlueprintCallProxyBase interface */
	virtual void Activate() override;

	//////////////////////////////////////////////////////////////////////////
	// Play Fab ion Helpers
	//////////////////////////////////////////////////////////////////////////

	//// Client

	// Authentication

	/** Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls which require an authenticated user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LoginWithPlayFab(const FString& Username, const FString& Password);

	/** Registers a new Playfab user account, returning a session identifier that can subsequently be used for API calls which require an authenticated user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* RegisterWithPlayFab(FString Username, FString Password, FString Email);

	/** Gets a Photon custom authentication token that can be used to securely join the player into a Photon room */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetPhotonAuthenticationToken(FString SessionTicket, bool PhotonRealtime, bool PhotonTurnbased, bool PhotonChat);

	/** Signs the user in using the Android device identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LoginWithAndroidDeviceID(FString AndroidDeviceId, FString OSVersion = "", FString AndroidDeviceType = "", bool CreateAccount = false);

	/** Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LoginWithEmail(FString Username, FString Password);

	/** Signs the user in using a Facebook access token, returning a session identifier that can subsequently be used for API calls which require an authenticated user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LoginWithFacebook(FString FacebookAccessToken, bool CreateAccount = false);

	/** Signs the user in using a Google account access token, returning a session identifier that can subsequently be used for API calls which require an authenticated user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LoginWithGoogle(FString GoogleAccessToken, bool CreateAccount = false);

	/** Signs the user in using the vendor-specific iOS device identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LoginWithIOSDeviceID(FString IOSDeviceId, FString OSVersion = "", FString DeviceModel = "", bool CreateAccount = false);

	/** Signs the user in using a Steam authentication ticket, returning a session identifier that can subsequently be used for API calls which require an authenticated user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Authentication", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LoginWithSteam(FString SteamAccessToken, bool CreateAccount = false);

	// Account Management

	/** Adds playfab username/password auth to an existing semi-anonymous account created via a 3rd party auth method.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* AddUsernamePassword(FString SessionTicket, FString Email, FString Username, FString Password);

	/** Retrieves the user's PlayFab account details  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetAccountInfo(FString SessionTicket, FString PlayFabId, FString Username = "", FString Email = "", FString TitleDisplayName = "");

	/** Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetPlayFabIDsFromFacebookIDs(FString SessionTicket, TArray<FString> FacebookIDs);

	/** Retrieves the unique PlayFab identifiers for the given set of Game Center identifiers (referenced in the Game Center Programming Guide as the Player Identifier) */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetPlayFabIDsFromGameCenterIDs(FString SessionTicket, TArray<FString> GameCenterIDs);

	/** Retrieves the unique PlayFab identifiers for the given set of PlayStation Network identifiers */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetPlayFabIDsFromPSNAccountIDs(FString SessionTicket, TArray<FString> PSNAccountIDs);

	/** Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers are the profile IDs for the user accounts, available as SteamId in
	the Steamworks Community API calls */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetPlayFabIDsFromSteamIDs(FString SessionTicket, TArray<FString> SteamIDs);

	/** Retrieves all requested data for a user in one unified request. By default, this API returns all data for the locally signed-in user. The input parameters may be used to
	limit the data retrieved any any subset of the available data, as well as retrieve the available data for a different user. Note that certain data, including inventory, virtual
	currency balances, and personally identifying information, may only be retrieved for the locally signed-in user. In the example below, a request is made for the account details,
	virtual currency balances, and specified user data for the locally signed-in user */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetUserCombinedInfo(FString SessionTicket, TArray<FString> UserDataKeys,
		TArray<FString> ReadOnlyDataKey, FString PlayFabId = "", FString Username = "",
		FString Email = "", FString TitleDisplayName = "", bool GetAccountInfo = false, bool GetInventory = true, bool GetVirtualCurrency = true,
		bool GetUserData = true, bool GetReadOnlyData = true);

	/** Links the Android device identifier to the user's PlayFab account  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LinkAndroidDeviceID(FString SessionTicket, FString AndroidDeviceId, FString OSVersion = "", FString AndroidDeviceType = "");

	/** Links the Facebook account associated with the provided Facebook access token to the user's PlayFab account  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LinkFacebookAccount(FString SessionTicket, FString FacebookAccessToken);

	/** Links the Game Center account associated with the provided Game Center ID to the user's PlayFab account  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LinkGameCenterAccount(FString SessionTicket, FString GameCenterId);

	/** Links the currently signed-in user account to the Google account specified by the Google account access token  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LinkGoogleAccount(FString SessionTicket, FString GoogleAccessToken);

	/** Links the vendor-specific iOS device identifier to the user's PlayFab account  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LinkIOSDeviceID(FString SessionTicket, FString IOSDeviceId, FString OSVersion = "", FString IOSDeviceModel = "");

	/** Links the Steam account associated with the provided Steam authentication ticket to the user's PlayFab account  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LinkSteamAccount(FString SessionTicket, FString SteamAccessToken);

	/** Forces an email to be sent to the registered email address for the user's account, with a link allowing the user to change the password  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* SendAccountRecoverEmail(FString Email);

	/** Unlinks the related Android device identifier from the user's PlayFab account  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UnlinkAndroidDeviceID(FString SessionTicket, FString AndroidDeviceId);

	/** Unlinks the related Facebook account from the user's PlayFab account  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UnlinkFacebookAccount(FString SessionTicket);

	/** Unlinks the related Game Center account from the user's PlayFab account  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UnlinkGameCenterAccount(FString SessionTicket);

	/** Unlinks the related Google account from the user's PlayFab account  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UnlinkGoogleAccount(FString SessionTicket);

	/** Unlinks the related iOS device identifier from the user's PlayFab account  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UnlinkIOSDeviceID(FString SessionTicket, FString IOSDeviceId);

	/** Unlinks the related Steam account from the user's PlayFab account  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UnlinkSteamAccount(FString SessionTicket);

	/** Updates the title specific display name for the user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UpdateUserTitleDisplayName(FString SessionTicket, FString DisplayName);

	// Player Data Management

	/** Retrieves a list of ranked friends of the current player for the given statistic, starting from the indicated point in the leaderboard  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetFriendLeaderboard(FString SessionTicket, FString StatisticName, int32 MaxResultsCount, int32 StartPosition = 0);

	/** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetLeaderboard(FString SessionTicket, FString StatisticName, int32 MaxResultsCount, int32 StartPosition = 0);

	/** Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetLeaderboardAroundCurrentUser(FString SessionTicket, FString StatisticName, int32 MaxResultsCount);

	/** Retrieves the title-specific custom data for the user which is readable and writable by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetUserData(FString SessionTicket, TArray<FString> Keys, FString PlayFabId = "");

	/** Retrieves the publisher-specific custom data for the user which is readable and writable by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetUserPublisherData(FString SessionTicket, TArray<FString> Keys, FString PlayFabId = "");

	/** Retrieves the publisher-specific custom data for the user which can only be read by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetUserPublisherReadOnlyData(FString SessionTicket, TArray<FString> Keys, FString PlayFabId = "");

	/** Retrieves the title-specific custom data for the user which can only be read by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetUserReadOnlyData(FString SessionTicket, TArray<FString> Keys, FString PlayFabId = "");

	/** Retrieves the details of all title-specific statistics for the user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetUserStatistics(FString SessionTicket);

	/** Creates and updates the title-specific custom data for the user which is readable and writable by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UpdateUserData(FString SessionTicket, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType);

	/** Creates and updates the publisher-specific custom data for the user which is readable and writable by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UpdateUserPublisherData(FString SessionTicket, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType);

	/** Updates the values of the specified title-specific statistics for the user */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UpdateUserStatistics(FString SessionTicket, UPlayFabJsonObject* Statistics);

	// Title-Wide Data Management

	/** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title Wide Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetCatalogItems(FString SessionTicket, FString CatalogVersion);

	/** Retrieves the set of items defined for the specified store, including all prices defined  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title Wide Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetStoreItems(FString SessionTicket, FString StoreId);

	/** Retrieves the key-value store of custom title settings  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title Wide Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetTitleData(FString SessionTicket, TArray<FString> Keys);

	/** Retrieves the title news feed, as configured in the developer portal */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Title Wide Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetTitleNews(FString SessionTicket, int32 NumberofEntries);

	// Player Item Management

	/** Increments the user's balance of the specified virtual currency by the stated amount  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* AddUserVirtualCurrency(FString SessionTicket, FString VirtualCurrency, int32 Amount);

	/** Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's inventory. */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ConsumeItem(FString SessionTicket, FString ItemInstanceId, int32 ConsumeCount);

	/** Retrieves the specified character's current inventory of virtual goods  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetCharacterInventory(FString SessionTicket, FString PlayFabId, FString CharacterId, FString CatalogVersion = "");

	/** Retrieves the user's current inventory of virtual goods  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetUserInventory(FString SessionTicket);

	/** Adds the virtual goods associated with the coupon to the user's inventory  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* RedeemCoupon(FString SessionTicket, FString CouponCode, FString CatalogVersion = "");

	/** Submit a report for another player (due to bad bahavior, etc.), so that customer service representatives for the title can take
	action concerning potentially toxic players.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ReportPlayer(FString SessionTicket, FString ReportedId, FString Reason);

	/** Decrements the user's balance of the specified virtual currency by the stated amount  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* SubtractUserVirtualCurrency(FString SessionTicket, FString VirtualCurrency, int32 Amount);

	/** Unlocks a container item in the user's inventory and consumes a key item of the type indicated by the container item  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UnlockContainerItem(FString SessionTicket, FString ContainerItemId, FString CatalogVersion = "");

	/** Creates an order for a list of items from the title catalog  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* StartPurchase(FString SessionTicket, UPlayFabJsonObject* Items, FString CatalogVersion = "", FString StoreId = "");

	/** Selects a payment option for purchase order created via StartPurchase  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* PayForPurchase(FString SessionTicket, FString OrderId, FString ProviderName, FString Currency);

	/** Confirms with the payment provider that the purchase was approved (if applicable) and adjusts inventory and virtual currency balances as appropriate  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ConfirmPurchase(FString SessionTicket, FString OrderId);

	/** Buys a single item with virtual currency. You must specify both the virtual currency to use to purchase, as well as what the client believes the price to be.
	This lets the server fail the purchase if the price has changed.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Player Item Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* PurchaseItem(FString SessionTicket, FString ItemId, FString VirtualCurrency, int32 Price, FString CatalogVersion = "", FString StoreId = "");

	// Friend List Managaement

	/** Adds the PlayFab user, based upon a match against a supplied unique identifier, to the friend list of the local user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* AddFriend(FString SessionTicket, FString FriendPlayFabId = "", FString FriendUsername = "",
		FString FriendEmail = "", FString FriendTitleDisplayName = "");

	/** Retrieves the current friend list for the local user, constrained to users who have PlayFab accounts. Friends from linked accounts (Facebook, Steam) are also included.
	You may optionally exclude some linked services' friends.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetFriendsList(FString SessionTicket, bool IncludeSteamFriends = true, bool IncludeFacebookFriends = true);

	/** Removes a specified user from the friend list of the local user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* RemoveFriend(FString SessionTicket, FString FriendPlayFabId);

	/** Updates the tag list for a specified user in the friend list of the local user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Friend List Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* SetFriendTags(FString SessionTicket, FString FriendPlayFabId, TArray<FString> Tags);

	// IOS-Specific APIs

	/** Registers the iOS device to receive push notifications */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | IOS Specific", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* RegisterFORIOSPushNotifications(FString SessionTicket, FString DeviceToken, bool SendPushNotificationConfirmation = false, FString ConfirmationMessage = "");

	/** Restores all in-app purchases based on the given refresh receipt.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | IOS Specific", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* RestoreIOSPurchases(FString SessionTicket, FString Base64ReceiptData);

	/** Validates with the Apple store that the receipt for an iOS in-app purchase is valid and that it matches the purchased catalog item */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | IOS Specific", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ValidateIOSReceipt(FString SessionTicket, FString Base64ReceiptData, FString CurrencyCode, FString PurchasePrice);

	// Matchmaking APIs

	/** Get details about all current running game servers matching the given parameters.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetCurrentGames(FString SessionTicket, ERegion::Type Region, FString BuildVersion = "", FString GameMode = "", FString StatisticName = "");

	/** Get details about the regions hosting game servers matching the given parameters.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetGameServerRegions(FString SessionTicket, FString BuildVersion);

	/** Attempts to locate a game session matching the given parameters. Note that parameters specified in the search are required (they are not weighting factors).
	If a slot is found in a server instance matching the parameters, the slot will be assigned to that player, removing it from the availabe set. In that case, the
	information on the game session will be returned, otherwise the Status returned will be GameNotFound. Note that EnableQueue is deprecated at this time.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* Matchmake(FString SessionTicket, ERegion::Type Region, FString BuildVersion = "", FString GameMode = "",
		FString LobbyId = "", FString StatisticName = "", FString CharacterId = "");

	/** Start a new game server with a given configuration, add the current player and return the connection information.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Matchmaking", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* StartGame(FString SessionTicket, FString BuildVersion, ERegion::Type Region, FString GameMode, FString StatisticName = "",
		FString CharacterId = "", bool PasswordRestricted = false, FString CustomCommandLineData = "");

	// Android-Specific APIs

	/** Registers the Android device to receive push notifications  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Android Specific", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* AndroidDevicePushNotificationRegistration(FString SessionTicket, FString DeviceToken, bool SendPushNotificationConfirmation = false,
		FString ConfirmationMessage = "");

	/** Validates a Google Play purchase and gives the corresponding item to the player.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Android Specific", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ValidateGooglePlayPurchase(FString SessionTicket, FString ReceiptJsonString, FString Signature);

	// Analytics

	/** Logs a custom analytics event  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Analytics", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* LogEvent(FString SessionTicket, FString EventName, UPlayFabJsonObject* Body, bool ProfileSetEvent = false);

	// Shared Group Data

	/** Adds users to the set of those able to update both the shared data, as well as the set of users in the group. Only users in the group can add new members.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* AddSharedGroupMembers(FString SessionTicket, FString SharedGroupId, TArray<FString> PlayFabIds);

	/** Requests the creation of a shared group object, containing key/value pairs which may be updated by all members of the group. Upon creation,
	the current user will be the only member of the group.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* CreateSharedGroup(FString SessionTicket, FString SharedGroupId);

	/** Retrieves the key-value store of custom publisher settings  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetPublisherData(FString SessionTicket, TArray<FString> Keys);

	/** Retrieves data stored in a shared group object, as well as the list of members in the group. Non-members of the group may use this to retrieve group data,
	including membership, but they will not receive data for keys marked as private.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetSharedGroupData(FString SessionTicket, FString SharedGroupId, TArray<FString> Keys, bool GetMembers = true);

	/** Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the group can remove members.
	If as a result of the call, zero users remain with access, the group and its associated data will be deleted.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* RemoveSharedGroupMembers(FString SessionTicket, FString SharedGroupId, TArray<FString> PlayFabIds);

	/** Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated or added in this call will be readable
	by users not in the group. By default, data permissions are set to Private. Regardless of the permission setting, only members of the group can update the data.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UpdateSharedGroupData(FString SessionTicket, FString SharedGroupId, UPlayFabJsonObject* Data, EUserDataPermision::Type Permission);

	// Sony Specific APIs

	/** Uses the supplied OAuth code to refresh the internally cached player PSN auth token  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Sony Specific", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* RefreshPSNAuthToken(FString SessionTicket, FString PSNAuthCode);

	// Server-Side Cloud Script

	/** Retrieves the title-specific URL for Cloud Script servers. This must be queried once, prior to making any calls to RunCloudScript. */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Server Side Cloud Script", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetCloudScriptUrl(FString SessionTicket, int32 Version, bool Testing);

	/** Triggers a particular server action, passing the provided inputs to the hosted Cloud Script. An action in this context is a handler in the JavaScript. NOTE: Before calling this API,
	you must call GetCloudScriptUrl to be assigned a Cloud Script server URL. When using an official PlayFab SDK, this URL is stored internally in the SDK, but GetCloudScriptUrl must still be manually called.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Server Side Cloud Script", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* RunCloudScript(FString SessionTicket, FString ActionId, UPlayFabJsonObject* Params, FString ParamsEncoded = "");

	// Content

	/** Retrieves the pre-authorized URL for accessing a content file for the title. A subsequent HTTP GET to the returned URL downloads the content; or a HEAD query to the returned URL retrieves
	the metadata of the content. This API only generates a pre-signed URL to access the content. A success result does not guarantee the existence of the content.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Content", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetContentDownloadUrl(FString SessionTicket, FString Key, FString HttpMethod = "", bool ThruCDN = true);

	// Characters

	/** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetCharacterLeaderboard(FString SessionTicket, FString StatisticName, int32 MaxResultsCount,
		FString CharacterType = "", int32 StartPosition = 0);

	/** Retrieves a list of ranked characters for the given statistic, centered on the currently signed-in user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetLeaderboardAroundCharacter(FString SessionTicket, FString CharacterId, FString StatisticName, int32 MaxResultsCount,
		FString CharacterType = "");

	/** Retrieves a list of all of the user's characters for the given statistic.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetLeaderboardForUserCharacters(FString SessionTicket, FString StatisticName, int32 MaxResultsCount);

	/** Grants the specified character type to the user.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GrantCharacterToUser(FString SessionTicket, FString ItemId, FString CharacterName, FString CatalogVersion = "");

	// Character Data

	/** Retrieves the title-specific custom data for the character which is readable and writable by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Character Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetCharacterData(FString SessionTicket, FString PlayFabId, FString CharacterId, TArray<FString> Keys);

	/** Retrieves the title-specific custom data for the character which can only be read by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Character Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetCharacterReadOnlyData(FString SessionTicket, FString PlayFabId, FString CharacterId, TArray<FString> Keys);

	/** Creates and updates the title-specific custom data for the user's character which is readable and writable by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Client | Character Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* UpdateCharacterData(FString SessionTicket, FString CharacterId, UPlayFabJsonObject* Data, EUserDataPermision::Type Permission);

	/// Server

	// Authentication

	/** Validated a client's session ticket, and if successful, returns details for that user */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Authentication", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* AuthenticateSessionTicket(FString SessionTicket);

	// Account Management

	/** Retrieves the relevant details for a specified user */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetUserAccountInfo(FString PlayFabId);

	/** Sends an iOS/Android Push Notification to a specific user, if that user's device has
	been configured for Push Notifications in PlayFab. If a user has linked both Android and iOS devices, both will be notified.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Account Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* SendPushNotification(FString RecipientPlayFabId, FString Message, FString Subject = "");

	// Player Data Management

	/** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetLeaderboard(FString StatisticName, int32 MaxResultsCount, int32 StartPosition = 0);

	/** Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetLeaderboardAroundUser(FString StatisticName, FString PlayFabId, int32 MaxResultsCount);

	/** Retrieves the title-specific custom data for the user which is readable and writable by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetUserData(TArray<FString> Keys, FString PlayFabId);

	/** Retrieves the title-specific custom data for the user which cannot be accessed by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetUserInternalData(TArray<FString> Keys, FString PlayFabId);

	/** Retrieves the publisher-specific custom data for the user which is readable and writable by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetUserPublisherData(TArray<FString> Keys, FString PlayFabId);

	/** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetUserPublisherInternalData(TArray<FString> Keys, FString PlayFabId);

	/** Retrieves the publisher-specific custom data for the user which can only be read by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetUserPublisherReadOnlyData(TArray<FString> Keys, FString PlayFabId);

	/** Retrieves the title-specific custom data for the user which can only be read by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetUserReadOnlyData(TArray<FString> Keys, FString PlayFabId);

	/** Retrieves the details of all title-specific statistics for the user */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetUserStatistics(FString PlayFabId);

	/** Updates the title-specific custom data for the user which is readable and writable by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateUserData(FString PlayFabId, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType);

	/** Updates the title-specific custom data for the user which cannot be accessed by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateUserInternalData(FString PlayFabId, UPlayFabJsonObject* Data);

	/** Updates the publisher-specific custom data for the user which is readable and writable by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateUserPublisherData(FString PlayFabId, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType);

	/** Updates the publisher-specific custom data for the user which cannot be accessed by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateUserPublisherInternalData(FString PlayFabId, UPlayFabJsonObject* Data);

	/** Updates the publisher-specific custom data for the user which can only be read by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateUserPublisherReadOnlyData(FString PlayFabId, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType);

	/** Updates the title-specific custom data for the user which can only be read by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateUserReadOnlyData(FString PlayFabId, UPlayFabJsonObject* Data, EUserDataPermision::Type PermissionType);

	/** Updates the values of the specified title-specific statistics for the user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateUserStatistics(FString PlayFabId, UPlayFabJsonObject* Statistics);

	// Title-Wide Data Management

	/** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title Wide Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetCatalogItems(FString CatalogVersion);

	/** Retrieves the key-value store of custom title settings  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title Wide Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetTitleData(TArray<FString> Keys);

	/** Retrieves the key-value store of custom internal title settings  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title Wide Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetTitleInternalData(TArray<FString> Keys);

	/** Updates the key-value store of custom title settings  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title Wide Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerSetTitleData(FString Key, FString Value);

	/** Updates the key-value store of custom title settings  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Title Wide Data Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerSetTitleInternalData(FString Key, FString Value);

	// Player Item Management

	/** Increments the character's balance of the specified virtual currency by the stated amount  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerAddCharacterVirtualCurrency(FString PlayFabId, FString CharacterId, FString VirtualCurrency, int32 Amount);

	/** Increments the user's balance of the specified virtual currency by the stated amount */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerAddUserVirtualCurrency(FString PlayFabId, FString VirtualCurrency, int32 Amount);

	/** Retrieves the specified character's current inventory of virtual goods  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetCharacterInventory(FString PlayFabId, FString CharacterId, FString CatalogVersion = "");

	/** Retrieves the specified user's current inventory of virtual goods  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetUserInventory(FString PlayFabId, FString CatalogVersion = "");

	/** Adds the specified items to the specified character's inventory */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGrantItemsToCharacter(FString PlayFabId, FString CharacterId, TArray<FString> ItemIds, FString CatalogVersion = "",
		FString Annotation = "");

	/** Adds the specified items to the specified user's inventory  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGrantItemsToUser(FString PlayFabId, TArray<FString> ItemIds, FString CatalogVersion = "",
		FString Annotation = "");

	/** Adds the specified items to the specified user inventories  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGrantItemsToUsers(UPlayFabJsonObject* ItemGrants, FString CatalogVersion = "");

	/** Modifies the number of remaining uses of a player's inventory item  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerModifyItemUses(FString PlayFabId, FString ItemInstanceId, int32 UsesToAdd);

	/** Moves an item from a character's inventory into another of the users's character's inventory.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerMoveItemToCharacterFromCharacter(FString PlayFabId, FString GivingCharacterId,
		FString ReceivingCharacterId, FString ItemInstanceId);

	/** Moves an item from a user's inventory into their character's inventory. */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerMoveItemToCharacterFromUser(FString PlayFabId, FString CharacterId,
		FString ItemInstanceId);

	/** Moves an item from a character's inventory into the owning user's inventory.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerMoveItemToUserFromCharacter(FString PlayFabId, FString CharacterId,
		FString ItemInstanceId);

	/** Submit a report about a player (due to bad bahavior, etc.) on behalf of another player, so that customer service
	representatives for the title can take action concerning potentially poxic players */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerReportPlayer(FString ReporterPlayFabId, FString ReporteePlayFabId,
		FString TitleId = "", FString Comment = "");

	/** Decrements the character's balance of the specified virtual currency by the stated amount */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerSubtractCharacterVirtualCurrency(FString PlayFabId, FString CharacterId, FString VirtualCurrency, int32 Amount);

	/** Decrements the user's balance of the specified virtual currency by the stated amount  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerSubtractUserVirtualCurrency(FString PlayFabId, FString VirtualCurrency, int32 Amount);

	/** Updates the key-value pair data tagged to the specified item, which is read-only from the client.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Player Item Management", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateUserInventoryItemCustomData(FString PlayFabId, FString ItemInstanceId,
		UPlayFabJsonObject* Data, FString CharacterId = "");

	// Matchmaking

	/** Informs the PlayFab match-making service that the user specified has left the Game Server Instance  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerNotifyMatchmakerPlayerLeft(FString PlayFabId, FString LobbyId);

	/** Validates a Game Server session ticket and returns details about the user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Matchmaking", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerRedeemMatchmakerTicket(FString Ticket, FString LobbyId);

	// Steam-Specific

	/** Awards the specified users the specified Steam achievements  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Steam Specific", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerAwardSteamAchievement(UPlayFabJsonObject* Achievements);

	// Analytics

	/** Logs a custom analytics event  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Analytics", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerLogEvent(FString EventName, UPlayFabJsonObject* Body, FString PlayFabId = "",
		FString EntityId = "", FString EntityType = "", bool PlayerEvent = true, bool ProfileSetEvent = false);

	// Shared Group Data

	/** Adds users to the set of those able to update both the shared data, as well as the set of users in the group.
	Only users in the group (and the server) can add new members.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerAddSharedGroupMembers(FString SharedGroupId, TArray<FString> PlayFabIds);

	/** Requests the creation of a shared group object, containing key/value pairs which may be updated by all members of
	the group. When created by a server, the group will initially have no members.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerCreateSharedGroup(FString SharedGroupId);

	/** Deletes a shared group, freeing up the shared group ID to be reused for a new group */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerDeleteSharedGroup(FString SharedGroupId);

	/** Retrieves the key-value store of custom publisher settings */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetPublisherData(TArray<FString> Keys);

	/** Retrieves data stored in a shared group object, as well as the list of members in the group.
	The server can access all public and private group data.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetSharedGroupData(FString SharedGroupId, TArray<FString> Keys, bool GetMembers = true);

	/** Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the group can remove members.
	If as a result of the call, zero users remain with access, the group and its associated data will be deleted.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerRemoveSharedGroupMembers(FString SharedGroupId, TArray<FString> PlayFabIds);

	/** Updates the key-value store of custom publisher settings  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerSetPublisherData(FString Key, FString Value);

	/** Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated or added in this call will be readable
	by users not in the group. By default, data permissions are set to Private. Regardless of the permission setting, only members of the group (and the server) can
	update the data. */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Shared Group Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateSharedGroupData(FString SharedGroupId, UPlayFabJsonObject* Data, EUserDataPermision::Type Permission);

	// Content

	/** Retrieves the pre-authorized URL for accessing a content file for the title. A subsequent HTTP GET to the returned URL downloads the content; or a HEAD
	query to the returned URL retrieves the metadata of the content. This API only generates a pre-signed URL to access the content. A success result does not
	guarantee the existence of the content.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Content", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetContentDownloadUrl(FString Key, FString HttpMethod = "", bool ThruCDN = true);

	// Characters

	/** Deletes the specific character ID from the specified user.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerDeleteCharacterFromUser(FString PlayFabId, FString CharacterId, bool SaveCharacterInventory = false);

	/** Lists all of the characters that belong to a specific user. */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetAllUsersCharacters(FString PlayFabId);

	/** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetCharacterLeaderboard(FString CharacterId, FString StatisticName, int32 MaxResultsCount,
		FString CharacterType = "", int32 StartPosition = 0);

	/** Retrieves the details of all title-specific statistics for the specific character */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetCharacterStatistics(FString PlayFabId, FString CharacterId);

	/** Retrieves a list of ranked characters for the given statistic, centered on the requested user  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetLeaderboardAroundCharacter(FString PlayFabId, FString CharacterId, FString StatisticName, int32 MaxResultsCount,
		FString CharacterType = "");

	/** Retrieves a list of all of the user's characters for the given statistic.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetLeaderboardForUserCharacters(FString PlayFabId, FString StatisticName, int32 MaxResultsCount);

	/** Grants the specified character type to the user. */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGrantCharacterToUser(FString PlayFabId, FString CharacterType, FString CharacterName);

	/** Updates the values of the specified title-specific statistics for the specific character  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Characters", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateCharacterStatistics(FString PlayFabId, FString CharacterId, UPlayFabJsonObject* CharacterStatistics);

	// Character Data

	/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetCharacterData(FString PlayFabId, FString CharacterId, TArray<FString> Keys, int32 IfChangedFromDataVersion = 0);

	/** Retrieves the title-specific custom data for the user's character which cannot be accessed by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetCharacterInternalData(FString PlayFabId, FString CharacterId, TArray<FString> Keys, int32 IfChangedFromDataVersion = 0);

	/** Retrieves the title-specific custom data for the user's character which can only be read by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerGetCharacterReadOnlyData(FString PlayFabId, FString CharacterId, TArray<FString> Keys, int32 IfChangedFromDataVersion = 0);

	/** Updates the title-specific custom data for the user's chjaracter which is readable and writable by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateCharacterData(FString PlayFabId, FString CharacterId, UPlayFabJsonObject* Data, EUserDataPermision::Type Permission);

	/** Updates the title-specific custom data for the user's character which cannot be accessed by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateCharacterInternalData(FString PlayFabId, FString CharacterId, UPlayFabJsonObject* Data, EUserDataPermision::Type Permission);

	/** Updates the title-specific custom data for the user's character which can only be read by the client  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Server | Character Data", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* ServerUpdateCharacterReadOnlyData(FString PlayFabId, FString CharacterId, UPlayFabJsonObject* Data, EUserDataPermision::Type Permission);

	/// Admin

	// Account Management

	// Player Data Management

	// Title-Wide Management

	// Player Item Management

	// Matchmaking

	// Custom Server Management

	// Shared Group Data

	// Server-Side Cloud Script

	/** Gets the contents and information of a specific Cloud Script revision.  */
	UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server Side Cloud Script", meta = (BlueprintInternalUseOnly = "true"))
		static UPlayFabRequestProxy* GetCloudScriptRevision(FString Version, FString Revision);

	// Content

	/** PlayFab Request Info */
	FString PlayFabClass;
	FString PlayFabSessionToken;
	FString CloudScriptVersion;
	bool isAdmin = false;
	bool isServer = false;
	bool isClient = false;
	bool useSecretKey = false;
	bool useSessionTicket = false;
	bool cloudScript = false;

	/** Is the response valid JSON? */
	bool bIsValidJsonResponse;
	FString ResponseContent;
	int32 ResponseCode;

private:
	/** Internal bind function for the IHTTPRequest::OnProcessRequestCompleted() event */
	void OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

protected:

	/** PlayFab App Id */
	static FString PlayFabAppId;

	/** PlayFab Api Key */
	static FString PlayFabApiKey;
	static FString PhotonRealtimeAppId;
	static FString PhotonTurnbasedAppId;
	static FString PhotonChatAppId;

	/** PlayFab URL */
	static FString PlayFabURL;
	static FString PlayFabLogicURL;

	/** Internal request data stored as JSON */
	UPROPERTY()
	UPlayFabJsonObject* RequestJsonObj;

	/** Response data stored as JSON */
	UPROPERTY()
	UPlayFabJsonObject* ResponseJsonObj;

	/** Mapping of header section to values. Used to generate final header string for request */
	TMap<FString, FString> RequestHeaders;
};