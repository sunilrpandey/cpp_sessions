#include "common.h"
#include "employee.h"

int Employee::emp_counter_ = 1;
// Constructors
Employee::Employee() : company_name_("KPIT"), grade_(1) {
    manager_ = nullptr;
    id_ = emp_counter_++;
    age_ = -1;
    salary_ = -1;

}
Employee :: Employee(int grade, const std::string & comp) : name_("INVALID_NAME"), age_(-1), salary_(-1111),grade_(grade), company_name_(comp)
{
    LOG("Empolyee created!!");
    id_ = emp_counter_++;
}

Employee::Employee(const std::string& name, int id, int age, double salary, int grade, const std::string& comp)
    : Employee(grade,comp)
    //: name_(name), age_(age), salary_(salary), grade_(grade), company_name_(comp)
{
    id = emp_counter_++;
    name_ = name, age_ = age, salary_ = salary;
    LOG("Empolyee init done!!")
}

// Destructor
Employee :: ~Employee() 
{
    LOG("Empolyee destroyed!!");
}

// Copy constructor
Employee::Employee(const Employee& other)
    : name_(other.name_)
    , age_(other.age_)
    , salary_(other.salary_) 
    , grade_(other.grade_)
    , company_name_(other.company_name_)
{
    id_ = emp_counter_++;
    LOG("Being copied!!");
}

Employee& Employee:: operator=(const Employee& other)
{
    if (this != &other) {
        name_ = other.name_;
        id_ = other.id_;
        age_ = other.age_;
        salary_ = other.salary_;
    }
    return *this;
}

// Equality operator
bool Employee :: operator==(const Employee& other) const {
    if (id_ == other.id_) {
        return true;
    }
    return false;
}