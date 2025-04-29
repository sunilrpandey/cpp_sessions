#include "common.h"
#include "demo_threads.h"
#include "sync_threads_using_mutex.h"
using namespace std;

int main()
{
	cout << "thread demos!!" << endl;
	ns_thread_sync::demo();
	ns_thread::demo();

	return 0;
}