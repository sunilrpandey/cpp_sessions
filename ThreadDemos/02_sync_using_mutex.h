#pragma once
#include "common.h""
#include <thread>
#include <string>
#include <mutex>
using namespace std;
#define LOOP_CNT 500
std::mutex sync_mut;
namespace ns_thread_sync
{
	void SharedPrint(const std::string& msg, int multiplier, bool sync_enabled) {

		if (sync_enabled) {
			std::lock_guard<std::mutex> guard(sync_mut);

			for (int i = 0; i < LOOP_CNT; i++)
				cout << msg + "  " + std::to_string(i * multiplier);
		}
		else {
			for (int i = 0; i < LOOP_CNT; i++)
				cout << msg + "  " + std::to_string(i * multiplier);
		}

	}
	
	void threadWorker(const std::string& msg, int multiplier, bool sync_enabled) {
		SharedPrint(msg, multiplier, sync_enabled);
	}

	class ThreadWrapper
	{
	public:
		std::thread t;
		ThreadWrapper(std::thread thd) :t(std::move(thd)) {}
		~ThreadWrapper() {
			if (t.joinable()) {
				t.join();
			}
		}
	};
	
	//here std::cout is shared resource
	void demo_race_condition_and_resolution()
	{
		bool sync_enabled = true;
		//coutput from worker thread
		std::thread t1(threadWorker, "\nWorker : ", 1, sync_enabled);
		ThreadWrapper tw(std::move(t1));
		
		//output from main thread
		SharedPrint("\nMain : ",10 , sync_enabled);
		//t1.join();
	}

} 