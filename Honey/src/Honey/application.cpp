#include "honey_pch.h"
#include "application.h"


#include "Honey/log.h"
#include <glad/glad.h>

namespace Honey {

#define BIND_EVENT(x) std::bind(&Application_C::x, this, std::placeholders::_1)

	Application_C* Application_C::_instance = nullptr;

	Application_C::Application_C()
	{
		HONEY_CORE_ASSERT(!_instance, "Application is running");
		_instance = this;
		_window = std::unique_ptr<Window_C>(Window_C::Create());
		_window->SetEventCallback(BIND_EVENT(OnEvent));
	}

	Application_C::~Application_C()
	{

	}

	void Application_C::PushLayer(Layer_C* layer)
	{
		_layer_stack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application_C::PushOverlay(Layer_C* layer)
	{
		_layer_stack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application_C::OnEvent(Event_C& event)
	{
		EventDispatcher_C dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent_C>(BIND_EVENT(OnWindowClose));
		// HONEY_CORE_TRACE("{0}", event);

		for (auto it = _layer_stack.end(); it != _layer_stack.begin();)
		{
			(*--it)->OnEvent(event);
			if (event._handled)
				break;
		}
	}
	void Application_C::Run()
	{
		while (_running) {

			for (Layer_C* layer : _layer_stack)
				layer->OnUpdate();
			 
			_window->OnUpdate();
		}
	}

	bool Application_C::OnWindowClose(WindowCloseEvent_C& event)
	{
		_running = false;
		return true;
	}
}