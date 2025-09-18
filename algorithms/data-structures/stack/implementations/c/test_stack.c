/**
 * Stack Test Suite using Unity Framework
 * 使用Unity框架的栈测试套件
 */

#include "unity.h"
#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Test helper functions
static int int_compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

static void* int_copy(int value) {
    int* ptr = (int*)malloc(sizeof(int));
    if (ptr) *ptr = value;
    return ptr;
}

// Test setup and teardown
void setUp(void) {
    // Called before each test
}

void tearDown(void) {
    // Called after each test
}

// Test basic stack initialization
void test_stack_init(void) {
    Stack stack;

    // Test initialization with unlimited capacity
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_init(&stack, 0));
    TEST_ASSERT_TRUE(stack_is_empty(&stack));
    TEST_ASSERT_EQUAL(0, stack_size(&stack));
    TEST_ASSERT_EQUAL(0, stack_capacity(&stack));

    stack_destroy(&stack);

    // Test initialization with fixed capacity
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_init(&stack, 10));
    TEST_ASSERT_TRUE(stack_is_empty(&stack));
    TEST_ASSERT_EQUAL(0, stack_size(&stack));
    TEST_ASSERT_EQUAL(10, stack_capacity(&stack));

    stack_destroy(&stack);
}

// Test stack push operations
void test_stack_push(void) {
    Stack stack;
    stack_init(&stack, 0);

    // Test pushing integers
    int* val1 = int_copy(10);
    int* val2 = int_copy(20);
    int* val3 = int_copy(30);

    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_push(&stack, val1));
    TEST_ASSERT_EQUAL(1, stack_size(&stack));
    TEST_ASSERT_FALSE(stack_is_empty(&stack));

    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_push(&stack, val2));
    TEST_ASSERT_EQUAL(2, stack_size(&stack));

    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_push(&stack, val3));
    TEST_ASSERT_EQUAL(3, stack_size(&stack));

    // Cleanup
    stack_destroy(&stack);
    free(val1);
    free(val2);
    free(val3);
}

// Test stack pop operations
void test_stack_pop(void) {
    Stack stack;
    stack_init(&stack, 0);

    int* val1 = int_copy(10);
    int* val2 = int_copy(20);
    int* val3 = int_copy(30);

    // Push elements
    stack_push(&stack, val1);
    stack_push(&stack, val2);
    stack_push(&stack, val3);

    // Test pop operations (LIFO)
    void* popped;
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_pop(&stack, &popped));
    TEST_ASSERT_EQUAL(30, *(int*)popped);
    TEST_ASSERT_EQUAL(2, stack_size(&stack));

    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_pop(&stack, &popped));
    TEST_ASSERT_EQUAL(20, *(int*)popped);
    TEST_ASSERT_EQUAL(1, stack_size(&stack));

    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_pop(&stack, &popped));
    TEST_ASSERT_EQUAL(10, *(int*)popped);
    TEST_ASSERT_EQUAL(0, stack_size(&stack));
    TEST_ASSERT_TRUE(stack_is_empty(&stack));

    // Test pop from empty stack
    TEST_ASSERT_EQUAL(STACK_ERROR_UNDERFLOW, stack_pop(&stack, &popped));

    stack_destroy(&stack);
    free(val1);
    free(val2);
    free(val3);
}

// Test stack peek operations
void test_stack_peek(void) {
    Stack stack;
    stack_init(&stack, 0);

    int* val1 = int_copy(10);
    int* val2 = int_copy(20);

    // Push elements
    stack_push(&stack, val1);
    stack_push(&stack, val2);

    // Test peek (should not remove elements)
    void* peeked;
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_peek(&stack, &peeked));
    TEST_ASSERT_EQUAL(20, *(int*)peeked);
    TEST_ASSERT_EQUAL(2, stack_size(&stack));  // Size should remain the same

    // Test peek after pop
    void* popped;
    stack_pop(&stack, &popped);
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_peek(&stack, &peeked));
    TEST_ASSERT_EQUAL(10, *(int*)peeked);

    // Test peek on empty stack
    stack_pop(&stack, &popped);
    TEST_ASSERT_EQUAL(STACK_ERROR_UNDERFLOW, stack_peek(&stack, &peeked));

    stack_destroy(&stack);
    free(val1);
    free(val2);
}

