#pragma once


#include "event.h"

#include <sstream>

namespace Honey {
	class HONEY_API MouseMovedEvent_C : public Event_C
	{
	public:
		MouseMovedEvent_C(float x, float y)
			: _x(x), _y(y) {}

		inline float GetX() const { return _x; }
		inline float GetY() const { return _y; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _x << ", " << _y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _x;
		float _y;
	};

	class HONEY_API MouseScrolledEvent_C : public Event_C
	{
	public:
		MouseScrolledEvent_C(float xOffset, float yOffset) 
			: _xOffset(xOffset), _yOffset(yOffset) {}

		inline float GetXOffset() const { return _xOffset; }
		inline float GetYOffset() const { return _yOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float _xOffset;
		float _yOffset;
	};

	class HONEY_API MouseButtonEvent_C : public Event_C
	{
	public:
		inline int GetMouseButton() const { return _button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent_C(int button)
			: _button(button) {}

		int _button;
	};

	class HONEY_API MouseButtonPressedEvent_C : public MouseButtonEvent_C
	{
	public: 
		MouseButtonPressedEvent_C(int button)
			: MouseButtonEvent_C(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HONEY_API MouseButtonReleasedEvent_C : public MouseButtonEvent_C
	{
	public:
		MouseButtonReleasedEvent_C(int button)
			: MouseButtonEvent_C(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}