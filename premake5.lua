workspace "SimpleMath"
	architecture "x64"

	configurations
	{
		"Test",
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

include "SimpleMath"
include "Application"

include "SimpleMath/tests"