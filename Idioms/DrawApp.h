#pragma once

#include <iostream>
#include <memory>

class DrawImpl;
class DrawApp
{
public:
	DrawApp();
	~DrawApp();

	void draw();

private:
	std::unique_ptr<DrawImpl> drawImpl;
};

