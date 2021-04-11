// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OPEnums.h"
#include "Queue.h"

/**
 * 
 */
class LOADDLL_API OPDatums
{
public:
	OPDatums();
	~OPDatums();
};

// struct Rect to record the rectangle information
// similar to Unity Rect
struct Rect
{
	float x; // left bottom
	float y; // left bottom
	float width;
	float height;
	Rect(float _x, float _y, float _width, float _height) :x(_x), y(_y), width(_width), height(_height) {}
	Rect() :x(0), y(0), width(0), height(0) {}
	// Vector2D center() need to be done
};

template <typename T> class Pair
{

public:
	Pair() { /*T left; T right;*/ }
	Pair(T Left, T Right) : left(Left), right(Right) {}
	T getLeft() { return this->left; }
	T getRight() { return this->right; }
	T setLeft(T left) { this->left = left; }
	T setRight(T right) { this->right = right; }
private:
	T left;
	T right;
};


template <typename T> class MultiArray
{

public:
	MultiArray() { data.Init(0, 0); sizes.Init(0, 0); }
	MultiArray(const TArray<T>& collection, const TArray<int>& sizes)
	{
		this->data = collection;
		this->sizes = sizes;
	}
	MultiArray(const TArray<T>& collection): data(collection){}
	// copy constructor
	MultiArray(const MultiArray<T>& array): data(array.data), sizes(array.sizes) {}
	// copy assignment
	MultiArray<T>& operator=(const MultiArray<T>& array)
	{
		data = array.data;
		sizes = array.sizes;
		return *this;
	}

	// get specific data according to bodyIndex, part and dimension
	T Get(int bodyIndex, int part, int dimension)
	{
		if (this->sizes.Num() > 3)
		{
			UE_LOG(LogTemp, Error, TEXT("Get DATA according to bodyIndex, part and dimension Error! Size overflow"));
			return -1;
		}
		int index = 0;
		int accumulated = 1;

		index += accumulated * dimension;
		accumulated *= this->sizes[2];

		index += accumulated * part;
		accumulated *= this->sizes[1];

		index += accumulated * bodyIndex;
		accumulated *= this->sizes[0];
		return this->data[index];
	}
	const TArray<int>& GetSize()
	{
		return sizes;
	}
	// Get Specific size according to layer
	int GetLayerSize(int layer)
	{
		if (layer < 0 || layer >= this->sizes.Num())
			return 0;
		return this->sizes[layer];
	}
	// Get size dimensions
	int GetDimensions()
	{
		return this->sizes.Num();
	}
	// true if empty
	bool Empty()
	{
		return (this->data.Num() == 0);
	}
private:
	void Resize(TArray<int> sizes)
	{
		this->sizes = sizes;
		int volume = 0;
		if (sizes.Num() == 0)
			volume = 0;
		else
		{
			volume = 1;
			for (auto& i : sizes) { volume *= i; }
		}

	}

	TArray<T> data;
	TArray<int> sizes;
};

//struct Rect;

struct OPDatum
{
	// constructor
	//OPDatum() :id(ULONGLONG_MAX), subId(0), subIdMax(0), frameNumber(0){}
	// constructor
	OPDatum() :id(ULONGLONG_MAX), subId(0), subIdMax(0) {}
	// copy constructor
	OPDatum(const OPDatum& Datum) :
	// ID
		id { Datum.id },
		subId{ Datum.subId },
		subIdMax{ Datum.subIdMax },
		name{ Datum.name },
		frameNumber{ Datum.frameNumber },
	// Input image and rendered version
		cvInputData{ Datum.cvInputData },
	// Resulting Array<float> data parameters
		poseKeypoints{ Datum.poseKeypoints },
		poseIds{ Datum.poseIds },
		poseScores{ Datum.poseScores },
		poseHeatMaps{ Datum.poseHeatMaps },
		poseCandidates{ Datum.poseCandidates },
		faceRectangles{ Datum.faceRectangles },
		faceKeypoints{ Datum.faceKeypoints },
		faceHeatMaps{ Datum.faceHeatMaps },
		handRectangles{ Datum.handRectangles },
		handKeypoints(Datum.handKeypoints), // Parentheses instead of braces to avoid error in GCC 4.8
		handHeatMaps(Datum.handHeatMaps), // Parentheses instead of braces to avoid error in GCC 4.8
	// 3-D Reconstruction parameters
		poseKeypoints3D{ Datum.poseKeypoints3D },
		faceKeypoints3D{ Datum.faceKeypoints3D },
		handKeypoints3D(Datum.handKeypoints3D) {} // Parentheses instead of braces to avoid error in GCC 4.8

