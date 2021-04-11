// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OPDatums.h"

//General Log
DECLARE_LOG_CATEGORY_EXTERN(OPOutputParserLOG, Log, All);
/**
 * 
 */
class LOADDLL_API OPOutputParser
{
public:
	OPOutputParser();
	~OPOutputParser();
	// All parse output method act through this function
	static void ParseOutput(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray, OutputType type);
	// Parse id, subId, subIdMax, frameNumber
	static void ParseDatumsInfo(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse name
	static void ParseName(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse poseKeyPoints
	static void ParsePoseKeypoints(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse poseIds
	static void ParsePoseIds(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse pose Scores
	static void ParsePoseScores(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse pose HeatMaps
	static void ParsePoseHeatMaps(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse handKeypoints
	static void ParseHandKeypoints(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse handRectangles
	static void ParseHandRectangles(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse handHeatMaps
	static void ParseHandHeatMaps(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse faceKeypoints
	static void ParseFaceKeypoints(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse faceRectangles
	static void ParseFaceRectangles(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse faceHeatmaps
	static void ParseFaceHeatMaps(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
	// Parse cvInputData
	static void ParseImage(OPDatum& datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray);
};
