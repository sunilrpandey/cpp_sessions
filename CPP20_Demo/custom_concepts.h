#pragma once
#include <iostream>
#include <concepts>
#include <type_traits>
using namespace std;

template <typename T>
concept MyIntegral = std::is_integral_v<T>;

template <typename T>
concept MyIntegral_1 = std::integral<T>;
 

template <typename T>
concept Multipliable = requires (T a, T b) {
	a* b;
};

template <typename T>
concept Incrementable = requires (T a) {
	a++;
	++a;
	a += 1;
};
template <typename T>
concept Addable = requires (T a, T b) {
	a + b;
};

// Custom concpet usage from built-in concepts
template <typename T>
	requires MyIntegral<T>
T custom_add1(T a, T b) {
	return a + b;
}

template <MyIntegral_1 T>
T custom_add2(T a, T b) {
	return a + b;
}



auto custom_add3(Multipliable auto  a, Multipliable auto b) {
	return a + b;
}

//Syntax4
template <typename T>
T custom_add4(T a, T b) requires Addable<T>
{
	return a + b;
}

void demoCustomConcepts()
{
	float a0{ 10.5 };
	float a1{ 20.5 };

	auto res1 = custom_add3(a0, a1); // concept is multipliable 
	std::cout << "concpet Multiable -> res1 : " << static_cast<int>(res1) << std::endl;

	int b0{ 11 };
	int b1{ 5 };
	auto res2 = custom_add1(b0, b1);
	std::cout << "concpet Integral -> res2 : " << res2 << std::endl;

	//
	//double c0{ 11.1 };
	//double c1{ 1.9 };
	//auto res3 = custom_add3(c0, c1);
	//std::cout << "res3 : " << res3 << std::endl;

	std::string s0{ "Hello"};
	std::string s1{ "World"};
	auto res3 = custom_add4(s0, s1); //custom_add3 -> multipliable concpet wont work here, will give compilation error
	std::cout << "concpet Addable -> res3 : " << res3 << std::endl;


} 