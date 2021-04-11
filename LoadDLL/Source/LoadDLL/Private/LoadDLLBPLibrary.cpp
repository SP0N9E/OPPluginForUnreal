// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LoadDLLBPLibrary.h"
#include "LoadDLL.h"
#include "OPWrapper.h"


ProducerType ULoadDLLBPLibrary::m_inputType = ProducerType::Webcam;
FString ULoadDLLBPLibrary::m_producerString = "-1";
int ULoadDLLBPLibrary::m_maxPeople = -1;
float ULoadDLLBPLibrary::m_renderThreshold = 0.05f;
bool ULoadDLLBPLibrary::m_handEnabled = false;
bool ULoadDLLBPLibrary::m_faceEnabled = false;
int ULoadDLLBPLibrary::m_netResolutionX = -1;
int ULoadDLLBPLibrary::m_netResolutionY = 368;
int ULoadDLLBPLibrary::m_handResolutionX = 368;
int ULoadDLLBPLibrary::m_handResolutionY = 368;
int ULoadDLLBPLibrary::m_faceResolutionX = 368;
int ULoadDLLBPLibrary::m_faceResolutionY = 368;
OPDatum ULoadDLLBPLibrary::m_Datum;
int ULoadDLLBPLibrary::m_numberPeople = 0;
//#ifdef _WIN32
//// Output callback register in Unity
//typedef void(__stdcall * OutputCallback) (void * ptrs, int ptrSize, int * sizes, int sizeSize, uint8 outputType);
//typedef void(__stdcall * DebugCallback) (FString message, int type);
//#endif


/*
* Send a callback function to openpose output. No output will be received if no callback is sent.
* Enable/disable the output callback. Can be set at runtime.
*/
typedef void(*_OPRegisterOutputCallback) (OutputCallback callback);
typedef void(*_OPSetOutputEnable) (bool enable);
_OPRegisterOutputCallback m_OPRegisterOutputCallback;
_OPSetOutputEnable m_OPSetOutputEnable;
/*
* Send a callback function to openpose logging system. No message will be received if no callback is sent.`
* The function will be called in op::log() or op::logError().
* Enable/disable the debug callback. Can be set at runtime.
*/
typedef void(*_OPRegisterDebugCallback)(DebugCallback callback);
typedef void(*_OPSetDebugEnable) (bool enable);
_OPRegisterDebugCallback m_OPRegisterDebugCallback;
_OPSetDebugEnable m_OPSetDebugEnable;
/*
 * Enable/disable image output callback. Disable will save some time since data is large.
 */
typedef void(*_OPSetImageOutputEnable) (bool enable);
_OPSetImageOutputEnable m_OPSetImageOutputEnable;
/*
* Run openpose if not running. It may take several seconds to fully start.
*/
typedef void(*_OPRun) ();
_OPRun m_OPRun;
/*
 * Shut down openpose program if it is running. It may take several seconds to fully stop it.
 */
typedef void(*_OPShutdown) ();
_OPShutdown m_OPShutdown;
/*
 * Openpose configurations - please read openpose documentation for explanation
 */
typedef void(*_OPConfigurePose) (
	uint8 poseMode,
	int netInputSizeX, int netInputSizeY, // Point
	int outputSizeX, int outputSizeY, // Point
	uint8 keypointScaleMode, // ScaleMode
	int gpuNumber, int gpuNumberStart, int scalesNumber, float scaleGap,
	uint8 renderMode, // RenderMode
	uint8 poseModel, // PoseModel
	bool blendOriginalFrame, float alphaKeypoint, float alphaHeatMap, int defaultPartToRender,
	char* modelFolder, bool heatMapAddParts, bool heatMapAddBkg,
	bool heatMapAddPAFs, // HeatMapType // uchar heatmap_type,
	uint8 heatMapScaleMode, // ScaleMode
	bool addPartCandidates, float renderThreshold, int numberPeopleMax,
	bool maximizePositives, double fpsMax, char* protoTxtPath, char* caffeModelPath, float upsamplingRatio);

typedef void(*_OPConfigureHand) (
	bool enable, uint8 detector, int netInputSizeX, int netInputSizeY, // Point
	int scalesNumber, float scaleRange,
	uint8 renderMode, // RenderMode
	float alphaKeypoint, float alphaHeatMap, float renderThreshold);

