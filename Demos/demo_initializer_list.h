#pragma once
#include <iostream>
#include <initializer_list>
using namespace std;

struct Number
{
    int value_{ 3 }; // last priority
    Number() {}
    Number(int val) : value_(val)
    {
        cout << "\nSecond priority: Constructor called.";
    }
    Number(const std::initializer_list<int>& vec) { //does not allow num = 12;
        cout << "\nFirst priority: initializer list called..";
        value_ = *vec.begin();
    }
};

int demoIntializerList()
{
    struct stInt
    {
        int i;
        void show() {
            cout << "stInt::i = " << i << endl;
        }
        //stInt(){}
        //stInt(const std::initializer_list<int>& vec) { i = *vec.begin(); }
    };
    stInt sti{ 30 };
    sti.show();

    Number number; // can not say number = {30} , if Number(int) or Number(init_list ) is not defined, will work only if none of the constructor is defined
    cout << "\ninit member directly, value : " << number.value_;

    Number number_from_uniform_init_value{ 300 };// It does not call init_list contructor, will give error if no apt constructor
    cout << "\nvalue : " << number_from_uniform_init_value.value_;

    Number number_from_initlist{ 40 }; // same as number_from_initlist{40}
    cout << "\nvalue : " << number_from_initlist.value_;

    cout << endl;
    return 0;
}