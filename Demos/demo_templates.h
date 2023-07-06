#pragma once
#include "templates_basics.h"
#include <tuple>

namespace ns_templates {

	void demoTemplateFunction()
	{
		cout << Max(5, 10);
		cout << Max(5.5f, 10.5f);


		cout << Max(KString("KPIT"), KString("Technologies"));

		cout << Max(5, 10.0);
		cout << Max(static_cast<float>(5), 10.5f);

		//cout << Max('a', 'b');



		cout << Max(2, 3.5);

		//cout << "\nFactorial : " << print<5>();
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
		demoTemplateFunction();
		demoTemplatesClass();

	}
}

namespace ns_variadic_templates
{
	template <typename T>
	T sum(T value) {
		return value;
	}

	template <typename T, typename... Args>
	T sum(T first, Args... rest) {
		return first + sum(rest...);
	}

	int demoRecursionWithVariadicTemplates() {
		int total = sum(1, 2, 3.5, 4, 5);
		return 0;
	}

	template <typename... Args>
	void printValues(Args... args) {
		((std::cout << args << " "), ...);
	}

	int demoVeriadicTemplateUsingFoldExpression() {
		printValues(1, 2, 3, "hello", 3.14);
		return 0;
	}

	/*
	template <typename... Args>
	class Tuple {
	public:
		Tuple(Args... args) : values(args...) {}

		void print() {
			(void(std::cout << ... << values) << endl);
		}

	private:
		std::tuple<Args...> values;
	};

	int demoVeriadicTemplateClass() {
		Tuple<int, std::string, double> tuple(1, "hello", 3.14);
		tuple.print();
		return 0;
	}

	*/


};