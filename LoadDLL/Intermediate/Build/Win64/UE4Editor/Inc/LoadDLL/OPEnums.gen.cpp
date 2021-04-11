// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/OPEnums.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOPEnums() {}
// Cross Module References
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_DataFormat();
	UPackage* Z_Construct_UPackage__Script_LoadDLL();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_DisplayMode();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_PoseModel();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_ElementToRender();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_RenderMode();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_HeatMapType();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_ScaleMode();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_ProducerType();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_Detector();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_PoseMode();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_Priority();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_OutputType();
	LOADDLL_API UEnum* Z_Construct_UEnum_LoadDLL_OPState();
// End Cross Module References
	static UEnum* DataFormat_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_DataFormat, Z_Construct_UPackage__Script_LoadDLL(), TEXT("DataFormat"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_DataFormat(DataFormat_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("DataFormat"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_DataFormat_CRC() { return 792486711U; }
	UEnum* Z_Construct_UEnum_LoadDLL_DataFormat()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("DataFormat"), 0, Get_Z_Construct_UEnum_LoadDLL_DataFormat_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "DataFormat::Json", (int64)DataFormat::Json },
				{ "DataFormat::Xml", (int64)DataFormat::Xml },
				{ "DataFormat::Yaml", (int64)DataFormat::Yaml },
				{ "DataFormat::Yml", (int64)DataFormat::Yml },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "ToolTip", "From OpenPose: op::DataFormat" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"DataFormat",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"DataFormat",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* DisplayMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_DisplayMode, Z_Construct_UPackage__Script_LoadDLL(), TEXT("DisplayMode"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_DisplayMode(DisplayMode_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("DisplayMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_DisplayMode_CRC() { return 4129948834U; }
	UEnum* Z_Construct_UEnum_LoadDLL_DisplayMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("DisplayMode"), 0, Get_Z_Construct_UEnum_LoadDLL_DisplayMode_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "DisplayMode::NoDisplay", (int64)DisplayMode::NoDisplay },
				{ "DisplayMode::DisplayAll", (int64)DisplayMode::DisplayAll },
				{ "DisplayMode::Display2D", (int64)DisplayMode::Display2D },
				{ "DisplayMode::Display3D", (int64)DisplayMode::Display3D },
				{ "DisplayMode::DisplayAdam", (int64)DisplayMode::DisplayAdam },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Display2D.ToolTip", "< All (2-D and 3-D/Adam) displays" },
				{ "Display3D.ToolTip", "< Only 2-D display." },
				{ "DisplayAdam.ToolTip", "< Only 3-D display." },
				{ "DisplayAll.ToolTip", "< No display." },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "NoDisplay.ToolTip", "original: uint16" },
				{ "ToolTip", "From OpenPose: op::DisplayMode" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"DisplayMode",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"DisplayMode",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* PoseModel_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_PoseModel, Z_Construct_UPackage__Script_LoadDLL(), TEXT("PoseModel"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_PoseModel(PoseModel_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("PoseModel"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_PoseModel_CRC() { return 4147398701U; }
	UEnum* Z_Construct_UEnum_LoadDLL_PoseModel()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("PoseModel"), 0, Get_Z_Construct_UEnum_LoadDLL_PoseModel_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "PoseModel::BODY_25", (int64)PoseModel::BODY_25 },
				{ "PoseModel::COCO_18", (int64)PoseModel::COCO_18 },
				{ "PoseModel::MPI_15", (int64)PoseModel::MPI_15 },
				{ "PoseModel::MPI_15_4", (int64)PoseModel::MPI_15_4 },
				{ "PoseModel::BODY_19", (int64)PoseModel::BODY_19 },
				{ "PoseModel::BODY_19_X2", (int64)PoseModel::BODY_19_X2 },
				{ "PoseModel::BODY_59", (int64)PoseModel::BODY_59 },
				{ "PoseModel::BODY_19N", (int64)PoseModel::BODY_19N },
				{ "PoseModel::BODY_25E", (int64)PoseModel::BODY_25E },
				{ "PoseModel::BODY_25_19", (int64)PoseModel::BODY_25_19 },
				{ "PoseModel::BODY_65", (int64)PoseModel::BODY_65 },
				{ "PoseModel::CAR_12", (int64)PoseModel::CAR_12 },
				{ "PoseModel::BODY_25D", (int64)PoseModel::BODY_25D },
				{ "PoseModel::BODY_23", (int64)PoseModel::BODY_23 },
				{ "PoseModel::CAR_22", (int64)PoseModel::CAR_22 },
				{ "PoseModel::Size", (int64)PoseModel::Size },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "BODY_19.ToolTip", "< Variation of the MPI model, reduced number of CNN stages to 4: faster but less accurate." },
				{ "BODY_19_X2.ToolTip", "< Experimental. Do not use." },
				{ "BODY_19N.ToolTip", "< Experimental. Do not use." },
				{ "BODY_23.ToolTip", "< Experimental. Do not use." },
				{ "BODY_25.ToolTip", "COCO + 6 foot keypoints + neck + lower abs model, with 25+1 components (see poseParameters.hpp for details)." },
				{ "BODY_25_19.ToolTip", "< Experimental. Do not use." },
				{ "BODY_25D.ToolTip", "< Experimental. Do not use." },
				{ "BODY_25E.ToolTip", "< Experimental. Do not use." },
				{ "BODY_59.ToolTip", "< Experimental. Do not use." },
				{ "BODY_65.ToolTip", "< Experimental. Do not use." },
				{ "CAR_12.ToolTip", "< Experimental. Do not use." },
				{ "CAR_22.ToolTip", "< Experimental. Do not use." },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "MPI_15.ToolTip", "< COCO model + neck, with 18+1 components (see poseParameters.hpp for details)." },
				{ "MPI_15_4.ToolTip", "< MPI model, with 15+1 components (see poseParameters.hpp for details)." },
				{ "Size.ToolTip", "< Experimental. Do not use." },
				{ "ToolTip", "From OpenPose: op::PoseModel" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"PoseModel",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"PoseModel",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ElementToRender_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_ElementToRender, Z_Construct_UPackage__Script_LoadDLL(), TEXT("ElementToRender"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ElementToRender(ElementToRender_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("ElementToRender"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_ElementToRender_CRC() { return 271701471U; }
	UEnum* Z_Construct_UEnum_LoadDLL_ElementToRender()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ElementToRender"), 0, Get_Z_Construct_UEnum_LoadDLL_ElementToRender_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ElementToRender::Skeleton", (int64)ElementToRender::Skeleton },
				{ "ElementToRender::Background", (int64)ElementToRender::Background },
				{ "ElementToRender::AddKeypoints", (int64)ElementToRender::AddKeypoints },
				{ "ElementToRender::AddPAFs", (int64)ElementToRender::AddPAFs },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "ToolTip", "From OpenPose: op::ElementToRender" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ElementToRender",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ElementToRender",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* RenderMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_RenderMode, Z_Construct_UPackage__Script_LoadDLL(), TEXT("RenderMode"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_RenderMode(RenderMode_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("RenderMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_RenderMode_CRC() { return 2730516484U; }
	UEnum* Z_Construct_UEnum_LoadDLL_RenderMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("RenderMode"), 0, Get_Z_Construct_UEnum_LoadDLL_RenderMode_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "RenderMode::None", (int64)RenderMode::None },
				{ "RenderMode::Auto", (int64)RenderMode::Auto },
				{ "RenderMode::Cpu", (int64)RenderMode::Cpu },
				{ "RenderMode::Gpu", (int64)RenderMode::Gpu },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Cpu.ToolTip", "It will select Gpu if CUDA verison, or Cpu otherwise" },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "ToolTip", "From OpenPose: op::RenderMode" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"RenderMode",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"RenderMode",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* HeatMapType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_HeatMapType, Z_Construct_UPackage__Script_LoadDLL(), TEXT("HeatMapType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_HeatMapType(HeatMapType_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("HeatMapType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_HeatMapType_CRC() { return 805843622U; }
	UEnum* Z_Construct_UEnum_LoadDLL_HeatMapType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("HeatMapType"), 0, Get_Z_Construct_UEnum_LoadDLL_HeatMapType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "HeatMapType::None", (int64)HeatMapType::None },
				{ "HeatMapType::Parts", (int64)HeatMapType::Parts },
				{ "HeatMapType::Background", (int64)HeatMapType::Background },
				{ "HeatMapType::PAFs", (int64)HeatMapType::PAFs },
				{ "HeatMapType::All", (int64)HeatMapType::All },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "ToolTip", "From OpenPose: op::HeatMapType  This one is DIFFERENT" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"HeatMapType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"HeatMapType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ScaleMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_ScaleMode, Z_Construct_UPackage__Script_LoadDLL(), TEXT("ScaleMode"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ScaleMode(ScaleMode_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("ScaleMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_ScaleMode_CRC() { return 1765952393U; }
	UEnum* Z_Construct_UEnum_LoadDLL_ScaleMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ScaleMode"), 0, Get_Z_Construct_UEnum_LoadDLL_ScaleMode_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ScaleMode::InputResolution", (int64)ScaleMode::InputResolution },
				{ "ScaleMode::NetOutputResolution", (int64)ScaleMode::NetOutputResolution },
				{ "ScaleMode::OutputResolution", (int64)ScaleMode::OutputResolution },
				{ "ScaleMode::ZeroToOne", (int64)ScaleMode::ZeroToOne },
				{ "ScaleMode::PlusMinusOne", (int64)ScaleMode::PlusMinusOne },
				{ "ScaleMode::UnsignedChar", (int64)ScaleMode::UnsignedChar },
				{ "ScaleMode::NoScale", (int64)ScaleMode::NoScale },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "NoScale.ToolTip", "[0, 255]" },
				{ "PlusMinusOne.ToolTip", "[0, 1]" },
				{ "ToolTip", "From OpenPose: op::ScaleMode" },
				{ "UnsignedChar.ToolTip", "[-1, 1]" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ScaleMode",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ScaleMode",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ProducerType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_ProducerType, Z_Construct_UPackage__Script_LoadDLL(), TEXT("ProducerType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ProducerType(ProducerType_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("ProducerType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_ProducerType_CRC() { return 2051703521U; }
	UEnum* Z_Construct_UEnum_LoadDLL_ProducerType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ProducerType"), 0, Get_Z_Construct_UEnum_LoadDLL_ProducerType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ProducerType::FlirCamera", (int64)ProducerType::FlirCamera },
				{ "ProducerType::ImageDirectory", (int64)ProducerType::ImageDirectory },
				{ "ProducerType::IPCamera", (int64)ProducerType::IPCamera },
				{ "ProducerType::Video", (int64)ProducerType::Video },
				{ "ProducerType::Webcam", (int64)ProducerType::Webcam },
				{ "ProducerType::None", (int64)ProducerType::None },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "FlirCamera.ToolTip", "Stereo FLIR (Point-Grey) camera reader. Based on Spinnaker SDK." },
				{ "ImageDirectory.ToolTip", "An image directory reader. It is able to read images on a folder with a interface similar to the OpenCV\ncv::VideoCapture." },
				{ "IPCamera.ToolTip", "An IP camera frames extractor, extending the functionality of cv::VideoCapture." },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "None.ToolTip", "No type defined. Default state when no specific Producer has been picked yet." },
				{ "ToolTip", "From OpenPose: op::ProducerType" },
				{ "Video.ToolTip", "A video frames extractor, extending the functionality of cv::VideoCapture." },
				{ "Webcam.ToolTip", "A webcam frames extractor, extending the functionality of cv::VideoCapture." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ProducerType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ProducerType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* Detector_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_Detector, Z_Construct_UPackage__Script_LoadDLL(), TEXT("Detector"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_Detector(Detector_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("Detector"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_Detector_CRC() { return 2342729961U; }
	UEnum* Z_Construct_UEnum_LoadDLL_Detector()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("Detector"), 0, Get_Z_Construct_UEnum_LoadDLL_Detector_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Detector::Body", (int64)Detector::Body },
				{ "Detector::OpenCV", (int64)Detector::OpenCV },
				{ "Detector::Provided", (int64)Detector::Provided },
				{ "Detector::BodyWithTracking", (int64)Detector::BodyWithTracking },
				{ "Detector::Size", (int64)Detector::Size },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "ToolTip", "From OpenPose: op::Detector" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"Detector",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"Detector",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* PoseMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_PoseMode, Z_Construct_UPackage__Script_LoadDLL(), TEXT("PoseMode"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_PoseMode(PoseMode_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("PoseMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_PoseMode_CRC() { return 4111401006U; }
	UEnum* Z_Construct_UEnum_LoadDLL_PoseMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("PoseMode"), 0, Get_Z_Construct_UEnum_LoadDLL_PoseMode_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "PoseMode::Disabled", (int64)PoseMode::Disabled },
				{ "PoseMode::Enabled", (int64)PoseMode::Enabled },
				{ "PoseMode::NoNetwork", (int64)PoseMode::NoNetwork },
				{ "PoseMode::Size", (int64)PoseMode::Size },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "ToolTip", "From OpenPose: op::PoseMode" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"PoseMode",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"PoseMode",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* Priority_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_Priority, Z_Construct_UPackage__Script_LoadDLL(), TEXT("Priority"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_Priority(Priority_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("Priority"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_Priority_CRC() { return 1839763400U; }
	UEnum* Z_Construct_UEnum_LoadDLL_Priority()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("Priority"), 0, Get_Z_Construct_UEnum_LoadDLL_Priority_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Priority::None", (int64)Priority::None },
				{ "Priority::Low", (int64)Priority::Low },
				{ "Priority::Normal", (int64)Priority::Normal },
				{ "Priority::High", (int64)Priority::High },
				{ "Priority::Max", (int64)Priority::Max },
				{ "Priority::NoOutput", (int64)Priority::NoOutput },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "ToolTip", "From OpenPose: op::Priority" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"Priority",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"Priority",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* OutputType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_OutputType, Z_Construct_UPackage__Script_LoadDLL(), TEXT("OutputType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_OutputType(OutputType_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("OutputType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_OutputType_CRC() { return 2093018413U; }
	UEnum* Z_Construct_UEnum_LoadDLL_OutputType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("OutputType"), 0, Get_Z_Construct_UEnum_LoadDLL_OutputType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "OutputType::None", (int64)OutputType::None },
				{ "OutputType::DatumsInfo", (int64)OutputType::DatumsInfo },
				{ "OutputType::Name", (int64)OutputType::Name },
				{ "OutputType::PoseKeypoints", (int64)OutputType::PoseKeypoints },
				{ "OutputType::PoseIds", (int64)OutputType::PoseIds },
				{ "OutputType::PoseScores", (int64)OutputType::PoseScores },
				{ "OutputType::PoseHeatMaps", (int64)OutputType::PoseHeatMaps },
				{ "OutputType::PoseCandidates", (int64)OutputType::PoseCandidates },
				{ "OutputType::FaceRectangles", (int64)OutputType::FaceRectangles },
				{ "OutputType::FaceKeypoints", (int64)OutputType::FaceKeypoints },
				{ "OutputType::FaceHeatMaps", (int64)OutputType::FaceHeatMaps },
				{ "OutputType::HandRectangles", (int64)OutputType::HandRectangles },
				{ "OutputType::HandKeypoints", (int64)OutputType::HandKeypoints },
				{ "OutputType::HandHeightMaps", (int64)OutputType::HandHeightMaps },
				{ "OutputType::PoseKeypoints3D", (int64)OutputType::PoseKeypoints3D },
				{ "OutputType::FaceKeypoints3D", (int64)OutputType::FaceKeypoints3D },
				{ "OutputType::HandKeypoints3D", (int64)OutputType::HandKeypoints3D },
				{ "OutputType::CameraMatrix", (int64)OutputType::CameraMatrix },
				{ "OutputType::CameraExtrinsics", (int64)OutputType::CameraExtrinsics },
				{ "OutputType::CameraIntrinsics", (int64)OutputType::CameraIntrinsics },
				{ "OutputType::Image", (int64)OutputType::Image },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "DatumsInfo.ToolTip", "Default value, also use as end of frame signal" },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "Name.ToolTip", "Includes: id, subId, subIdMax, frameNumber" },
				{ "ToolTip", "Output type for output callback" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"OutputType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"OutputType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* OPState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_LoadDLL_OPState, Z_Construct_UPackage__Script_LoadDLL(), TEXT("OPState"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_OPState(OPState_StaticEnum, TEXT("/Script/LoadDLL"), TEXT("OPState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_LoadDLL_OPState_CRC() { return 3445929754U; }
	UEnum* Z_Construct_UEnum_LoadDLL_OPState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_LoadDLL();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("OPState"), 0, Get_Z_Construct_UEnum_LoadDLL_OPState_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "OPState::None", (int64)OPState::None },
				{ "OPState::Ready", (int64)OPState::Ready },
				{ "OPState::Running", (int64)OPState::Running },
				{ "OPState::Stopping", (int64)OPState::Stopping },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/OPEnums.h" },
				{ "Ready.ToolTip", "Default value, not used" },
				{ "Running.ToolTip", "OP not yet started and ready to start" },
				{ "Stopping.ToolTip", "OP is running (or starting)" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_LoadDLL,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"OPState",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"OPState",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
