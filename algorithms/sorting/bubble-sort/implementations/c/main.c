/**
 * Bubble Sort Demo Program
 * 冒泡排序演示程序
 */

#include "bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("=== Bubble Sort Demo ===\n\n");

    // Test arrays
    int test_arrays[][10] = {
        {64, 34, 25, 12, 22, 11, 90},  // 7 elements
        {5, 2, 8, 1, 9},               // 5 elements
        {1, 2, 3, 4, 5},               // Already sorted
        {5, 4, 3, 2, 1},               // Reverse sorted
        {42},                          // Single element
        {3, 3, 3, 3}                   // All same elements
    };

    int array_lengths[] = {7, 5, 5, 5, 1, 4};
    int num_tests = sizeof(array_lengths) / sizeof(array_lengths[0]);

    // Test basic bubble sort
    printf("=== Basic Bubble Sort ===\n");
    for (int i = 0; i < num_tests; i++) {
        // Create a copy of the test array
        int* arr = array_copy(test_arrays[i], array_lengths[i]);
        if (arr == NULL) {
            printf("Error: Failed to allocate memory\n");
            continue;
        }

        printf("Test %d - Original: ", i + 1);
        print_array(arr, array_lengths[i]);
        printf("\n");

        if (bubble_sort(arr, array_lengths[i])) {
            printf("         Sorted:   ");
            print_array(arr, array_lengths[i]);
            printf("\n");
        } else {
            printf("         Error: Failed to sort\n");
        }

        free(arr);
        printf("\n");
    }

    // Test descending sort
    printf("=== Descending Bubble Sort ===\n");
    int arr_desc[] = {64, 34, 25, 12, 22, 11, 90};
    size_t len_desc = sizeof(arr_desc) / sizeof(arr_desc[0]);

    printf("Original: ");
    print_array(arr_desc, len_desc);
    printf("\n");

    if (bubble_sort_descending(arr_desc, len_desc)) {
        printf("Descending: ");
        print_array(arr_desc, len_desc);
        printf("\n");
    } else {
        printf("Error: Failed to sort in descending order\n");
    }

    printf("\n");

    // Test with result tracking
    printf("=== Bubble Sort with Result Tracking ===\n");
    int arr_result[] = {64, 34, 25, 12, 22, 11, 90};
    size_t len_result = sizeof(arr_result) / sizeof(arr_result[0]);
    BubbleSortResult result;

    printf("Original: ");
    print_array(arr_result, len_result);
    printf("\n");

    if (bubble_sort_with_result(arr_result, len_result, &result)) {
        printf("Sorted:   ");
        print_array(arr_result, len_result);
        printf("\n");
        printf("Comparisons: %zu\n", result.comparisons);
        printf("Swaps:       %zu\n", result.swaps);
    } else {
        printf("Error: Failed to sort with result tracking\n");
    }

    printf("\n");

    // Test utility functions
    printf("=== Utility Functions ===\n");

    int sorted_arr[] = {1, 2, 3, 4, 5};
    int unsorted_arr[] = {1, 3, 2, 4, 5};

    printf("Sorted array:   ");
    print_array(sorted_arr, 5);
    printf(" - Is sorted: %s\n", is_sorted_ascending(sorted_arr, 5) ? "Yes" : "No");

    printf("Unsorted array: ");
    print_array(unsorted_arr, 5);
    printf(" - Is sorted: %s\n", is_sorted_ascending(unsorted_arr, 5) ? "Yes" : "No");

    printf("\nDemo completed successfully!\n");
    return 0;
}