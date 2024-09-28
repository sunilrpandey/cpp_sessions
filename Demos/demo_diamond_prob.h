#pragma once
#include <iostream>
namespace diamondprob {
	class Base
	{
	public:
		int mem;
		int arr[10];
		Base(int ii = 10) : mem(ii) {

			std::cout << "Base Class: " << mem << std::endl;
		}
		virtual void fun() {
			std::cout << "mem value : " << mem << std::endl;
		}

	};
	class MidDer1 : public virtual Base {
	public:

		MidDer1(int mi = 20) :Base(mi) {
			std::cout << "MidDer1 Class : " << mem << std::endl;

		}
		virtual void fun() {
			std::cout << "MidDer1 : " << mem;
		}

	};
	class MidDer2 : public virtual Base {
	public:
		MidDer2(int mi = 21) :Base(mi) {
			std::cout << "MidDer2 Class : " << mem << std::endl;

		}
		virtual void fun() {
			std::cout << "MidDer2 : " << mem;
		}
	};
	class Derived :public MidDer1, public MidDer2 {
	public:
		Derived(int mi = 31) :MidDer1(mi), MidDer2(mi), Base(mi) {

		}
		virtual void fun() {
			std::cout << "Derived : " << mem;
		}

	};

	void demo() {
		// It will be error if you have fun function in 'Dervied' class until you inherit Mid SubClasses virtually
		// and It iwll have 
		MidDer1 md;
		md.fun();
		Derived dd;
		dd.fun();

	}
};

