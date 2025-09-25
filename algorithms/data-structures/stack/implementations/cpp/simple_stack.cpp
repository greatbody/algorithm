/**
 * Simple Stack Implementation in C++
 *
 * A minimal, cross-platform stack implementation using STL
 */

#include <iostream>
#include <vector>
#include <string>

class SimpleStack {
private:
    std::vector<int> items;

public:
    // Push element onto stack
    void push(int item) {
        items.push_back(item);
    }

    // Pop element from stack
    int pop() {
        if (items.empty()) {
            std::cout << "Stack underflow!" << std::endl;
            return -1;
        }
        int top = items.back();
        items.pop_back();
        return top;
    }

    // Peek at top element
    int peek() {
        if (items.empty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return items.back();
    }

    // Check if stack is empty
    bool isEmpty() {
        return items.empty();
    }

    // Get stack size
    size_t size() {
        return items.size();
    }

    // Print stack contents
    void print() {
        std::cout << "Stack: [";
        for (size_t i = 0; i < items.size(); ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << items[i];
        }
        std::cout << "]" << std::endl;
    }
};

// Simple test function
void testStack() {
    std::cout << "Testing Simple Stack" << std::endl;
    std::cout << "===================" << std::endl;

    SimpleStack stack;

    std::cout << "Pushing elements: 10, 20, 30" << std::endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.print();
    std::cout << "Top element: " << stack.peek() << std::endl;

    std::cout << "Popping elements:" << std::endl;
    while (!stack.isEmpty()) {
        std::cout << "Popped: " << stack.pop() << std::endl;
    }

    std::cout << std::endl;
}

// Main function
int main() {
    std::cout << "Simple Stack Implementation" << std::endl;
    std::cout << "==========================" << std::endl << std::endl;

    testStack();

    std::cout << "Test completed!" << std::endl;
    return 0;
}