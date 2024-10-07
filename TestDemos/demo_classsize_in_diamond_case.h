#pragma once
#include "common.h"


/* In case of virtual bases
Check size of derived to observe how top base data is copied to bottom derived if not virtually derived.Check if Derived has two copy of top base!
sizeof Base : 40
sizeof Bottom Dervied : 56
Anyways !
sizeof MidDer1 : 48
sizeof MidDer2 : 48
*/
// TODO: in below example need to figure out how/why rank from base class is getting udpated
// in both the mid derived classes
namespace ns_classsize
{
    class Base
    {
    public:
        Base() {}
        int arr[10] = {10,20,30,40,50,60,70,80,90,100};
        int rank = 1;
        int init_rank = 10;
        void dump(const std::string & msg) {
            cout << msg << endl;
        }

    };
    class MidDer1 : public virtual Base {
    public:
        MidDer1() : Base() {
            arr[1] = 100;
            rank = 21;
        }
    };
    class MidDer2 : public virtual Base {
    public:
        MidDer2() : Base() {
            arr[1] = 1000;
            rank = 22;
        }
    };
    class Derived :public MidDer2, public MidDer1 {
    public:
        Derived():MidDer1(),MidDer2() {}
        void showArr() {
            std::cout << "\narr[1] : " << arr[1];
            std::cout << "\nrank : " << rank;

        }
    };

    Base fun1() {
        return Base();
    }

    void demo_sizeof_derived_class() {

        Derived dr;
        dr.showArr();
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