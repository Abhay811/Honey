#pragma once

#include "Honey/layer.h"
#include "Honey/Events/mouse_event.h"
#include "Honey/Events/key_event.h"
#include "Honey/Events/application_event.h"

namespace Honey {
	class HONEY_API ImGuiLayer_C : public Layer_C
	{
	public:
		ImGuiLayer_C();
		~ImGuiLayer_C();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event_C& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent_C& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent_C& event);
		bool OnMouseMovedEvent(MouseMovedEvent_C& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent_C& event);
		bool OnKeyPressedEvent(KeyPressEvent_C& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent_C& event);
		bool OnKeyTypedEvent(KeyTypedEvent_C& event);
		bool OnWindowResizedEvent(WindowResizeEvent_C& event);

	private:
		float _time;
	};
}