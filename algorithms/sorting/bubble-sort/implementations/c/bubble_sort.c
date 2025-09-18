/**
 * Bubble Sort Implementation in C
 * 冒泡排序的C语言实现
 */

#include "bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Swap two integers
 * 交换两个整数
 */
static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Sort an integer array using bubble sort algorithm
 * 使用冒泡排序算法对整数数组进行排序
 */
bool bubble_sort(int* arr, size_t length) {
    if (arr == NULL || length == 0) {
        return true;  // Empty array is considered sorted
    }

    // Traverse through all array elements
    for (size_t i = 0; i < length; i++) {
        // Flag to optimize by detecting if array is already sorted
        bool swapped = false;

        // Last i elements are already in place
        for (size_t j = 0; j < length - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no swapping happened, array is sorted
        if (!swapped) {
            break;
        }
    }

    return true;
}

/**
 * Sort an integer array in descending order using bubble sort
 * 使用冒泡排序算法对整数数组进行降序排序
 */
bool bubble_sort_descending(int* arr, size_t length) {
    if (arr == NULL || length == 0) {
        return true;  // Empty array is considered sorted
    }

    for (size_t i = 0; i < length; i++) {
        bool swapped = false;

        for (size_t j = 0; j < length - i - 1; j++) {
            // Change comparison for descending order
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    return true;
}

/**
 * Sort an integer array with detailed result information
 * 对整数数组进行排序并返回详细信息
 */
bool bubble_sort_with_result(int* arr, size_t length, BubbleSortResult* result) {
    if (arr == NULL || result == NULL) {
        return false;
    }

    result->array = arr;
    result->length = length;
    result->comparisons = 0;
    result->swaps = 0;

    if (length == 0) {
        return true;  // Empty array is considered sorted
    }

    for (size_t i = 0; i < length; i++) {
        bool swapped = false;

        for (size_t j = 0; j < length - i - 1; j++) {
            result->comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                result->swaps++;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    return true;
}

/**
 * Generic bubble sort for any data type with custom comparison
 * 通用冒泡排序，支持自定义比较函数
 */
bool bubble_sort_generic(void* base, size_t num_elements, size_t element_size,
                        int (*compare)(const void*, const void*)) {
    if (base == NULL || num_elements == 0 || element_size == 0 || compare == NULL) {
        return true;  // Empty array is considered sorted
    }

    char* arr = (char*)base;

    for (size_t i = 0; i < num_elements; i++) {
        bool swapped = false;

        for (size_t j = 0; j < num_elements - i - 1; j++) {
            char* elem1 = arr + j * element_size;
            char* elem2 = arr + (j + 1) * element_size;

            if (compare(elem1, elem2) > 0) {
                // Swap elements
                for (size_t k = 0; k < element_size; k++) {
                    char temp = elem1[k];
                    elem1[k] = elem2[k];
                    elem2[k] = temp;
                }
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    return true;
}

/**
 * Check if an array is sorted in ascending order
 * 检查数组是否按升序排序
 */
bool is_sorted_ascending(const int* arr, size_t length) {
    if (arr == NULL || length <= 1) {
        return true;
    }

    for (size_t i = 0; i < length - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }

    return true;
}

/**
 * Check if an array is sorted in descending order
 * 检查数组是否按降序排序
 */
bool is_sorted_descending(const int* arr, size_t length) {
    if (arr == NULL || length <= 1) {
        return true;
    }

    for (size_t i = 0; i < length - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return false;
        }
    }

    return true;
}

/**
 * Create a copy of an integer array
 * 创建整数数组的副本
 */
int* array_copy(const int* source, size_t length) {
    if (source == NULL || length == 0) {
        return NULL;
    }

    int* copy = (int*)malloc(length * sizeof(int));
    if (copy == NULL) {
        return NULL;
    }

    memcpy(copy, source, length * sizeof(int));
    return copy;
}

/**
 * Print an integer array
 * 打印整数数组
 */
void print_array(const int* arr, size_t length) {
    if (arr == NULL) {
        printf("NULL");
        return;
    }

    printf("[");
    for (size_t i = 0; i < length; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", arr[i]);
    }
    printf("]");
}