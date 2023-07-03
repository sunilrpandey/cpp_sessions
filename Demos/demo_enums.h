#pragma once
#include "common.h"

void demoEnum(Color selectedColor)
{
	switch (selectedColor) {
	case RED:
		cout << "The selected color is red." << endl;
		break;
	case GREEN:
		cout << "The selected color is green." << endl;
		break;
	case BLUE:
		cout << "The selected color is blue." << endl;
		break;
	default:
		cout << "Invalid color selection." << endl;
		break;
	}
}
