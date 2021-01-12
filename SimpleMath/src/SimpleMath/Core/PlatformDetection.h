#pragma once

/*
* https://github.com/TheCherno/Hazel/blob/master/Hazel/src/Hazel/Core/PlatformDetection.h 
*/

#ifdef _WIN32
	#ifdef _WIN64
		#define SM_PLATFORM_WINDOWS
	#else
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>

	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define SM_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple platform!"
	#endif
#elif defined(__ANDROID__)
	#error "Android is not supported!"
#elif defined(__linux__)
	#define SM_PLATFORM_LINUX
#else
	#error "Unknown platform!"
#endif