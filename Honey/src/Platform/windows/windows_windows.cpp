#include "honey_pch.h"
#include "windows_window.h"
#include "Honey/log.h"

namespace Honey {
	
	static bool s_GLFWInitialized = false;

	Window_C* Window_C::Create(const WindowProps& props)
	{
		return new WindowsWindow_C(props);
	}

	WindowsWindow_C::WindowsWindow_C(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow_C::~WindowsWindow_C()
	{
		Shutdown();
	}

	void WindowsWindow_C::Init(const WindowProps& props)
	{
		_data.title = props._title;
		_data.width = props._width;
		_data.height = props._height;

		HONEY_CORE_INFO("Creating window {0} ({1}, {2})", props._title, props._width, props._height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			HONEY_CORE_ASSERT(success, "Could not initalize GLFW");

			s_GLFWInitialized = true;
		}

		_window = glfwCreateWindow((int)props._width, (int)props._height, _data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		SetVSync(true);
	}

	void WindowsWindow_C::Shutdown()
	{
		glfwDestroyWindow(_window);
	}

	void WindowsWindow_C::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}

	void WindowsWindow_C::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		_data.VSync = enabled;
	}

	bool WindowsWindow_C::IsVSync() const
	{
		return _data.VSync;
	}

}