#pragma once
#include <iostream>
#include <concepts>
using namespace std;

/*
requires clause can be 
- simple requirement
- nested requirement
- compound requirement
- type requirement
*/

//simple
template <typename T>
concept CheckIntegral = requires (T a) {
	std::is_integral_v<T>;
	//requires std::is_integral_v<T>;
};

//nested
template <typename T>
concept CheckSize= requires (T a) {
	sizeof(T) <=4 ; // checks syntaxes only
	requires sizeof(T) <= 4; // checks if expression is true
}; 

//compound addable plus result is integral
template <typename T>
concept Addable_Integral = requires (T a, T b) {
	{a + b} -> std::integral;
};

template <typename T>
concept Addable_Convertile_Int = requires (T a, T b) {
	{a + b} -> std::convertible_to<int>;
};

Addable_Convertile_Int auto addFunc(Addable_Convertile_Int auto a, Addable_Convertile_Int auto b) {
	return a + b;
}

void demoRequires()
{
	std::cout << "\nrquires demo :" << endl;
	double a{ 4.2 };
	double b{ 2.4 };

	double res = addFunc(a, b);
	std::cout << "res :" << res;

	auto s1 = "Hello";
	auto s2 = "Hello";

	//auto res1 = addFunc(s1, s2);
	//std::cout << "\nadd str :" << res1;
}