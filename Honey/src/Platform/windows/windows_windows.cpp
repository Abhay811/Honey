#include "honey_pch.h"
#include "windows_window.h"
#include "Honey/log.h"

#include "Honey/Events/application_event.h"
#include "Honey/Events/key_event.h"
#include "Honey/Events/mouse_event.h"

namespace Honey {
	
	static bool s_GLFWInitialized = false;
	static void GLFWErrorCallback(int error, const char* description)
	{
		HONEY_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}
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
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		_window = glfwCreateWindow((int)props._width, (int)props._height, _data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		SetVSync(true);

		// set GLFW callbacks

		glfwSetWindowSizeCallback(_window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				data.width = width;
				data.height = height;
				WindowResizeEvent_C event(width, height);
				data.eventCallback(event);
			});

		glfwSetWindowCloseCallback(_window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent_C event;
				data.eventCallback(event);
			});

		glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressEvent_C event(key, 0);
						data.eventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent_C event(key);
						data.eventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressEvent_C event(key, 1);
						data.eventCallback(event);
						break;
					}
				}
			});

		glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent_C event(button);
						data.eventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent_C event(button);
						data.eventCallback(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(_window, [](GLFWwindow* window, double xOffset, double yOffset) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				
				MouseScrolledEvent_C event((float)xOffset, (float)yOffset);
				data.eventCallback(event);
			});

		glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent_C event((float)xPos, (float)yPos);
				data.eventCallback(event);
			});
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