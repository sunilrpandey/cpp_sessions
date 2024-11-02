#pragma once

#include <iostream>
#include <compare>
#include <string>

class Person {
public:
    std::string name;
    int age;

    // Defaulted three-way comparison operator, compares member wise, will compare name first
    //auto operator<=>(const Person& other) const = default; 

    //to compare age implement like below
    auto operator<=>(const Person& other) const {
        return age <=> other.age;
    }


};

void demoThreewayOperator() {
    Person alice{ "Alice", 30 };
    Person bob{ "Bob", 25 };

    // Compare ages using the three-way comparison operator
    if (alice < bob) {
        std::cout << "Alice is younger than Bob." << std::endl;
    }
    else if (alice > bob) {
        std::cout << "Alice is older than Bob." << std::endl;
    }
    else {
        std::cout << "Alice and Bob are the same age." << std::endl;
    }

    return;
}
