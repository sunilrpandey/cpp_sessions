#pragma once
#include <iostream>
#include <concepts>
using namespace std;
// A mechanism to place constraints
// as we did for param type.not in function body bu
// standard build in concept and custom concept
// https://en.cppreference.com/w/cpp/concepts
/*
syntax 1
template <typename T>
requires std::integral<T>
T add( T a, T b){
    return a + b;
}
template <typename T>
requires std::is_integral_v<T>
T add( T a, T b){
    return a + b;
}
syntax 2
template <std::integral T>
T add( T a, T b){
    return a + b;
}
syntax 3
auto add(std::integral auto a , std::integral auto b){
    return a + b;
}
//Syntax4
template <typename T>
T add( T a, T b) requires std::integral<T>
{
	return a + b;
}
*/

template <typename T>
requires std::integral<T>
T add1(T a, T b) {
	return a + b;
}

template <std::integral T>
T add2(T a, T b) {
	return a + b;
}



auto add3(std::integral auto  a, std::integral auto b) {
	return a + b;
}

//Syntax4
template <typename T>
requires std::integral<T>
T add4( T a, T b)// requires std::integral<T>
{
    return a + b;
}



void demoBuiltInConcepts()
{
	char a0{ 10 };
	char a1{ 20 };

	auto res1 = add3(a0, a1);
	std::cout << "res1 : " << static_cast<int>(res1) << std::endl;

	int b0{ 11 };
	int b1{ 5 };
	auto res2 = add1(b0, b1);
	std::cout << "res2 : " << res2 << std::endl;

	//
	//double c0{ 11.1 };
	//double c1{ 1.9 };
	//auto res3 = add(c0, c1);
	//std::cout << "res3 : " << res3 << std::endl;
	
}
