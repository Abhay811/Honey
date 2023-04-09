#pragma once
#include "honey_pch.h"
#include "event.h"


namespace Honey {
	class HONEY_API WindowResizeEvent_C : public Event_C
	{
	public:
		WindowResizeEvent_C(unsigned int width, unsigned int height) 
			: _width(width), _height(height) {}

		inline unsigned int GetWidth() const { return _width; }
		inline unsigned int GetHeight() const { return _height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << _width << ", " << _height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int _width;
		unsigned int _height;
	};

	class HONEY_API WindowCloseEvent_C : public Event_C
	{
	public:
		WindowCloseEvent_C() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	class HONEY_API AppTickEvent_C : public Event_C
	{
	public:
		AppTickEvent_C() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	class HONEY_API AppUpdateEvent_C : public Event_C
	{
	public:
		AppUpdateEvent_C() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HONEY_API AppRenderEvent_C : public Event_C
	{
	public:
		AppRenderEvent_C() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}