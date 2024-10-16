#pragma once

#include <iostream>
#include <type_traits>
using namespace std;
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

	auto func_one_param = [] <typename T>(T a, T b) { //forces to have one param only
		return a + b;
	};


	char a{ 'c' };
	int b{ 63 };

	auto result = func(a, b);
	std::cout << "result : " << result << std::endl;
	std::cout << "sizeof(result) : " << sizeof(result) << std::endl;

	
	auto res2 = func_one_param(10, 20); // when we want func params to be of same type
	std::cout << "res2: " << res2 << std::endl;

	auto res3 = func(a, b);
	std::cout << "res3 : " << res3 << std::endl;


}

void demoTypeTraits() {
	auto func_sum = []<typename T> (T a, T b) {
		return a + b;
	};
	func_sum(2, 3);
	func_sum(2.2, 3.5);

	auto func_sum_integral_only = []<typename T> (T a, T b) {
		static_assert(std::is_integral_v<T>, "\n Hello!, Integral args only!");
		return a + b;
	};

	func_sum_integral_only(2, 3);
	//func_sum_integral_only(2.2, 3.5);

}