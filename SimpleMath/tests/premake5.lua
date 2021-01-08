workspace "SimpleTest"
	architecture "x64"
	startproject "SimpleTest"

	configurations
	{
		"Debug",
		"Release"
	}

-- Absolute paths to static libs include dirs
IncludeDir = {}
IncludeDir["googletest"] = "%{wks.location}/../vendor/googletest/googletest/include"

project "SimpleTest"
	location "SimpleTest"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++11"
	staticruntime "On"
	systemversion "latest"

	targetdir ("%{wks.location}/../../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/../../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
	}

	includedirs
	{
		"%{IncludeDir.googletest}"
	}

	links
	{
		"googletest",
		"SimpleMath"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"

group "Dependencies"
	include "../vendor/googletest/googletest"
group ""
includeexternal "SimpleMath"