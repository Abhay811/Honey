#include <honey.h>


class ExampleLayer : public Honey::Layer_C
{
public:
	ExampleLayer() : Layer_C("Example") {}

	void OnUpdate() override
	{
		HONEY_INFO("ExampleLayer::Update");

	}

	void OnEvent(Honey::Event_C& event) override
	{
		HONEY_TRACE("{0}", event);
	}
};
class Sandbox_C : public Honey::Application_C
{
public:
	Sandbox_C()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Honey::ImGuiLayer_C());
	}
	~Sandbox_C()
	{

	}
};

Honey::Application_C* Honey::CreateApplication()
{
	return new Sandbox_C();
}