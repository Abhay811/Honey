#pragma once

#include "event.h"

#include <sstream>

namespace Honey {

	class HONEY_API KeyEvent_C : public Event_C
	{
	public:
		inline int GetKeyCode() const { return _keycode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent_C(int keycode)
			: _keycode(keycode) {}

		int _keycode;
	};

	class HONEY_API KeyPressEvent_C : public KeyEvent_C
	{
	public:
		KeyPressEvent_C(int keycode, int repeatCount)
			: KeyEvent_C(keycode), _repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return _repeatCount; }
			
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _keycode << " (" << _repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int _repeatCount;
	};

	class HONEY_API KeyReleasedEvent_C : public KeyEvent_C
	{
	public:
		KeyReleasedEvent_C(int keycode)
			: KeyEvent_C(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << _keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}