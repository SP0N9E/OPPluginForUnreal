// Fill out your copyright notice in the Description page of Project Settings.

#include "OPWrapper.h"
#include "LoadDLLBPLibrary.h"

template <typename T>
void Clear(std::queue<T>& q)
{
	std::queue<T> empty;
	swap(empty, q);
}


OPState OPWrapper::opState = OPState::Ready;
OPDatum currentData_origin;
std::queue<OPDatum> dataBuffer_origin;
OPDatum OPWrapper::currentData = currentData_origin;
std::queue<OPDatum> OPWrapper::dataBuffer = dataBuffer_origin;
//OutputCallback OPOutputCallback = OPWrapper::OPOutput;
OutputCallback OPOutputCallback = OPWrapper::OPOutput;

OPWrapper::OPWrapper()
{
	opState = OPState::Ready;
}

OPWrapper::~OPWrapper()
{
}


void OPWrapper::OPRegisterCallbacks()
{
	ULoadDLLBPLibrary::M_OPRegisterDebugCallback(OPLog);
	//ULoadDLLBPLibrary::M_OPRegisterOutputCallback_test(OPOutput);
	ULoadDLLBPLibrary::M_OPRegisterOutputCallback_test(OPOutputCallback);

}

void OPWrapper::OPEnableDebug(bool enable)
{
	ULoadDLLBPLibrary::M_OPSetDebugEnable(enable);
}

void OPWrapper::OPEnableOutput(bool enable)
{
	ULoadDLLBPLibrary::M_OPSetOutputEnable(enable);
}

void OPWrapper::OPEnableImageOutput(bool enable)
{
	ULoadDLLBPLibrary::M_OPSetImageOutputEnable(enable);
}

void OPWrapper::OPRun()
{
	if (opState == OPState::Ready) {
		// Start OP thread
		opState = OPState::Running;
		/// TODO:THREAD NEED TO BE DONE HERE
		/// UPDATE:DON'T KNOW IF IT WORK
		//SimpleThread::JoyInit();
		//SimpleThread::JoyInit(dataBuffer, currentData, opState); // don't know if it work
		UE_LOG(LogTemp, Warning, TEXT("OPRun"));
		std::thread opThread{ OPExecuteThread };
		//std::thread opThread(OPExecuteThread);
		opThread.detach();
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Trying to start, while OpenPose already started or not ready"));
	}
}

bool OPWrapper::OPGetOutput(OPDatum & data)
{
	if (dataBuffer.size() > 0)
	{
		data = dataBuffer.front();
		dataBuffer.pop();
		return true;
	}
	else
	{
		/*OPDatum newData;
		data = newData;*/
		data = OPDatum();
		return false;
	}
}

void OPWrapper::OPShutDown()
{
	if (opState == OPState::Running) {
		opState = OPState::Stopping;
		ULoadDLLBPLibrary::M_OPShutdown();
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Trying to shutdown, while OpenPose is not running"));
	}
}

void OPWrapper::OPConfigurePose(PoseMode poseMode, int netInputSizeX, int netInputSizeY,
	int outputSizeX, int outputSizeY, ScaleMode keypointScaleMode, 
	int gpuNumber, int gpuNumberStart, int scalesNumber, 
	float scaleGap, RenderMode renderMode, PoseModel poseModel, 
	bool blendOriginalFrame, float alphaKeypoint, float alphaHeatMap, 
	int defaultPartToRender, FString modelFolder, HeatMapType heatMapTypes, 
	ScaleMode heatMapScaleMode, bool addPartCandidates, float renderThreshold, 
	int numberPeopleMax, bool maximizePositives, double fpsMax, 
	FString protoTxtPath, FString caffeModelPath, float upsamplingRatio)
{
	ULoadDLLBPLibrary::M_OPConfigurePose(
		poseMode, netInputSizeX, netInputSizeY,
		outputSizeX, outputSizeY, keypointScaleMode,
		gpuNumber, gpuNumberStart, scalesNumber,
		scaleGap, renderMode, poseModel,
		blendOriginalFrame, alphaKeypoint, alphaHeatMap,
		defaultPartToRender, modelFolder, heatMapTypes,
		heatMapScaleMode, addPartCandidates, renderThreshold,
		numberPeopleMax, maximizePositives, fpsMax,
		protoTxtPath, caffeModelPath, upsamplingRatio);
}

