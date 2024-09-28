#pragma once
#include "common.h"
using namespace std;
namespace ns_move_semantics {
#pragma region "r/l value demo"
	//void show(int i) {
	//	cout << "int - " << i;
	//}
	void show(const int& i) {
		cout << endl << "const int ref - " << i;
	}
	void show(int&& i) {
		cout << endl << "r value ref - " << i;
	}
#pragma endregion


	template <typename T>
	void relayWithoutPerfectForwarding(T&& val) {
		show(val);
	}
	template <typename T>
	void relayWithPerfectForwarding(T&& val) {
		show(std::forward<T>(val));
	}
	void relayWithoutPerfectForwarding_forInt(int&& val) {
		show(val);
	}
	void relayWithPerfectForwarding_forInt(int&& val) {
		show(std::forward<int>(val));
	}

#pragma endregion

	int demoPerfectForwarding()
	{
		auto i = 10;
		cout << ": Perfect Forwarding Demo : ";

		cout << "\n\nshowing value based on passed type, value or rvalue";
		show(i);
		show(std::move(i));

		//std::forward use
		cout << "\n\nForwarding now without using std::forward";
		relayWithoutPerfectForwarding(std::move(i));
		cout << "\n\nForwarding now with std::forward";
		relayWithPerfectForwarding(std::move(i));

		// moving an object typically involves transferring ownership of the underlying resources 
		// (e.g., dynamically allocated memory) from the source object to the destination object. 
		// In the case of a basic type like int, which doesn't have any associated resources, 
		// moving it doesn't have any significant effect other than indicating that it can be efficiently moved from.

		// therefore below code will work without any issues thoug 'i' has been moved
		relayWithoutPerfectForwarding(i);

		cout << endl;
		return 0;
	}
};