// Test stack capacity limits
void test_stack_capacity(void) {
    Stack stack;
    stack_init(&stack, 3);  // Limited capacity

    int* val1 = int_copy(10);
    int* val2 = int_copy(20);
    int* val3 = int_copy(30);
    int* val4 = int_copy(40);

    // Fill to capacity
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_push(&stack, val1));
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_push(&stack, val2));
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_push(&stack, val3));
    TEST_ASSERT_EQUAL(3, stack_size(&stack));

    // Try to exceed capacity
    TEST_ASSERT_EQUAL(STACK_ERROR_OVERFLOW, stack_push(&stack, val4));

    stack_destroy(&stack);
    free(val1);
    free(val2);
    free(val3);
    free(val4);
}

// Test stack clear operation
void test_stack_clear(void) {
    Stack stack;
    stack_init(&stack, 0);

    int* val1 = int_copy(10);
    int* val2 = int_copy(20);

    stack_push(&stack, val1);
    stack_push(&stack, val2);
    TEST_ASSERT_EQUAL(2, stack_size(&stack));

    // Clear the stack
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_clear(&stack));
    TEST_ASSERT_TRUE(stack_is_empty(&stack));
    TEST_ASSERT_EQUAL(0, stack_size(&stack));

    stack_destroy(&stack);
    free(val1);
    free(val2);
}

// Test stack to array conversion
void test_stack_to_array(void) {
    Stack stack;
    stack_init(&stack, 0);

    int* val1 = int_copy(10);
    int* val2 = int_copy(20);
    int* val3 = int_copy(30);

    stack_push(&stack, val1);
    stack_push(&stack, val2);
    stack_push(&stack, val3);

    // Convert to array
    void* array[3];
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_to_array(&stack, array, 3));

    // Verify array contents (bottom to top)
    TEST_ASSERT_EQUAL(10, *(int*)array[0]);
    TEST_ASSERT_EQUAL(20, *(int*)array[1]);
    TEST_ASSERT_EQUAL(30, *(int*)array[2]);

    // Test with insufficient array size
    void* small_array[2];
    TEST_ASSERT_EQUAL(STACK_ERROR_INVALID_ARGUMENT, stack_to_array(&stack, small_array, 2));

    stack_destroy(&stack);
    free(val1);
    free(val2);
    free(val3);
}

// Test error conditions
void test_stack_error_conditions(void) {
    Stack stack;
    void* dummy;

    // Test NULL stack operations
    TEST_ASSERT_EQUAL(STACK_ERROR_NULL_POINTER, stack_init(NULL, 0));
    TEST_ASSERT_EQUAL(STACK_ERROR_NULL_POINTER, stack_destroy(NULL));
    TEST_ASSERT_EQUAL(STACK_ERROR_NULL_POINTER, stack_push(NULL, &dummy));
    TEST_ASSERT_EQUAL(STACK_ERROR_NULL_POINTER, stack_pop(NULL, &dummy));
    TEST_ASSERT_EQUAL(STACK_ERROR_NULL_POINTER, stack_peek(NULL, &dummy));
    TEST_ASSERT_EQUAL(STACK_ERROR_NULL_POINTER, stack_clear(NULL));

    // Test with valid stack but NULL parameters
    stack_init(&stack, 0);
    TEST_ASSERT_EQUAL(STACK_ERROR_NULL_POINTER, stack_pop(&stack, NULL));
    TEST_ASSERT_EQUAL(STACK_ERROR_NULL_POINTER, stack_peek(&stack, NULL));
    TEST_ASSERT_EQUAL(STACK_ERROR_NULL_POINTER, stack_to_array(&stack, NULL, 0));

    stack_destroy(&stack);
}

// Test stack with string data
void test_stack_with_strings(void) {
    Stack stack;
    stack_init(&stack, 0);

    char* str1 = strdup("Hello");
    char* str2 = strdup("World");
    char* str3 = strdup("C Programming");

    // Push strings
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_push(&stack, str1));
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_push(&stack, str2));
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_push(&stack, str3));

    // Pop and verify
    void* popped;
    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_pop(&stack, &popped));
    TEST_ASSERT_EQUAL_STRING("C Programming", (char*)popped);

    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_pop(&stack, &popped));
    TEST_ASSERT_EQUAL_STRING("World", (char*)popped);

    TEST_ASSERT_EQUAL(STACK_SUCCESS, stack_pop(&stack, &popped));
    TEST_ASSERT_EQUAL_STRING("Hello", (char*)popped);

    stack_destroy(&stack);
    free(str1);
    free(str2);
    free(str3);
}

// Main test runner
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_stack_init);
    RUN_TEST(test_stack_push);
    RUN_TEST(test_stack_pop);
    RUN_TEST(test_stack_peek);
    RUN_TEST(test_stack_capacity);
    RUN_TEST(test_stack_clear);
    RUN_TEST(test_stack_to_array);
    RUN_TEST(test_stack_error_conditions);
    RUN_TEST(test_stack_with_strings);

    return UNITY_END();
}