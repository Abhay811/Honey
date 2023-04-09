#include <honey.h>

class Sandbox_C : public Honey::Application_C
{
public:
	Sandbox_C()
	{

	}
	~Sandbox_C()
	{

	}
};

Honey::Application_C* Honey::CreateApplication()
{
	return new Sandbox_C();
}