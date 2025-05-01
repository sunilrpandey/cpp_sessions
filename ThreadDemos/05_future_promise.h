#pragma once
#include <iostream>
#include <thread>
#include <future>

namespace ns_thread {
	using namespace std;
	int factorial(int n) {
		if (n < 2) {
			return 1;
		}
		return n * factorial(n - 1); \
	}
	void demo_factorial(int n) {
		cout << "Factorial of " << n << " : " << factorial(n);
	}
	void demo_future() {

		cout << "\nCalculate factorial from differnt thread" << endl;
		std::thread tf(demo_factorial, 5);
		tf.join();

		int n = 5;
		cout << "\nCalculate factorial by launching thread through async" << endl;
		/*future<int>*/ auto res = async(launch::deferred | launch::async, factorial, n);
		cout << "Factorial of " << n << " : " << res.get();

		return;
	}
}

