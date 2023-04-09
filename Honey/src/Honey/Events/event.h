#pragma once

#include "honey_pch.h"
#include "Honey/core.h"


namespace Honey {

	enum class EventType
	{
		None = 0,
		WindowClose, 
		WindowResize, 
		WindowFocus,
		WindowLostFocus,
		WindowMoved,
		AppTick,
		AppUpdate,
		AppRender,
		KeyPressed,
		KeyReleased,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type;}\
					virtual EventType GetEventType() const override { return GetStaticType(); }\
					virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HONEY_API Event_C
	{
		friend class EventDispatcher_C;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	private:
		bool _handled = false;
	};

	class EventDispatcher_C
	{
		template<typename T>
		using EventFunction = std::function<bool(T&)>;
	public:
		EventDispatcher_C(Event_C& event) : 
			_event(event) {}

		template<typename T>
		bool Dispatch(EventFunction<T> func)
		{
			if (_event.GetEventType() == T::GetStatictype())
			{
				_event._handled = func(*(T*)&_event);
				return true;
			}
			return false;
		}
	private:
		Event_C& _event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event_C& e)
	{
		return os << e.ToString();
	}
}