#include "honey_pch.h"
#include "application.h"

#include "Honey/Events/application_event.h"
#include "Honey/log.h"

namespace Honey {
	Application_C::Application_C()
	{
		_window = std::unique_ptr<Window_C>(Window_C::Create());
	}

	Application_C::~Application_C()
	{

	}

	void Application_C::Run()
	{
		while (_running) {
			_window->OnUpdate();
		}
	}
}