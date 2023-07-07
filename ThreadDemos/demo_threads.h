#pragma once
#include "common.h""
#include <thread>
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
	void demo()
	{
		auto lmdaFunc = []() {cout << "\nHello from thread - LmdaFunc!!!"; };
		std::function<void()> stdFunc = lmdaFunc;
		std::thread t1(stdFunc);
		std::thread t2(threadFunc,"\nHello from Func");
		std::thread t3((FuncObj()));

		t1.join();
		t2.join();
		t3.join();
		//t1.detach();
		cout << "\nHello from Main thread!!!";
	}
}