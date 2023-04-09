#pragma once

#include<memory>


#include "core.h"
#include "spdlog/spdlog.h"

namespace Honey {

	class HONEY_API Log_C
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_core_logger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_client_logger; }

	private:
		static std::shared_ptr<spdlog::logger> s_core_logger;
		static std::shared_ptr<spdlog::logger> s_client_logger;
	};

}

// core logger
#define HONEY_CORE_ERROR(...)	::Honey::Log_C::GetCoreLogger()->error(__VA_ARGS__)
#define HONEY_CORE_WARN(...)	::Honey::Log_C::GetCoreLogger()->warn(__VA_ARGS__)
#define HONEY_CORE_INFO(...)	::Honey::Log_C::GetCoreLogger()->info(__VA_ARGS__)
#define HONEY_CORE_TRACE(...)	::Honey::Log_C::GetCoreLogger()->trace(__VA_ARGS__)
#define HONEY_CORE_FATAL(...)	::Honey::Log_C::GetCoreLogger()->fatal(__VA_ARGS__)

// client logger
#define HONEY_ERROR(...)		::Honey::Log_C::GetClientLogger()->error(__VA_ARGS__)
#define HONEY_WARN(...)			::Honey::Log_C::GetClientLogger()->warn(__VA_ARGS__)
#define HONEY_INFO(...)			::Honey::Log_C::GetClientLogger()->info(__VA_ARGS__)
#define HONEY_TRACE(...)		::Honey::Log_C::GetClientLogger()->trace(__VA_ARGS__)
#define HONEY_FATAL(...)		::Honey::Log_C::GetClientLogger()->fatal(__VA_ARGS__)