typedef void(*_OPConfigureFace) (bool enable, uint8 detector, int netInputSizeX, int netInputSizeY, // Point
	uint8 renderMode, // RenderMode
	float alphaKeypoint, float alphaHeatMap, float renderThreshold);
typedef void(*_OPConfigureExtra) (bool reconstruct3d, int minViews3d, bool identification, int tracking, int ikThreads);
typedef void(*_OPConfigureInput) (uint8 producerType, char* producerString, // ProducerType
	unsigned long long frameFirst, unsigned long long frameStep, unsigned long long frameLast,
	bool realTimeProcessing, bool frameFlip, int frameRotate, bool framesRepeat,
	int cameraResolutionX, int cameraResolutionY, // Point
	char* cameraParameterPath, bool undistortImage, int numberViews);
typedef void(*_OPConfigureOutput) (double verbose, char* writeKeypoint, uint8 writeKeypointFormat, // DataFormat
	char* writeJson, char* writeCocoJson, int writeCocoJsonVariants, int writeCocoJsonVariant, char* writeImages,
	char* writeImagesFormat, char* writeVideo, double writeVideoFps, bool writeVideoWithAudio,
	char* writeHeatMaps, char* writeHeatMapsFormat, char* writeVideo3D, char* writeVideoAdam, char* writeBvh,
	char* udpHost, char* udpPort);
typedef void(*_OPConfigureGui) (uint16 displayMode, // DisplayMode
	bool guiVerbose, bool fullScreen);
typedef void(*_OPConfigureDebugging) (uint8 loggingLevel, // Priority
	bool disableMultiThread,
	unsigned long long profileSpeed);

_OPConfigurePose m_OPConfigurePose;
_OPConfigureHand m_OPConfigureHand;
_OPConfigureFace m_OPConfigureFace;
_OPConfigureExtra m_OPConfigureExtra;
_OPConfigureInput m_OPConfigureInput;
_OPConfigureOutput m_OPConfigureOutput;
_OPConfigureGui m_OPConfigureGui;
_OPConfigureDebugging m_OPConfigureDebugging;


// dll handler
void* v_dllHandle;

ULoadDLLBPLibrary::ULoadDLLBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float ULoadDLLBPLibrary::LoadDLLSampleFunction(float Param)
{
	return -1;
}

// import dll from folder
bool ULoadDLLBPLibrary::importDLL(FString folder, FString name)
{
	//这里是通过GamePluginsDir获取当前工程的插件目录，folder和named都作为参数传递，得到的filePath就是目标dll的具体位置了
	FString filePath = *FPaths::GamePluginsDir() + folder + "/" + name;
	if (FPaths::FileExists(filePath))
	{
		v_dllHandle = FPlatformProcess::GetDllHandle(*filePath);//Retrieve the DLL.
		if (v_dllHandle != NULL)
		{
			return true;
		}
	}
	UE_LOG(LogTemp, Error, TEXT("%s not loaded"), *name);
	return false;  // Return an error.
}

