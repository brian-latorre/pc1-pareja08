#include <cassert>
#include <iostream>
#include "../src/solution.hpp"

int main() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    
    assert(minStack->getMin() == -3); // El mínimo debe ser -3
    minStack->pop();
    assert(minStack->top() == 0);
    assert(minStack->getMin() == -2); // Tras el pop, el mínimo vuelve a ser -2
    
    std::cout << "Pruebas de MinStack pasadas correctamente." << std::endl;
    return 0;
}