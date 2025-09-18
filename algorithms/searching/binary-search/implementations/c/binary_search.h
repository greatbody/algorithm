/**
 * Binary Search Implementation in C
 * C语言二分查找实现
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1) for iterative, O(log n) for recursive
 */

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Binary search result structure
 * 二分查找结果结构体
 */
typedef struct {
    int index;      // Index of found element, -1 if not found
    bool found;     // Whether the element was found
} BinarySearchResult;

/**
 * Binary search range result structure
 * 二分查找范围结果结构体
 */
typedef struct {
    int first_index;    // Index of first occurrence, -1 if not found
    int last_index;     // Index of last occurrence, -1 if not found
    bool found;         // Whether the element was found
} BinarySearchRangeResult;

/**
 * Binary search with verbose output result
 * 带详细输出的二分查找结果
 */
typedef struct {
    int index;      // Index of found element, -1 if not found
    int steps;      // Number of steps taken
    bool found;     // Whether the element was found
} BinarySearchVerboseResult;

/**
 * Performs binary search on a sorted integer array (iterative approach)
 * 在已排序的整数数组上执行二分查找（迭代方法）
 *
 * @param arr Pointer to sorted integer array
 * @param size Size of the array
 * @param target Target value to search for
 * @return BinarySearchResult containing index and found status
 */
BinarySearchResult binary_search(const int* arr, size_t size, int target);

/**
 * Performs binary search on a sorted integer array (recursive approach)
 * 在已排序的整数数组上执行二分查找（递归方法）
 *
 * @param arr Pointer to sorted integer array
 * @param size Size of the array
 * @param target Target value to search for
 * @return BinarySearchResult containing index and found status
 */
BinarySearchResult binary_search_recursive(const int* arr, size_t size, int target);

/**
 * Performs binary search with step-by-step verbose output
 * 执行带详细步骤输出的二分查找
 *
 * @param arr Pointer to sorted integer array
 * @param size Size of the array
 * @param target Target value to search for
 * @return BinarySearchVerboseResult containing index, steps, and found status
 */
BinarySearchVerboseResult binary_search_verbose(const int* arr, size_t size, int target);

/**
 * Find the first occurrence of target in a sorted array with duplicates
 * 在包含重复元素的已排序数组中查找目标值的第一次出现
 *
 * @param arr Pointer to sorted integer array
 * @param size Size of the array
 * @param target Target value to search for
 * @return BinarySearchResult containing index of first occurrence
 */
BinarySearchResult binary_search_first_occurrence(const int* arr, size_t size, int target);

/**
 * Find the last occurrence of target in a sorted array with duplicates
 * 在包含重复元素的已排序数组中查找目标值的最后一次出现
 *
 * @param arr Pointer to sorted integer array
 * @param size Size of the array
 * @param target Target value to search for
 * @return BinarySearchResult containing index of last occurrence
 */
BinarySearchResult binary_search_last_occurrence(const int* arr, size_t size, int target);

/**
 * Find the range [first_index, last_index] of target in sorted array
 * 在已排序数组中查找目标值的所有出现位置范围
 *
 * @param arr Pointer to sorted integer array
 * @param size Size of the array
 * @param target Target value to search for
 * @return BinarySearchRangeResult containing first and last indices
 */
BinarySearchRangeResult binary_search_range(const int* arr, size_t size, int target);

/**
 * Find the insertion point for target to maintain sorted order
 * 查找目标值的插入位置以保持数组排序
 *
 * @param arr Pointer to sorted integer array
 * @param size Size of the array
 * @param target Target value to find insertion point for
 * @return Index where target should be inserted
 */
size_t binary_search_insertion_point(const int* arr, size_t size, int target);

/**
 * Generic binary search function with custom comparison
 * 通用二分查找函数，支持自定义比较函数
 *
 * @param base Pointer to the first element of the array
 * @param nmemb Number of elements in the array
 * @param size Size of each element
 * @param key Pointer to the key to search for
 * @param compar Comparison function (like strcmp, should return <0, 0, >0)
 * @return Pointer to found element, or NULL if not found
 */
void* binary_search_generic(const void* base, size_t nmemb, size_t size,
                           const void* key, int (*compar)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif /* BINARY_SEARCH_H */