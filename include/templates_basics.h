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
















