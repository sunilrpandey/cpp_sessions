#pragma once
#include <functional>
#include <assert.h>
#include <iostream>

using namespace std;
int ly_add(int i, int j, int k) {
    return i - j - k;
}

int demoBind()
{
    std::function<int(int, int, int)> func = ly_add;
    auto answer = func(2, 3, 100);
    assert(answer == -101);
    cout << answer;

    // here -1 means place first param, -2 means place second param 
    // ** from the two param called func - funPow2 here **
    std::function<int(int, int)> funPow2 = std::bind(ly_add, placeholders::_1, placeholders::_2, 100);
    // in below example for ly_add i = 200, j = 30
    answer = funPow2(200, 30);
    assert(answer == 70);

    funPow2 = std::bind(ly_add, placeholders::_1, placeholders::_2, 5); 
    answer = funPow2(10, 1); 
    assert(answer == 4);


    auto funPow3 = std::bind(ly_add, 20, placeholders::_2, 5); //20 and 5 are hardcoded as first/third arg
    //placeholders::_2 means 3 woudl be passed as second arg, 
    // 10 as first param would be ignored. since it is hardcoded as 20 in definition
    answer = funPow3(10, 3); 
    assert(answer == 12);

    auto funPow4 = std::bind(ly_add, placeholders::_2, placeholders::_1, 5); 
    answer = funPow4(10, 1); //  Here 1 would be passed as first and 10 would be passed as second arg 
    assert(answer == -14);


    return 0;
}

