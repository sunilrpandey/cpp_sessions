#pragma once
#include "KString.h"

class KStringDemo
{
public:

    void demoStringClass()
    {
        { // demo 1
            KString str1("Hello");
            KString str2("World");
            KString str3 = str1 + str2;
            std::cout << str3;

            KString str4 = str1 + "__" + str2;
            std::cout << str4 << std::endl;

            str4 += "!!!";
            std::cout << str3 << std::endl; // prints "Hello World!!!"

            KString sub_string = str4.subString(3, 25);
            std::cout << sub_string << std::endl;

            KString str5("123");
            int num = str5.to_int(); // conversion to int
            std::cout << num << std::endl; //

            KString str6("12.305");
            num = str6.to_float(); // conversion to int
            std::cout << num << std::endl; //
        }

    }

    void demoNewDeleteOperatorOverload()
    {
        KString* pStr = new KString("abc");
        KString* pStrArray = new KString[3];

        delete pStr;
        delete[] pStrArray;
    }

    void demoKStrings()
    {
        //demoStringClass();
        //demoNewDeleteOperatorOverload();

    }
};