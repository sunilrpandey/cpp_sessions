#pragma once
#include <iostream>
#include <type_traits>
#include <vector>

/*
std::is_integral_v<T> is another syntax (Helper variable template) for std::is_integral<T>::value nd
template< class T >
constexpr bool is_integral_v = is_integral<T>::value;
from https://en.cppreference.com/w/cpp/types/is_integral
*/

template <typename T> 
void func(T value)
{
	if (std::is_integral<T>::value) {
		std::cout << "\nIntegral value " << std::endl;
	}
	else {
		std::cout << "\nNon Integral value" << std::endl;
	}
}

template <typename T>
void func_integral_param_only(T value)
{
	//static_assert(std::is_integral<T>::value, "Only Integral param allowed"); OR
	static_assert(std::is_integral_v<T>, "Only Integral param allowed");
	
	std::cout << "\nIntegral Value :" << value;
}



void demoBasicTypeTraits()
{
	std::cout << std::boolalpha;
	std::cout << std::is_integral<int>::value;

	func(23);
	func(23.5);

	func_integral_param_only(23);
	//func_integral_param_only(23.5);

	// enum/class are not integratl type even if they have 
	enum E : int {};
	class A { int i; };
	
	static_assert(std::is_integral_v<E> == false);
	static_assert(std::is_integral_v<A> == false);
	static_assert(std::is_integral_v<vector<int>> == false);
	static_assert(std::is_integral_v<int[2]> == false);

	//force input param

	auto func = []<typename T>
}
