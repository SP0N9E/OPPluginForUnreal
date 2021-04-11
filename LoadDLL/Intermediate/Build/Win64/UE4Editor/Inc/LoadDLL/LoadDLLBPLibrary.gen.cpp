// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/LoadDLLBPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLoadDLLBPLibrary() {}
// Cross Module References
	LOADDLL_API UClass* Z_Construct_UClass_ULoadDLLBPLibrary_NoRegister();
	LOADDLL_API UClass* Z_Construct_UClass_ULoadDLLBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_LoadDLL();
	LOADDLL_API UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_freeDLL();
	LOADDLL_API UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_get_OPSetOutputEnableFromDll();
	LOADDLL_API UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_importAllMethod_UE();
	LOADDLL_API UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_importDLL();
	LOADDLL_API UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_importMethod_OPSetOutputEnable();
	LOADDLL_API UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_LoadDLLSampleFunction();
	LOADDLL_API UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeEnd();
	LOADDLL_API UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeStart();
	LOADDLL_API UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeUpdate();
	LOADDLL_API UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeUpdate_OutputData();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	LOADDLL_API UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_setAllUserParam();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_ProducerType();
// End Cross Module References
	void ULoadDLLBPLibrary::StaticRegisterNativesULoadDLLBPLibrary()
	{
		UClass* Class = ULoadDLLBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "freeDLL", &ULoadDLLBPLibrary::execfreeDLL },
			{ "get_OPSetOutputEnableFromDll", &ULoadDLLBPLibrary::execget_OPSetOutputEnableFromDll },
			{ "importAllMethod_UE", &ULoadDLLBPLibrary::execimportAllMethod_UE },
			{ "importDLL", &ULoadDLLBPLibrary::execimportDLL },
			{ "importMethod_OPSetOutputEnable", &ULoadDLLBPLibrary::execimportMethod_OPSetOutputEnable },
			{ "LoadDLLSampleFunction", &ULoadDLLBPLibrary::execLoadDLLSampleFunction },
			{ "OpenposeEnd", &ULoadDLLBPLibrary::execOpenposeEnd },
			{ "OpenposeStart", &ULoadDLLBPLibrary::execOpenposeStart },
			{ "OpenposeUpdate", &ULoadDLLBPLibrary::execOpenposeUpdate },
			{ "OpenposeUpdate_OutputData", &ULoadDLLBPLibrary::execOpenposeUpdate_OutputData },
			{ "setAllUserParam", &ULoadDLLBPLibrary::execsetAllUserParam },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_freeDLL()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "LoadDLLTesting" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
				{ "ToolTip", "?\xcd\xb7?dll" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadDLLBPLibrary, "freeDLL", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_get_OPSetOutputEnableFromDll()
	{
		struct LoadDLLBPLibrary_eventget_OPSetOutputEnableFromDll_Parms
		{
			bool enable;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_enable_SetBit = [](void* Obj){ ((LoadDLLBPLibrary_eventget_OPSetOutputEnableFromDll_Parms*)Obj)->enable = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_enable = { UE4CodeGen_Private::EPropertyClass::Bool, "enable", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LoadDLLBPLibrary_eventget_OPSetOutputEnableFromDll_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_enable_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_enable,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "LoadDLLTesting" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
				{ "ToolTip", "????dll?????\xc4\xb7???" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadDLLBPLibrary, "get_OPSetOutputEnableFromDll", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(LoadDLLBPLibrary_eventget_OPSetOutputEnableFromDll_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_importAllMethod_UE()
	{
		struct LoadDLLBPLibrary_eventimportAllMethod_UE_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((LoadDLLBPLibrary_eventimportAllMethod_UE_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LoadDLLBPLibrary_eventimportAllMethod_UE_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "LoadDLLTesting" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadDLLBPLibrary, "importAllMethod_UE", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(LoadDLLBPLibrary_eventimportAllMethod_UE_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_importDLL()
	{
		struct LoadDLLBPLibrary_eventimportDLL_Parms
		{
			FString folder;
			FString name;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((LoadDLLBPLibrary_eventimportDLL_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LoadDLLBPLibrary_eventimportDLL_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_name = { UE4CodeGen_Private::EPropertyClass::Str, "name", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventimportDLL_Parms, name), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_folder = { UE4CodeGen_Private::EPropertyClass::Str, "folder", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventimportDLL_Parms, folder), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_name,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_folder,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "LoadDLLTesting" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
				{ "ToolTip", "????dll" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadDLLBPLibrary, "importDLL", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(LoadDLLBPLibrary_eventimportDLL_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_importMethod_OPSetOutputEnable()
	{
		struct LoadDLLBPLibrary_eventimportMethod_OPSetOutputEnable_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((LoadDLLBPLibrary_eventimportMethod_OPSetOutputEnable_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LoadDLLBPLibrary_eventimportMethod_OPSetOutputEnable_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "LoadDLLTesting" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
				{ "ToolTip", "??\xc8\xa1""dll?\xd0\xb5\xc4\xb7?????\xd6\xb8??" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadDLLBPLibrary, "importMethod_OPSetOutputEnable", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(LoadDLLBPLibrary_eventimportMethod_OPSetOutputEnable_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_LoadDLLSampleFunction()
	{
		struct LoadDLLBPLibrary_eventLoadDLLSampleFunction_Parms
		{
			float Param;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventLoadDLLSampleFunction_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Param = { UE4CodeGen_Private::EPropertyClass::Float, "Param", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventLoadDLLSampleFunction_Parms, Param), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Param,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "LoadDLLTesting" },
				{ "DisplayName", "Execute Sample function" },
				{ "Keywords", "LoadDLL sample test testing" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadDLLBPLibrary, "LoadDLLSampleFunction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(LoadDLLBPLibrary_eventLoadDLLSampleFunction_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "OpenPoseUserLibrary" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
				{ "ToolTip", "Call this function when the level ends" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadDLLBPLibrary, "OpenposeEnd", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "OpenPoseUserLibrary" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
				{ "ToolTip", "call this function after level blueprint start" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadDLLBPLibrary, "OpenposeStart", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "OpenPoseUserLibrary" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
				{ "ToolTip", "Call this function every frame" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadDLLBPLibrary, "OpenposeUpdate", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeUpdate_OutputData()
	{
		struct LoadDLLBPLibrary_eventOpenposeUpdate_OutputData_Parms
		{
			TArray<FVector2D> poseKeypoints;
			int32 numberPeople;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_numberPeople = { UE4CodeGen_Private::EPropertyClass::Int, "numberPeople", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventOpenposeUpdate_OutputData_Parms, numberPeople), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_poseKeypoints = { UE4CodeGen_Private::EPropertyClass::Array, "poseKeypoints", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventOpenposeUpdate_OutputData_Parms, poseKeypoints), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_poseKeypoints_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "poseKeypoints", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_numberPeople,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_poseKeypoints,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_poseKeypoints_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "OpenPoseUserLibrary" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
				{ "ToolTip", "Call this function every frame" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadDLLBPLibrary, "OpenposeUpdate_OutputData", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(LoadDLLBPLibrary_eventOpenposeUpdate_OutputData_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULoadDLLBPLibrary_setAllUserParam()
	{
		struct LoadDLLBPLibrary_eventsetAllUserParam_Parms
		{
			ProducerType inputType;
			FString producerString;
			int32 maxPeople;
			float renderThreshold;
			bool handEnabled;
			bool faceEnabled;
			int32 netResolutionX;
			int32 netResolutionY;
			int32 handResolutionX;
			int32 handResolutionY;
			int32 faceResolutionX;
			int32 faceResolutionY;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_faceResolutionY = { UE4CodeGen_Private::EPropertyClass::Int, "faceResolutionY", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventsetAllUserParam_Parms, faceResolutionY), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_faceResolutionX = { UE4CodeGen_Private::EPropertyClass::Int, "faceResolutionX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventsetAllUserParam_Parms, faceResolutionX), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_handResolutionY = { UE4CodeGen_Private::EPropertyClass::Int, "handResolutionY", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventsetAllUserParam_Parms, handResolutionY), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_handResolutionX = { UE4CodeGen_Private::EPropertyClass::Int, "handResolutionX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventsetAllUserParam_Parms, handResolutionX), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_netResolutionY = { UE4CodeGen_Private::EPropertyClass::Int, "netResolutionY", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventsetAllUserParam_Parms, netResolutionY), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_netResolutionX = { UE4CodeGen_Private::EPropertyClass::Int, "netResolutionX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventsetAllUserParam_Parms, netResolutionX), METADATA_PARAMS(nullptr, 0) };
			auto NewProp_faceEnabled_SetBit = [](void* Obj){ ((LoadDLLBPLibrary_eventsetAllUserParam_Parms*)Obj)->faceEnabled = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_faceEnabled = { UE4CodeGen_Private::EPropertyClass::Bool, "faceEnabled", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LoadDLLBPLibrary_eventsetAllUserParam_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_faceEnabled_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			auto NewProp_handEnabled_SetBit = [](void* Obj){ ((LoadDLLBPLibrary_eventsetAllUserParam_Parms*)Obj)->handEnabled = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_handEnabled = { UE4CodeGen_Private::EPropertyClass::Bool, "handEnabled", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LoadDLLBPLibrary_eventsetAllUserParam_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_handEnabled_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_renderThreshold = { UE4CodeGen_Private::EPropertyClass::Float, "renderThreshold", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventsetAllUserParam_Parms, renderThreshold), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_maxPeople = { UE4CodeGen_Private::EPropertyClass::Int, "maxPeople", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventsetAllUserParam_Parms, maxPeople), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_producerString = { UE4CodeGen_Private::EPropertyClass::Str, "producerString", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventsetAllUserParam_Parms, producerString), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_inputType = { UE4CodeGen_Private::EPropertyClass::Enum, "inputType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LoadDLLBPLibrary_eventsetAllUserParam_Parms, inputType), Z_Construct_UEnum_LoadDLL_ProducerType, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_inputType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_faceResolutionY,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_faceResolutionX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_handResolutionY,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_handResolutionX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_netResolutionY,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_netResolutionX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_faceEnabled,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_handEnabled,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_renderThreshold,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_maxPeople,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_producerString,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_inputType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_inputType_Underlying,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "OpenPoseUserLibrary" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
				{ "ToolTip", "set openpose parameters" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadDLLBPLibrary, "setAllUserParam", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(LoadDLLBPLibrary_eventsetAllUserParam_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULoadDLLBPLibrary_NoRegister()
	{
		return ULoadDLLBPLibrary::StaticClass();
	}
	UClass* Z_Construct_UClass_ULoadDLLBPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
				(UObject* (*)())Z_Construct_UPackage__Script_LoadDLL,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ULoadDLLBPLibrary_freeDLL, "freeDLL" }, // 3170944064
				{ &Z_Construct_UFunction_ULoadDLLBPLibrary_get_OPSetOutputEnableFromDll, "get_OPSetOutputEnableFromDll" }, // 1172593867
				{ &Z_Construct_UFunction_ULoadDLLBPLibrary_importAllMethod_UE, "importAllMethod_UE" }, // 429074081
				{ &Z_Construct_UFunction_ULoadDLLBPLibrary_importDLL, "importDLL" }, // 2466985611
				{ &Z_Construct_UFunction_ULoadDLLBPLibrary_importMethod_OPSetOutputEnable, "importMethod_OPSetOutputEnable" }, // 622632908
				{ &Z_Construct_UFunction_ULoadDLLBPLibrary_LoadDLLSampleFunction, "LoadDLLSampleFunction" }, // 1231226478
				{ &Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeEnd, "OpenposeEnd" }, // 356808015
				{ &Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeStart, "OpenposeStart" }, // 115620193
				{ &Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeUpdate, "OpenposeUpdate" }, // 2980392467
				{ &Z_Construct_UFunction_ULoadDLLBPLibrary_OpenposeUpdate_OutputData, "OpenposeUpdate_OutputData" }, // 1922544720
				{ &Z_Construct_UFunction_ULoadDLLBPLibrary_setAllUserParam, "setAllUserParam" }, // 1229649032
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "LoadDLLBPLibrary.h" },
				{ "ModuleRelativePath", "Public/LoadDLLBPLibrary.h" },
				{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ULoadDLLBPLibrary>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ULoadDLLBPLibrary::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00000080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULoadDLLBPLibrary, 2274464893);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULoadDLLBPLibrary(Z_Construct_UClass_ULoadDLLBPLibrary, &ULoadDLLBPLibrary::StaticClass, TEXT("/Script/LoadDLL"), TEXT("ULoadDLLBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULoadDLLBPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
