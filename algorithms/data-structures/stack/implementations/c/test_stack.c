/**
 * Unit tests for Simple Stack using minunit
 */

#include <stdio.h>
#include "stack.h"
#include "minunit.h"

int tests_run = 0;

// Test stack initialization
static char* test_stack_init() {
    SimpleStack stack;
    stackInit(&stack);

    mu_assert("Stack should be empty after initialization", stackIsEmpty(&stack));
    mu_assert("Stack should not be full after initialization", !stackIsFull(&stack));
    mu_assert("Stack top should be -1 after initialization", stack.top == -1);

    return 0;
}

// Test stack push and pop operations
static char* test_stack_push_pop() {
    SimpleStack stack;
    stackInit(&stack);

    // Test pushing elements
    stackPush(&stack, 10);
    mu_assert("Stack should not be empty after push", !stackIsEmpty(&stack));
    mu_assert("Top element should be 10", stackPeek(&stack) == 10);

    stackPush(&stack, 20);
    mu_assert("Top element should be 20", stackPeek(&stack) == 20);

    stackPush(&stack, 30);
    mu_assert("Top element should be 30", stackPeek(&stack) == 30);

    // Test popping elements
    mu_assert("Popped element should be 30", stackPop(&stack) == 30);
    mu_assert("Top element should be 20 after pop", stackPeek(&stack) == 20);

    mu_assert("Popped element should be 20", stackPop(&stack) == 20);
    mu_assert("Top element should be 10 after pop", stackPeek(&stack) == 10);

    mu_assert("Popped element should be 10", stackPop(&stack) == 10);
    mu_assert("Stack should be empty after popping all elements", stackIsEmpty(&stack));

    return 0;
}

// Test stack underflow
static char* test_stack_underflow() {
    SimpleStack stack;
    stackInit(&stack);

    mu_assert("Pop on empty stack should return -1", stackPop(&stack) == -1);
    mu_assert("Peek on empty stack should return -1", stackPeek(&stack) == -1);

    return 0;
}

// Test stack overflow
static char* test_stack_overflow() {
    SimpleStack stack;
    stackInit(&stack);

    // Fill the stack
    for (int i = 0; i < MAX_STACK_SIZE; i++) {
        stackPush(&stack, i);
    }

    mu_assert("Stack should be full", stackIsFull(&stack));

    // Try to push one more element (should handle overflow gracefully)
    stackPush(&stack, 999);
    mu_assert("Stack should still be full after overflow attempt", stackIsFull(&stack));
    mu_assert("Top element should remain unchanged after overflow", stackPeek(&stack) == MAX_STACK_SIZE - 1);

    return 0;
}

// Test LIFO behavior
static char* test_stack_lifo() {
    SimpleStack stack;
    stackInit(&stack);

    // Push elements in order
    for (int i = 1; i <= 5; i++) {
        stackPush(&stack, i);
    }

    // Pop elements should come out in reverse order (LIFO)
    for (int i = 5; i >= 1; i--) {
        mu_assert("Elements should pop in LIFO order", stackPop(&stack) == i);
    }

    return 0;
}

// Run all tests
static char* all_tests() {
    mu_run_test(test_stack_init);
    mu_run_test(test_stack_push_pop);
    mu_run_test(test_stack_underflow);
    mu_run_test(test_stack_overflow);
    mu_run_test(test_stack_lifo);
    return 0;
}

// Test runner
int main(void) {
    printf("Running Stack Unit Tests with Minunit\n");
    printf("====================================\n\n");

    char *result = all_tests();
    if (result != 0) {
        printf("TEST FAILED: %s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }

    printf("Tests run: %d\n", tests_run);

    return result != 0;
}