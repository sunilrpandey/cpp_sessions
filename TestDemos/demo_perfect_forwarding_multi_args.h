#pragma once
#include <iostream>
#include <string>

void target(int& x, const std::string& s) {
    std::cout << "target called with lvalue int: " << x << ", string: " << s << "\n";
}

void target(int& x, std::string&& s) {
    std::cout << "target called with lvalue int: " << x << ", raw string: " << s << "\n";
}

void target(int&& x, std::string&& s) {
    std::cout << "target called with rvalue int and string\n";
}

template<typename... Args>
void forwardToTarget(Args&&... args) {
    target(std::forward<Args>(args)...);
}

void demo_perfect_forwarding_multi_arg() {
    int x = 5;
    std::string name = "Radar";

    forwardToTarget(x, name);                    // lvalue + lvalue
    forwardToTarget(x, "camera");                    // lvalue + lvalue
    forwardToTarget(10, std::string("Lidar"));   // rvalue + rvalue
}

