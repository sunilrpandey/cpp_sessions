#pragma once
#include <iostream>
#include <thread>
#include <future>

namespace ns_thread {
	int fact(int n) {
		if (n < 2) {
			return 1;
		}
		return n * fact(n - 1); \
	}
	void factorial(int n) {
		std::cout << "Factorial of " << n << " : " << fact(n);
	}

	int fact1(std::future<int>& promised_param) {

		auto n = promised_param.get();
		
		return fact(n);;
	}

	void demo_future() {

		cout << "\nCalculate factorial from differnt thread" << endl;
		std::thread tf(factorial, 5);
		tf.join();

		int n = 5;
		cout << "\nCalculate factorial by launching thread through async" << endl;
		/*future<int>*/ auto res = std::async(std::launch::deferred | std::launch::async, fact, n);
		cout << "Factorial of " << n << " : " << res.get();

		return;
	}

	

	void demo_promise() {
		std::promise<int> promised_num;
		std::future<int> f = promised_num.get_future();

		auto res = std::async(std::launch::async, fact1, std::ref(f));
		promised_num.set_value(6);
		//promised_num.set_exception(std::make_exception_ptr(std::runtime_error("NO Promise honored")));
		cout << "Factorial of " << res.get() << " : ";
		//cout << res.get();
		

	}

	void worker_thread(std::promise<void> p) {
		std::cout << "\n in worker thread..\n"; 
		this_thread::sleep_for(chrono::milliseconds(1000));
		p.set_value();
		this_thread::sleep_for(chrono::milliseconds(100));

		std::cout << "\n still in worker thread..\n";
	}

	void demo_promise_as_onetime_event_barrier() {

		std::cout << "\n Demo: promise as barrier" << std::endl;
		std::promise<void> p;
		std::future<void> f = p.get_future();

		std::thread t(worker_thread, std::move(p));		

		f.wait();
		std::cout << "\n promise signalled, wait over, resuming main thread..\n";
		this_thread::sleep_for(chrono::milliseconds(100));
		std::cout << "\n still in main thread..\n";
		t.join();
	}

	int fact_using_shared_future(std::shared_future<int> sf) {

		auto n = sf.get();

		return fact(n);;
	}
	void fact2(std::shared_future<int> sf) {

		auto n = sf.get();

		std::cout << "Fact 2 : " <<  fact(n) << std::endl;


	}


	void demo_shared_future() {
		std::promise<int> p;
		std::future<int> f = p.get_future();
		std::shared_future<int> sf = f.share(); 
		// is necessory for multiple calls since you can call get on future only once
		auto f1 = std::async(std::launch::async | std::launch::deferred
			, fact_using_shared_future
			, sf);
		std::thread t(fact2, sf);
		p.set_value(6);
		cout << "Factorial (SF) : " << f1.get();
		t.join();


	}
}

