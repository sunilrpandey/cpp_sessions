#pragma once
#include <iostream>
//overriding needs same function signature for both base and derviced
// over-riding operators does not make sense since for derived class why to keep signature for base class
// but if you are still hell bent, it can be done
// only clone kind of function can 

class Base_OO {
public:
    virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }

    // Overloaded operator
    virtual Base_OO operator+(const Base_OO& other) {
        std::cout << "Base::operator+" << std::endl;
        return *this;
    }

    virtual Base_OO* clone(int a, int b) {
        return new Base_OO();
    }
};

class Derived_OO : public Base_OO {
public:
    void foo() override {
        std::cout << "Derived::foo()" << std::endl;
    }

    // Overloaded operator (not virtual)

    virtual Base_OO operator + (const Base_OO& other) {
        std::cout << "Derived::operator+" << std::endl;
        return *this;
    }

    virtual Derived_OO* clone(int a, int b) {
        return new Derived_OO();
    }
};

int demo_oo() {
    Base_OO baseObj;
    Derived_OO derivedObj;

    //// Calls Base::operator+
    //Base_OO result1 = baseObj + baseObj;

    //Base_OO* pBase = &derivedObj;
    //// Calls Derived::operator+
    //Base_OO result2 = pBase->operator+(baseObj);

    // Calls Base::operator+
    Base_OO result1 = baseObj + baseObj;

    Base_OO& pBase = derivedObj;
    // Calls Derived::operator+
    Base_OO result2 = pBase + baseObj;

    return 0;
}
