// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector2D;
enum class ProducerType : uint8;
#ifdef LOADDLL_LoadDLLBPLibrary_generated_h
#error "LoadDLLBPLibrary.generated.h already included, missing '#pragma once' in LoadDLLBPLibrary.h"
#endif
#define LOADDLL_LoadDLLBPLibrary_generated_h

#define OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOpenposeEnd) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::OpenposeEnd(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpenposeUpdate_OutputData) \
	{ \
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_poseKeypoints); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_numberPeople); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::OpenposeUpdate_OutputData(Z_Param_Out_poseKeypoints,Z_Param_Out_numberPeople); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpenposeUpdate) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::OpenposeUpdate(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpenposeStart) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::OpenposeStart(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execsetAllUserParam) \
	{ \
		P_GET_ENUM(ProducerType,Z_Param_inputType); \
		P_GET_PROPERTY(UStrProperty,Z_Param_producerString); \
		P_GET_PROPERTY(UIntProperty,Z_Param_maxPeople); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_renderThreshold); \
		P_GET_UBOOL(Z_Param_handEnabled); \
		P_GET_UBOOL(Z_Param_faceEnabled); \
		P_GET_PROPERTY(UIntProperty,Z_Param_netResolutionX); \
		P_GET_PROPERTY(UIntProperty,Z_Param_netResolutionY); \
		P_GET_PROPERTY(UIntProperty,Z_Param_handResolutionX); \
		P_GET_PROPERTY(UIntProperty,Z_Param_handResolutionY); \
		P_GET_PROPERTY(UIntProperty,Z_Param_faceResolutionX); \
		P_GET_PROPERTY(UIntProperty,Z_Param_faceResolutionY); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::setAllUserParam(ProducerType(Z_Param_inputType),Z_Param_producerString,Z_Param_maxPeople,Z_Param_renderThreshold,Z_Param_handEnabled,Z_Param_faceEnabled,Z_Param_netResolutionX,Z_Param_netResolutionY,Z_Param_handResolutionX,Z_Param_handResolutionY,Z_Param_faceResolutionX,Z_Param_faceResolutionY); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execfreeDLL) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::freeDLL(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execget_OPSetOutputEnableFromDll) \
	{ \
		P_GET_UBOOL(Z_Param_enable); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::get_OPSetOutputEnableFromDll(Z_Param_enable); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execimportMethod_OPSetOutputEnable) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULoadDLLBPLibrary::importMethod_OPSetOutputEnable(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execimportAllMethod_UE) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULoadDLLBPLibrary::importAllMethod_UE(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execimportDLL) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_folder); \
		P_GET_PROPERTY(UStrProperty,Z_Param_name); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULoadDLLBPLibrary::importDLL(Z_Param_folder,Z_Param_name); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadDLLSampleFunction) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Param); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULoadDLLBPLibrary::LoadDLLSampleFunction(Z_Param_Param); \
		P_NATIVE_END; \
	}


#define OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOpenposeEnd) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::OpenposeEnd(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpenposeUpdate_OutputData) \
	{ \
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_poseKeypoints); \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_numberPeople); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::OpenposeUpdate_OutputData(Z_Param_Out_poseKeypoints,Z_Param_Out_numberPeople); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpenposeUpdate) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::OpenposeUpdate(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpenposeStart) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::OpenposeStart(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execsetAllUserParam) \
	{ \
		P_GET_ENUM(ProducerType,Z_Param_inputType); \
		P_GET_PROPERTY(UStrProperty,Z_Param_producerString); \
		P_GET_PROPERTY(UIntProperty,Z_Param_maxPeople); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_renderThreshold); \
		P_GET_UBOOL(Z_Param_handEnabled); \
		P_GET_UBOOL(Z_Param_faceEnabled); \
		P_GET_PROPERTY(UIntProperty,Z_Param_netResolutionX); \
		P_GET_PROPERTY(UIntProperty,Z_Param_netResolutionY); \
		P_GET_PROPERTY(UIntProperty,Z_Param_handResolutionX); \
		P_GET_PROPERTY(UIntProperty,Z_Param_handResolutionY); \
		P_GET_PROPERTY(UIntProperty,Z_Param_faceResolutionX); \
		P_GET_PROPERTY(UIntProperty,Z_Param_faceResolutionY); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::setAllUserParam(ProducerType(Z_Param_inputType),Z_Param_producerString,Z_Param_maxPeople,Z_Param_renderThreshold,Z_Param_handEnabled,Z_Param_faceEnabled,Z_Param_netResolutionX,Z_Param_netResolutionY,Z_Param_handResolutionX,Z_Param_handResolutionY,Z_Param_faceResolutionX,Z_Param_faceResolutionY); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execfreeDLL) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::freeDLL(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execget_OPSetOutputEnableFromDll) \
	{ \
		P_GET_UBOOL(Z_Param_enable); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		ULoadDLLBPLibrary::get_OPSetOutputEnableFromDll(Z_Param_enable); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execimportMethod_OPSetOutputEnable) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULoadDLLBPLibrary::importMethod_OPSetOutputEnable(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execimportAllMethod_UE) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULoadDLLBPLibrary::importAllMethod_UE(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execimportDLL) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_folder); \
		P_GET_PROPERTY(UStrProperty,Z_Param_name); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=ULoadDLLBPLibrary::importDLL(Z_Param_folder,Z_Param_name); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadDLLSampleFunction) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Param); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=ULoadDLLBPLibrary::LoadDLLSampleFunction(Z_Param_Param); \
		P_NATIVE_END; \
	}


#define OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULoadDLLBPLibrary(); \
	friend LOADDLL_API class UClass* Z_Construct_UClass_ULoadDLLBPLibrary(); \
public: \
	DECLARE_CLASS(ULoadDLLBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LoadDLL"), NO_API) \
	DECLARE_SERIALIZER(ULoadDLLBPLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_INCLASS \
private: \
	static void StaticRegisterNativesULoadDLLBPLibrary(); \
	friend LOADDLL_API class UClass* Z_Construct_UClass_ULoadDLLBPLibrary(); \
public: \
	DECLARE_CLASS(ULoadDLLBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LoadDLL"), NO_API) \
	DECLARE_SERIALIZER(ULoadDLLBPLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULoadDLLBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULoadDLLBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULoadDLLBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULoadDLLBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULoadDLLBPLibrary(ULoadDLLBPLibrary&&); \
	NO_API ULoadDLLBPLibrary(const ULoadDLLBPLibrary&); \
public:


#define OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULoadDLLBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULoadDLLBPLibrary(ULoadDLLBPLibrary&&); \
	NO_API ULoadDLLBPLibrary(const ULoadDLLBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULoadDLLBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULoadDLLBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULoadDLLBPLibrary)


#define OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_PRIVATE_PROPERTY_OFFSET
#define OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_35_PROLOG
#define OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_PRIVATE_PROPERTY_OFFSET \
	OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_RPC_WRAPPERS \
	OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_INCLASS \
	OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_PRIVATE_PROPERTY_OFFSET \
	OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_INCLASS_NO_PURE_DECLS \
	OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h_38_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class LoadDLLBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_LoadDLLBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
