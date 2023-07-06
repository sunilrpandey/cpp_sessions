#pragma once
#include <iostream>
#include "common.h"
using namespace std;

namespace ns_move_semantics {

    /*
        Observation :
        1. const ref version is used for ravlue if && veriosn is not available
        2. if both are available, && version would be preferred.
        3. if string& (l value) value is not available const & version is used for lvalue but if
        l value and const ref verson both are available 'lvalue' verison would be preferred by compiler
        void printName(std::string& name)
        void printName(const std::string& name)
        void printName std::string&& name)
    */
#define RValueImplDone 1
    template<typename T>
    void print(T& name) {
        cout << endl << "[lalue version,pure]" << endl;
    }
    template<typename T>
    void print(const T& name) {
        cout << endl << "[lalue (const ref)version, if ravlue impl is not available]" << endl;
    }
#if RValueImplDone
    template<typename T>
    void print(T&& name) {
        cout << endl << "[ralue version]" << endl;
    }
#endif
    class CppRobot
    {
    public:
        string name_;
        static const int k = 32;
        static int counter;
        char ar[100];

        // constructor 
        CppRobot(const string& str = "") :name_(str) {
            LOG("Constructor called");
            name_.append(to_string(counter++));
            cout << "\nBirth : " << name_.c_str();
        }
        // construction from init list 
        CppRobot(const initializer_list<string>& vec_str) {
            LOG("\nConstructor with Initializer list called");
            name_ = *(vec_str.begin());
            CppRobot(name_);            
        }


        // construction from init list 
        CppRobot(const CppRobot& rhs) {
            LOG("Copy Constructor called");
            name_ = rhs.name_;
            counter++;
        }
        // assignment operator
        CppRobot& operator = (const CppRobot& rhs) {
            LOG("Assignment operator called");
            name_ = rhs.name_;
            return *this;
        }
#if RValueImplDone
        // construction from init list 
        CppRobot(CppRobot&& rhs) {
            LOG("Move Constructor called");
            name_ = rhs.name_;
            rhs.name_ = "";
        }
        // assignment operator
        CppRobot& operator = (CppRobot&& rhs) {
            LOG("Move Assignment called");
            name_ = rhs.name_;
            rhs.name_ = "";
            return *this;
        }
#endif
        //distructor 
        ~CppRobot() {
            cout << "\nDeath : " << name_.c_str();
        }
        static int objectCount() { return counter; }
    };
    int CppRobot::counter = 0;

    CppRobot getRobot(const std::string& str) {
        CppRobot bot(str);
        return bot;
    }

    void logRobot(CppRobot&& robo) {
        cout << "\nname : " << robo.name_ << "\tCount :" << robo.counter;
    }

    void logRobot(const CppRobot& robo) {
        cout << "\nname : " << robo.name_ << "\tCount :" << robo.counter;
    }

    void demoMoveSemantics_NoObjectCreatedWhileReturning()
    {

        CppRobot bot = getRobot("Robo");
        cout << "\nname : " << bot.name_ << "\tCount :" << bot.counter;

        cout << "\nlogRobot demo" << endl;
        //logRobot(bot);
        logRobot(CppRobot("RoboUpgraded"));

        return;
    }

    int demoLRValuePreferences()
    {
        auto fn = "first";
        string ln = "last";
        auto n = fn + ln;
        print(fn);
        print(fn + ln);

        return 0;
    }

    void demoRValue() {

        demoMoveSemantics_NoObjectCreatedWhileReturning();
        demoLRValuePreferences();
    }
}