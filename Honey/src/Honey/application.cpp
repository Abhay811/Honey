#include "honey_pch.h"
#include "application.h"


#include "Honey/log.h"
#include "Honey/Events/event.h"

namespace Honey {

#define BIND_EVENT(x) std::bind(&Application_C::x, this, std::placeholders::_1)

	Application_C::Application_C()
	{
		_window = std::unique_ptr<Window_C>(Window_C::Create());
		_window->SetEventCallback(BIND_EVENT(OnEvent));
	}

	Application_C::~Application_C()
	{

	}

	void Application_C::OnEvent(Event_C& event)
	{
		EventDispatcher_C dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent_C>(BIND_EVENT(OnWindowClose));
		HONEY_CORE_TRACE("{0}", event);
	}
	void Application_C::Run()
	{
		while (_running) {
			_window->OnUpdate();
		}
	}

	bool Application_C::OnWindowClose(WindowCloseEvent_C& event)
	{
		_running = false;
		return true;
	}
}