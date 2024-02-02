#include "common.h"
#include "demo_threads.h"
using namespace std;

class Base
{

public:
	virtual void fun(int i = 10) {
		cout << i;
	}
};

class Derived : public Base
{
public:
	virtual void fun(int i = 20) {
		cout << i;
	}
};



int main()
{
	Base* p = new Derived;
	p->fun();

	return 0;
	
	//cout << "thread demos!!" << endl;
	//ns_thread::demo();

	//return 0;
}