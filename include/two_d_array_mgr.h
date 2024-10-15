#pragma once
#include "common.h"

class TwoDArrayManager
{
    int num_rows;
    int num_col;
    int** pDynArray;
public:
    TwoDArrayManager() {
        num_rows = NUM_ROWS;
        num_col = NUM_COL;
        allocateMemory();
    }

    TwoDArrayManager(int r, int c) :num_rows(r), num_col(c) {
        allocateMemory();
    }

    TwoDArrayManager(const TwoDArrayManager& rhs) :num_rows(rhs.num_rows), num_col(rhs.num_rows) {
        allocateMemory();
    }

    TwoDArrayManager operator = (TwoDArrayManager& rhs){
        if(rhs == *this)
            return *this;
    }
    bool operator == (TwoDArrayManager& rhs) {
        if (rhs.pDynArray == this->pDynArray)
            return true;
        return false;
    }

    void allocateMemory() {
        cout << "\n..allocting space for 2D array of size : " << num_rows << " x " << num_col << endl;

        pDynArray = new int* [num_rows];
        for (int i = 0; i < num_rows; i++) {
            pDynArray[i] = new int[num_col];
        }
    }
    void deallocateMemory() {
        cout << "\n..freeing up space allocated for 2D array of size : " << num_rows << " x " << num_col << endl;

        for (int i = 0; i < num_rows; i++) {
            delete[] pDynArray[i];
        }
        delete[] pDynArray;

    }

    void populateArray(int counter) {
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_col; j++) {
                pDynArray[i][j] = counter++;
            }
        }
    }
    void showArrayElements() {
        cout << "\nDisplaying Array elements\n";
        int counter = 11;
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_col; j++) {
                cout << pDynArray[i][j] << "\t";
            }
            cout << endl;
        }
    }
    int& operator()(int r, int c) {
        return pDynArray[r][c];
    }

    ~TwoDArrayManager() {
        deallocateMemory();
    }

    ////need to check if it works , though not safe if caller does not know size of rows and try to access
    //int* operator[](int row_index) {
    //    return pDynArray[row_index];
    //}
    
#if 1 // needed to overload [][]
private:
    class Row
    {
        int* row_elems;
    public:
        Row(int* rowData) :row_elems(rowData) {

        }
        int& operator [] (int index) {
            return row_elems[index];
        }
    };

public:
    Row operator[](int row_index) {
        return Row(pDynArray[row_index]);
    }
#endif
};
