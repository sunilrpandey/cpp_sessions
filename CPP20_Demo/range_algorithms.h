#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>


using namespace std;
// why range algos with iterator pairs are better 
// this gives better exceptions/logging 
// One can use cocepts



 

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

//gives control/aspect of types being stored in collections
//projection basically controls values being passed to algorithm
void demoProjection() {

	auto col = std::vector<int>{ 97,22,43,98,65,29,41 };
	//std::sort(col.begin(), col.end());

	auto print = [](int n) {cout << n << " - "; };
	std::cout << "\nDemo: Display without projection : ";
	std::for_each(col.begin(), col.end(), print);
	
	std::cout << "\nProjection: control what you want to do on collection data : ";
	std::cout << "\nDemo: Display with projection : ";
	std::ranges::for_each(col.begin(), col.end(), print, [](int n) {return n % 10; });


	std::cout << "\nDemo: Pairs" << std::endl;
	using num_string_pair = std::pair<int, std::string> ;
	std::vector<num_string_pair> prs{ {3,"three"},{1,"one"}, {2,"two"}, };
	auto print_pair = [](const num_string_pair& pr) {cout << "[ " << pr.first << " : " << pr.second << " ], "; };

	std::ranges::for_each(prs.begin(), prs.end(), print_pair);

	auto print_pr = [](const auto & n) {cout << n << " : "; };
	std::ranges::for_each(prs.begin(), prs.end(), print_pr, [](const num_string_pair& pr) {return pr.first; });
	
	cout << std::endl << "changes projection to print second field : " << std::endl;
	std::ranges::for_each(prs.begin(), prs.end(), print_pr, [](const num_string_pair& pr) {return pr.second; });

	cout << std::endl << "sort pairs using projection :" << std::endl;
	std::ranges::sort(prs, std::less<>{}, [](const num_string_pair& pr) {return pr.first; });
	//or 
	//std::ranges::sort(prs, std::less<>{}, &num_string_pair::first);
	//std::ranges::sort(prs, std::less<>{}, & num_string_pair::second);

	std::ranges::for_each(prs, print_pair);
}


void demoRangeAlgorithms_withIterPairs() {
	auto col = std::vector<int>{ 21,121,3,4,55,46,7,8 };
	std::ranges::sort(col.begin(), col.end()); 
	std::cout << "\nsorted collection : ";
	showCollection(col);

	auto lst = std::list<int>{ 21,121,3,4,55,46,7,8 };
	
	//sort function does not work for list iterator since it expects random access iterator not bidirection iterator provided by list
	//std::ranges::sort(lst.begin(), lst.end());
	std::cout << "\nsorted collection : ";
	showCollection(lst);
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
	cout << std::boolalpha << "\nall numbers are even :" << v_even << std::endl;

	//std::ranges::sort()
	//std::find_if()
	
	auto v9 = std::vector<int>{ 21,121,3,4,55,46,7,8 };
	std::cout << "copy to console : ";
	std::ranges::copy(v9, std::ostream_iterator<int>(std::cout, "_"));

	std::ranges::for_each(v9, [](int n) { n *= 2; });

	std::cout << "------" << std::endl;
	std::cout << "\ncol *= 2 : ";
	showCollection(v9);



//gives better logging 
	
}