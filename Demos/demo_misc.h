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
     
    void demo() 
    {
        demoBind();

    }
};
