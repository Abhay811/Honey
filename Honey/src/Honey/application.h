#pragma once

#include "core.h"
#include "Events/event.h"
#include "window.h"

namespace Honey {
	class HONEY_API Application_C
	{
	public:
		Application_C();
		virtual ~Application_C();

		void Run();
	private:
		std::unique_ptr<Window_C> _window;
		bool _running = true;
	};

	Application_C* CreateApplication();
}
