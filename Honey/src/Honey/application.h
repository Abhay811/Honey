#pragma once

#include "core.h"
#include "Honey/Events/event.h"
#include "window.h"

#include "Honey/Events/application_event.h"
#include "Honey/layer_stack.h"

namespace Honey {
	class HONEY_API Application_C
	{
	public:
		Application_C();
		virtual ~Application_C();

		void Run();
		void OnEvent(Event_C& event);

		void PushLayer(Layer_C* layer);
		void PushOverlay(Layer_C* layer);

		inline static Application_C& Get() { return *_instance; }
		inline Window_C& GetWindow() { return *_window; }
	private:
		bool OnWindowClose(WindowCloseEvent_C& event);
		std::unique_ptr<Window_C> _window;
		bool _running = true;

		LayerStack_C _layer_stack;
	private:
		static Application_C* _instance;
	};

	Application_C* CreateApplication();
}
