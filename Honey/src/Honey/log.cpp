#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Honey
{
	std::shared_ptr<spdlog::logger> Log_C::s_core_logger;
	std::shared_ptr<spdlog::logger> Log_C::s_client_logger;


	void Log_C::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_core_logger = spdlog::stdout_color_mt("HONEY");
		s_core_logger->set_level(spdlog::level::trace);

		s_client_logger = spdlog::stdout_color_mt("APP");
		s_client_logger->set_level(spdlog::level::trace);
	}
}