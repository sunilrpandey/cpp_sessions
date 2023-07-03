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


