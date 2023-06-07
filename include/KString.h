#pragma once
#include <cstring> // for string functions
#include <iostream>

using namespace std;

class Printer;
class KString {
public:

    //Default Constructor
    KString();

    //Parameterized constructor
    KString(int length);
    KString(const char* str);

    //destructor 
    ~KString();

    //copy constructor
    KString(const KString& other);

    // Assignment operator
    KString& operator=(const KString& other);

    //Move constructor
    KString(KString&& other) noexcept;

    // Move Assignment operator
    KString& operator=(KString&& other) noexcept;

    // Operator overloading
    KString operator+(const KString& other) const;
    KString& operator+=(const KString& other);
   
    
    static void* operator new (size_t size);
    static void operator delete (void * ptr);

    static void* operator new[](size_t size);
    static void operator delete[](void* ptr);

    //Member function    
    KString subString(int startIndex, int length) const;
    int length() {
        return m_size;
    }
    bool empty() {
        return m_size == 0;
    }

    friend bool operator >= (KString& lhs, KString& rhs) {
        if (lhs.m_size  >= rhs.m_size)
            return true;
        else
            return false;        
    }


    // Create a new MyString object to hold the substring
    
    int to_int() const;
    float to_float() const;
    friend std::ostream& operator<<(std::ostream& os, const KString& str) {
        return os << str.m_data;
    }
    friend void print(const KString& str);
    friend Printer;

private:
    int m_size;
    char* m_data;
};
