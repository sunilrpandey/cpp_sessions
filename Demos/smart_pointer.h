#pragma once
#include "common.h"
class Corp
{
public:
	Corp(int num_emp = 1) :emp_count(num_emp) {

		emp_ids = new int[num_emp];
	}
	~Corp() {
		cout << "\ndeleting corp" << endl;
		delete[] emp_ids;
	}
	void print() {
		cout << "printing required info" << endl;
	}
private:
	int* emp_ids;
	int emp_count;
};

class SmartCorpPointer
{
public:
	SmartCorpPointer(Corp* p) :ptr(p) {}
	~SmartCorpPointer() { delete ptr; }

	Corp* operator -> () {
		return ptr;
	}
	Corp& operator * () {
		return *ptr;
	}
private:

	Corp* ptr;
};

template<typename T>
class SmartPointer
{
public:
	SmartPointer(T* p) :ptr(p) {}
	~SmartPointer() { delete ptr; }

	T* operator -> () {
		return ptr;
	}
	T& operator * () {
		return *ptr;
	}
private:

	T* ptr;
};

void demoSmartPointer()
{
	{
		Corp* p = new Corp(25);
		p->print();
	}
	{
		SmartCorpPointer corpPtr(new Corp(25));
		corpPtr->print();
	}
	{
		SmartPointer<Corp> smrtPtr(new Corp(25));
		smrtPtr->print();

	}
}

