#pragma once
#include "smart_pointer.h"
#include "unique_pointer.h"
#include "custom_shared_pointer.h"

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

void demoSharedPointer()
{
	SharedPointer<int> sptr(new int(42));
	//SharedPointer<int> sptr = make_shared_pointer<int>(42);
	cout << *sptr << endl;
	*sptr = 100;
	cout << *sptr << endl;

	sptr.reset(new int(99));
	cout << *sptr << endl;


	SharedPointer<int> uptr1(new int(10));
	cout << "count : " << uptr1.getCount() << endl;
	SharedPointer<int> uptr2(uptr1);
	cout << "value at uptr2 : " << *uptr2 << "  count : " << uptr2.getCount();

	SharedPointer<int> uptr3;
	//cout << "count : " << uptr3.getCount() << endl;
	uptr3 = std::move(uptr2);
	if (uptr2.get())
		cout << "value still there : " << *uptr2;
	else {
		cout << "\nuptr2 moved to uptr3 ";
		cout << "\nvalue at uptr3 : " << *uptr3 << "  count : " << uptr3.getCount();;
	}
}
void demoUniquePointer()
{
	UniquePointer<int> uptr(new int(42));
	cout << *uptr << endl;
	*uptr = 100;
	cout << *uptr << endl;

	uptr.reset(new int(99));
	cout << *uptr << endl;

	int* rawPtr = uptr.release();
	if (!uptr.get()) {
		LOG("data released and collected at rawPtr : ");
		cout << *rawPtr << endl;
		delete rawPtr;
	}

	UniquePointer<int> uptr1(new int(10));
	UniquePointer<int> uptr2(std::move(uptr1)); //move constructor'
	cout << "value at uptr2 : " << *uptr2;

	UniquePointer<int> uptr3;
	uptr3 = std::move(uptr2);
	if (uptr2.get())
		cout << "value still there : " << *uptr2;
	else {
		cout << "uptr2 moved to uptr3 ";
		cout << "\nvalue at uptr3 : " << *uptr3;
	}

	return;
}
