#pragma once

#include "includes.h"

namespace rvalue_use_cases
{

#if 0 // wont work, const int& or int&& work
	int& getNum() {
		return 10;
	}

#endif

	int&& getNum() {
		return 10;
	}

};

void demo_rvalue_refs()
{
	using namespace rvalue_use_cases;

	int i = getNum();
	cout << "demo_rvalue_refs  :  " << i << endl;

}
