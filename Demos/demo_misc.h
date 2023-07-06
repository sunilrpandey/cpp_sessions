#pragma once
#include "common.h"
#include <assert.h>
namespace ns_misc {
    void demoPointer2ConstAndConstPointer()
    {
        cout << "\nPointer to const and const pointer demo : \n";
        //--- Const Pointer variables 
        const char* pConstStr = "Hello";
        //pStr[0] = 'h'; //not allowed
        char anotherString[] = "World";
        pConstStr = anotherString;

        char* const constPtr = anotherString;
        char yetAnotherString[] = "Going Nowhere";
        //constPtr = yetAnotherString; // Not allowed        

    }

    void changeArrElem(int a[3]) {
        a[0] = 10;
        a[1] = 20;
        a[2] = 30;
    }

    void verifyArrayPassedbyRef() {
        int arr[3] = { 1,2,3 };
        changeArrElem(arr); //array is always passed as reference
        cout << "changed array elems : " << arr[0] << arr[1] << arr[2];
        return;

    }

    int ly_add(int i, int j, int k) {
        return i - j - k;
    }

    int demoBind()
    {
        std::function<int(int, int, int)> func = ly_add;
        auto answer = func(2, 3, 100);
        assert(answer == -101);
        cout << answer;
        
        std::function<int(int,int)> funPow2 = std::bind(ly_add, placeholders::_1, placeholders::_2,100);
        answer = funPow2(200,30);
        assert(answer == 70);
        
        funPow2 = std::bind(ly_add, placeholders::_1, placeholders::_2, 5);
        answer = funPow2(10, 1);
        assert(answer == 4);

        return 0;
    }
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
    void demo() 
    {
        verifyArrayPassedbyRef();
        demoPointer2ConstAndConstPointer();
        demoBind();
    }
};
