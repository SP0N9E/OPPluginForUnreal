// Some copyright should be here...

using UnrealBuildTool;
using System;
using System.IO;

public class LoadDLL : ModuleRules
{
    private string OpenPosePath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/OpenPose/")); }
    }

    private string OpenPose3rdParty
    {
        get { return Path.GetFullPath(Path.Combine(OpenPosePath, "3rdparty")); }
    }

    private string OpenPoseInclude
    {
        get { return Path.GetFullPath(Path.Combine(OpenPosePath, "include")); }
    }
    private string OpenPoseLibPath
    {
        get { return Path.GetFullPath(Path.Combine(OpenPosePath, "lib")); }
    }

    private string OpenCVInclude
    {
        get { return Path.GetFullPath(Path.Combine(OpenPose3rdParty, "windows/opencv/include")); }
    }

    private string OpenCVLibPath
    {
        get { return Path.GetFullPath(Path.Combine(OpenPose3rdParty, "windows/opencv/x64/vc15/lib")); }
    }

    private string OpenCVDllPath
    {
        get { return Path.GetFullPath(Path.Combine(OpenPose3rdParty, "windows/opencv/x64/vc15/bin")); }
    }

    public LoadDLL(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"LoadDLL/Public",
                Path.Combine(OpenCVInclude),

				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"LoadDLL/Private",
                Path.Combine(OpenCVInclude),
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "OpenCV",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Projects",
                "InputCore",
                "UnrealEd",
                "LevelEditor",
                "CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",

				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        //Add OpenCV lib and load dlls
        PublicLibraryPaths.Add(OpenCVLibPath);
        //PublicDelayLoadDLLs.Add("opencv_world401.dll");
        //PublicDelayLoadDLLs.Add("opencv_ffmpeg401_64.dll");
        //PublicAdditionalLibraries.Add("opencv_world401.lib");

        //Load caffe dll

        //Add OpenPose lib and load dlls
        PublicLibraryPaths.Add(OpenPoseLibPath);
        //PublicDelayLoadDLLs.Add("openpose.dll");
        //PublicAdditionalLibraries.Add("openpose.lib");
    }
}
