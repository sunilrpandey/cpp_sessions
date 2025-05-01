#pragma once
#include "common.h""
#include <thread>
#include <chrono>
// join func makes sure that is it is completed. thread instantiation starts running assoicated func
// sleeping_func outputs first line, sleeps and allows other thread to complete and completes its remaining line

// t1.join() followe dby t2.join does not gurantee that t1 completes before t2

namespace ns_thread
{
	void threadFunc(const std::string& msg) {
		cout << msg;
	}
	class FuncObj
	{
	public:
		void operator()() {
			cout << "\nHello from thread - FuncObj!!!";
		}
	};
	void sleeping_func(int ms) {
		cout << "\nHello from thread - Sleep Func!!!";
		this_thread::sleep_for(chrono::milliseconds(ms));
		cout << "\nSlept soundedly - Sleep Func!!!";
	}
	void demo_instantiation()
	{
		auto lmdaFunc = []() {cout << "\nHello from thread - LmdaFunc!!!"; };
		std::function<void()> stdFunc = lmdaFunc;
		std::thread t1(sleeping_func, 5000);
		std::thread t2(threadFunc,"\nHello from Func");
		std::thread t3((FuncObj()));
		std::thread t4(lmdaFunc);
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		//t1.detach();
		cout << "\nHello from Main thread!!!";
	}
}