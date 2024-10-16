#include "common.h"
#include "func_templates_examples.h"
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


template <typename ReturnType typename T, typename S>
//template < typename T,typename ReturnType , typename S>
//template < typename T, typename P,typename ReturnType >
ReturnType Max(T a, S b)
{
	if (a >= b)
		return a;

	return b;
}

but cleaner way would be 
template <typename T, typename P>
auto maximum ( T a, P b){
	return (a > b)? a : b;
}

decltype is used to deduce type of expression 
e.g. sizeof(decltype((a>b)?a:b))

decltype((a>b)?a:b) c;

-> decltype as return type
decltype((a>b)?a:b) Max(T a, S b){ // will get error since a, b in decltype are used before they are declareed in param list, to make it trailing 
	if (a >= b)
		return a;

	return b;
}
make it trailing
auto Max(T a, S b) -> decltype((a>b)?a:b) // auto here is just a placeholder which will be deduced by decltype
{ 
	if (a >= b)
		return a;

	return b;
}

decltype(auto) Max(T a, S b)
{
	if (a >= b)
		return a;

	return b;
}

//In C++, the ternary operator ? : promotes both operands to a common type(which is usually the more general type) to avoid precision loss.
// In this case, the common type will be double, because double can represent both integerand floating - point values,
// whereas int cannot represent floating - point values without losing precision.


