#pragma once
#include "common.h"
#include <utility>
#include <memory>

namespace ns_wkptr
{
	#define log(msg) cout << endl << msg << endl
	class Person
	{
		std::string name_;
	public:
		Person(const std::string& val) {
			name_ = val;
			std::string msg = name_ + " created.\n";
			log(msg.c_str());
		}
		~Person() {
			std::string msg = name_ + " destroyed.\n";
			log(msg.c_str());
		}
		weak_ptr<Person> friend_; // instead of 
		//shared_ptr<A> friend_; // instead of 
	public:

		std::string name() { return name_; }
		void show() {
			cout << "my name : " << name().c_str();
		}
		void setFriend(shared_ptr<Person> pA) {
			friend_ = pA;
		}
		void showFriend() { 

			if (!friend_.expired())  // check if obj is still alive
				friend_.lock()->show(); // use lock to invoke shared_ptr
			else
				cout << name_.c_str() << " : my friend is expired!" << endl;
		}

	};

int demo_weakptrs()
{
	{
		shared_ptr<ns_wkptr::Person> spA = make_shared<ns_wkptr::Person>("objA");
		shared_ptr<ns_wkptr::Person> spB = make_shared<ns_wkptr::Person>("objB");

		spA->setFriend(spB);
		spB->setFriend(spA);


		spA.reset(); // that is why weak_ptr is useful
		spB->showFriend(); // 
		int i = 0;
	}
	return 0;
}

template<typename T>
void pass_smartptr_to_func(T sp)
{
	cout << "\nname : " << sp->name();
	return;
}
template<>
void pass_smartptr_to_func<std::shared_ptr<ns_wkptr::Person>>(std::shared_ptr<ns_wkptr::Person> sp)
{
	cout << "\nname : " << sp->name() << "\tCount :" << sp.use_count();
	return;
}
void demo_pass_smartptrs_to_func() 
{
	shared_ptr<ns_wkptr::Person> spA = make_shared<ns_wkptr::Person>("SO_Person");
	cout << "\nname : " << spA->name() <<  "\tCount :" << spA.use_count();
	pass_smartptr_to_func(spA);
	cout << "\nname : " << spA->name() << "\tCount :" << spA.use_count();

	unique_ptr<ns_wkptr::Person> upA = make_unique<ns_wkptr::Person>("Unq_Person");
	pass_smartptr_to_func(move(upA));
	if (upA) {
		cout << "It should not be alive by now!!";
	}
	return;
}

void demo()
{
	demo_pass_smartptrs_to_func();
	//demo_weakptrs();
}
};


