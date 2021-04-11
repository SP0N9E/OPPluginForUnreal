// Fill out your copyright notice in the Description page of Project Settings.

#include "OPOutputParser.h"
#include <string>
//General Log
DEFINE_LOG_CATEGORY(OPOutputParserLOG);

OPOutputParser::OPOutputParser()
{
}

OPOutputParser::~OPOutputParser()
{
}

void OPOutputParser::ParseOutput(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray, OutputType type)
{
	switch (type)
	{
	case OutputType::None: break;
	case OutputType::DatumsInfo: ParseDatumsInfo(datum, ptrArray, sizeArray);
		break;
	case OutputType::Name: ParseName(datum, ptrArray, sizeArray);
		break;
	case OutputType::PoseKeypoints: ParsePoseKeypoints(datum, ptrArray, sizeArray);
		break;
	case OutputType::PoseIds: ParsePoseIds(datum, ptrArray, sizeArray);
		break;
	case OutputType::PoseScores: ParsePoseScores(datum, ptrArray, sizeArray);
		break;
	case OutputType::FaceRectangles: ParseFaceRectangles(datum, ptrArray, sizeArray);
		break;
	case OutputType::FaceKeypoints: ParseFaceKeypoints(datum, ptrArray, sizeArray);
		break;
	case OutputType::HandRectangles: ParseHandRectangles(datum, ptrArray, sizeArray);
		break;
	case OutputType::HandKeypoints: ParseHandKeypoints(datum, ptrArray, sizeArray);
		break;
	case OutputType::Image: ParseImage(datum, ptrArray, sizeArray);
		break;
	default:
		break;
	}
}

void OPOutputParser::ParseDatumsInfo(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 4)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseDatumsInfo DatumsInfo array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseDatumsInfo DatumsInfo size length invalid: %d"), sizeArray.Num());
	}
	int64* lp_0 = static_cast<int64*>(const_cast<void*>(ptrArray[0]));
	int64* lp_1 = static_cast<int64*>(const_cast<void*>(ptrArray[1]));
	int64* lp_2 = static_cast<int64*>(const_cast<void*>(ptrArray[2]));
	int64* lp_3 = static_cast<int64*>(const_cast<void*>(ptrArray[3]));
	datum.id = (uint64)(*lp_0);
	datum.subId = (uint64)(*lp_1);
	datum.subIdMax = (uint64)(*lp_2);
	datum.frameNumber = (uint64)(*lp_3);
	UE_LOG(OPOutputParserLOG, Warning, TEXT("Function ParseDatumsInfo(id to framenumber) : %d, %d, %d, %d"), datum.id, datum.subId, datum.subIdMax, datum.frameNumber);
}

void OPOutputParser::ParseName(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseName Name array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseName Name size length invalid: %d"), sizeArray.Num());
	}
	auto namePtr = static_cast<std::string*>(const_cast<void*>(ptrArray[0]));
	auto name = *namePtr;
	FString fname(name.c_str());
	datum.name = fname;
	UE_LOG(OPOutputParserLOG, Warning, TEXT("Function ParseName Name : %s"), *fname);
}

void OPOutputParser::ParsePoseKeypoints(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParsePoseKeypoints PoseKeypoints array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 3)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParsePoseKeypoints PoseKeypoints size length invalid: %d"), sizeArray.Num());
	}
	int volume = 1;
	for (int i = 0; i < sizeArray.Num(); i++)
	{
		volume *= sizeArray[i];
	}
	if (volume == 0) return;
	float* fArrayPtr = static_cast<float*>(const_cast<void*>(ptrArray[0]));
	TArray<float> valArray(fArrayPtr, volume);
	datum.poseKeypoints = MultiArray<float>(valArray, sizeArray);
}

