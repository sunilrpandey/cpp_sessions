#pragma once
#include "common.h"

void demoEnum(Color selectedColor)
{
	switch (selectedColor) {
	case Color::RED:
		cout << "The selected color is red." << endl;
		break;
	case Color::GREEN:
		cout << "The selected color is green." << endl;
		break;
	case Color::BLUE:
		cout << "The selected color is blue." << endl;
		break;
	default:
		cout << "Invalid color selection." << endl;
		break;
	}
}
