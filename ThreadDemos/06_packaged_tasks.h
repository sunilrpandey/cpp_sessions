#pragma once

#include <iostream>
#include <thread>
#include <condition_variable>
#include <queue>
#include <future>
#include <functional>

namespace ns_thread
{

	std::queue<std::packaged_task<int()>> task_q;
	std::mutex task_mut;
	std::condition_variable task_cv;

	void factorial(int n);
	int fact(int n);
	
	void producer_task() {
		std::packaged_task<int()> t(std::bind(fact, 6));
		//std::future<int> ret = t.get_future();
		std::packaged_task<int()> t2(std::bind(fact, 9));
		//std::future<int> ret2 = t2.get_future();
		{
			std::unique_lock<std::mutex> locker(task_mut);

			task_q.push(std::move(t));
			task_q.push(std::move(t2));
			locker.unlock();
			task_cv.notify_one();
		}
		//std::cout << "I see: " << ret.get() << std::endl;
		//std::cout << "I see: " << ret2.get() << std::endl;

	}

	void consumer_task() {
		int i = 0;
		while (i < 10000) {
			if (!task_q.empty()) {
				std::unique_lock<std::mutex> locker(task_mut);
				task_cv.wait(locker, []() {return !task_q.empty(); });
				//if (task_q.empty()) // not neeeded 
				//	continue;
				std::packaged_task<int()> t = std::move(task_q.front());
				task_q.pop();
				auto f = t.get_future();
				t();
				std::cout << "I see: " << f.get() << std::endl;
				locker.unlock();

			}
			i++;
		}
	}

	void demo_packaged_tasks() {
		std::thread tp(producer_task);
		std::thread tc(consumer_task);

		tp.join();
		tc.join();
	}

}


