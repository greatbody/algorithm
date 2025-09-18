/**
 * Binary Search Demo Program in C
 * C语言二分查找演示程序
 *
 * This program demonstrates the usage of the Binary Search implementation
 * 本程序演示二分查找实现的使用方法
 */

#include "binary_search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Demo function for basic binary search operations
void demo_basic_operations(void) {
    printf("=== Basic Binary Search Operations ===\n");

    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Array: [");
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n\n");

    // Test cases
    int test_values[] = {7, 1, 19, 6, 20};
    size_t num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (size_t i = 0; i < num_tests; i++) {
        int target = test_values[i];
        BinarySearchResult result = binary_search(arr, size, target);

        printf("Searching for %d: ", target);
        if (result.found) {
            printf("Found at index %d\n", result.index);
        } else {
            printf("Not found\n");
        }
    }

    printf("\n");
}

// Demo function for recursive binary search
void demo_recursive_search(void) {
    printf("=== Recursive Binary Search ===\n");

    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    int target = 7;
    BinarySearchResult result = binary_search_recursive(arr, size, target);

    printf("Recursive search for %d: ", target);
    if (result.found) {
        printf("Found at index %d\n", result.index);
    } else {
        printf("Not found\n");
    }

    printf("\n");
}

// Demo function for verbose binary search
void demo_verbose_search(void) {
    printf("=== Verbose Binary Search (with step-by-step output) ===\n");

    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    int target = 7;
    BinarySearchVerboseResult result = binary_search_verbose(arr, size, target);

    printf("\nResult: ");
    if (result.found) {
        printf("Found at index %d in %d steps\n", result.index, result.steps);
    } else {
        printf("Not found after %d steps\n", result.steps);
    }

    printf("\n");
}

// Demo function for duplicate handling
void demo_duplicate_handling(void) {
    printf("=== Duplicate Element Handling ===\n");

    int arr[] = {1, 2, 2, 2, 2, 3, 4, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Array with duplicates: [");
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");

    int target = 2;

    // First occurrence
    BinarySearchResult first = binary_search_first_occurrence(arr, size, target);
    printf("First occurrence of %d: ", target);
    if (first.found) {
        printf("index %d\n", first.index);
    } else {
        printf("not found\n");
    }

    // Last occurrence
    BinarySearchResult last = binary_search_last_occurrence(arr, size, target);
    printf("Last occurrence of %d: ", target);
    if (last.found) {
        printf("index %d\n", last.index);
    } else {
        printf("not found\n");
    }

    // Range
    BinarySearchRangeResult range = binary_search_range(arr, size, target);
    printf("Range of %d: ", target);
    if (range.found) {
        printf("[%d, %d]\n", range.first_index, range.last_index);
    } else {
        printf("not found\n");
    }

    printf("\n");
}

// Demo function for insertion point
void demo_insertion_point(void) {
    printf("=== Insertion Point Search ===\n");

    int arr[] = {1, 3, 5, 7, 9};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Sorted array: [");
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");

    int targets[] = {0, 2, 4, 6, 8, 10};
    size_t num_targets = sizeof(targets) / sizeof(targets[0]);

    for (size_t i = 0; i < num_targets; i++) {
        int target = targets[i];
        size_t pos = binary_search_insertion_point(arr, size, target);
        printf("Insert %d at position %zu to maintain sorted order\n", target, pos);
    }

    printf("\n");
}

// Demo function for generic binary search
void demo_generic_search(void) {
    printf("=== Generic Binary Search (with strings) ===\n");

    const char* arr[] = {"apple", "banana", "cherry", "date", "elderberry"};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("String array: [");
    for (size_t i = 0; i < size; i++) {
        printf("\"%s\"", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");

    const char* targets[] = {"cherry", "grape", "banana"};
    size_t num_targets = sizeof(targets) / sizeof(targets[0]);

    for (size_t i = 0; i < num_targets; i++) {
        const char* target = targets[i];
        char** result = (char**)binary_search_generic(arr, size, sizeof(char*),
                                                     &target, (int (*)(const void*, const void*))strcmp);

        printf("Searching for \"%s\": ", target);
        if (result != NULL) {
            printf("Found \"%s\"\n", *result);
        } else {
            printf("Not found\n");
        }
    }

    printf("\n");
}

// Demo function for edge cases
void demo_edge_cases(void) {
    printf("=== Edge Cases ===\n");

    // Empty array
    BinarySearchResult result = binary_search(NULL, 0, 5);
    printf("Empty array search: %s\n", result.found ? "found" : "not found");

    // Single element
    int single[] = {42};
    result = binary_search(single, 1, 42);
    printf("Single element [42], search 42: %s at index %d\n",
           result.found ? "found" : "not found", result.index);

    result = binary_search(single, 1, 10);
    printf("Single element [42], search 10: %s\n",
           result.found ? "found" : "not found");

    // Two elements
    int two[] = {10, 20};
    result = binary_search(two, 2, 15);
    printf("Two elements [10,20], search 15: %s\n",
           result.found ? "found" : "not found");

    printf("\n");
}

int main(void) {
    printf("Binary Search Implementation Demo in C\n");
    printf("=======================================\n\n");

    demo_basic_operations();
    demo_recursive_search();
    demo_verbose_search();
    demo_duplicate_handling();
    demo_insertion_point();
    demo_generic_search();
    demo_edge_cases();

    printf("Demo completed successfully!\n");
    return 0;
}