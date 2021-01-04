#include <iostream>
#include <SimpleMath.h>

int main()
{
	SimpleMath::Log::Init();
	SM_INFO("Application has been initialized");
	SM_CORE_WARN("Some functionality may be broken");
}