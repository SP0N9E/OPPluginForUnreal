// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LoadDLL.h"
#include "LevelEditor.h"
#include "LogMacros.h"

#include <thread>

#define LOCTEXT_NAMESPACE "FLoadDLLModule"

void FLoadDLLModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
#pragma region Init0
	TMap<FString, void*> DllsHandles;

	FString RootOpenCVPath = FPaths::ProjectPluginsDir() / FString::Printf(TEXT("LoadDll/ThirdParty/OpenPose/lib/"));

	DllsHandles.Add("boost_filesystem-vc141-mt-x64-1_69");
	DllsHandles.Add("boost_thread-vc141-mt-x64-1_69");

	DllsHandles.Add("caffehdf5");
	DllsHandles.Add("caffehdf5_hl");
	DllsHandles.Add("caffezlib1");
	DllsHandles.Add("cublas64_100");
	DllsHandles.Add("cudart64_100");
	DllsHandles.Add("curand64_100");
	DllsHandles.Add("cudnn64_7");
	DllsHandles.Add("freeglut");
	DllsHandles.Add("gflags");
	DllsHandles.Add("glog");
	DllsHandles.Add("libgcc_s_seh-1");
	DllsHandles.Add("libgfortran-3");
	DllsHandles.Add("libopenblas");
	DllsHandles.Add("caffe");

	DllsHandles.Add("libquadmath-0");
	DllsHandles.Add("opencv_ffmpeg401_64");
	DllsHandles.Add("opencv_world401");
	DllsHandles.Add("opencv_world401d");

	for (auto& Val : DllsHandles)
	{
		FString Filename = FString::Printf(TEXT("%s.dll"), *Val.Key);

		FString LibraryPath = FPaths::Combine(*RootOpenCVPath, Filename);
		/*UE_LOG(LogTemp, Warning, TEXT("LibraryPath : %s"), *LibraryPath);*/
		//Val.Value = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;
		if (FPaths::FileExists(LibraryPath))
		{
			Val.Value = FPlatformProcess::GetDllHandle(*LibraryPath);
		}

		if (Val.Value)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s loaded"), *LibraryPath);

		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("%s not loaded"), *LibraryPath);

		}
	}
}

void FLoadDLLModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLoadDLLModule, LoadDLL)