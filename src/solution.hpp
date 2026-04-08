#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <stack>

class MinStack {
private:
    std::stack<int> main_stack;
    std::stack<int> min_stack;

public:
    MinStack() {}
    void push(int val);
    void pop();
    int top();
    int getMin();
};

#endif