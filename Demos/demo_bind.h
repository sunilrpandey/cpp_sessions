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

    return 0;
}

