#pragma once

#include "Honey/core.h"
#include "Honey/Events/event.h"

namespace Honey {
	class HONEY_API Layer_C
	{
	public:
		Layer_C(const std::string& name = "Layer");
		virtual ~Layer_C();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event_C& event) {}

		inline const std::string& GetName() const { return _name; }

	private:
		std::string _name;
	};
}


