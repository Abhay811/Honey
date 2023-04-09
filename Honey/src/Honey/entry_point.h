#pragma once


#ifdef HONEY_PLATFORM_WINDOWS

extern Honey::Application_C* Honey::CreateApplication();

int main(int argc, char** argv)
{
	Honey::Log_C::Init();
	HONEY_CORE_ERROR("Initialized log!");
	auto app = Honey::CreateApplication();
	app->Run();
	delete app;
}

#endif