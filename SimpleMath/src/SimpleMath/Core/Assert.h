#pragma once

/*
* https://github.com/TheCherno/Hazel/blob/master/Hazel/src/Hazel/Core/Assert.h
*/

#include "SimpleMath/Core/Base.h"
#include "SimpleMath/Core/Log.h"
#include <filesystem>

#ifdef SM_ENABLE_ASSERTS

	#define SM_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { SM##type##ERROR(msg, __VA_ARGS__); SM_DEBUGBREAK(); } }
	#define SM_INTERNAL_ASSERT_WITH_MSG(type, check, ...) SM_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define SM_INTERNAL_ASSERT_NO_MSG(type, check) SM_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", SM_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define SM_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define SM_INTERNAL_ASSERT_GET_MACRO(...) SM_EXPAND_MACRO( SM_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, SM_INTERNAL_ASSERT_WITH_MSG, SM_INTERNAL_ASSERT_NO_MSG) )

	#define SM_ASSERT(...) SM_EXPAND_MACRO( SM_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define SM_CORE_ASSERT(...) SM_EXPAND_MACRO( SM_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )

#else

	#define SM_ASSERT(...)
	#define SM_CORE_ASSERT(...)

#endif