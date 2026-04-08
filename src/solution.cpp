#include "solution.hpp"

void MinStack::push(int val) {
    main_stack.push(val);
    // Si la pila de mínimos está vacía o el nuevo valor es menor/igual al mínimo actual
    if (min_stack.empty() || val <= min_stack.top()) {
        min_stack.push(val);
    }
}

void MinStack::pop() {
    if (main_stack.empty()) {
        return;
    }
    if (main_stack.top() == min_stack.top()) {
        min_stack.pop();
    }
    main_stack.pop();
}

int MinStack::top() {
    return main_stack.top();
}

int MinStack::getMin() {
    return min_stack.top(); // Operación O(1)
}