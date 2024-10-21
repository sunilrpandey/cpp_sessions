#pragma once
#include <string.h>

template<typename T>
class Adder {

public:
	Adder() = default;
	T execute(T a, T b);
};

template<typename T>
T Adder<T>::execute(T a,T b) {
	return a + b;
}


template<>
class Adder<char*> {

public:
	Adder() = default;
	char* execute(char* a, char * b);
};


//Notes : 
// class Adder<char*> instead of just class Adder
//template<> is not required if defining outside class

char* Adder<char*>::execute(char* a, char* b) {
	return strcat(a, b);
	
}
