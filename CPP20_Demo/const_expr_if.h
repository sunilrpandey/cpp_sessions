#pragma once
#include <iostream>

void func_int(int) {
	std::cout << "int param" << std::endl;
}

void func_float(float) {
	std::cout << "float param" << std::endl;
}
template<typename T>
void func(T value) {
	if constexpr (std::is_integral_v<T>)
		func_int(value);
	else if constexpr (std::is_floating_point_v<T>)
		func_float(value);
	else
		static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>, "Only int or float is allowed");
}
void demoConstExprIf() {
	func(10);
	func(10.5);
	//func("xyz");
}

