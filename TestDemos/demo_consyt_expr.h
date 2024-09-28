#pragma once
#include "common.h"
namespace ns_constexpr
{
    constexpr int size() { //forces to compute at compiel time
        return 1000;
    }
    constexpr int cubed(int x) { return x * x * x; } // 'CAN' be computed at compile time 

    void demoConstExpr()
    {
        int arr[size() + 24];            // will be computed at compile time
        cout << "sizeof arr " << sizeof(arr) << endl;

        cout << "\n4 cubed : " << cubed(4) << endl;// will be computed at compile time

        int x = 5;
        cout << "\nx=5 cubed : " << cubed(x) << endl; // will be computed at run time

    }

    template <int N>
    constexpr int fibonacci() {
        if constexpr (N <= 1) {
            return N;
        }
        else {
            return fibonacci<N - 1>() + fibonacci<N - 2>();
        }
    }

    int demoFibonacciUsingMetaProgramming() {
        constexpr int fib5 = fibonacci<5>(); // ensure calculation is done at compile time only, computation/assigment will happen at compile time
        auto x = 6;
        int fib6 = fibonacci<6>(); //computation of fibonacci<6> will happen at compile time but assignment will happen at runtime
        return 0;
    }


}

