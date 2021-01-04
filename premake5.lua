workspace "SimpleMath"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

project "SimpleMath"
	location "SimpleMath"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	cppdialect "C++11"
	staticruntime "On"
	systemversion "latest"

	defines
	{
		"SM_BUILD_LIB"
	}

	filter "configurations:Debug"
		defines "SM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SM_DIST"
		optimize "On"

project "Application"
	location "Application"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"SimpleMath/vendor/spdlog/include",
		"SimpleMath/src"
	}

	links
	{
		"SimpleMath"
	}

	cppdialect "C++11"
	staticruntime "On"
	systemversion "latest"

	filter "configurations:Debug"
		defines "SM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SM_DIST"
		optimize "On"