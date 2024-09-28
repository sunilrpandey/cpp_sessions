#pragma once
#include <iostream>

using namespace std;

// Demo includes
// - Veriadic template 
// - Operator new/delete overload

int int_storage[100];


class Test
{
private:
	int pri_mem_var = -1;
public :
	int i = 10;
	int mem = -1;
public:
	//int getI() { return i; }
	friend ostream& operator << (ostream& os, Test t) {
		cout << "\nTest object : " << t.i << endl;
		return os;
	}

	void* operator new (size_t sz) {
		cout << "\nSize requested : " << sz;
		return (void*)(& int_storage[0]);
		//return malloc(sz);
	}

	void operator delete(void * p) {
		cout << "\nStorage freed.. ";
		Test* t = (Test*)p;
		t->i = -1000;
		cout << *t;
		//free(p);
	}
};

//one arg terminator
//template<typename T>
//void print(T obj) {
//	cout << obj << endl;
//}

void print() { 
	//cout << obj << endl;
	//cout << endl << "Done for this call" << endl;

	cout << "\n\n\n\n\n";
}

template<typename T, typename... Args>
void print(T obj, Args... more) {
	cout << obj << ", ";
	print(more...);
}


void demo_operator_new_delete()
{
	{
		for (int i = 0; i < 100; i++) {
			int_storage[i] = i;
		}

		Test* t = new Test;
		t->i = 1000;
		cout << *t;

		delete t;


	}
	return;

}

void Demo_VariadicTemplate()
{

	cout << "::: Print :::" << endl;
	print(5);

	cout << "::: Print with Variable Arguments :::" << endl;
	print(5, 7.5, 'y', Test());

	return;
}

