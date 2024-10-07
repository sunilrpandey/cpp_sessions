#include "DrawApp.h"

int main()
{
	auto drApp = std::unique_ptr<DrawApp>();
	drApp->draw();

	return 0;
}