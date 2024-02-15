#pragma once
#include "common.h"


/* In case of virtual bases
Check size of derived to observe how top base data is copied to bottom derived if not virtually derived.Check if Derived has two copy of top base!
sizeof Base : 40
sizeof Dervied : 56
Anyways !
sizeof MidDer1 : 48
sizeof MidDer2 : 48
*/
namespace ns_classsize
{
    class Base
    {
    public:
        int arr[10];
        void dump(const std::string & msg) {
            cout << msg << endl;
        }

    };
    class MidDer1 : public virtual Base {};
    class MidDer2 : public virtual Base {};
    class Derived :public MidDer1, public MidDer2 {};

    Base fun1() {
        return Base();
    }

    void demo_sizeof_derived_class() {

        Base b1 = fun1();
        b1.dump("\nCheck size of derived to observe how top base data is copied to bottom derived if not virtually derived.");

        //int sz = sizeof(Derived)/sizeof(int);
        int size_base = sizeof(Base);
        int size_derived = sizeof(Derived);
        
        ostringstream ostr;        
        ostr << "Check if Derived has two copy of top base! \nsizeof Base : " << sizeof(Base) << "\nsizeof Dervied : " << sizeof(Derived);
        b1.dump(ostr.str());
        ostr.clear();
        
        ostr << "\n Anyways ! \nsizeof MidDer1 : " << sizeof(MidDer1) << "\nsizeof MidDer2 : " << sizeof(MidDer2);
        b1.dump(ostr.str());

    }
};