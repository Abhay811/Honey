#pragma once

#ifdef HONEY_PLATFORM_WINDOWS
	#ifdef HONEY_BUILD_DLL
		#define HONEY_API __declspec(dllexport)
	#else
		#define HONEY_API __declspec(dllimport)
	#endif
#else
	#error Honey only support Windows!
#endif

#ifdef HONEY_ENABLE_ASSERTS
	#define HONEY_ASSERT(x, ...) { if(!(x)) { HONEY_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HONEY_CORE_ASSERT(x, ...) { if(!(x)) { HONEY_CORE_ERROR("Assertion Failed: {0}", _VA_ARGS__); __debugbreak(); } }
#else
	#define HONEY_ASSERT(x, ...)
	#define HONEY_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HONEY_BIND_EVENT_FUN(fn) std::bind(&fn, this, std::placeholders::_1)