-> Default argument
template <typename ReturnType = int, typename T, typename S>
	ReturnType GetMax(T a, S b) {

	you can use default argument or override, make sure to specify return type 
	auto res = GetMax(100.5, 12.5); // default return type is int
		cout << "Sizeof Return Type : " << sizeof(res) << " and value : " <<  res << endl;
		auto r = GetMax<double, int>(100.5, 12.5);


One can have non type template parameter but only integral types are allowed as on C++ 20
	template<typename T, int size> // non type param 'int size' can be first param as wll 
	void printCollection(T collection[]) {
		for (auto i = 0; i < size; i++) {
			std::cout << collection[i] << "  ";
		}
		std::cout << endl;
	}

	-> auto function templates in cpp20
	auto funcAdd(auto a, auto b) {
		return a + b;
	}

	void demoAutoFunctionTemplates()
	{
		auto r = funcAdd(5.0, 10);
		cout << "size : " << sizeof(r) << " value : " << r;

	}
	C++ 17 implementation for the same
	template<typename T, typename S>
	decltype(auto) funcAdd(T a, S b) {
		return a + b;
	}

	Another CPP 20 addition
	Named Template Parameters for lambda func
	void demoNamedTemplateParameters() {
		auto func = [] <typename T, typename P>(T a, P b) {
			return a + b;
		};

		char a{ 'c' };
		int b{ 63 };

		auto result = func(a, b);
		std::cout << "result : " << result << std::endl;
		std::cout << "sizeof(result) : " << sizeof(result) << std::endl;
	}


*/

namespace ns_templates {

	void demoTypeDeductionAndExplicitArgs()
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

	void demoFunctionTemplatesWithOverloading() {
		//calling overloaded functions
		auto x{ 10 }, y{ 20 };

		auto m1 = Max(x, y);
		cout << "\n(T version) | Max of (x,y) : " << m1;

		auto m2 = Max(&x, &y);
		cout << "\n(T* version) | Max of (x,y) : " << *m2;
	}

	void Demo_Max_TwoParams_auto_returnType() {

		auto mx = Max_TwoParams_auto_returnType(12, 30); // will not work for (12,30.0)
		cout << "\nMax of (12,30) is : " << mx;

		auto mx1 = Max_TwoParams_auto_returnType_trailing_declType(12, 30); // will work for (12,30.0) too
		cout << "\nMax of (12,30) is  (trailing decltype): " << mx1;

		auto mx2 = Max_TwoParams_auto_returnType_trailing_declType(122, 30.5); 
		//cout << "\nsizeof(mx2)"<<  sizeof(mx2); // due to ternary operator in decltype sizeof mx2 is 8 i.e. double
		cout << "\nMax of (12,30.0) is (trailing decltype): " << mx2;

		auto mx3 = Max_TwoParams_auto_returnType_decltye_auto(12, 30.5);
		cout << "\nMax of (12,30.5) is (demo decltype(auto)): " << mx3;

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
	void demo_TwoParamFunctionTemplates() {
		cout << "\nDemo-TwoParamFunctionTemplates" << endl;
		auto x{ 5 };
		auto y{ 10.5 };
		auto mx = Max_TwoParams<int, int, double>(x, y);
		cout << mx;
	}
	
	void demo_declType() {
		int a{ 100};
		double b{ 30.0 };
		decltype((a > b) ? a : b) c;
		std::cout << "sizeof(a) : " << sizeof(a) << "\nsizeof(b) : " << sizeof(b) << "\nsizeof(c) : " << sizeof(c);
		//std::cout << "sizeof(int) : " << sizeof(int) << "\nsizeof(double) : " << sizeof(double) << "\nsizeof(char) : " << sizeof(char) << "\nsizeof(c) : " << sizeof(c);
	}

	// demoDefaultArgument
	namespace ns_templates_default_args {

		template <typename ReturnType = int, typename T, typename S>
		ReturnType GetMax(T a, S b) {
			if (a >= b)
				return a;
			else
				return b;
		}

		void demoDefaultArgument() {
			cout << "Demo : Default Argument" << endl;
			auto res = GetMax(100.5, 12.5); // default return type is int
			cout << "Sizeof Return Type : " << sizeof(res) << " and value : " << res << endl;
			auto r = GetMax<double, int>(100.5, 12.5);
			cout << "Sizeof Return Type : " << sizeof(r) << " and value : " << r << endl;
		}
	}

	namespace ns_templates_non_type_params
	{
		template<typename T, int size>
		void printCollection(T collection[]) {
			for (auto i = 0; i < size; i++) {
				std::cout << collection[i] << "  ";
			}
			std::cout << endl;
		}

		void demoNonTypeTemplateParameter() {
			cout << "Demo : Non Type Template Parameter" << endl;
			float arr[3] = { 2.3,4.5,6.7 };
			printCollection<float, 3>(arr);
		}
	}

	template<typename T, typename S>
	decltype(auto) funcAdd_cpp17(T a, S b) {
		return a + b;
	}

	void demoAutoFunctionTemplates_cpp17()
	{
		cout << "\nDemo : Alternate impl of Auto Function Templates in CPP 20" << endl;
		auto r = funcAdd_cpp17(5.0, 10);
		cout << "size : " << sizeof(r) << " value : " << r;

	}


	#if __cplusplus >= 202002L
	namespace ns_templates_cpp20 {

		
		
		// supported in cpp 20 onwards
		auto funcAdd(auto a, auto b) {
			return a + b;
		}

		

		void demoAutoFunctionTemplates()
		{
			auto r = funcAdd(5.0, 10);
			cout << "size : " << sizeof(r) << " value : " << r;

		}

		void demoNamedTemplateParameters() {
			auto func = [] <typename T, typename P>(T a, P b) {
				return a + b;
			};

			char a{ 'c' };
			int b{ 63 };

			auto result = func(a, b);
			std::cout << "result : " << result << std::endl;
			std::cout << "sizeof(result) : " << sizeof(result) << std::endl;
		}
	}
	#endif

	void demoAutoLambdaParameters() {
		auto func = [] (auto a, auto b) {
			return a + b;
		};

		char a{ 'c' };
		int b{ 63 };

		auto result = func(a, b);
		std::cout << "result : " << result << std::endl;
		std::cout << "sizeof(result) : " << sizeof(result) << std::endl;
	}

	void demo_templates()
	{
#define RUN_ALL_DEMO 0
#if RUN_ALL_DEMO

		cout << "Demo : Template Functions" << endl;
		demoTypeDeductionAndExplicitArgs();
		demo_TwoParamFunctionTemplates();
		Demo_Max_TwoParams_auto_returnType();
		demoFunctionTemplatesWithOverloading();
		
		ns_templates_non_type_params::demoNonTypeTemplateParameter();
		ns_templates_default_args::demoDefaultArgument();

		//demoNamedTemplateParameters();
		//return;

		//demo_declType();

	#if __cplusplus >= 202002L 
			ns_templates_cpp20::demoAutoFunctionTemplates();
			return;
	#else
			demoAutoFunctionTemplates_cpp17();
	#endif 
		
#endif
		demoAutoLambdaParameters();
		
		

		/*
		cout << "Demo : Template Class" << endl;
		demoTemplatesClass();

		cout << "\nDemo : Template MetaProgramming" << endl;
		ns_templates::demo_factorial_using_meta_programming();
		*/
	}
};

