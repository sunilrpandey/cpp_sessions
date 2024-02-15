#pragma once
#include "two_d_array_mgr.h"

// Need to take rows as class in order to operload/implement [][] operator
// Arrays are always passed as ref

class ArrayDemo
{
public:
    void demoArray()
    {
        int arr[5] = { 10,20,30,40,50 };
        int* pArray = new int[5];
        for (int i = 0; i < 5; i++)
            pArray[i] = 100 * (i + 1); // fills array with 100,200,300 etc

        for (int i = 0; i < 5; i++) {
            cout << "Static Array elment arr[" << i << "] - " << arr[i];
            cout << "   Dynamic Array elment arr[" << i << "] - " << pArray[i];
            cout << endl;
        }

        delete[] pArray;

    }

    void demoMultiDimentionalArray()
    {
        int inputArray[NUM_ROWS][NUM_COL] = { {10,20},
                                              {30,40}
        };
        int staticArray[NUM_ROWS][NUM_COL]; //2D Array with statically allocated memory
        
        int** pDynArray = new int * [NUM_ROWS];//Dyanamically created 2D Array, it is array of rows(an array itself)
        int* pArrayAs2dArray = new int[NUM_ROWS * NUM_COL];//Dyanamically created Array, 2D array data is mapped here

        for (int i = 0; i < NUM_ROWS; i++) {
            pDynArray[i] = new int[NUM_COL];
        }
        for (int i = 0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COL; j++) {
                staticArray[i][j] = inputArray[i][j];
                pDynArray[i][j] = inputArray[i][j] * 2;
                pArrayAs2dArray[i * NUM_COL + j] = inputArray[i][j] * 3;
            } 
        }
        cout << "\nDisplay Static Array : \n";
        for (int i = 0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COL; j++) {
                cout << staticArray[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "\nDisplay Dynamic 2D Array : \n";
        for (int i = 0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COL; j++) {
                cout << pDynArray[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "\nDisplay Array as 2D Array : \n";
        for (int i = 0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COL; j++) {
                cout << pArrayAs2dArray[i * NUM_COL + j] << "\t";
            }
            cout << endl;
        }
        //delete dynamically created 2d dynamic array
        for (int i = 0; i < NUM_ROWS; i++) {
            delete[] pDynArray[i];
        }

        delete[] pDynArray;
        delete[] pArrayAs2dArray;
    }
    void demoReference(TwoDArrayManager& twoDArray)
    {
        twoDArray.showArrayElements();
    }
    void demo2DArrayManagerClass()
    {
        TwoDArrayManager twoDArray(3, 5);
        twoDArray.populateArray(1);
        twoDArray.showArrayElements();
        cout << "\nElement at (0,3) should be 4 and what I got is :  " << twoDArray(0, 3);

#if 0 // needed to overload [][]
        {
            cout << "\nElement at [0][3] should be 4 and what I got is :  " << twoDArray[0][3];
            twoDArray[0][3] = 76;
            twoDArray.showArrayElements();
            cout << "\nupdated Element at [0][3] should be  :  " << twoDArray[0][3];
        }
#endif

        // demoReference(twoDArray); as we discussed before
    }

    void changeArrElem(int a[3]) {
        a[0] = 10;
        a[1] = 20;
        a[2] = 30;
    }

    void demoVerifyArrayPassedbyRef() {
        int arr[3] = { 1,2,3 };
        changeArrElem(arr); //array is always passed as reference
        cout << "changed array elems : " << arr[0] << arr[1] << arr[2];
        return;

    }


    void demo_arrays()
    {

        demoArray();
        //demoMultiDimentionalArray();

        //demo2DArrayManagerClass();

        demoVerifyArrayPassedbyRef();

    }
};