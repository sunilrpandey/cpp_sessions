#include <iostream>

using namespace std;

class Base
{
public:
	Base() {
		cout << "\nBase created !" << endl;
	}

	virtual ~Base() {
		cout << "\nBase destroyed!" << endl;
	}


	//methogds
	virtual void method() 
	{
		cout << "\nBase Method !" << endl;
	}

	void adhoc_method()
	{
		cout << "\nBase Adhoc Method !" << endl;
	}

};

class Derived : public Base
{
public:
	Derived() {
		cout << "\nDerived created !" << endl;
	}

	~Derived() {
		cout << "\nDerived destroyed!" << endl;
	}
	void adhoc_method()
	{
		cout << "\nDerived Adhoc Method !" << endl;
	}


	//methogds
	void method()
	{
		cout << "\nDerived Method !" << endl;
	}
};

class MultiLevelDerived : public Derived
{
public:
	MultiLevelDerived() {
		cout << "\nMultiLevelDerived created !" << endl;
	}

	~MultiLevelDerived() {
		cout << "\nMultiLevelDerived destroyed!" << endl;
	}


	//methogds
	void method()
	{
		cout << "\nMultiLevelDerived Method !" << endl;
	}
};

class ParallelBase
{
public:
	ParallelBase() {
		cout << "\nParallelBase created !" << endl;
	}

	~ParallelBase() {
		cout << "\nParallelBase destroyed!" << endl;
	}


	//methogds
	void parallel_method()
	{
		cout << "\nParallelBase Method !" << endl;
	}
};

class MultiInheritedDerived : public Base, public ParallelBase
{
public:
	MultiInheritedDerived() {
		cout << "\nMultiInheritedDerived created !" << endl;
	}

	~MultiInheritedDerived() {
		cout << "\nMultiInheritedDerived destroyed!" << endl;
	}


	//methogds
	void method()
	{
		cout << "\nMultiInheritedDerived Method !" << endl;
	}
};

class base1
{
private:
	int a;
public:
	int b;
protected:
	int c;
};

class Der1 : public base1
{
public:
	void method() {
		cout << c;
	}
	~Der1() {}

};

class Der2 : protected base1
{
public:
	void method() {
		cout << c << b;
	}

};

class Der3 : private base1
{
public:
	void method() {
		cout << c << b;
	}

};
class Der4 : private Der3
{
public:
	void method() {
		//cout << c << b;
	}

};

class Person
{
public:
	Person(const std::string& n) : name(n) { cout << "\nPerson created" << endl; }
	virtual ~Person() { cout << "\nPerson destroyed" << endl; }
	virtual void showName() {
		cout << "Name : " << name << endl;
	}
	
	std::string name;
};

class Student : virtual public Person
{
public:
	Student(const std::string& n, const std::string& s) :Person(n), subject(s) {
		cout << "\nStudent created" << endl;
	}
	virtual ~Student() { cout << "\Student destroyed" << endl; }
	std::string subject;
};
class Faculty : virtual public Person
{
public:
	Faculty(const std::string& n, const std::string& d) : Person(n), department(d) {
		cout << "\nFaculty created" << endl;
	}
	virtual ~Faculty() { cout << "\Faculty destroyed" << endl; }
	std::string department;
};
class TA : public Student , public Faculty
{
public:
	TA(const std::string& n, const std::string& s, const std::string& d) :Student(n, s), Faculty(n, d),Person(n) {
		cout << "\nTA created" << endl;
	}
	virtual ~TA() { cout << "\TA destroyed" << endl; }
	std::string department;
};

class InheritanceDemo
{
public:
	void inheritanceTypes_and_BasicsDemo()
	{
		cout << "\nBase Demo : " << endl;
		Base base;
		base.method();

		cout << "\nDerived Demo : " << endl;
		Derived derived;
		derived.method();

		cout << "\nMultilevel inheritance Demo : " << endl;
		MultiLevelDerived mult_level_derived;
		mult_level_derived.method();

		cout << "\nMultiple inheritanceDemo : " << endl;
		MultiInheritedDerived mult_inherited_derived;
		mult_inherited_derived.method();

	}
	void virtualFuncDemo()
	{
		Base* pB = new Base;
		pB->method();

		Derived* pD = new Derived;
		pD->method();

		delete pB;
		pB = pD;
		pB->method();
		pB->adhoc_method();
		delete pB;
	}
	void demoDiamondProb()
	{
		Student st("Student", "CS");
		st.showName();

		TA ta("Teaching Assistant", "CS", "Automotive");
		ta.showName(); //Error if not student and Faculty are not virtually derived, Init Base from bottom class constructor only
	}


	int demo_inheritance()
	{
		//inheritanceBasicDemo();
		//virtualFuncDemo();

		//Der1 d1;
		//d1.a
		//d1.b; //can
		//;
		//Der2 d2;
		//d2.b

		demoDiamondProb();

		//Student st("abc", "math");
		//cout << st.name << endl;



		return 0;
	}
};