bool ULoadDLLBPLibrary::importAllMethod_UE()
{
	if (v_dllHandle != NULL)
	{
		FString procName = "_OPRegisterOutputCallback";
		m_OPRegisterOutputCallback = (_OPRegisterOutputCallback)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPRegisterOutputCallback == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPRegisterOutputCallback not imported"));
			return false;
		}

		procName = "_OPSetOutputEnable";
		m_OPSetOutputEnable = (_OPSetOutputEnable)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPSetOutputEnable == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPSetOutputEnable not imported"));
			return false;
		}

		procName = "_OPSetDebugEnable";
		m_OPSetDebugEnable = (_OPSetDebugEnable)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPSetDebugEnable == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPSetDebugEnable not imported"));
			return false;
		}

		procName = "_OPRegisterDebugCallback";
		m_OPRegisterDebugCallback = (_OPRegisterDebugCallback)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPRegisterDebugCallback == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPRegisterDebugCallback not imported"));
			return false;
		}

		procName = "_OPSetImageOutputEnable";
		m_OPSetImageOutputEnable = (_OPSetImageOutputEnable)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPSetImageOutputEnable == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPSetImageOutputEnable not imported"));
			return false;
		}

		procName = "_OPRun";
		m_OPRun = (_OPRun)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPRun == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPRun not imported"));
			return false;
		}

		procName = "_OPShutdown";
		m_OPShutdown = (_OPShutdown)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPShutdown == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPShutdown not imported"));
			return false;
		}

		procName = "_OPConfigurePose";
		m_OPConfigurePose = (_OPConfigurePose)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPConfigurePose == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPConfigurePose not imported"));
			return false;
		}

		procName = "_OPConfigureHand";
		m_OPConfigureHand = (_OPConfigureHand)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPConfigureHand == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPConfigureHand not imported"));
			return false;
		}

		procName = "_OPConfigureFace";
		m_OPConfigureFace = (_OPConfigureFace)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPConfigureFace == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPConfigureFace not imported"));
			return false;
		}

		procName = "_OPConfigureExtra";
		m_OPConfigureExtra = (_OPConfigureExtra)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPConfigureExtra == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPConfigureExtra not imported"));
			return false;
		}

		procName = "_OPConfigureInput";
		m_OPConfigureInput = (_OPConfigureInput)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPConfigureInput == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPConfigureInput not imported"));
			return false;
		}

		procName = "_OPConfigureOutput";
		m_OPConfigureOutput = (_OPConfigureOutput)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPConfigureOutput == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPConfigureOutput not imported"));
			return false;
		}

		procName = "_OPConfigureGui";
		m_OPConfigureGui = (_OPConfigureGui)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPConfigureGui == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPConfigureGui not imported"));
			return false;
		}

		procName = "_OPConfigureDebugging";
		m_OPConfigureDebugging = (_OPConfigureDebugging)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPConfigureDebugging == NULL)
		{
			UE_LOG(LogTemp, Error, TEXT("function _OPConfigureDebugging not imported"));
			return false;
		}
	}
	return true;
}

// import specific function from dll
bool ULoadDLLBPLibrary::importMethod_OPSetOutputEnable()
{
	if (v_dllHandle != NULL)
	{
		m_OPSetOutputEnable = NULL;
		FString procName = "_OPSetOutputEnable"; // name of the function
		// get function handler
		m_OPSetOutputEnable = (_OPSetOutputEnable)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_OPSetOutputEnable != NULL)
		{
			return true;
		}
	}
	UE_LOG(LogTemp, Error, TEXT("function _OPSetOutputEnable  not imported"));
	return false;  // Return an error.
}

// 
void ULoadDLLBPLibrary::get_OPSetOutputEnableFromDll(bool enable)
{
	if (m_OPSetOutputEnable != NULL)
	{
		m_OPSetOutputEnable(enable);
	}
}

void ULoadDLLBPLibrary::freeDLL()
{
	if (v_dllHandle != NULL)
	{
		m_OPSetOutputEnable = NULL;
		m_OPRegisterOutputCallback = NULL;
		m_OPSetDebugEnable = NULL;
		m_OPSetImageOutputEnable = NULL;
		m_OPRun = NULL;
		m_OPShutdown = NULL;
		m_OPConfigurePose = NULL;
		m_OPConfigureHand = NULL;
		m_OPConfigureFace = NULL;
		m_OPConfigureExtra = NULL;
		m_OPConfigureInput = NULL;
		m_OPConfigureOutput = NULL;
		m_OPConfigureGui = NULL;
		m_OPConfigureDebugging = NULL;


		FPlatformProcess::FreeDllHandle(v_dllHandle);
		v_dllHandle = NULL;
	}
}

void ULoadDLLBPLibrary::M_OPRegisterOutputCallback(void(*OutputCallback)(void *, int, int *, int, uint8))
{
	m_OPRegisterOutputCallback(OutputCallback);
}

void ULoadDLLBPLibrary::M_OPRegisterOutputCallback_test(OutputCallback Callback)
{
	m_OPRegisterOutputCallback(Callback);
}



void ULoadDLLBPLibrary::M_OPRegisterDebugCallback(void(*DebugCallback)(const char* const, int))
{
	m_OPRegisterDebugCallback(DebugCallback);
}

void ULoadDLLBPLibrary::M_OPRun()
{
	m_OPRun();
}

void ULoadDLLBPLibrary::M_OPShutdown()
{
	m_OPShutdown();
}

