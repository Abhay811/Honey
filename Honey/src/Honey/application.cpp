#include "application.h"

#include "Honey/Events/application_event.h"
#include "Honey/log.h"

namespace Honey {
	Application_C::Application_C()
	{

	}

	Application_C::~Application_C()
	{

	}

	void Application_C::Run()
	{
		WindowResizeEvent_C e(1280, 720);
		HONEY_TRACE(e);
		while (true);
	}
}