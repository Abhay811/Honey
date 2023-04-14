#include "honey_pch.h"
#include "imgui_layer.h"

#include "imgui.h"
#include "Platform/OpenGL/imgui_opengl_renderer.h"
#include <GLFW/glfw3.h>

#include "Honey/application.h"

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
	}
}