void ULoadDLLBPLibrary::M_OPSetDebugEnable(bool enable)
{
	m_OPSetDebugEnable(enable);
}

void ULoadDLLBPLibrary::M_OPSetOutputEnable(bool enable)
{
	m_OPSetOutputEnable(enable);
}

void ULoadDLLBPLibrary::M_OPSetImageOutputEnable(bool enable)
{
	m_OPSetImageOutputEnable(enable);
}

void ULoadDLLBPLibrary::M_OPConfigurePose(PoseMode poseMode, int netInputSizeX, int netInputSizeY,
	int outputSizeX, int outputSizeY, ScaleMode keypointScaleMode, 
	int gpuNumber, int gpuNumberStart, int scalesNumber, 
	float scaleGap, RenderMode renderMode, PoseModel poseModel, 
	bool blendOriginalFrame, float alphaKeypoint, float alphaHeatMap, 
	int defaultPartToRender, FString modelFolder, HeatMapType heatMapTypes, 
	ScaleMode heatMapScaleMode, bool addPartCandidates, float renderThreshold, 
	int numberPeopleMax, bool maximizePositives, double fpsMax, 
	FString protoTxtPath, FString caffeModelPath, float upsamplingRatio)
{
	FString folder = "LoadDLL";
	modelFolder = *FPaths::GamePluginsDir() + folder + "/models/";
	char* modelFolderPtr = TCHAR_TO_UTF8(*modelFolder);
	char* protoTxtPathPtr = TCHAR_TO_UTF8(*protoTxtPath);
	char* caffeModelPathPtr = TCHAR_TO_UTF8(*caffeModelPath);
	bool heatMapAddParts, heatMapAddBkg, heatMapAddPAFs;
	heatMapAddParts = (uint8)heatMapTypes & (uint8)HeatMapType::Parts;
	heatMapAddBkg = (uint8)heatMapTypes & (uint8)HeatMapType::Background;
	heatMapAddPAFs = (uint8)heatMapTypes & (uint8)HeatMapType::PAFs;

	m_OPConfigurePose(
		(uint8)poseMode, netInputSizeX, netInputSizeY, // Point
		outputSizeX, outputSizeY, // Point
		(uint8)keypointScaleMode, // ScaleMode
		gpuNumber, gpuNumberStart, scalesNumber, scaleGap,
		(uint8)renderMode, // RenderMode
		(uint8)poseModel, // PoseModel
		blendOriginalFrame, alphaKeypoint, alphaHeatMap, defaultPartToRender, modelFolderPtr,
		heatMapAddParts,
		heatMapAddBkg,
		heatMapAddPAFs, // vector<HeatMapType>
		(uint8)heatMapScaleMode, // ScaleMode
		addPartCandidates, renderThreshold, numberPeopleMax,
		maximizePositives, fpsMax, protoTxtPathPtr, caffeModelPathPtr, upsamplingRatio);
}

void ULoadDLLBPLibrary::M_OPConfigureHand(bool enable, Detector detector, int netInputSizeX, int netInputSizeY, int scalesNumber, float scaleRange, RenderMode renderMode, float alphaKeypoint, float alphaHeatMap, float renderThreshold)
{
	m_OPConfigureHand(enable, (uint8)detector,
		netInputSizeX, netInputSizeY, scalesNumber,
		scaleRange, (uint8)renderMode, alphaKeypoint,
		alphaHeatMap, renderThreshold);
}

void ULoadDLLBPLibrary::M_OPConfigureFace(bool enable, Detector detector, int netInputSizeX, int netInputSizeY, RenderMode renderMode, float alphaKeypoint, float alphaHeatMap, float renderThreshold)
{
	m_OPConfigureFace(enable, (uint8)detector,
		netInputSizeX, netInputSizeY, (uint8)renderMode,
		alphaKeypoint, alphaHeatMap, renderThreshold);
}

void ULoadDLLBPLibrary::M_OPConfigureExtra(bool reconstruct3d, int minViews3d, bool identification, int tracking, int ikThreads)
{
	m_OPConfigureExtra(reconstruct3d, minViews3d, identification, tracking, ikThreads);
}

