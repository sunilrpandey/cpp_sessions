#pragma once
#include "KString.h" 

template <typename T>
T Max(T a, T b)
{
	cout << "\nCalling function template" << endl;
	if (a >= b)
		return a;

	return b;
}
template <typename T>
T* Max(T* a, T* b)
{
	cout << "\nMax function for (T*)" << endl;
	if (*a >= *b)
		return a;

	return b;
}

//Here you have to specify ReturnType while calling,. others can be deduced from arguments
template <typename ReturnType, typename T, typename S>
ReturnType Max_TwoParams(T a, S b)
{
	cout << "\nCalling function template" << endl;
	if (a >= b)
		return a;

	return b;
}
template <typename T, typename S>
auto Max_TwoParams_auto_returnType(T a, S b) // will work for (12,30) but not for (12,30.0)
{
	cout << "\nDemo: Max_TwoParams_auto_returnType" << endl;
	if (a >= b)
		return a;

	return b;
}

//In C++, the ternary operator ? : promotes both operands to a common type(which is usually the more general type) to avoid precision loss.
// In this case, the common type will be double, because double can represent both integerand floating - point values, 
// whereas int cannot represent floating - point values without losing precision.
template <typename T, typename S>
auto Max_TwoParams_auto_returnType_trailing_declType(T a, S b)->decltype((a>=b)?a:b) // will work for (12,30.0) as well 
{
	cout << "\nDemo: Max_TwoParams_auto_returnType_trailing_declType" << endl;
	if (a >= b)
		return a;

	return b;
}

// this one is same but you can not split declration and definition
template <typename T, typename P>
decltype(auto) Max_TwoParams_auto_returnType_decltye_auto(T a, P b) {
	return (a > b) ? a : b;
}

// One can have param as reference as well 
template <typename T>
T Max_PassbyRef(const T& a, const T& b)
{
	cout << "\nCalling function template" << endl;
	if (a >= b)
		return a;

	return b;
}


template <typename T>
T Min(T a, T b)
{
	T max = Max(a, b);
	cout << "\ncalling template function -  MIN" << endl;
	if (a == max)
		return b;

	return a;
}

float Max(float a, float b)
{
	cout << "\nClassic function" << endl;

	if (a >= b)
		return a;

	return b;
}


template <>
float Max(float a, float b)
{
	cout << "\ncalling specialized template function" << endl;

	if (a >= b)
		return a;

	return b;
}

char Max(char a, char b) = delete;

//template <typename T, typename S>
//T Max(T a, S b)
//{
//	cout << "\ncalling Max2" << endl;
//	if (a >= b)
//		return a;
//
//	return b;
//}
















