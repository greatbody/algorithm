/**
 * Binary Search Implementation in C - Source File
 * C语言二分查找实现 - 源文件
 */

#include "binary_search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Performs binary search on a sorted integer array (iterative approach)
 * 在已排序的整数数组上执行二分查找（迭代方法）
 */
BinarySearchResult binary_search(const int* arr, size_t size, int target) {
    BinarySearchResult result = {-1, false};

    if (arr == NULL || size == 0) {
        return result;
    }

    size_t left = 0;
    size_t right = size - 1;

    while (left <= right) {
        // Use left + (right - left) / 2 to avoid potential overflow
        size_t mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result.index = (int)mid;
            result.found = true;
            return result;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            if (mid == 0) break;  // Prevent underflow
            right = mid - 1;
        }
    }

    return result;
}

/**
 * Helper function for recursive binary search
 * 递归二分查找的辅助函数
 */
static BinarySearchResult binary_search_recursive_helper(const int* arr, size_t left, size_t right, int target) {
    BinarySearchResult result = {-1, false};

    if (left > right) {
        return result;
    }

    size_t mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        result.index = (int)mid;
        result.found = true;
        return result;
    } else if (arr[mid] < target) {
        return binary_search_recursive_helper(arr, mid + 1, right, target);
    } else {
        if (mid == 0) return result;  // Prevent underflow
        return binary_search_recursive_helper(arr, left, mid - 1, target);
    }
}

/**
 * Performs binary search on a sorted integer array (recursive approach)
 * 在已排序的整数数组上执行二分查找（递归方法）
 */
BinarySearchResult binary_search_recursive(const int* arr, size_t size, int target) {
    BinarySearchResult result = {-1, false};

    if (arr == NULL || size == 0) {
        return result;
    }

    return binary_search_recursive_helper(arr, 0, size - 1, target);
}

/**
 * Performs binary search with step-by-step verbose output
 * 执行带详细步骤输出的二分查找
 */
BinarySearchVerboseResult binary_search_verbose(const int* arr, size_t size, int target) {
    BinarySearchVerboseResult result = {-1, 0, false};

    if (arr == NULL || size == 0) {
        printf("Empty array provided\n");
        return result;
    }

    size_t left = 0;
    size_t right = size - 1;

    printf("Searching for %d in array of size %zu\n", target, size);
    printf("Array: [");
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");

    while (left <= right) {
        result.steps++;
        size_t mid = left + (right - left) / 2;

        printf("\nStep %d:\n", result.steps);
        printf("  left=%zu, right=%zu, mid=%zu\n", left, right, mid);
        printf("  arr[%zu] = %d\n", mid, arr[mid]);

        if (arr[mid] == target) {
            printf("  Target found at index %zu!\n", mid);
            result.index = (int)mid;
            result.found = true;
            return result;
        } else if (arr[mid] < target) {
            printf("  %d < %d, search right half\n", arr[mid], target);
            left = mid + 1;
        } else {
            printf("  %d > %d, search left half\n", arr[mid], target);
            if (mid == 0) break;  // Prevent underflow
            right = mid - 1;
        }
    }

    printf("\nTarget %d not found in array after %d steps\n", target, result.steps);
    return result;
}

/**
 * Find the first occurrence of target in a sorted array with duplicates
 * 在包含重复元素的已排序数组中查找目标值的第一次出现
 */
BinarySearchResult binary_search_first_occurrence(const int* arr, size_t size, int target) {
    BinarySearchResult result = {-1, false};

    if (arr == NULL || size == 0) {
        return result;
    }

    size_t left = 0;
    size_t right = size - 1;
    int first_index = -1;

    while (left <= right) {
        size_t mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            first_index = (int)mid;
            result.found = true;
            // Continue searching in left half for first occurrence
            if (mid == 0) break;  // Prevent underflow
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            if (mid == 0) break;  // Prevent underflow
            right = mid - 1;
        }
    }

    result.index = first_index;
    return result;
}

/**
 * Find the last occurrence of target in a sorted array with duplicates
 * 在包含重复元素的已排序数组中查找目标值的最后一次出现
 */
BinarySearchResult binary_search_last_occurrence(const int* arr, size_t size, int target) {
    BinarySearchResult result = {-1, false};

    if (arr == NULL || size == 0) {
        return result;
    }

    size_t left = 0;
    size_t right = size - 1;
    int last_index = -1;

    while (left <= right) {
        size_t mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            last_index = (int)mid;
            result.found = true;
            // Continue searching in right half for last occurrence
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            if (mid == 0) break;  // Prevent underflow
            right = mid - 1;
        }
    }

    result.index = last_index;
    return result;
}

/**
 * Find the range [first_index, last_index] of target in sorted array
 * 在已排序数组中查找目标值的所有出现位置范围
 */
BinarySearchRangeResult binary_search_range(const int* arr, size_t size, int target) {
    BinarySearchRangeResult result = {-1, -1, false};

    BinarySearchResult first = binary_search_first_occurrence(arr, size, target);
    if (!first.found) {
        return result;
    }

    BinarySearchResult last = binary_search_last_occurrence(arr, size, target);

    result.first_index = first.index;
    result.last_index = last.index;
    result.found = true;

    return result;
}

/**
 * Find the insertion point for target to maintain sorted order
 * 查找目标值的插入位置以保持数组排序
 */
size_t binary_search_insertion_point(const int* arr, size_t size, int target) {
    if (arr == NULL) {
        return 0;
    }

    size_t left = 0;
    size_t right = size;

    while (left < right) {
        size_t mid = left + (right - left) / 2;

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

/**
 * Generic binary search function with custom comparison
 * 通用二分查找函数，支持自定义比较函数
 */
void* binary_search_generic(const void* base, size_t nmemb, size_t size,
                           const void* key, int (*compar)(const void*, const void*)) {
    if (base == NULL || nmemb == 0 || size == 0 || key == NULL || compar == NULL) {
        return NULL;
    }

    size_t left = 0;
    size_t right = nmemb - 1;

    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        void* mid_elem = (char*)base + mid * size;

        int cmp_result = compar(key, mid_elem);

        if (cmp_result == 0) {
            return mid_elem;
        } else if (cmp_result > 0) {
            left = mid + 1;
        } else {
            if (mid == 0) break;  // Prevent underflow
            right = mid - 1;
        }
    }

    return NULL;
}