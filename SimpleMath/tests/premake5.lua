workspace "SimpleTest"
	architecture "x64"
	startproject "SimpleTest"

	configurations
	{
		"Test"
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
		"%{prj.name}/*.h",
		"%{prj.name}/*.cpp",
	}

	includedirs
	{
		"%{IncludeDir.googletest}",
		"%{wks.location}/../src",
		"%{wks.location}/../vendor/spdlog/include"
	}

	links
	{
		"googletest",
		"SimpleMath"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Test"
		runtime "Debug"
		symbols "On"

group "Dependencies"
	include "../vendor/googletest/googletest"
group ""
includeexternal "SimpleMath"