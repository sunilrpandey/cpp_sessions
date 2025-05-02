#include "common.h"
#include "01_instantiation.h"
#include "02_sync_using_mutex.h"
#include "04_order_condition_variable.h"
#include "05_future_promise.h"

using namespace std;

int main()
{
	cout << "thread demos!!" << endl;
	//ns_thread::demo_instantiation();
	//ns_thread_sync::demo_race_condition_and_resolution();

	//ns_thread::demo_ordering_using_condition_variable();
	//ns_thread::demo_future();

	//ns_thread::demo_promise();
	ns_thread::demo_promise_as_onetime_event_barrier();

	return 0;
} 