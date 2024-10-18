#include <iostream>

//const member function can modify static member variable
//const member variable is supposed to be initialized in initializer list only not as
//member wise initalisation
// order of static variable initialization is not ordered

// static constant pre cpp17, 
// we can initialize static const init/enums
// static const int var{10}, 
// static const Color clr{Color::green}

// classname::varname{intvalue} // where var is static const, will be init like static
// whereas only const members will be initialized in initializer list only

using namespace std;
namespace ns_static
{
	class A
	{
	public:
		A() {
			cout << counter++ << " ";
			counter_17++;
		}
		static void printTotolObjectCreated() {
			cout << "-> Cant access publically A::counter if counter is private" << endl;
			cout << endl << "A's total object created : " << A::counter;
			cout << endl << "Using cpp17 A's total object created : " << A::counter_17;
		}
		void CanModifyStaticMember() const {
			counter++;
		}

	//private:
		static int counter;
		inline static int counter_17{2}; // started with cpp 17

		//static constant 
		static inline const double PI{ 3.1416 }; //cpp17
		static inline const std::string name{ "A_Name"}; //cpp17

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