void OPOutputParser::ParsePoseIds(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParsePoseIds PoseIds array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParsePoseIds PoseIds size length invalid: %d"), sizeArray.Num());
	}
	int volume = 1;
	for (int i = 0; i < sizeArray.Num(); i++)
	{
		volume *= sizeArray[i];
	}
	if (volume == 0) return;
	long* fArrayPtr = static_cast<long*>(const_cast<void*>(ptrArray[0]));
	TArray<long> valArray(fArrayPtr, volume);

	datum.poseIds = MultiArray<long>(valArray, sizeArray);
}

void OPOutputParser::ParsePoseScores(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParsePoseScores PoseScores array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParsePoseScores PoseScores size length invalid: %d"), sizeArray.Num());
	}
	int volume = 1;
	for (int i = 0; i < sizeArray.Num(); i++)
	{
		volume *= sizeArray[i];
	}
	if (volume == 0) return;

	float* fArrayPtr = static_cast<float*>(const_cast<void*>(ptrArray[0]));
	TArray<float> valArray(fArrayPtr, volume);
	datum.poseScores = MultiArray<float>(valArray, sizeArray);
}

void OPOutputParser::ParsePoseHeatMaps(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParsePoseHeatMaps PoseHeatMaps array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 3)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParsePoseHeatMaps PoseHeatMaps size length invalid: %d"), sizeArray.Num());
	}
	int volume = 1;
	for (int i = 0; i < sizeArray.Num(); i++)
	{
		volume *= sizeArray[i];
	}
	if (volume == 0) return;

	float* fArrayPtr = static_cast<float*>(const_cast<void*>(ptrArray[0]));
	TArray<float> valArray(fArrayPtr, volume);
	datum.poseHeatMaps = MultiArray<float>(valArray, sizeArray);
}

void OPOutputParser::ParseHandKeypoints(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 2)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseHandKeypoints HandKeypoints array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 3)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseHandKeypoints HandKeypoints size length invalid: %d"), sizeArray.Num());
	}
	int volume = 1;
	for (int i = 0; i < sizeArray.Num(); i++)
	{
		volume *= sizeArray[i];
	}
	if (volume == 0) return;

	// Left
	float* fArrayPtrL = static_cast<float*>(const_cast<void*>(ptrArray[0]));
	TArray<float> valArrayL(fArrayPtrL, volume);
	auto handKeypointsL = MultiArray<float>(valArrayL, sizeArray);
	// Right
	float* fArrayPtrR = static_cast<float*>(const_cast<void*>(ptrArray[1]));
	TArray<float> valArrayR(fArrayPtrR, volume);
	auto handKeypointsR = MultiArray<float>(valArrayR, sizeArray);

	datum.handKeypoints = Pair<MultiArray<float>>(handKeypointsL, handKeypointsR);
}

void OPOutputParser::ParseHandRectangles(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 2)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseHandRectangles HandKeypoints size length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray[0] != 3 || sizeArray[1] != 4)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseHandRectangles HandKeypoints sizes invalid"));
	}
	/// TODO: Need to do sth here
	/*datum.handRectangles = new List<Pair<Rect>>();
	foreach(var ptr in ptrArray) {
		var tempData = new float[8];
		Marshal.Copy(ptr, tempData, 0, 8);
		Rect left = new Rect(tempData[0], tempData[1], tempData[2], tempData[3]);
		Rect right = new Rect(tempData[4], tempData[5], tempData[6], tempData[7]);
		datum.handRectangles.Add(new Pair<Rect>(left, right));
	}*/
	TArray<Pair<Rect>> rectanglesArray;
	for (int i = 0; i< ptrArray.Num(); i++)
	{
		float* fArrayPtr = static_cast<float*>(const_cast<void*>(ptrArray[i]));
		TArray<float> valArray(fArrayPtr, 8);
		Rect left(valArray[0], valArray[1], valArray[2], valArray[3]);
		Rect right(valArray[4], valArray[5], valArray[6], valArray[7]);
		rectanglesArray.Add(Pair<Rect>(left, right));
	}
	datum.handRectangles = rectanglesArray;
}

