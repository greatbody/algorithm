/**
 * Simple Stack Implementation in C++
 *
 * A minimal, cross-platform stack implementation using STL
 */

#include <iostream>
#include <vector>
#include <string>
#include "stack.hpp"

// Push element onto stack
void SimpleStack::push(int item) {
    items.push_back(item);
}

// Pop element from stack
int SimpleStack::pop() {
    if (items.empty()) {
        std::cout << "Stack underflow!" << std::endl;
        return -1;
    }
    int top = items.back();
    items.pop_back();
    return top;
}

// Peek at top element
int SimpleStack::peek() {
    if (items.empty()) {
        std::cout << "Stack is empty!" << std::endl;
        return -1;
    }
    return items.back();
}

// Check if stack is empty
bool SimpleStack::isEmpty() {
    return items.empty();
}

// Get stack size
size_t SimpleStack::size() {
    return items.size();
}

// Print stack contents
void SimpleStack::print() {
    std::cout << "Stack: [";
    for (size_t i = 0; i < items.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << items[i];
    }
    std::cout << "]" << std::endl;
}