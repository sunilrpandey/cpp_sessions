#include "common.h"

class RefereneCount
{
public:
	RefereneCount(int i = 0) {
		count = i;
	}
	void increment() {
		count++;
	}
	void decrment() {
		count--;
	}
	int getCount() {
		return count;
	}
private:
	int count;

};

template <typename T>
class SharedPointer
{
public:
	SharedPointer(T* ptr = nullptr) :ptr_(ptr) {
		if (ptr_ != nullptr) {
			ref_count_ = new RefereneCount(1);
		}
	}
	SharedPointer(const SharedPointer& rhs) {
		ptr_ = rhs.ptr_;
		ref_count_ = rhs.ref_count_;
		if (ptr_ != nullptr) {
			ref_count_->increment();
		}
	}
	SharedPointer& operator = (const SharedPointer& rhs) {
		cleanup();
		ptr_ = rhs.ptr_;
		ref_count_ = rhs.ref_count_;
		if (ptr_ != nullptr) {
			ref_count_->increment();
		}
	}

	SharedPointer(SharedPointer&& rhs) {
		ptr_ = rhs.ptr_;
		ref_count_ = rhs.ref_count_;
		rhs.ptr_ = nullptr;
		rhs.ref_count_ = nullptr;
	}
	SharedPointer& operator = (SharedPointer&& rhs) {
		cleanup();
		ptr_ = rhs.ptr_;
		ref_count_ = rhs.ref_count_;
		rhs.ptr_ = nullptr;
		rhs.ref_count_ = nullptr;
		return *this;
	}

	void cleanup() {
		if (ref_count_) {
			ref_count_->decrment();
			if (!ref_count_->getCount()) {
				delete ptr_;
				delete ref_count_;
			}
		}
	}

	~SharedPointer() {
		cleanup();
	}

	int getCount() {
		return ref_count_->getCount();
	}
	T* get() {
		return ptr_;
	}

	T* operator ->() {
		return ptr_;
	}
	T& operator * () {
		return *ptr_;
	}
	void reset(T* new_ptr = nullptr) {
		T* temp = ptr_;
		ptr_ = new_ptr;
		delete temp;
	}

private:
	T* ptr_;
	RefereneCount* ref_count_;
};

// MakeShared function
template <typename T, typename... Args>
SharedPointer<T> make_shared_pointer(Args&&... args) {
	return SharedPointer<T>(new T(std::forward<Args>(args)...));
}


