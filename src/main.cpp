#include <iostream>
#include "solution.hpp"

int main() {
    std::cout << "=== Demostracion de Min Stack (Problema 8) ===" << std::endl;
    MinStack minStack;

    std::cout << "Haciendo push de: -2, 0, -3" << std::endl;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    std::cout << "Minimo actual (debe ser -3): " << minStack.getMin() << std::endl;

    std::cout << "Haciendo pop..." << std::endl;
    minStack.pop();

    std::cout << "Top actual (debe ser 0): " << minStack.top() << std::endl;
    std::cout << "Minimo despues de pop (debe ser -2): " << minStack.getMin() << std::endl;

    std::cout << "==============================================" << std::endl;
    return 0;
}