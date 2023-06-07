#pragma once
#include "common.h"
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