void OPOutputParser::ParseHandHeatMaps(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 2)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseHandHeatMaps HandHeatMaps array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 4)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseHandHeatMaps HandHeatMaps size length invalid: %d"), sizeArray.Num());
	}
	int volume = 1;
	for (int i = 0; i < sizeArray.Num(); i++)
	{
		volume *= sizeArray[i];
	}
	if (volume == 0) return;

	// Left
	float* fArrayPtrL = static_cast<float*>(const_cast<void*>(ptrArray[0]));
	TArray<float> valArrayL(fArrayPtrL, volume);
	auto handHeatMapsL = MultiArray<float>(valArrayL, sizeArray);
	// Right
	float* fArrayPtrR = static_cast<float*>(const_cast<void*>(ptrArray[1]));
	TArray<float> valArrayR(fArrayPtrR, volume);
	auto handHeatMapsR = MultiArray<float>(valArrayR, sizeArray);

	datum.handHeatMaps = Pair<MultiArray<float>>(handHeatMapsL, handHeatMapsR);
}

void OPOutputParser::ParseFaceKeypoints(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseFaceKeypoints FaceKeypoints array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 3)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseFaceKeypoints FaceKeypoints size length invalid: %d"), sizeArray.Num());
	}
	int volume = 1;
	for (int i = 0; i < sizeArray.Num(); i++)
	{
		volume *= sizeArray[i];
	}
	if (volume == 0) return;

	float* fArrayPtr = static_cast<float*>(const_cast<void*>(ptrArray[0]));
	TArray<float> valArray(fArrayPtr, volume);
	datum.faceKeypoints = MultiArray<float>(valArray, sizeArray);
}

void OPOutputParser::ParseFaceRectangles(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if(ptrArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseFaceRectangles FaceRect array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 2)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseFaceRectangles FaceRect size length invalid: %d"), sizeArray.Num());
	}
	int volume = 1;
	for (int i = 0; i < sizeArray.Num(); i++)
	{
		volume *= sizeArray[i];
	}
	if (volume == 0) return;

	float* fArrayPtr = static_cast<float*>(const_cast<void*>(ptrArray[0]));
	TArray<float> valArray(fArrayPtr, volume);
	// Using Rect here
	TArray<Rect> rectArray;
	for (int i = 0; i < sizeArray[0]; i++)
	{
		Rect rect(valArray[i * 4 + 0], valArray[i * 4 + 1], valArray[i * 4 + 2], valArray[i * 4 + 3]);
		rectArray.Add(rect);
	}
	datum.faceRectangles = rectArray;
}

void OPOutputParser::ParseFaceHeatMaps(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseFaceHeatMaps FaceHeatMaps array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 4)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseFaceHeatMaps FaceHeatMaps size length invalid: %d"), sizeArray.Num());
	}
	int volume = 1;
	for (int i = 0; i < sizeArray.Num(); i++)
	{
		volume *= sizeArray[i];
	}
	if (volume == 0) return;

	float* fArrayPtr = static_cast<float*>(const_cast<void*>(ptrArray[0]));
	TArray<float> valArray(fArrayPtr, volume);
	datum.faceHeatMaps = MultiArray<float>(valArray, sizeArray);
}

void OPOutputParser::ParseImage(OPDatum & datum, const TArray<void*>& ptrArray, const TArray<int>& sizeArray)
{
	if (ptrArray.Num() != 1)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseImage Image array length invalid: %d"), ptrArray.Num());
	}
	if (sizeArray.Num() != 3)
	{
		UE_LOG(OPOutputParserLOG, Error, TEXT("Function ParseImage Image size length invalid: %d"), sizeArray.Num());
	}
	int volume = 1;
	for (int i = 0; i < sizeArray.Num(); i++)
	{
		volume *= sizeArray[i];
	}
	if (volume == 0) return;

	uint8* fArrayPtr = static_cast<uint8*>(const_cast<void*>(ptrArray[0]));
	TArray<uint8> valArray(fArrayPtr, volume);
	datum.cvInputData = MultiArray<uint8>(valArray, sizeArray);
}
