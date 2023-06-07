#include "common.h"
#include "demo_employee.h"
#include "file_manger_demo.h"
#include "demo_inheritance.h"
#include "demo_array.h"
#include "demo_kstring.h"
#include "demo_misc.h"
#include "demo_friends.h"
#include "templates_basics.h"
#include "smart_pointer.h"
#include "unique_pointer.h"

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
	SharedPointer(const SharedPointer& rhs){
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

	~SharedPointer(){
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
	cout << "value at uptr2 : " << *uptr2<< "  count : " << uptr2.getCount();

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



void demoEnum(Color selectedColor)
{
	switch (selectedColor) {
	case RED:
		cout << "The selected color is red." << endl;
		break;
	case GREEN:
		cout << "The selected color is green." << endl;
		break;
	case BLUE:
		cout << "The selected color is blue." << endl;
		break;
	default:
		cout << "Invalid color selection." << endl;
		break;
	}
}




int main()
{
		

	/*
	KStringDemo ksd;
	ksd.demoKSTrings();

	
	ArrayDemo ad;
	ad.demo_arrays();

	InheritanceDemo id;
	id.demo_inheritance();

	EmployeeClassDemo ecd;
	ecd.demo();

	DemoFriends df;
	df.demoFriends();


	FileHandlingDemo fhd;
	fhd.demo_file_func_demo();
	fhd.demo_filehandling_with_class_objects();

	
	
	demo_templates();
	
	demoPointer2ConstAndConstPointer();
	
	demoSmartPointer();	
	demoUniquePointer();
	demoSharedPointer();

	*/
	




	demo_templates();

	
	




	
	return 0;
}