void ULoadDLLBPLibrary::M_OPConfigureInput(ProducerType producerType, FString producerString, uint64 frameFirst, uint64 frameStep, uint64 frameLast, bool realTimeProcessing, bool frameFlip, int frameRotate, bool framesRepeat, int cameraResolutionX, int cameraResolutionY, FString cameraParameterPath, bool undistortImage, int numberViews)
{
	FString folder = "LoadDLL";
	cameraParameterPath = *FPaths::GamePluginsDir() + folder + "/models/cameraParameters/";
	char* cameraParameterPathPtr = TCHAR_TO_UTF8(*cameraParameterPath);
	char* producerStringPtr = TCHAR_TO_UTF8(*producerString);
	m_OPConfigureInput(
		(uint8)producerType, producerStringPtr,
		frameFirst, frameStep, frameLast,
		realTimeProcessing, frameFlip, frameRotate,
		framesRepeat, cameraResolutionX, cameraResolutionY,
		cameraParameterPathPtr, undistortImage, numberViews);
}

void ULoadDLLBPLibrary::M_OPConfigureOutput(double verbose, FString writeKeypoint, DataFormat writeKeypointFormat, FString writeJson, FString writeCocoJson, int writeCocoJsonVariants, int writeCocoJsonVariant, FString writeImages, FString writeImagesFormat, FString writeVideo, double writeVideoFps, bool writeVideoWithAudio, FString writeHeatMaps, FString writeHeatMapsFormat, FString writeVideo3D, FString writeVideoAdam, FString writeBvh, FString udpHost, FString udpPort)
{
	char* writeKeypointPtr = TCHAR_TO_UTF8(*writeKeypoint);
	char* writeJsonPtr = TCHAR_TO_UTF8(*writeJson);
	char* writeCocoJsonPtr = TCHAR_TO_UTF8(*writeCocoJson);
	char* writeImagesPtr = TCHAR_TO_UTF8(*writeImages);
	char* writeImagesFormatPtr = TCHAR_TO_UTF8(*writeImagesFormat);
	char* writeVideoPtr = TCHAR_TO_UTF8(*writeVideo);
	char* writeHeatMapsPtr = TCHAR_TO_UTF8(*writeHeatMaps);
	char* writeHeatMapsFormatPtr = TCHAR_TO_UTF8(*writeHeatMapsFormat);
	char* writeVideo3DPtr = TCHAR_TO_UTF8(*writeVideo3D);
	char* writeVideoAdamPtr = TCHAR_TO_UTF8(*writeVideoAdam);
	char* writeBvhPtr = TCHAR_TO_UTF8(*writeBvh);
	char* udpHostPtr = TCHAR_TO_UTF8(*udpHost);
	char* udpPortPtr = TCHAR_TO_UTF8(*udpPort);
	m_OPConfigureOutput(
		verbose, writeKeypointPtr,
		(uint8)writeKeypointFormat, writeJsonPtr, writeCocoJsonPtr,
		writeCocoJsonVariants, writeCocoJsonVariant, writeImagesPtr,
		writeImagesFormatPtr, writeVideoPtr, writeVideoFps,
		writeVideoWithAudio, writeHeatMapsPtr, writeHeatMapsFormatPtr,
		writeVideo3DPtr, writeVideoAdamPtr, writeBvhPtr,
		udpHostPtr, udpPortPtr);
}

void ULoadDLLBPLibrary::M_OPConfigureGui(DisplayMode displayMode, bool guiVerbose, bool fullScreen)
{
	m_OPConfigureGui((uint16)displayMode, guiVerbose, fullScreen);
}

void ULoadDLLBPLibrary::M_OPConfigureDebugging(Priority loggingLevel, bool disableMultiThread, uint64 profileSpeed)
{
	m_OPConfigureDebugging((uint8)loggingLevel, disableMultiThread, profileSpeed);
}

void ULoadDLLBPLibrary::setAllUserParam(ProducerType inputType, FString producerString, int maxPeople, float renderThreshold, bool handEnabled, bool faceEnabled, int netResolutionX, int netResolutionY, int handResolutionX, int handResolutionY, int faceResolutionX, int faceResolutionY)
{
	m_inputType = inputType;
	m_producerString = producerString;
	m_maxPeople = maxPeople;
	m_renderThreshold = renderThreshold;
	m_handEnabled = handEnabled;
	m_faceEnabled = faceEnabled;
	m_netResolutionX = netResolutionX;
	m_netResolutionY = netResolutionY;
	m_handResolutionX = handResolutionX;
	m_handResolutionY = handResolutionY;
	m_faceResolutionX = faceResolutionX;
	m_faceResolutionY = faceResolutionY;
}

