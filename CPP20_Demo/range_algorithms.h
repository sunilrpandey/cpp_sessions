#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
void showCollection(T& col) {
	/*auto display = [](T& col) {
		for (auto& i : col) {
			cout << i << "  ";
		}
	};
	display(col);
	*/
	[](T& vec) {
		for (auto& i : vec) {
			cout << i << "  ";
		}
	}(col);

	return;
}
template<typename T>
void showCollection_forloop(T& col) {
	for (auto& i : col) {
		cout << i << "  ";
	}
}

void demoAlgorithms()
{
	std::vector<int> v1 = { 1, 2, 3, 4, 5 };
	std::partition(v1.begin(), v1.end(), [](int x) { return x % 2 == 0; });
	// v is now partitioned: {2, 4, 1, 3, 5}
	showCollection(v1);
	return;

	std::vector<int> vec = { 1, 2, 2, 3, 3, 3, 4 };
	auto it = std::unique(vec.begin(), vec.end());
	vec.erase(it, vec.end()); // v = {1, 2, 3, 4}

	showCollection(vec);
	return;

	auto v = std::vector<int>{ 1,2,3,4,5,6,7,8 };
	showCollection(v);
	//showCollection_forloop(v);
	auto v_even = std::all_of(v.begin(), v.end(), [](int n) {
		return n % 2 == 0;
		}
	);
	_ASSERT(v_even == false);
	cout << std::boolalpha << "\nall numbers are even :" << v_even;

	for_each(v.begin(), v.end(), [](int& n) {
		n *= 2;
		});
	std::cout << "\nv *= 2" << std::endl;
	showCollection(v);

	v_even = std::all_of(v.begin(), v.end(), [](int n) {
		return n % 2 == 0;
		}
	);
	_ASSERT(v_even == true);
	cout << std::boolalpha << "\nall numbers are even :" << v_even;

	return;
}

void demoRangeAlgorithms() {

	auto v = std::vector<int>{ 1,2,3,4,5,6,7,8 };
	showCollection(v);
	//showCollection_forloop(v);
	auto v_even = std::ranges::all_of(v, [](int n) {
		return n % 2 == 0;
		}
	);
	_ASSERT(v_even == false);
	cout << std::boolalpha << "\nall numbers are even :" << v_even;

	for_each(v.begin(), v.end(), [](int& n) {
		n *= 2;
		});
	std::cout << "\nv *= 2" << std::endl;
	showCollection(v);

	v_even = std::ranges::all_of(v, [](int n) {
		return n % 2 == 0;
		}
	);
	_ASSERT(v_even == true);
	cout << std::boolalpha << "\nall numbers are even :" << v_even;


}