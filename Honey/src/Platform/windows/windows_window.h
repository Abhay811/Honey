#pragma once

#include "Honey/window.h"

#include <GLFW/glfw3.h>

namespace Honey {
	class WindowsWindow_C : public Window_C
	{
	public:
		WindowsWindow_C(const WindowProps& props);
		virtual ~WindowsWindow_C();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return _data.width; }
		inline unsigned int GetHeight() const override { return _data.height; }

		// Window attributes

		inline void SetEventCallback(const EventCallbackFunction& callback) override { _data.eventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* _window;
		
		struct WindowData
		{
			std::string title;
			unsigned int width;
			unsigned int height;
			bool VSync;

			EventCallbackFunction eventCallback;
		};

		WindowData _data;
	};
}
