// Copyright 2016 bitHeads, Inc. All Rights Reserved.

#pragma once

#include "BCBlueprintCallProxyBase.h"
#include "IServerCallback.h"
#include "BCProductProxy.generated.h"

UCLASS(MinimalAPI)
class UBCProductProxy : public UBCBlueprintCallProxyBase, public IServerCallback
{
    GENERATED_BODY()

public:
    UBCProductProxy(const FObjectInitializer& ObjectInitializer);

    /**
    * Gets the player's currency for the given currency type
    * or all currency types if null passed in.
    *
    * Service Name - Product
    * Service Operation - GetPlayerVC
    *
    * Param - currencyType The currency type to retrieve or null
    * if all currency types are being requested.
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* GetCurrency(const FString& currencyType);

	/**
	* @deprecated Method is now available in Cloud Code only for security - removal after March 22 2016
	*/
	DEPRECATED("3.2.0", "Method is now available in Cloud Code only for security - removal after March 22 2016")
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* AwardCurrency(const FString& currencyType, int32 amount);

	/**
	* @deprecated Method is now available in Cloud Code only for security - removal after March 22 2016
	*/
	DEPRECATED("3.2.0", "Method is now available in Cloud Code only for security - removal after March 22 2016")
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* ConsumeCurrency(const FString& currencyType, int32 amount);

	/**
	* @deprecated Method is now available in Cloud Code only for security - removal after March 22 2016
	*/
	DEPRECATED("3.2.0", "Method is now available in Cloud Code only for security - removal after March 22 2016")
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* ResetCurrency();

    /**
    * Method gets the active sales inventory for the passed-in platform and
    * currency type.
    *
    * Service Name - Product
    * Service Operation - GetInventory
    *
    * Param - platform The store platform. Valid stores are:
    * - itunes
    * - facebook
    * - appworld
    * - steam
    * - windows
    * - windowsPhone
    * - googlePlay
    * Param - userCurrency The currency to retrieve the sales
    * inventory for. This is only used for Steam and Facebook stores.
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* GetSalesInventory(const FString& platform, const FString& userCurrency);

    /**
    * Method gets the active sales inventory for the passed-in platform,
    * currency type and category.
    *
    * Service Name - Product
    * Service Operation - GetInventory
    *
    * Param - platform The store platform. Valid stores are:
    * - itunes
    * - facebook
    * - appworld
    * - steam
    * - windows
    * - windowsPhone
    * - googlePlay
    * Param - userCurrency The currency to retrieve the sales
    * inventory for. This is only used for Steam and Facebook stores.
    * Param - category Inventory category to retrieve
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* GetSalesInventoryByCategory(const FString& platform, const FString& userCurrency, const FString& category);

    /**
    * Method verifies an iTunes receipt and awards the items related to this receipt.
    *
    * Service Name - Product
    * Server Operation - OP_CASH_IN_RECEIPT
    *
    * Param - base64EncReceiptData The iTunes receipt
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* VerifyItunesReceipt(const FString& base64EncReceiptData);

    /**
    * Initialize Steam Transaction
    *
    * Service Name - Product
    * Service Operation - StartSteamTransaction
    *
    * Param - language ISO 639-1 language code
    * Param - items Items to purchase
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* StartSteamTransaction(const FString& language, const FString& itemId);

    /**
    * Finalize Steam Transaction
    *
    * Service Name - Product
    * Service Operation - FinalizeSteamTransaction
    *
    * Param - transId Steam transaction id
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* FinalizeSteamTransaction(const FString& transId);

    /**
    * Verify Microsoft Receipt
    *
    * Service Name - Product
    * Service Operation - VerifyMicrosoftReceipt
    *
    * Param - receipt Receipt XML
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* VerifyMicrosoftReceipt(const FString& receipt);

    /**
    * Confirms a google play purchase. On success, the player will be awarded the
    * associated currencies.
    *
    * Service Name - Product
    * Server Operation - CONFIRM_GOOGLEPLAY_PURCHASE
    *
    * Param - orderId The order id
    * Param - productId The product id
    * Param - token Google Play token string
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* ConfirmGooglePlayPurchase(const FString& orderId, const FString& productId, const FString& token);

    /**
    * Get Eligible Promotions
    *
    * Service Name - Product
    * Service Operation - GetEligiblePromotions
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Product")
        static UBCProductProxy* GetEligiblePromotions();

    //Response delegates
    UPROPERTY(BlueprintAssignable)
        FBrainCloudCallbackDelegate OnSuccess;

    UPROPERTY(BlueprintAssignable)
        FBrainCloudCallbackDelegate OnFailure;

protected:
    // IServerCallback interface
    void serverCallback(ServiceName serviceName, ServiceOperation serviceOperation, const FString& jsonData);
    void serverError(ServiceName serviceName, ServiceOperation serviceOperation, int32 statusCode, int32 reasonCode, const FString& jsonError);
    // End of IServerCallback interface
};