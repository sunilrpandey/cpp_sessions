#pragma once
#include <iostream>
//#include <cstring> // for string functions
//#include <string>


using namespace std;
class Employee
{
public:    
    //constructor
    Employee();
    Employee(int grade, const std::string& comp = "KPIT"); 
    Employee(const std::string& name, int id, int age, double salary, int grade = 1, const std::string& comp = "ABC"); // parametrized constructo4
    
    Employee(const Employee& other); // Copy constructor, construction followed by initialization from other other object
    Employee& operator=(const Employee& other);// Assignment operator Initialiation using other object 
    
    ~Employee();   // Destructor
    // Equality operator
    bool operator==(const Employee& other) const;
    
    // Output stream operator    
    friend std::ostream& operator << (std::ostream& os, const Employee& emp) {
        os << "Name: " << emp.name_ << ", ID: " << emp.id_ << ", Age: " << emp.age_ << ", Salary: " << emp.salary_;
        return os;
    }

    
    std::string getName() { //getter
        return this->name_;
    }
    void setName(const std::string& value) {//Setter/setter
        name_ = value;
    }
private:
    std::string name_;
    
public: 
    int id_;
    int age_;
    double salary_;
    
    //class level variable
    static int emp_counter_; 
    
    const std::string& company_name_;   
    const int grade_;

    Employee* manager_;

    // default info;
    std::string base_loc_;
};
