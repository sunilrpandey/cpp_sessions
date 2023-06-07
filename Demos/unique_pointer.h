#pragma once
#include "common.h"
template<typename T>
class UniquePointer
{
	UniquePointer(const UniquePointer& rhs) = delete;
	UniquePointer& operator = (const UniquePointer& rhs) = delete;
public:
	UniquePointer(T* ptr = nullptr) :ptr_(ptr) {}
	UniquePointer(UniquePointer&& rhs) :ptr_(rhs.ptr_) {
		LOG("Move constructed!");		
		rhs.ptr_ = nullptr;
	}
	UniquePointer& operator = (UniquePointer&& rhs) {
		LOG("Move assigned!");
		if (&rhs != this) {
			delete ptr_;
			ptr_ = rhs.ptr_;
			rhs.ptr_ = nullptr;
			return *this;
		}
	}
	T* operator -> () {
		return ptr_;
	}
	T& operator * () {
		return *ptr_;
	}
	T* get() const {
		return ptr_;
	}
	T* release() {
		T* temp = ptr_;
		ptr_ = nullptr;
		return temp;
	}
	void reset(T* new_ptr = nullptr) {
		T* temp = ptr_;
		ptr_ = new_ptr;
		delete temp;
	}

private:
	T* ptr_;
};

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
	if(uptr2.get())
		cout << "value still there : " << *uptr2;
	else {
		cout << "uptr2 moved to uptr3 ";
		cout << "\nvalue at uptr3 : " << *uptr3;
	}

	return;
}

