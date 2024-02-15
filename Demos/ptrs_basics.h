#pragma once
#include <iostream>
using namespace std;
void demoPointer2ConstAndConstPointer()
{
    cout << "\nPointer to const and const pointer demo : \n";
    //Pointer to const string 
    const char* pConstStr = "Hello";
    //pStr[0] = 'h'; //not allowed
    char anotherString[] = "World";
    pConstStr = anotherString;

    //const pointer
    char* const constPtr = anotherString;
    char yetAnotherString[] = "Going Nowhere";
    //constPtr = yetAnotherString; // Not allowed        

}
