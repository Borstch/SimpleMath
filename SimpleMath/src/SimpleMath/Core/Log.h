#pragma once

#include "SimpleMath.h"
#include <spdlog/spdlog.h>

namespace SimpleMath
{

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define SM_CORE_TRACE(...)		::SimpleMath::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SM_CORE_INFO(...)		::SimpleMath::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SM_CORE_WARN(...)		::SimpleMath::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SM_CORE_ERROR(...)		::SimpleMath::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SM_CORE_CRITICAL(...)	::SimpleMath::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SM_TRACE(...)			::SimpleMath::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SM_INFO(...)			::SimpleMath::Log::GetClientLogger()->info(__VA_ARGS__)
#define SM_WARN(...)			::SimpleMath::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SM_ERROR(...)			::SimpleMath::Log::GetClientLogger()->error(__VA_ARGS__)
#define SM_CRITICAL(...)		::SimpleMath::Log::GetClientLogger()->critical(__VA_ARGS__)