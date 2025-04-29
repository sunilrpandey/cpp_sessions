#include "common.h"
#include "demo_threads.h"
#include "sync_threads_using_mutex.h"
using namespace std;

int main()
{
	cout << "thread demos!!" << endl;
<<<<<<< HEAD
	//ns_thread::demo();
=======

>>>>>>> 66ce17f19a24c5d0de892d659c071bb04adbe366
	ns_thread_sync::demo();
	ns_thread::demo();

	return 0;
}