void ULoadDLLBPLibrary::OpenposeStart()
{
	UE_LOG(LogTemp, Warning, TEXT("Openpose Start"));
	OPWrapper::opState = OPState::Ready;
	// Register callbacks
	OPWrapper::OPRegisterCallbacks();
	// Enable OpenPose log to unreal (default true)
	OPWrapper::OPEnableDebug(true);
	// Enable OpenPose output to unreal (default true)
	OPWrapper::OPEnableOutput(true);
	// Enable receiving image (default false)
	OPWrapper::OPEnableImageOutput(true);

	// Configure OpenPose with default value, or using specific configuration for each
	UserConfigureOpenPose();

	// Start OpenPose
	OPWrapper::OPRun();
}

void ULoadDLLBPLibrary::OpenposeUpdate()
{
	if (OPWrapper::OPGetOutput(m_Datum)) // true: has new frame data
	{
		// update number of people in UI
		if (m_Datum.poseKeypoints.Empty())
		{
			m_numberPeople = 0;
		}
		else
			m_numberPeople = m_Datum.poseKeypoints.GetLayerSize(0);
		
		UE_LOG(LogTemp, Warning, TEXT("number Of People: %d"), m_numberPeople);
		// get pose Keypoints after processing, return it to the outside

		
	}
	else
	{
		//UE_LOG(LogTemp, Error, TEXT("OpenposeUpdate() failed"));
	}
}

void ULoadDLLBPLibrary::OpenposeUpdate_OutputData(TArray<FVector2D>& poseKeypoints, int32& numberPeople)
{
	if (OPWrapper::OPGetOutput(m_Datum)) // true: has new frame data
	{
		// update number of people in UI
		if (m_Datum.poseKeypoints.Empty())
		{
			m_numberPeople = 0;
		}
		else
			m_numberPeople = m_Datum.poseKeypoints.GetLayerSize(0);
		numberPeople = m_numberPeople;

		UE_LOG(LogTemp, Warning, TEXT("number Of People: %d"), m_numberPeople);

		TArray<FVector2D> poseKeypoints_temp;
		
		// get pose Keypoints after processing, return it to the outside
		for (int i = 0; i < m_numberPeople;i++)
		{
			poseKeypoints_temp.Append(getPoseKeypointsData(m_Datum, i, m_renderThreshold));
		}
		poseKeypoints = poseKeypoints_temp;
	}
	else
	{
		//UE_LOG(LogTemp, Error, TEXT("OpenposeUpdate_OutputData() failed"));
	}
}


void ULoadDLLBPLibrary::OpenposeEnd()
{
	if (OPWrapper::opState == OPState::Running)
		M_OPShutdown();
}

