// Copyright 2016 bitHeads, Inc. All Rights Reserved.

#pragma once

#include "BCBlueprintCallProxyBase.h"
#include "IServerCallback.h"
#include "BCGamificationProxy.generated.h"

UCLASS(MinimalAPI)
class UBCGamificationProxy : public UBCBlueprintCallProxyBase, public IServerCallback
{
    GENERATED_BODY()

public:
    UBCGamificationProxy(const FObjectInitializer& ObjectInitializer);

    /**
    * Method retrieves all gamification data for the player.
    *
    * Service Name - Gamification
    * Service Operation - Read
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadAllGamification(bool includeMetaData = false);

    /**
    * Method retrieves all milestones defined for the game.
    *
    * Service Name - Gamification
    * Service Operation - ReadMilestones
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadMilestones(bool includeMetaData = false);

    /**
    * Read all of the achievements defined for the game.
    *
    * Service Name - Gamification
    * Service Operation - ReadAchievements
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadAchievements(bool includeMetaData = false);

    /**
    * Method returns all defined xp levels and any rewards associated
    * with those xp levels.
    *
    * Service Name - Gamification
    * Service Operation - ReadXpLevels
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadXpLevelsMetaData();

    /**
    * Method retrives the list of achieved achievements.
    *
    * Service Name - Gamification
    * Service Operation - ReadAchievedAchievements
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadAchievedAchievements(bool includeMetaData = false);

    /**
    * Method retrieves the list of completed milestones.
    *
    * Service Name - Gamification
    * Service Operation - ReadCompleteMilestones
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadCompletedMilestones(bool includeMetaData = false);

    /**
    * Method retrieves the list of in progress milestones
    *
    * Service Name - Gamification
    * Service Operation - ReadInProgressMilestones
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadInProgressMilestones(bool includeMetaData = false);

    /**
    * Method retrieves milestones of the given category.
    *
    * Service Name - Gamification
    * Service Operation - ReadMilestonesByCategory
    *
    * Param - category The milestone category
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadMilestonesByCategory(FString category, bool includeMetaData = false);

    /**
    * Method will award the achievements specified. On success, this will
    * call AwardThirdPartyAchievement to hook into the client-side Achievement
    * service (ie GameCentre, Facebook etc).
    *
    * Service Name - Gamification
    * Service Operation - AwardAchievements
    *
    * Param - achievementIds A comma separated list of achievement ids to award
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* AwardAchievements(const TArray<FString>& achievements);

    /**
    * Resets the specified milestones' statuses to LOCKED.
    *
    * Service Name - Gamification
    * Service Operation - ResetMilestones
    *
    * Param - milestoneIds List of milestones to reset
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ResetMilestones(const TArray<FString>& milestoneIds);

    /**
    * Method retrieves all of the quests defined for the game.
    *
    * Service Name - Gamification
    * Service Operation - ReadQuests
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadQuests(bool includeMetaData = false);

    /**
    *  Method returns all completed quests.
    *
    * Service Name - Gamification
    * Service Operation - ReadCompletedQuests
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadCompletedQuests(bool includeMetaData = false);

    /**
    *  Method returns quests that are in progress.
    *
    * Service Name - Gamification
    * Service Operation - ReadInProgressQuests
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadInProgressQuests(bool includeMetaData = false);

    /**
    *  Method returns quests that have not been started.
    *
    * Service Name - Gamification
    * Service Operation - ReadNotStartedQuests
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadNotStartedQuests(bool includeMetaData = false);

    /**
    *  Method returns quests with a status.
    *
    * Service Name - Gamification
    * Service Operation - ReadQuestsWithStatus
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadQuestsWithStatus(bool includeMetaData = false);

    /**
    *  Method returns quests with a basic percentage.
    *
    * Service Name - Gamification
    * Service Operation - ReadQuestsWithBasicPercentage
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadQuestsWithBasicPercentage(bool includeMetaData = false);

    /**
    *  Method returns quests with a complex percentage.
    *
    * Service Name - Gamification
    * Service Operation - ReadQuestsWithComplexPercentage
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadQuestsWithComplexPercentage(bool includeMetaData = false);

    /**
    * Method returns quests for the given category.
    *
    * Service Name - Gamification
    * Service Operation - ReadQuestsByCategory
    *
    * Param - category The quest category
    */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "BrainCloud|Gamification")
        static UBCGamificationProxy* ReadQuestsByCategory(FString category, bool includeMetaData = false);

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