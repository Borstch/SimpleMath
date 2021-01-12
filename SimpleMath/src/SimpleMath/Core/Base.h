#pragma once

/*
* https://github.com/TheCherno/Hazel/blob/master/Hazel/src/Hazel/Core/Base.h
*/

#include "PlatformDetection.h"

#ifdef SMATH_DEBUG
	#if defined(SM_PLATFORM_WINDOWS)
		#define SM_DEBUGBREAK() __debugbreak()
	#elif defined(SM_PLATFORM_LINUX)
		#include <signal.h>
		#define SM_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define SM_ENABLE_ASSERTS
#else
	#define SM_DEBUGBREAK()
#endif

#define SM_EXPAND_MACRO(x) x
#define SM_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)