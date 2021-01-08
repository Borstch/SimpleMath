project "Application"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++11"
	staticruntime "On"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.location}/src/**.h",
		"%{prj.location}/src/**.cpp",
	}

	includedirs
	{
		"%{wks.location}/SimpleMath/vendor/spdlog/include",
		"%{wks.location}/SimpleMath/src"
	}

	links
	{
		"SimpleMath"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "SM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SM_DIST"
		runtime "Release"
		optimize "On"