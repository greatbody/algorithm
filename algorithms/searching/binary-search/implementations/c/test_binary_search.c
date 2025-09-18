/**
 * Binary Search Test Suite using Unity Framework
 * 使用Unity框架的二分查找测试套件
 */

#include "unity.h"
#include "binary_search.h"
#include <stdlib.h>
#include <string.h>

// Test helper functions
static int int_compare(const void* a, const void* b) {
    return *(const int*)a - *(const int*)b;
}

// Test setup and teardown
void setUp(void) {
    // Called before each test
}

void tearDown(void) {
    // Called after each test
}

// Test basic binary search functionality
void test_binary_search_basic(void) {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    // Test found elements
    BinarySearchResult result = binary_search(arr, size, 7);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(3, result.index);

    result = binary_search(arr, size, 1);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(0, result.index);

    result = binary_search(arr, size, 19);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(9, result.index);

    // Test not found elements
    result = binary_search(arr, size, 6);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.index);

    result = binary_search(arr, size, 20);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.index);
}

// Test binary search edge cases
void test_binary_search_edge_cases(void) {
    // Empty array
    BinarySearchResult result = binary_search(NULL, 0, 5);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.index);

    // Single element array
    int single[] = {42};
    result = binary_search(single, 1, 42);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(0, result.index);

    result = binary_search(single, 1, 10);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.index);

    // Two element array
    int two[] = {10, 20};
    result = binary_search(two, 2, 10);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(0, result.index);

    result = binary_search(two, 2, 20);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(1, result.index);

    result = binary_search(two, 2, 15);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.index);
}

// Test recursive binary search
void test_binary_search_recursive(void) {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    // Test found elements
    BinarySearchResult result = binary_search_recursive(arr, size, 7);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(3, result.index);

    result = binary_search_recursive(arr, size, 1);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(0, result.index);

    // Test not found elements
    result = binary_search_recursive(arr, size, 6);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.index);

    // Test empty array
    result = binary_search_recursive(NULL, 0, 5);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.index);
}

// Test first occurrence search
void test_binary_search_first_occurrence(void) {
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    // Test first occurrence of 2
    BinarySearchResult result = binary_search_first_occurrence(arr, size, 2);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(1, result.index);

    // Test first occurrence of 1
    result = binary_search_first_occurrence(arr, size, 1);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(0, result.index);

    // Test element not found
    result = binary_search_first_occurrence(arr, size, 6);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.index);
}

// Test last occurrence search
void test_binary_search_last_occurrence(void) {
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    // Test last occurrence of 2
    BinarySearchResult result = binary_search_last_occurrence(arr, size, 2);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(4, result.index);

    // Test last occurrence of 5
    result = binary_search_last_occurrence(arr, size, 5);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(7, result.index);

    // Test element not found
    result = binary_search_last_occurrence(arr, size, 6);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.index);
}

// Test range search
void test_binary_search_range(void) {
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    // Test range of 2
    BinarySearchRangeResult result = binary_search_range(arr, size, 2);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(1, result.first_index);
    TEST_ASSERT_EQUAL(4, result.last_index);

    // Test range of single element
    result = binary_search_range(arr, size, 1);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(0, result.first_index);
    TEST_ASSERT_EQUAL(0, result.last_index);

    // Test element not found
    result = binary_search_range(arr, size, 6);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.first_index);
    TEST_ASSERT_EQUAL(-1, result.last_index);
}

// Test insertion point
void test_binary_search_insertion_point(void) {
    int arr[] = {1, 3, 5, 7, 9};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    // Test insertion points
    TEST_ASSERT_EQUAL(0, binary_search_insertion_point(arr, size, 0));   // Before first
    TEST_ASSERT_EQUAL(1, binary_search_insertion_point(arr, size, 2));   // Between 1 and 3
    TEST_ASSERT_EQUAL(2, binary_search_insertion_point(arr, size, 4));   // Between 3 and 5
    TEST_ASSERT_EQUAL(3, binary_search_insertion_point(arr, size, 6));   // Between 5 and 7
    TEST_ASSERT_EQUAL(4, binary_search_insertion_point(arr, size, 8));   // Between 7 and 9
    TEST_ASSERT_EQUAL(5, binary_search_insertion_point(arr, size, 10));  // After last

    // Test with existing elements (should return the position of existing element)
    TEST_ASSERT_EQUAL(0, binary_search_insertion_point(arr, size, 1));
    TEST_ASSERT_EQUAL(2, binary_search_insertion_point(arr, size, 5));

    // Test empty array
    TEST_ASSERT_EQUAL(0, binary_search_insertion_point(NULL, 0, 5));
}

// Test generic binary search
void test_binary_search_generic(void) {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    // Test with integers
    int key = 7;
    int* result = (int*)binary_search_generic(arr, size, sizeof(int), &key, int_compare);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL(7, *result);

    // Test not found
    key = 6;
    result = (int*)binary_search_generic(arr, size, sizeof(int), &key, int_compare);
    TEST_ASSERT_NULL(result);

    // Test with strings
    const char* str_arr[] = {"apple", "banana", "cherry", "date", "elderberry"};
    size_t str_size = sizeof(str_arr) / sizeof(str_arr[0]);
    const char* key_str = "cherry";

    char** str_result = (char**)binary_search_generic(str_arr, str_size, sizeof(char*),
                                                     &key_str, (int (*)(const void*, const void*))strcmp);
    TEST_ASSERT_NOT_NULL(str_result);
    TEST_ASSERT_EQUAL_STRING("cherry", *str_result);

    // Test not found
    key_str = "grape";
    str_result = (char**)binary_search_generic(str_arr, str_size, sizeof(char*),
                                              &key_str, (int (*)(const void*, const void*))strcmp);
    TEST_ASSERT_NULL(str_result);
}

// Test verbose binary search (capture output)
void test_binary_search_verbose(void) {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    // Test found element
    BinarySearchVerboseResult result = binary_search_verbose(arr, size, 7);
    TEST_ASSERT_TRUE(result.found);
    TEST_ASSERT_EQUAL(3, result.index);
    TEST_ASSERT_TRUE(result.steps > 0);

    // Test not found element
    result = binary_search_verbose(arr, size, 6);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.index);
    TEST_ASSERT_TRUE(result.steps > 0);

    // Test empty array
    result = binary_search_verbose(NULL, 0, 5);
    TEST_ASSERT_FALSE(result.found);
    TEST_ASSERT_EQUAL(-1, result.index);
    TEST_ASSERT_EQUAL(0, result.steps);
}

// Main test runner
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_binary_search_basic);
    RUN_TEST(test_binary_search_edge_cases);
    RUN_TEST(test_binary_search_recursive);
    RUN_TEST(test_binary_search_first_occurrence);
    RUN_TEST(test_binary_search_last_occurrence);
    RUN_TEST(test_binary_search_range);
    RUN_TEST(test_binary_search_insertion_point);
    RUN_TEST(test_binary_search_generic);
    RUN_TEST(test_binary_search_verbose);

    return UNITY_END();
}