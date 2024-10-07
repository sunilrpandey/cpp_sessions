#include "DrawApp.h"

class DrawImpl
{
public:
	DrawImpl();
	~DrawImpl();
	
	void specializedDraw() {
		std::cout << "Special Draw " << std::endl;
	}

private:
	

};

DrawImpl::DrawImpl()
{
}

DrawImpl::~DrawImpl()
{
}


DrawApp::DrawApp():drawImpl(std::make_unique<DrawImpl>())
{
	

}

DrawApp::~DrawApp()
{
}

void DrawApp::draw()
{
	drawImpl->specializedDraw();
}
