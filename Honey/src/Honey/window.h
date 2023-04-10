#pragma once

#include "honey_pch.h"

#include "Honey/core.h"
#include "Honey/Events/event.h"

namespace Honey {

	struct WindowProps
	{
		std::string _title;
		unsigned int _width;
		unsigned int _height;

		WindowProps(const std::string& title = "Honey Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: _title(title), _width(width), _height(height) {}
	};

	// Interface 
	class HONEY_API Window_C
	{
	public:
		using EventCallbackFunction = std::function<void(Event_C&)>;

		virtual ~Window_C() {}
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window_C* Create(const WindowProps& props = WindowProps());
	};
}