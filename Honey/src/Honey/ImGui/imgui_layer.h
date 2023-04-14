#pragma once

#include "Honey/layer.h"

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
		float _time;
	};
}