	// copy assignment
	OPDatum& operator=(const OPDatum& Datum)
	{
		// ID
		id = Datum.id;
		subId = Datum.subId;
		subIdMax = Datum.subIdMax;
		name = Datum.name;
		frameNumber = Datum.frameNumber;
		// Input image and rendered version
		cvInputData = Datum.cvInputData;
		// Resulting Array<float> data parameters
		poseKeypoints = Datum.poseKeypoints;
		poseIds = Datum.poseIds;
		poseScores = Datum.poseScores;
		poseHeatMaps = Datum.poseHeatMaps;
		poseCandidates = Datum.poseCandidates;
		faceRectangles = Datum.faceRectangles;
		faceKeypoints = Datum.faceKeypoints;
		faceHeatMaps = Datum.faceHeatMaps;
		handRectangles = Datum.handRectangles;
		handKeypoints = Datum.handKeypoints; // Parentheses instead of braces to avoid error in GCC 4.8
		handHeatMaps = Datum.handHeatMaps; // Parentheses instead of braces to avoid error in GCC 4.8
		// 3-D Reconstruction parameters
		poseKeypoints3D = Datum.poseKeypoints3D;
		faceKeypoints3D = Datum.faceKeypoints3D;
		handKeypoints3D = Datum.handKeypoints3D;
		return *this;
	}
		 

	
	uint64 id; /**< Datum ID. Internally used to sort the Datums if multi-threading is used. */
	uint64 subId; /**< Datum sub-ID. Internally used to sort the Datums if multi-threading is used. */
	uint64 subIdMax; /**< Datum maximum sub-ID. Used to sort the Datums if multi-threading is used. */

	/**
	* Name used when saving the data to disk (e.g. `write_images` or `write_keypoint` flags in the demo).
	*/
	FString name;
	/**
	* Corresponding frame number.
	* If the producer (e.g., video) starts from frame 0 and does not repeat any frame, then frameNumber should
	* match the field id.
	*/
	uint64 frameNumber;

	// --------------------------- Input image and rendered version parameters ---------------------------- //
	/**
	 * Original image to be processed in cv::Mat uchar format.
	 * Size: (input_width x input_height) x 3 channels (BGR)
	 */
	MultiArray<uint8> cvInputData;

	// Other parameters not available

	// ------------------------------ Resulting Array<float> data parameters ------------------------------ //
	/**
	 * Body pose (x,y,score) locations for each person in the image.
	 * It has been resized to the desired output resolution (e.g. `resolution` flag in the demo).
	 * Size: #people x #body parts (e.g. 18 for COCO or 15 for MPI) x 3 ((x,y) coordinates + score)
	 */
	MultiArray<float> poseKeypoints;

	/**
	 * People ID
	 * It returns a person ID for each body pose, providing temporal consistency. The ID will be the same one
	 * for a person across frames. I.e. this ID allows to keep track of the same person in time.
	 * If either person identification is disabled or poseKeypoints is empty, poseIds will also be empty.
	 * Size: #people
	 */
	MultiArray<long> poseIds;

	/**
	 * Body pose global confidence/score for each person in the image.
	 * It does not only consider the score of each body keypoint, but also the score of each PAF association.
	 * Optimized for COCO evaluation metric.
	 * It will highly penalyze people with missing body parts (e.g. cropped people on the borders of the image).
	 * If poseKeypoints is empty, poseScores will also be empty.
	 * Size: #people
	 */
	MultiArray<float> poseScores;

	/**
	 * Body pose heatmaps (body parts, background and/or PAFs) for the whole image.
	 * This parameter is by default empty and disabled for performance. Each group (body parts, background and
	 * PAFs) can be individually enabled.
	 * #heatmaps = #body parts (if enabled) + 1 (if background enabled) + 2 x #PAFs (if enabled). Each PAF has 2
	 * consecutive channels, one for x- and one for y-coordinates.
	 * Order heatmaps: body parts + background (as appears in POSE_BODY_PART_MAPPING) + (x,y) channel of each PAF
	 * (sorted as appears in POSE_BODY_PART_PAIRS). See `pose/poseParameters.hpp`.
	 * The user can choose the heatmaps normalization: ranges [0, 1], [-1, 1] or [0, 255]. Check the
	 * `heatmaps_scale` flag in {OpenPose_path}doc/demo_overview.md for more details.
	 * Size: #heatmaps x output_net_height x output_net_width
	 */
	MultiArray<float> poseHeatMaps;

