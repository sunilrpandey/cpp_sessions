#include "common.h"
#include "demo_threads.h"
#include "sync_threads_using_mutex.h"
using namespace std;

int main()
{
	cout << "thread demos!!" << endl;
	//ns_thread::demo();
	ns_thread_sync::demo();

	return 0;
}