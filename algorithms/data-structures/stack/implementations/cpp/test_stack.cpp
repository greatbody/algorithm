/**
 * Unit tests for Simple Stack in C++
 *
 * A minimal testing framework for C++ stack implementation
 */

#include <iostream>
#include <cassert>
#include "stack.hpp"

// Simple test framework macros
#define TEST_START(test_name) std::cout << "Running " << test_name << "... "; 
#define TEST_PASS() std::cout << "PASS" << std::endl; tests_passed++
#define TEST_FAIL(reason) std::cout << "FAIL: " << reason << std::endl; tests_failed++; return false

int tests_passed = 0;
int tests_failed = 0;

// Test stack initialization
bool test_stack_init() {
    TEST_START("test_stack_init");
    
    SimpleStack stack;
    
    if (!stack.isEmpty()) {
        TEST_FAIL("Stack should be empty after initialization");
    }
    
    if (stack.size() != 0) {
        TEST_FAIL("Stack size should be 0 after initialization");
    }
    
    TEST_PASS();
    return true;
}

// Test stack push and pop operations
bool test_stack_push_pop() {
    TEST_START("test_stack_push_pop");
    
    SimpleStack stack;
    
    // Test pushing elements
    stack.push(10);
    if (stack.isEmpty()) {
        TEST_FAIL("Stack should not be empty after push");
    }
    
    if (stack.peek() != 10) {
        TEST_FAIL("Top element should be 10");
    }
    
    stack.push(20);
    if (stack.peek() != 20) {
        TEST_FAIL("Top element should be 20");
    }
    
    stack.push(30);
    if (stack.peek() != 30) {
        TEST_FAIL("Top element should be 30");
    }
    
    // Test popping elements
    if (stack.pop() != 30) {
        TEST_FAIL("Popped element should be 30");
    }
    
    if (stack.peek() != 20) {
        TEST_FAIL("Top element should be 20 after pop");
    }
    
    if (stack.pop() != 20) {
        TEST_FAIL("Popped element should be 20");
    }
    
    if (stack.peek() != 10) {
        TEST_FAIL("Top element should be 10 after pop");
    }
    
    if (stack.pop() != 10) {
        TEST_FAIL("Popped element should be 10");
    }
    
    if (!stack.isEmpty()) {
        TEST_FAIL("Stack should be empty after popping all elements");
    }
    
    TEST_PASS();
    return true;
}

// Test stack underflow
bool test_stack_underflow() {
    TEST_START("test_stack_underflow");
    
    SimpleStack stack;
    
    if (stack.pop() != -1) {
        TEST_FAIL("Pop on empty stack should return -1");
    }
    
    if (stack.peek() != -1) {
        TEST_FAIL("Peek on empty stack should return -1");
    }
    
    TEST_PASS();
    return true;
}

// Test stack behavior with many elements
bool test_stack_large_operations() {
    TEST_START("test_stack_large_operations");
    
    SimpleStack stack;
    
    // Push many elements
    for (int i = 0; i < 1000; i++) {
        stack.push(i);
    }
    
    if (stack.size() != 1000) {
        TEST_FAIL("Stack size should be 1000 after pushing 1000 elements");
    }
    
    if (stack.peek() != 999) {
        TEST_FAIL("Top element should be 999");
    }
    
    // Pop all elements in reverse order (LIFO)
    for (int i = 999; i >= 0; i--) {
        if (stack.pop() != i) {
            TEST_FAIL("Elements should pop in LIFO order");
        }
    }
    
    if (!stack.isEmpty()) {
        TEST_FAIL("Stack should be empty after popping all elements");
    }
    
    TEST_PASS();
    return true;
}

// Test LIFO behavior
bool test_stack_lifo() {
    TEST_START("test_stack_lifo");
    
    SimpleStack stack;
    
    // Push elements in order
    for (int i = 1; i <= 5; i++) {
        stack.push(i);
    }
    
    // Pop elements should come out in reverse order (LIFO)
    for (int i = 5; i >= 1; i--) {
        if (stack.pop() != i) {
            TEST_FAIL("Elements should pop in LIFO order");
        }
    }
    
    TEST_PASS();
    return true;
}

// Run all tests
void run_all_tests() {
    std::cout << "Running Stack Unit Tests for C++ Implementation" << std::endl;
    std::cout << "==============================================" << std::endl << std::endl;
    
    test_stack_init();
    test_stack_push_pop();
    test_stack_underflow();
    test_stack_large_operations();
    test_stack_lifo();
    
    std::cout << std::endl;
    std::cout << "Test Summary:" << std::endl;
    std::cout << "=============" << std::endl;
    std::cout << "Tests passed: " << tests_passed << std::endl;
    std::cout << "Tests failed: " << tests_failed << std::endl;
    std::cout << "Total tests: " << (tests_passed + tests_failed) << std::endl;
    
    if (tests_failed == 0) {
        std::cout << std::endl << "ALL TESTS PASSED!" << std::endl;
    } else {
        std::cout << std::endl << "SOME TESTS FAILED!" << std::endl;
    }
}

// Main function
int main() {
    run_all_tests();
    return tests_failed > 0 ? 1 : 0;
}