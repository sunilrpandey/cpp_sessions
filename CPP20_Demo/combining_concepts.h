#pragma once

#include <iostream>
#include <concepts>

using namespace std;

template<typename T>
concept SizeConstraint = requires (T a) {
	sizeof(T) <= 4;
			//requires sizeof(T) <= 4 && std::is_integral_v<T>;
			requires std::is_integral_v<T>&& requires (T a) {
				a++;
				requires sizeof(T) <= 4;
	};
};

SizeConstraint auto add(SizeConstraint auto a, SizeConstraint auto b) {
	return a + b;
}

void demoCombiningConcepts() {
	char x{ 23 };
	char y{ 20 };

	char res = add(x, y);
	std::cout << "\ncombinging concepts : " << res;

	int a{ 23 };
	int b{ 20 };

	int res_i = add(a, b);
	std::cout << "\ncombinging concepts : " << res_i;
	
	//--wont work
	//double res_d = add(3.5, 4.2);
	//std::cout << "\ncombinging concepts : " << res_d;

}