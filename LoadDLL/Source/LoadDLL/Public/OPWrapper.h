// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OPDatums.h"
//#include "LoadDLLBPLibrary.h"
#include "SimpleThread.h"
#include "Queue.h"
#include <queue>
#include <thread>

#include "OPOutputParser.h"


/**
 * 
 */
class LOADDLL_API OPWrapper
{
public:
#pragma region properties

	static OPDatum currentData;
	//static TQueue<OPDatum> dataBuffer;
	static std::queue<OPDatum> dataBuffer;
	//static Thread opThread;
#pragma endregion
public:
	OPWrapper();
	~OPWrapper();
	static OPState opState;
	static void OPRegisterCallbacks();
	// Enable debug message from OpenPose (default true). Can set in run-time
	static void OPEnableDebug(bool enable);
	// Enable receiving output from OpenPose (default true). Can set in run-time
	static void OPEnableOutput(bool enable);
	// Enable receiving camera image from OpenPose (default false). Can set in run-time
	static void OPEnableImageOutput(bool enable);
	// Lazy way to configure all parameters in default
	static void OPConfigureAllInDefault() {
		OPConfigurePose();
		OPConfigureHand();
		OPConfigureFace();
		OPConfigureExtra();
		OPConfigureInput();
		OPConfigureOutput();
		OPConfigureGui();
		OPConfigureDebugging();
	}
	// Start OpenPose thread with last configuration parameters
	static void OPRun();
	
	// Get NEXT output frame. Note that frame is possible to be omitted if buffer size overflow. 
	static bool OPGetOutput(OPDatum& data);

	// Stop OpenPose if running
	static void OPShutDown();

	// Pose parameter configuration (with default value)
	// Please refer to OpenPose documentation for parameter explanation
	static void OPConfigurePose(
		PoseMode poseMode = PoseMode::Enabled, int netInputSizeX = -1, int netInputSizeY = 368,
		int outputSizeX = -1, int outputSizeY = -1,
		ScaleMode keypointScaleMode = ScaleMode::InputResolution,
		int gpuNumber = -1, int gpuNumberStart = 0, int scalesNumber = 1, float scaleGap = 0.25f,
		RenderMode renderMode = RenderMode::Auto, PoseModel poseModel = PoseModel::BODY_25,
		bool blendOriginalFrame = true, float alphaKeypoint = 0.6f, float alphaHeatMap = 0.7f,
		int defaultPartToRender = 0, FString modelFolder = "",
		HeatMapType heatMapTypes = HeatMapType::None, ScaleMode heatMapScaleMode = ScaleMode::ZeroToOne,
		bool addPartCandidates = false, float renderThreshold = 0.05f, int numberPeopleMax = -1,
		bool maximizePositives = false, double fpsMax = -1.0,
		FString protoTxtPath = "", FString caffeModelPath = "", float upsamplingRatio = 0.0f);

