#include <iostream>
#include <vector>
using namespace std;

int main()
{
    auto arr = { 10,20,30,40,50 };
    for (auto i : arr)
        cout << i << ", ";

    return 0;
}