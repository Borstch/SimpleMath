project "SimpleMath"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
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
		"%{prj.location}/vendor/spdlog/include",
		"%{prj.location}/src"
	}

	defines
	{
		"SM_BUILD_LIB"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Test"
		defines "SMATH_TEST"
		runtime "Debug"
		symbols "On"

	filter "configurations:Debug"
		defines "SMATH_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SMATH_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SMATH_DIST"
		runtime "Release"
		optimize "On"