void OPWrapper::OPConfigureHand(bool enable, Detector detector, 
	int netInputSizeX, int netInputSizeY, int scalesNumber, 
	float scaleRange, RenderMode renderMode, float alphaKeypoint, 
	float alphaHeatMap, float renderThreshold)
{
	ULoadDLLBPLibrary::M_OPConfigureHand(enable, detector,
		netInputSizeX, netInputSizeY, scalesNumber,
		scaleRange, renderMode, alphaKeypoint,
		alphaHeatMap, renderThreshold);
}

void OPWrapper::OPConfigureFace(bool enable, Detector detector, 
	int netInputSizeX, int netInputSizeY, RenderMode renderMode,
	float alphaKeypoint, float alphaHeatMap, float renderThreshold)
{
	ULoadDLLBPLibrary::M_OPConfigureFace(enable, detector,
		netInputSizeX, netInputSizeY, renderMode,
		alphaKeypoint, alphaHeatMap, renderThreshold);
	
}

void OPWrapper::OPConfigureExtra(bool reconstruct3d, int minViews3d,
	bool identification, int tracking, int ikThreads)
{
	ULoadDLLBPLibrary::M_OPConfigureExtra(reconstruct3d, minViews3d,
		identification, tracking, ikThreads);
}

void OPWrapper::OPConfigureInput(ProducerType producerType, FString producerString, 
	uint64 frameFirst, uint64 frameStep, uint64 frameLast, 
	bool realTimeProcessing, bool frameFlip, int frameRotate, 
	bool framesRepeat, int cameraResolutionX, int cameraResolutionY, 
	FString cameraParameterPath, bool undistortImage, int numberViews)
{
	ULoadDLLBPLibrary::M_OPConfigureInput(producerType, producerString,
		frameFirst, frameStep, frameLast,
		realTimeProcessing, frameFlip, frameRotate,
		framesRepeat, cameraResolutionX, cameraResolutionY,
		cameraParameterPath, undistortImage, numberViews);
}

void OPWrapper::OPConfigureOutput(double verbose, FString writeKeypoint,
	DataFormat writeKeypointFormat, FString writeJson, FString writeCocoJson,
	int writeCocoJsonVariants, int writeCocoJsonVariant, FString writeImages, 
	FString writeImagesFormat, FString writeVideo, double writeVideoFps, 
	bool writeVideoWithAudio, FString writeHeatMaps, FString writeHeatMapsFormat, 
	FString writeVideo3D, FString writeVideoAdam, FString writeBvh, 
	FString udpHost, FString udpPort)
{
	ULoadDLLBPLibrary::M_OPConfigureOutput(verbose, writeKeypoint,
		writeKeypointFormat, writeJson, writeCocoJson,
		writeCocoJsonVariants, writeCocoJsonVariant, writeImages,
		writeImagesFormat, writeVideo, writeVideoFps,
		writeVideoWithAudio, writeHeatMaps, writeHeatMapsFormat,
		writeVideo3D, writeVideoAdam, writeBvh,
		udpHost, udpPort);
}

void OPWrapper::OPConfigureGui(DisplayMode displayMode, bool guiVerbose, bool fullScreen)
{
	ULoadDLLBPLibrary::M_OPConfigureGui(displayMode, guiVerbose, fullScreen);
}

void OPWrapper::OPConfigureDebugging(Priority loggingLevel, bool disableMultiThread, uint64 profileSpeed)
{
	ULoadDLLBPLibrary::M_OPConfigureDebugging(loggingLevel, disableMultiThread, profileSpeed);
}

void OPWrapper::OPExecuteThread()
{
	UE_LOG(LogTemp, Warning, TEXT("OPExecuteThread"));
	// Start OP with output callback
	ULoadDLLBPLibrary::M_OPRun();

	// Thread end, clean up
	Clear(OPWrapper::dataBuffer);
	currentData = OPDatum();

	// Change state
	opState = OPState::Ready;
}