	// Hand parameter configuration (with default value)
	// Please refer to OpenPose documentation for parameter explanation
	static void OPConfigureHand(
		bool enable = false, Detector detector = Detector::Body,
		int netInputSizeX = 368, int netInputSizeY = 368,
		int scalesNumber = 1, float scaleRange = 0.4f, RenderMode renderMode = RenderMode::Auto,
		float alphaKeypoint = 0.6f, float alphaHeatMap = 0.7f, float renderThreshold = 0.2f);
	// Face parameter configuration (with default value)
	// Please refer to OpenPose documentation for parameter explanation
	static void OPConfigureFace(
		bool enable = false, Detector detector = Detector::Body,
		int netInputSizeX = 368, int netInputSizeY = 368,
		RenderMode renderMode = RenderMode::Auto,
		float alphaKeypoint = 0.6f, float alphaHeatMap = 0.7f, float renderThreshold = 0.4f);
	// Extra parameter configuration (with default value)
	// NOTICE: 3D output is not yet supported
	// Please refer to OpenPose documentation for parameter explanation
	static void OPConfigureExtra(
		bool reconstruct3d = false, int minViews3d = -1, bool identification = false,
		int tracking = -1, int ikThreads = 0);
	// Input parameter configuration (with default value)
	// Please refer to OpenPose documentation for parameter explanation
	static void OPConfigureInput(
		ProducerType producerType = ProducerType::None, FString producerString = "-1",
		uint64 frameFirst = 0, uint64 frameStep = 1, uint64 frameLast = LONG_MAX,
		bool realTimeProcessing = false, bool frameFlip = false,
		int frameRotate = 0, bool framesRepeat = false,
		int cameraResolutionX = -1, int cameraResolutionY = -1, FString cameraParameterPath = "",
		bool undistortImage = false, int numberViews = -1);
	// Output parameter configuration (with default value)
	// Please refer to OpenPose documentation for parameter explanation
	static void OPConfigureOutput(
		double verbose = -1.0, FString writeKeypoint = "", DataFormat writeKeypointFormat = DataFormat::Xml,
		FString writeJson = "", FString writeCocoJson = "", int writeCocoJsonVariants = 1,
		int writeCocoJsonVariant = 1, FString writeImages = "", FString writeImagesFormat = "png",
		FString writeVideo = "", double writeVideoFps = -1.0, bool writeVideoWithAudio = false, FString writeHeatMaps = "",
		FString writeHeatMapsFormat = "png", FString writeVideo3D = "", FString writeVideoAdam = "",
		FString writeBvh = "", FString udpHost = "", FString udpPort = "8051");
	// GUI parameter configuration (with default value)
	// Please refer to OpenPose documentation for parameter explanation
	static void OPConfigureGui(
		DisplayMode displayMode = DisplayMode::NoDisplay,
		bool guiVerbose = false, bool fullScreen = false);
	// Debugging parameter configuration (with default value)
	// Please refer to OpenPose documentation for parameter explanation
	static void OPConfigureDebugging(
		Priority loggingLevel = Priority::High, // Priority
		bool disableMultiThread = false, uint64 profileSpeed = 1000);
	static void OPLog(const char* const message, int type)
	{
		FString Fmessgae(message);
		switch (type)
		{
		case 0: UE_LOG(LogTemp, Warning, TEXT("OP_LOG: %s"), *Fmessgae); break;
		case 1: UE_LOG(LogTemp, Warning, TEXT("OP_Warning: %s"), *Fmessgae); break;
		case -1: UE_LOG(LogTemp, Error, TEXT("OP_Error: %s"), *Fmessgae); break;
		default: UE_LOG(LogTemp, Warning, TEXT("OPLog type invalid")); break;
		}
	}

	static void OPOutput(void * ptrs, int ptrSize, int * sizes, int sizeSize, uint8 outputType)
	{
		//UE_LOG(LogTemp, Warning, TEXT("enter OPOutput!!!!!!"));
		if ((OutputType)outputType == OutputType::None)
		{
			OPWrapper::dataBuffer.push(OPWrapper::currentData);
			OPDatum currentData_temp;
			OPWrapper::currentData = currentData_temp;
			// Control the buffer soze no greater than 10
			if (OPWrapper::dataBuffer.size() > 10)
			{
				OPWrapper::dataBuffer.pop();
			}
			return;
		}
		// Safety check
		if (ptrSize < 0 || sizeSize < 0) return;

		// Parse ptrPtr to ptrAray 
		/// TODO: still don't know how to solve this
		/// UPDATE: param 'ptrs' is actually ptrPtr, see openpose source UnityBinding.cpp line 89
		/// so transform void* into void**
		auto ptrPtr = static_cast<void**>(ptrs);
		//auto ptrPtr = (void**)ptrs;
		TArray<void*> ptrArray(ptrPtr, ptrSize);

		// Parse sizePtr to sizeArray
		TArray<int> sizeArray(sizes, sizeSize);
		
		// Write output to data struct
		OPOutputParser::ParseOutput(OPWrapper::currentData, ptrArray, sizeArray, (OutputType)outputType);
	}
	
	//OutputCallback OPOutputCallback = OPOutput;

	static void OPExecuteThread();

private:


};




