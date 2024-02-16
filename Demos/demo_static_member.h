#pragma once
#include "common.h"
namespace ns_static
{
	class A
	{
	public:
		A() {
			cout << counter++ << " ";
		}
		static void printTotolObjectCreated() {
			cout << "-> Cant access publically A::counter if counter is private" << endl;
			cout << endl << "A's total object created : " << A::counter;
		}

	//private:
		static int counter;
	};
	int A::counter = 0;

	static void demo_write_numbers_without_loop() {
		cout << endl << "Below ojbect array prints line as part of construction!! - ";
		A a[5];

	}

	void demo_static() {
		demo_write_numbers_without_loop();
		A::printTotolObjectCreated();
	}

}
