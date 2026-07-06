/**
 * Simple Stack Implementation in C++
 *
 * A minimal, cross-platform stack implementation using STL
 */

#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

class SimpleStack {
private:
    std::vector<int> items;

public:
    // Push element onto stack
    void push(int item);

    // Pop element from stack
    int pop();

    // Peek at top element
    int peek();

    // Check if stack is empty
    bool isEmpty();

    // Get stack size
    size_t size();

    // Print stack contents
    void print();
};

#endif // STACK_HPP