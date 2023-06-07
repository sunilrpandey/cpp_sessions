#pragma once
#include "employee.h"

class EmployeeClassDemo
{
public:
    void demoEmployeeClass()
    {
        {
            Employee emp1;
            Employee emp2(2, "Google");
            //create employee class to use another parametrized constructor
        }
        {


            Employee emp1("XYZ", 123, 21, 210000);
            std::cout << "name : " << emp1.getName() << "  salary : " << emp1.salary_ << endl;

            Employee emp2 = emp1; // copy constructor 

            std::cout << "name : " << emp2.getName() << "  salary : " << emp2.salary_ << endl;

            Employee emp3("DEF", 456, 23, 23244);

            emp2 = emp3; //assignment operator

            cout << emp2;

            emp2 = emp2;

            int i = 100;
            cout << i;
        }

        {
            Employee* pEmp = new Employee();
            std::cout << "name : " << pEmp->getName() << "  salary : " << pEmp->salary_ << endl;
            delete pEmp;
            std::cout << "name : " << pEmp->getName() << "  salary : " << pEmp->salary_ << endl;
        }
    }
    void demoPointer_to_employee_object()
    {
        //--- POinter variables 
        cout << "\nPointer variables demo \n";
        Employee emp1("XYZ", 123, 21, 210000);
        Employee* pEmp = &emp1;
        std::cout << "name : " << pEmp->getName() << "  salary : " << pEmp->salary_ << endl;

        Employee emp2("ABC", 456, 41, 410000);
        pEmp = &emp2;
        std::cout << "name : " << pEmp->getName() << "  salary : " << pEmp->salary_ << endl;
    }

    void demo()
    {
        demoEmployeeClass();
        demoPointer_to_employee_object();
    }
};