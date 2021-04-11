// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LOADDLL_OPEnums_generated_h
#error "OPEnums.generated.h already included, missing '#pragma once' in OPEnums.h"
#endif
#define LOADDLL_OPEnums_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID OP_BrandNewTest_Plugins_LoadDLL_Source_LoadDLL_Public_OPEnums_h


#define FOREACH_ENUM_DATAFORMAT(op) \
	op(DataFormat::Json) \
	op(DataFormat::Xml) \
	op(DataFormat::Yaml) \
	op(DataFormat::Yml) 
#define FOREACH_ENUM_DISPLAYMODE(op) \
	op(DisplayMode::NoDisplay) \
	op(DisplayMode::DisplayAll) \
	op(DisplayMode::Display2D) \
	op(DisplayMode::Display3D) \
	op(DisplayMode::DisplayAdam) 
#define FOREACH_ENUM_POSEMODEL(op) \
	op(PoseModel::BODY_25) \
	op(PoseModel::COCO_18) \
	op(PoseModel::MPI_15) \
	op(PoseModel::MPI_15_4) \
	op(PoseModel::BODY_19) \
	op(PoseModel::BODY_19_X2) \
	op(PoseModel::BODY_59) \
	op(PoseModel::BODY_19N) \
	op(PoseModel::BODY_25E) \
	op(PoseModel::BODY_25_19) \
	op(PoseModel::BODY_65) \
	op(PoseModel::CAR_12) \
	op(PoseModel::BODY_25D) \
	op(PoseModel::BODY_23) \
	op(PoseModel::CAR_22) \
	op(PoseModel::Size) 
#define FOREACH_ENUM_ELEMENTTORENDER(op) \
	op(ElementToRender::Skeleton) \
	op(ElementToRender::Background) \
	op(ElementToRender::AddKeypoints) \
	op(ElementToRender::AddPAFs) 
#define FOREACH_ENUM_RENDERMODE(op) \
	op(RenderMode::None) \
	op(RenderMode::Auto) \
	op(RenderMode::Cpu) \
	op(RenderMode::Gpu) 
#define FOREACH_ENUM_HEATMAPTYPE(op) \
	op(HeatMapType::None) \
	op(HeatMapType::Parts) \
	op(HeatMapType::Background) \
	op(HeatMapType::PAFs) \
	op(HeatMapType::All) 
#define FOREACH_ENUM_SCALEMODE(op) \
	op(ScaleMode::InputResolution) \
	op(ScaleMode::NetOutputResolution) \
	op(ScaleMode::OutputResolution) \
	op(ScaleMode::ZeroToOne) \
	op(ScaleMode::PlusMinusOne) \
	op(ScaleMode::UnsignedChar) \
	op(ScaleMode::NoScale) 
#define FOREACH_ENUM_PRODUCERTYPE(op) \
	op(ProducerType::FlirCamera) \
	op(ProducerType::ImageDirectory) \
	op(ProducerType::IPCamera) \
	op(ProducerType::Video) \
	op(ProducerType::Webcam) \
	op(ProducerType::None) 
#define FOREACH_ENUM_DETECTOR(op) \
	op(Detector::Body) \
	op(Detector::OpenCV) \
	op(Detector::Provided) \
	op(Detector::BodyWithTracking) \
	op(Detector::Size) 
#define FOREACH_ENUM_POSEMODE(op) \
	op(PoseMode::Disabled) \
	op(PoseMode::Enabled) \
	op(PoseMode::NoNetwork) \
	op(PoseMode::Size) 
#define FOREACH_ENUM_PRIORITY(op) \
	op(Priority::None) \
	op(Priority::Low) \
	op(Priority::Normal) \
	op(Priority::High) \
	op(Priority::Max) \
	op(Priority::NoOutput) 
#define FOREACH_ENUM_OUTPUTTYPE(op) \
	op(OutputType::None) \
	op(OutputType::DatumsInfo) \
	op(OutputType::Name) \
	op(OutputType::PoseKeypoints) \
	op(OutputType::PoseIds) \
	op(OutputType::PoseScores) \
	op(OutputType::PoseHeatMaps) \
	op(OutputType::PoseCandidates) \
	op(OutputType::FaceRectangles) \
	op(OutputType::FaceKeypoints) \
	op(OutputType::FaceHeatMaps) \
	op(OutputType::HandRectangles) \
	op(OutputType::HandKeypoints) \
	op(OutputType::HandHeightMaps) \
	op(OutputType::PoseKeypoints3D) \
	op(OutputType::FaceKeypoints3D) \
	op(OutputType::HandKeypoints3D) \
	op(OutputType::CameraMatrix) \
	op(OutputType::CameraExtrinsics) \
	op(OutputType::CameraIntrinsics) \
	op(OutputType::Image) 
#define FOREACH_ENUM_OPSTATE(op) \
	op(OPState::None) \
	op(OPState::Ready) \
	op(OPState::Running) \
	op(OPState::Stopping) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
