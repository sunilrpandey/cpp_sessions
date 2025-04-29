#include <iostream>

class Counter {
public:
    int count = 0;

    auto getCounterLambda() {
        // Capture *this by value
        return [*this]() {
            return count;
        };
    }

    void incrementAndPrint() {
        auto incrementer = [this]() mutable {
            count++;
            std::cout << "Count inside lambda: " << count << std::endl;
        };
        incrementer();
    }
};

int demoPassThisToMemeberFunc() {
    Counter c;
    auto counterLambda = c.getCounterLambda();  // Store the lambda

    c.incrementAndPrint(); // Output: Count inside lambda: 1
    c.incrementAndPrint(); // Output: Count inside lambda: 2

    std::cout << "Count outside: " << c.count << std::endl; // Output: Count outside: 2
    std::cout << "Captured count: " << counterLambda() << std::endl; // Output: Captured count: 0
    return 0;
}
