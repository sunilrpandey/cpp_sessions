#pragma once

#include "common.h""
#include <thread>
#include <string>
#include <condition_variable>
#include <deque>
using namespace std;


namespace ns_thread
{

	std::deque<int> dq;
	std::mutex mut;
	std::condition_variable cv;

	void producer() {
		int data = 10;
		while (data > 0) {
			std::unique_lock<std::mutex> locker(mut);
			dq.push_back(data);
			locker.unlock();
			cv.notify_one();
			std::cout << "\nAdded : " << data << "\t";
			--data;
		}
	}

	void consumer() {
		int data = 0;
		while (data != 1) {
			std::unique_lock<std::mutex> locker(mut);
			cv.wait(locker, []() {return !dq.empty(); });
			data = dq.back();
			dq.pop_back();
			std::cout << "\nReceived : " << data << "\t";
			locker.unlock();
		}
	}

	void demo_ordering_using_condition_variable() {
		std::thread tp(producer);
		std::thread tc(consumer);

		tp.join();
		tc.join();
	}

}

