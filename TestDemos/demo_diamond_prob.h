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
		Derived(int mi = 40) :MidDer1(mi/2), MidDer2(mi/4)/*, Base(mi)*/ {

		}
		virtual void fun() {
			std::cout << "Derived : " << mem;
			MidDer1::fun();
			MidDer2::fun();
		}

	};

	class MultilevelVirtuallyDerived : public MidDer1
	{
	public:
		//here base class needs to be initialized 
		MultilevelVirtuallyDerived(int mm = 40) :MidDer1(mm),Base(mm) {

		}
		virtual void fun() {
			std::cout << "MultilevelVirtuallyDerived : " << mem;
			MidDer1::fun();
			
		}

	};

	void demo_diamond_prob() {
		// It will be error if you have no fun function in 'Dervied' class until you inherit Mid SubClasses virtually
		// and It iwll have 
		// Basically a virtually derived class will call its base class for its own object 
		// instantiation but would not call its base class if its derived class object is 
		// instantiated.
		MidDer1 md;
		md.fun();
		Derived dd;
		dd.fun();

		
		MultilevelVirtuallyDerived mvd;
		mvd.fun();

	}
};

