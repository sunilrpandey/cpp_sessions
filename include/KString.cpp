#include "KString.h"
#include "common.h"
//Constructor
KString :: KString() : KString("") 
{
    LOG("Default Constructor Called");
}

KString :: KString(int length) 
{
    LOG("Constructor KString(int length)  Called");
    m_data = new char[length + 1];
    m_size = 0;
}
KString :: KString(const char* str) {
    std::string msg = std::string("Constructor KString(const char* str) Called") + std::string(str);
    LOG(msg.c_str());
    m_size = strlen(str);
    m_data = nullptr;
    if (m_size > 0) {
        m_data = new char[m_size + 1];
        std::memcpy(m_data, str, m_size);
        m_data[m_size] = '\0';
    }
}

//destructor 
KString :: ~KString() {
    LOG("Destructor Called");
    if(m_data == nullptr)
        delete[] m_data;
}

//copy constructor
KString :: KString(const KString& other) {
    LOG("Copy Constructor Called");
    char* new_data = new char[other.m_size + 1];
    std::memcpy(new_data, other.m_data, other.m_size + 1);
    m_size = other.m_size;
    m_data = new_data;
}

// Assignment operator
KString& KString :: operator=(const KString& other) {
    LOG("Assignment Operator Called");
    if (this != &other) {
        char* new_data = new char[other.m_size + 1];
        std::memcpy(new_data, other.m_data, other.m_size + 1);
        delete[] m_data;
        m_size = other.m_size;
        m_data = new_data;
    }
    return *this;
}

KString :: KString(KString&& other) noexcept : m_size(other.m_size), m_data(other.m_data) {
    LOG("Move Constructor Called");
    other.m_size = 0;
    other.m_data = nullptr;
}

KString& KString :: operator=(KString&& other) noexcept {
    LOG("Move Assignment Operator Called");
    if (this != &other) {
        delete[] m_data;
        m_size = other.m_size;
        m_data = other.m_data;
        other.m_size = 0;
        other.m_data = nullptr;
    }
    return *this;
}

// Operator overloading
KString KString :: operator+(const KString& other) const 
{
    KString result;
    result.m_size = m_size + other.m_size;
    result.m_data = new char[result.m_size + 1];
    std::memcpy(result.m_data, m_data, m_size);
    std::memcpy(result.m_data + m_size, other.m_data, other.m_size + 1);
    return result;
}
KString& KString :: operator+=(const KString& other) 
{
    *this = *this + other;
    return *this;
}

//Member function    
KString KString::subString(int startIndex, int length) const 
{
    
    if (startIndex < 0 || startIndex >= m_size) {
        cout << "Indexing : Out of Range" << endl;
        return "Invalid String";
    }

    // Adjust length if necessary
    if (startIndex + length > m_size) {
        length = m_size - startIndex;
    }

    // Create a new MyString object to hold the substring
    KString sub_string(length + 1);

    // Copy the characters of the substring into the new MyString
    for (int i = 0; i < length; i++) {
        sub_string.m_data[i] = m_data[startIndex + i];
    }
    sub_string.m_data[length] = '\0';

    return sub_string;
}

void* KString::operator new (size_t size)
{
    cout << "\nCreated using overloaded new";
    return std::malloc(size);
    //return ::operator new(size);
}
void KString::operator delete (void* ptr)
{
    cout << "\nCreated using overloaded delete"; 
    ::std::free(ptr);
    //::operator delete(ptr);
}
void* KString::operator new[](size_t size)
{
    cout << "\nCreated using overloaded new[]"; 

    return std::malloc(size);
    //return ::operator new[](size);
}
void KString::operator delete[](void* ptr)
{
    cout << "\nCreated using overloaded delete[]"; 
    //::operator delete[](ptr);
    std::free(ptr);
}



int KString::to_int() const {
    return atoi(m_data);
}
float KString::to_float() const {
    return atof(m_data);
}


