// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OPEnums.h"
#include "OPDatums.h"
#include "Misc/Paths.h"
//#include "OPWrapper.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/LineBatchComponent.h"
#include "LoadDLLBPLibrary.generated.h"


// Define callback function
typedef void(__stdcall * OutputCallback) (void * ptrs, int ptrSize, int * sizes, int sizeSize, uint8 outputType);
typedef void(__stdcall * DebugCallback) (const char* const str, int type);
//typedef void(__stdcall * DebugCallback) (FString message, int type);

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class ULoadDLLBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "LoadDLL sample test testing"), Category = "LoadDLLTesting")
	static float LoadDLLSampleFunction(float Param);

	//导入dll
	UFUNCTION(BlueprintCallable, Category = "LoadDLLTesting")
		static bool importDLL(FString folder, FString name);
	UFUNCTION(BlueprintCallable, Category = "LoadDLLTesting")
		static bool importAllMethod_UE();
	//获取dll中的方法的指针
	UFUNCTION(BlueprintCallable, Category = "LoadDLLTesting")
		static bool importMethod_OPSetOutputEnable();
	//调用dll里面的方法
	UFUNCTION(BlueprintCallable, Category = "LoadDLLTesting")
		static void get_OPSetOutputEnableFromDll(bool enable);
	//释放dll
	UFUNCTION(BlueprintCallable, Category = "LoadDLLTesting")
		static void freeDLL();
	// openpose中导出的函数
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPRegisterOutputCallback(void(*OutputCallback) (void *, int, int *, int, uint8));
		static void M_OPRegisterOutputCallback_test(OutputCallback Callback);
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPRegisterDebugCallback(void(*DebugCallback) (const char* const, int));
		static void M_OPRun();
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPShutdown();
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPSetDebugEnable(bool enable);
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPSetOutputEnable(bool enable);
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPSetImageOutputEnable(bool enable);
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPConfigurePose(PoseMode poseMode, int netInputSizeX, int netInputSizeY,
			int outputSizeX, int outputSizeY, ScaleMode keypointScaleMode,
			int gpuNumber, int gpuNumberStart, int scalesNumber, float scaleGap,
			RenderMode renderMode, PoseModel poseModel,
			bool blendOriginalFrame, float alphaKeypoint, float alphaHeatMap,
			int defaultPartToRender, FString modelFolder,
			HeatMapType heatMapTypes, ScaleMode heatMapScaleMode,
			bool addPartCandidates, float renderThreshold, int numberPeopleMax,
			bool maximizePositives, double fpsMax,
			FString protoTxtPath, FString caffeModelPath, float upsamplingRatio);
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPConfigureHand(bool enable, Detector detector,
			int netInputSizeX, int netInputSizeY, int scalesNumber,
			float scaleRange, RenderMode renderMode, float alphaKeypoint,
			float alphaHeatMap, float renderThreshold);
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPConfigureFace(bool enable, Detector detector,
			int netInputSizeX, int netInputSizeY, RenderMode renderMode,
			float alphaKeypoint, float alphaHeatMap, float renderThreshold);
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPConfigureExtra(bool reconstruct3d, int minViews3d,
			bool identification, int tracking, int ikThreads);
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPConfigureInput(ProducerType producerType, FString producerString,
			uint64 frameFirst, uint64 frameStep, uint64 frameLast,
			bool realTimeProcessing, bool frameFlip, int frameRotate,
			bool framesRepeat, int cameraResolutionX, int cameraResolutionY,
			FString cameraParameterPath, bool undistortImage, int numberViews);
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPConfigureOutput(double verbose, FString writeKeypoint,
			DataFormat writeKeypointFormat, FString writeJson, FString writeCocoJson,
			int writeCocoJsonVariants, int writeCocoJsonVariant, FString writeImages,
			FString writeImagesFormat, FString writeVideo, double writeVideoFps,
			bool writeVideoWithAudio, FString writeHeatMaps, FString writeHeatMapsFormat,
			FString writeVideo3D, FString writeVideoAdam, FString writeBvh,
			FString udpHost, FString udpPort);
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPConfigureGui(DisplayMode displayMode, bool guiVerbose, bool fullScreen);
	//UFUNCTION(BlueprintCallable, Category = "LoadDLLOPMethod")
		static void M_OPConfigureDebugging(Priority loggingLevel, bool disableMultiThread, uint64 profileSpeed);
	
	static ProducerType m_inputType; 
	static FString m_producerString;
	static int m_maxPeople;
	static float m_renderThreshold;
	static bool m_handEnabled;
	static bool m_faceEnabled;
	static int m_netResolutionX;
	static int m_netResolutionY;
	static int m_handResolutionX;
	static int m_handResolutionY;
	static int m_faceResolutionX;
	static int m_faceResolutionY;
	static OPDatum m_Datum; // Output
	static int m_numberPeople;
	// set openpose parameters
	UFUNCTION(BlueprintCallable, Category = "OpenPoseUserLibrary")
		static void setAllUserParam(ProducerType inputType, FString producerString, int maxPeople, float renderThreshold,
			bool handEnabled, bool faceEnabled, int netResolutionX, int netResolutionY, int handResolutionX, int handResolutionY,
			int faceResolutionX, int faceResolutionY);
	// call this function after level blueprint start
	UFUNCTION(BlueprintCallable, Category = "OpenPoseUserLibrary")
		static void OpenposeStart();
	// Call this function every frame
	UFUNCTION(BlueprintCallable, Category = "OpenPoseUserLibrary")
		static void OpenposeUpdate();
	// Call this function every frame
	UFUNCTION(BlueprintCallable, Category = "OpenPoseUserLibrary")
		static void OpenposeUpdate_OutputData(TArray<FVector2D>& poseKeypoints, int32& numberPeople);
	// Call this function when the level ends
	UFUNCTION(BlueprintCallable, Category = "OpenPoseUserLibrary")
		static void OpenposeEnd();
	// Parameters can be set here
		static void UserConfigureOpenPose();
	
		void MyDebugDrawLine(const FVector& StartPost);
private:
	static TArray<FVector2D> getPoseKeypointsData(OPDatum& Datum, int32 BodyIdx, float RenderThreshold);


		
};