	/**
	 * Body pose candidates for the whole image.
	 * This parameter is by default empty and disabled for performance. It can be enabled with `candidates_body`.
	 * Candidates refer to all the detected body parts, before being assembled into people. Note that the number
	 * of candidates is equal or higher than the number of body parts after being assembled into people.
	 * Size: #body parts x min(part candidates, POSE_MAX_PEOPLE) x 3 (x,y,score).
	 * Rather than vector, it should ideally be:
	 * std::array<std::vector<std::array<float,3>>, #BP> poseCandidates;
	 */
	TArray<TArray<FVector>> poseCandidates;// Not supported yet

	/**
	 * Face detection locations (x,y,width,height) for each person in the image.
	 * It is resized to cvInputData.size().
	 * Size: #people
	 */
	TArray<Rect> faceRectangles;

	/**
	 * Face keypoints (x,y,score) locations for each person in the image.
	 * It has been resized to the same resolution as `poseKeypoints`.
	 * Size: #people x #face parts (70) x 3 ((x,y) coordinates + score)
	 */
	MultiArray<float> faceKeypoints;

	/**
	 * Face pose heatmaps (face parts and/or background) for the whole image.
	 * Analogous of bodyHeatMaps applied to face. However, there is no PAFs and the size is different.
	 * Size: #people x #face parts (70) x output_net_height x output_net_width
	 */
	MultiArray<float> faceHeatMaps;

	/**
	 * Hand detection locations (x,y,width,height) for each person in the image.
	 * It is resized to cvInputData.size().
	 * Size: #people
	 */
	TArray<Pair<Rect>> handRectangles;

	/**
	 * Hand keypoints (x,y,score) locations for each person in the image.
	 * It has been resized to the same resolution as `poseKeypoints`.
	 * handKeypoints[0] corresponds to left hands, and handKeypoints[1] to right ones.
	 * Size each Array: #people x #hand parts (21) x 3 ((x,y) coordinates + score)
	 */
	Pair<MultiArray<float>> handKeypoints;

	/**
	 * Hand pose heatmaps (hand parts and/or background) for the whole image.
	 * Analogous of faceHeatMaps applied to face.
	 * Size each Array: #people x #hand parts (21) x output_net_height x output_net_width
	 */
	Pair<MultiArray<float>> handHeatMaps;

	// ---------------------------------------- 3-D Reconstruction parameters ---------------------------------------- //
	/**
	 * Body pose (x,y,z,score) locations for each person in the image.
	 * Size: #people x #body parts (e.g. 18 for COCO or 15 for MPI) x 4 ((x,y,z) coordinates + score)
	 */
	MultiArray<float> poseKeypoints3D; // Not supported yet

	/**
	 * Face keypoints (x,y,z,score) locations for each person in the image.
	 * It has been resized to the same resolution as `poseKeypoints3D`.
	 * Size: #people x #face parts (70) x 4 ((x,y,z) coordinates + score)
	 */
	MultiArray<float> faceKeypoints3D; // Not supported yet

	/**
	 * Hand keypoints (x,y,z,score) locations for each person in the image.
	 * It has been resized to the same resolution as `poseKeypoints3D`.
	 * handKeypoints[0] corresponds to left hands, and handKeypoints[1] to right ones.
	 * Size each Array: #people x #hand parts (21) x 4 ((x,y,z) coordinates + score)
	 */
	Pair<MultiArray<float>> handKeypoints3D; // Not supported yet

	///**
	// * 3x4 camera matrix of the camera (equivalent to cameraIntrinsics * cameraExtrinsics).
	// */
	//Matrix4x4 cameraMatrix; // Not supported yet

	///**
	// * 3x4 extrinsic parameters of the camera.
	// */
	//Matrix4x4 cameraExtrinsics; // Not supported yet

	///**
	// * 3x3 intrinsic parameters of the camera.
	// */
	//Matrix4x4 cameraIntrinsics; // Not supported yet
};


