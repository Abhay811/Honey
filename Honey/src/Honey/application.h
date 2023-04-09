#pragma once

#include "core.h"

namespace Honey {
	class HONEY_API Application_C
	{
	public:
		Application_C();
		virtual ~Application_C();

		void Run();
	};

	Application_C* CreateApplication();
}
