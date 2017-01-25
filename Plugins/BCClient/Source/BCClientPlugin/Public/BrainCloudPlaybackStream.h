// Copyright 2016 bitHeads, Inc. All Rights Reserved.

#pragma once

class BrainCloudClient;
class IServerCallback;

class BCCLIENTPLUGIN_API BrainCloudPlaybackStream
{
public:
    BrainCloudPlaybackStream(BrainCloudClient* client);

    /**
    * Starts a stream
    *
    * Service Name - PlaybackStream
    * Service Operation - StartStream
    *
    * @param targetPlayerId The player to start a stream with
    * @param includeSharedData Whether to include shared data in the stream
    * @param callback The method to be invoked when the server response is received
    */
    void startStream(const FString& targetPlayerId, bool includeSharedData, IServerCallback * callback);

    /**
    * Reads a stream
    *
    * Service Name - PlaybackStream
    * Service Operation - ReadStream
    *
    * @param playbackStreamId Identifies the stream to read
    * @param callback The method to be invoked when the server response is received
    */
    void readStream(const FString& playbackStreamId, IServerCallback * callback);

    /**
    * Ends a stream
    *
    * Service Name - PlaybackStream
    * Service Operation - EndStream
    *
    * @param playbackStreamId Identifies the stream to read
    * @param callback The method to be invoked when the server response is received
    */
    void endStream(const FString& playbackStreamId, IServerCallback * callback);

    /**
    * Deletes a stream
    *
    * Service Name - PlaybackStream
    * Service Operation - DeleteStream
    *
    * @param playbackStreamId Identifies the stream to read
    * @param callback The method to be invoked when the server response is received
    */
    void deleteStream(const FString& playbackStreamId, IServerCallback * callback);

    /**
    * Adds a stream event
    *
    * Service Name - PlaybackStream
    * Service Operation - AddEvent
    *
    * @param playbackStreamId Identifies the stream to read
    * @param jsonEventData Describes the event
    * @param jsonSummary Current summary data as of this event
    * @param callback The method to be invoked when the server response is received
    */
    void addEvent(const FString& playbackStreamId, const FString& jsonEventData, const FString& jsonSummary, IServerCallback * callback);

    /**
    * Gets stream summaries for initiating player
    *
    * Service Name - PlaybackStream
    * Service Operation - GetStreamSummariesForInitiatingPlayer
    *
    * @param initiatingPlayerId The player that started the stream
    * @param callback The method to be invoked when the server response is received
    */
    void getStreamSummariesForInitiatingPlayer(const FString& initiatingPlayerId, IServerCallback * callback);

    /**
    * Gets stream summaries for target player
    *
    * Service Name - PlaybackStream
    * Service Operation - GetStreamSummariesForTargetPlayer
    *
    * @param targetPlayerId The player that started the stream
    * @param callback The method to be invoked when the server response is received
    */
    void getStreamSummariesForTargetPlayer(const FString& targetPlayerId, IServerCallback * callback);

private:
    BrainCloudClient* _client = nullptr;
};