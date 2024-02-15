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

    std::function<int(int, int)> funPow2 = std::bind(ly_add, placeholders::_1, placeholders::_2, 100);
    answer = funPow2(200, 30);
    assert(answer == 70);

    funPow2 = std::bind(ly_add, placeholders::_1, placeholders::_2, 5); 
    answer = funPow2(10, 1); 
    assert(answer == 4);


    auto funPow3 = std::bind(ly_add, 20, placeholders::_2, 5); //20 and 5 are hardcoded as first/third arg
    answer = funPow3(10, 1); //placeholders::_2 means 1 woudl be passed as second arg, placeholders::_1 means 10 would be passed as seond arg of funPow2 fun in above line
    
    auto funPow4 = std::bind(ly_add, placeholders::_2, placeholders::_1, 5); 
    answer = funPow4(10, 1); //  Here 1 would be passed as first and 10 would be passed as second arg 


    return 0;
}

