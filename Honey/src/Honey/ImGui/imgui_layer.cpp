#include "honey_pch.h"
#include "imgui_layer.h"

#include "imgui.h"
#include "Platform/OpenGL/imgui_opengl_renderer.h"
#include <GLFW/glfw3.h>

#include "Honey/application.h"


#include <glad/glad.h>

namespace Honey {

	ImGuiLayer_C::ImGuiLayer_C()
		: Layer_C("ImGuiLayer")
	{
	}

	ImGuiLayer_C::~ImGuiLayer_C()
	{
	}

	void ImGuiLayer_C::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 410");
	}
	void ImGuiLayer_C::OnDetach()
	{
	}

	void ImGuiLayer_C::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application_C& app = Application_C::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());
		float time = (float)glfwGetTime();

		io.DeltaTime = _time > 0.0 ? (time - _time) : (1.0f / 60.0f);
		_time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);
		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	}

	void ImGuiLayer_C::OnEvent(Event_C& event)
	{
		EventDispatcher_C dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent_C>(HONEY_BIND_EVENT_FUN(ImGuiLayer_C::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent_C>(HONEY_BIND_EVENT_FUN(ImGuiLayer_C::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent_C>(HONEY_BIND_EVENT_FUN(ImGuiLayer_C::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrolledEvent_C>(HONEY_BIND_EVENT_FUN(ImGuiLayer_C::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressEvent_C>(HONEY_BIND_EVENT_FUN(ImGuiLayer_C::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyTypedEvent_C>(HONEY_BIND_EVENT_FUN(ImGuiLayer_C::OnKeyTypedEvent));
		dispatcher.Dispatch<KeyReleasedEvent_C>(HONEY_BIND_EVENT_FUN(ImGuiLayer_C::OnKeyReleasedEvent));
		dispatcher.Dispatch<WindowResizeEvent_C>(HONEY_BIND_EVENT_FUN(ImGuiLayer_C::OnWindowResizedEvent));
	}

	bool ImGuiLayer_C::OnMouseButtonPressedEvent(MouseButtonPressedEvent_C& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = true;
		return false;
	}
	bool ImGuiLayer_C::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent_C& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[event.GetMouseButton()] = false;

		return false;
	}

	bool ImGuiLayer_C::OnMouseMovedEvent(MouseMovedEvent_C& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(event.GetX(), event.GetY());

		return false;
	}

	bool ImGuiLayer_C::OnMouseScrolledEvent(MouseScrolledEvent_C& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += event.GetXOffset();
		io.MouseWheel += event.GetYOffset();

		return false;
	}
	bool ImGuiLayer_C::OnKeyPressedEvent(KeyPressEvent_C& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[event.GetKeyCode()] = true;

		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

		return false;
	}
	bool ImGuiLayer_C::OnKeyReleasedEvent(KeyReleasedEvent_C& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[event.GetKeyCode()] = false;

		return false;
	}
	bool ImGuiLayer_C::OnKeyTypedEvent(KeyTypedEvent_C& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = event.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter((unsigned short)keycode);

		return false;
	}

	bool ImGuiLayer_C::OnWindowResizedEvent(WindowResizeEvent_C& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(event.GetWidth(), event.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, event.GetWidth(), event.GetHeight());
		return false;
	}
}