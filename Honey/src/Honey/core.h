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


#define BIT(x) (1 << x)