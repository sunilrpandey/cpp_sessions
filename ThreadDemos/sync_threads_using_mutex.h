#pragma once
#include "common.h""
#include <thread>
#include <string>
using namespace std;
#define LOOP_CNT 500
namespace ns_thread_sync
{
	void SharedPrint(const std::string& msg) {

		for (int i = 0; i < LOOP_CNT; i++)
			cout << msg + "  " + std::to_string(i);
	}
	
	void threadWorker(const std::string& msg) {
		SharedPrint(msg);
	}
	
	void demo()
	{
		std::thread t1(threadWorker, "\nThis call is to be done from			Worker : ");
		SharedPrint("\nThis is normal function				Main :");
		t1.join();
	}

} 