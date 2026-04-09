#include <cassert>
#include <iostream>
#include "../src/solution.hpp"

int main() {
    MinStack minStack;

    // 1. Caso Normal 
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(minStack.getMin() == -3);
    minStack.pop();
    assert(minStack.top() == 0);
    assert(minStack.getMin() == -2);

    // 2. Caso de Valores repetidos
    MinStack repetidos;
    repetidos.push(5);
    repetidos.push(5);
    repetidos.push(2);
    repetidos.push(2);
    assert(repetidos.getMin() == 2);
    repetidos.pop();
    assert(repetidos.getMin() == 2);

    // 3. Caso borde: Pop en una pila completamente vacía
    MinStack pilaVacia;
    pilaVacia.pop();
    std::cout << "Todas las pruebas pasaron exitosamente!" << std::endl;
    return 0;
}