void ULoadDLLBPLibrary::UserConfigureOpenPose()
{
	OPWrapper::OPConfigurePose(
		/* poseMode */ PoseMode::Enabled, /* netInputSizeX */ m_netResolutionX, /* netInputSizeY */ m_netResolutionY,
		/* outputSizeX */ -1, /* outputSizeY */ -1, /* keypointScaleMode */ ScaleMode::InputResolution,
		/* gpuNumber */ -1, /* gpuNumberStart */ 0, /* scalesNumber */ 1,
		/* scaleGap */ 0.25f, /* renderMode */ RenderMode::Auto, /* poseModel */ PoseModel::BODY_25,
		/* blendOriginalFrame */ true, /* alphaKeypoint */ 0.6f, /* alphaHeatMap */ 0.7f,
		/* defaultPartToRender */ 0, /* modelFolder */ "",	/* heatMapTypes */ HeatMapType::None,
		/* heatMapScaleMode */ ScaleMode::ZeroToOne, /* addPartCandidates */ false, /* renderThreshold */ m_renderThreshold,
		/* numberPeopleMax */ m_maxPeople,	/* maximizePositives */ false, /* fpsMax fps_max */ -1.0,
		/* protoTxtPath */ "", /* caffeModelPath */ "", /* upsamplingRatio */ 0.0f);
	OPWrapper::OPConfigureHand(
		/* enable */ m_handEnabled, /* detector */ Detector::Body,
		/* netInputSizeX */ m_handResolutionX, /* netInputSizeY */ m_handResolutionY,
		/* scalesNumber */ 1, /* scaleRange */ 0.4f, /* renderMode */ RenderMode::Auto,
		/* alphaKeypoint */ 0.6f, /* alphaHeatMap */ 0.7f, /* renderThreshold */ 0.2f);
	OPWrapper::OPConfigureFace(
		/* enable */ m_faceEnabled, /* detector */ Detector::Body,
		/* netInputSizeX */ m_faceResolutionX, /* netInputSizeY */ m_faceResolutionY,
		/* renderMode */ RenderMode::Auto,
		/* alphaKeypoint */ 0.6f, /* alphaHeatMap */ 0.7f, /* renderThreshold */ 0.4f);
	OPWrapper::OPConfigureExtra(
		/* reconstruct3d */ false, /* minViews3d */ -1, /* identification */ false, /* tracking */ -1,
		/* ikThreads */ 0);
	OPWrapper::OPConfigureInput(
		/* producerType */ m_inputType, /* producerString */ m_producerString,
		/* frameFirst */ 0, /* frameStep */ 1, /* frameLast */ ULONGLONG_MAX,
		/* realTimeProcessing */ false, /* frameFlip */ false,
		/* frameRotate */ 0, /* framesRepeat */ false,
		/* cameraResolutionX */ -1, /* cameraResolutionY */ -1,
		/* cameraParameterPath */ "",
		/* undistortImage */ false, /* numberViews */ -1);
	OPWrapper::OPConfigureOutput(
		/* verbose */ -1.0, /* writeKeypoint */ "", /* writeKeypointFormat */ DataFormat::Xml,
		/* writeJson */ "", /* writeCocoJson */ "", /* writeCocoJsonVariants */ 1,
		/* writeCocoJsonVariant */ 1, /* writeImages */ "", /* writeImagesFormat */ "png",
		/* writeVideo */ "", /* writeVideoFps */ -1.0, /* writeVideoWithAudio */ false,
		/* writeHeatMaps */ "", /* writeHeatMapsFormat */ "png", /* writeVideo3D */ "",
		/* writeVideoAdam */ "", /* writeBvh */ "", /* udpHost */ "", /* udpPort */ "8051");
	OPWrapper::OPConfigureGui(
		/* displayMode */ DisplayMode::NoDisplay, /* guiVerbose */ false, /* fullScreen */ false);
	OPWrapper::OPConfigureDebugging(
		/* loggingLevel */ Priority::High, /* disableMultiThread */ false, /* profileSpeed */ 1000);

}

void ULoadDLLBPLibrary::MyDebugDrawLine(const FVector& StartPost)
{
	ULineBatchComponent* const LineBatcher = GetWorld()->PersistentLineBatcher;
	if (LineBatcher != NULL)
	{
		//画点
		LineBatcher->DrawPoint(StartPost, FLinearColor::Blue, 5, 10, 0.f);
		//画线
		//LineBatcher->DrawLine(StartPost, EndPos, LineColor, 10, 0.f);
		//还有很多其他的绘制函数 DrawLines  DrawBox  DrawDirectionalArrow   DrawCircle  DrawSolidBox  DrawMesh
	}
}

TArray<FVector2D> ULoadDLLBPLibrary::getPoseKeypointsData(OPDatum & Datum, int32 BodyIdx, float RenderThreshold)
{
	TArray<FVector2D> poseArray;
	if (BodyIdx >= Datum.poseKeypoints.GetLayerSize(0))
	{
		UE_LOG(LogTemp, Warning, TEXT("BodyIdx invalid, too much"));
	}
	// Pose
	for (int part = 0; part < 25;part++)
	{
		// Joints overflow
		if (part >= Datum.poseKeypoints.GetSize()[1])
		{
			UE_LOG(LogTemp, Warning, TEXT("Pose Joints invalid, too much"));
		}
		// Compare score
		if (Datum.poseKeypoints.Get(BodyIdx, part,2) > RenderThreshold)
		{
			FVector2D pos(Datum.poseKeypoints.Get(BodyIdx, part, 0), Datum.poseKeypoints.Get(BodyIdx, part, 1));
			poseArray.Emplace(pos);
		}
	}
	return poseArray;
}






