#include "common.h"
#include "templates_basics.h"
#include "template_meta_prog.h"
#include "template_array.h"
#include "template_sized_array.h"

// specific template function can be deleted // char implementation of Max function is deleted (= delete)
// function written using templates are function template (blueprint )and instance out of it is template function
// if classic function is there it will have followed by specialized template function and then template function
// one can have template specialization, which tells compiler not to generate for particular type
/*
template <>
float Max(float a, float b)
{
	cout << "\ncalling specialized template function" << endl;

	if (a >= b)
		return a;

	return b;
}
*/


// Function template with overloading, overloading is taken when we have one template param as T and another T*
/*
template <typename T>
T* Max(T* a, T* b)
{
	cout << "\nCalling function template" << endl;
	if (*a >= *b)
		return a;

	return b;
}
*/
// in case of const char * for maximum pointer , first choice would be raw implementation, then specialized function , then T* verison , then T version

// -> -> overload when you can, specialise when you need to.
// https://stackoverflow.com/questions/7108033/should-you-prefer-overloading-over-specialization-of-function-templates

// -> Function templates with multiple parameters
// BUt below is problematic
/*
template <typename T, typename S>
T Max(T a, S b)
{
	if (a >= b)
		return a;

	return b;
}

/*
template <typename ReturnType typename T, typename S>
//template < typename T,typename ReturnType , typename S>
//template < typename T, typename P,typename ReturnType >
ReturnType Max(T a, S b)
{
	if (a >= b)
		return a;

	return b;
}
*/

namespace ns_templates {

	void demoFunctionTemplates()
	{
		//--Template type deduction 
		cout << "\nDemo : Template type deduction" << std::endl;
		cout << Max(5, 10);
		cout << Max(5.5f, 10.5f); // if classic function is available compiler wont generate it for float
		cout << Max(KString("KPIT"), KString("Technologies"));
		//cout << Max(5, 10.0); // Since two types it will  call two template param version.. 
		cout << Max(static_cast<float>(5), 10.5f);
		//Deleted specialized function 
		//cout << Max('a', 'b'); 
		//cout << Max(2.0, 3.5);

		// By providing Explicit argument 
		cout << "\nDemo : Template type deduction by Explicit argument" << std::endl;
		//cout << Max<int>(5, 10.0); // will call two template param version 
		cout << Max<double>(5.0f, 10.0); // this will call single param version

		

	}

	void functionTemplatesWithOverloading() {
		//calling overloaded functions
		auto x{ 10 }, y{ 20 };

		auto m1 = Max(x, y);
		cout << "\n(T version) | Max of (x,y) : " << m1;

		auto m2 = Max(&x, &y);
		cout << "\n(T* version) | Max of (x,y) : " << *m2;
	}

	void demoTemplatesClass()
	{

		{
			SizedArray<int, 15> arr;
			for (int i = 0; i < 5; i++) {
				arr[i] = i + 1;
			}
			arr.print();

			SizedArray<float, 5> flt_arr;
			for (int i = 0; i < 5; i++) {
				flt_arr[i] = (i + 1) / 2.0f;
			}
			flt_arr.print();
			return;
		}

		{
			Array<int> arr(5);
			for (int i = 0; i < 5; i++) {
				arr[i] = i + 1;
			}
			arr.print();

			Array<float> flt_arr(5);
			for (int i = 0; i < 5; i++) {
				flt_arr[i] = (i + 1) / 2.0f;
			}
			flt_arr.print();
			return;
		}

	}

	void demo_templates()
	{
		
		cout << "Demo : Template Functions" << endl;
		demoFunctionTemplates();

		/*
		cout << "Demo : Template Class" << endl;
		demoTemplatesClass();

		cout << "\nDemo : Template MetaProgramming" << endl;
		ns_templates::demo_factorial_using_meta_programming();
		*/
	}
};

