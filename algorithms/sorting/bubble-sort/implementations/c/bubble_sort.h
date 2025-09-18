/**
 * Bubble Sort Implementation in C
 * 冒泡排序的C语言实现
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Result structure for bubble sort operations
 * 冒泡排序结果结构体
 */
typedef struct {
    int* array;        // Sorted array (owned by caller)
    size_t length;     // Length of the array
    size_t comparisons; // Number of comparisons made
    size_t swaps;      // Number of swaps made
} BubbleSortResult;

/**
 * Sort an integer array using bubble sort algorithm
 * 使用冒泡排序算法对整数数组进行排序
 *
 * @param arr Array to sort (will be modified)
 * @param length Length of the array
 * @return true on success, false on error
 */
bool bubble_sort(int* arr, size_t length);

/**
 * Sort an integer array in descending order using bubble sort
 * 使用冒泡排序算法对整数数组进行降序排序
 *
 * @param arr Array to sort (will be modified)
 * @param length Length of the array
 * @return true on success, false on error
 */
bool bubble_sort_descending(int* arr, size_t length);

/**
 * Sort an integer array with detailed result information
 * 对整数数组进行排序并返回详细信息
 *
 * @param arr Array to sort (will be modified)
 * @param length Length of the array
 * @param result Result structure to fill
 * @return true on success, false on error
 */
bool bubble_sort_with_result(int* arr, size_t length, BubbleSortResult* result);

/**
 * Generic bubble sort for any data type with custom comparison
 * 通用冒泡排序，支持自定义比较函数
 *
 * @param base Pointer to the array
 * @param num_elements Number of elements
 * @param element_size Size of each element in bytes
 * @param compare Comparison function (should return <0, 0, or >0)
 * @return true on success, false on error
 */
bool bubble_sort_generic(void* base, size_t num_elements, size_t element_size,
                        int (*compare)(const void*, const void*));

/**
 * Check if an array is sorted in ascending order
 * 检查数组是否按升序排序
 *
 * @param arr Array to check
 * @param length Length of the array
 * @return true if sorted, false otherwise
 */
bool is_sorted_ascending(const int* arr, size_t length);

/**
 * Check if an array is sorted in descending order
 * 检查数组是否按降序排序
 *
 * @param arr Array to check
 * @param length Length of the array
 * @return true if sorted, false otherwise
 */
bool is_sorted_descending(const int* arr, size_t length);

/**
 * Create a copy of an integer array
 * 创建整数数组的副本
 *
 * @param source Source array
 * @param length Length of the array
 * @return Pointer to new array (must be freed by caller), or NULL on error
 */
int* array_copy(const int* source, size_t length);

/**
 * Print an integer array
 * 打印整数数组
 *
 * @param arr Array to print
 * @param length Length of the array
 */
void print_array(const int* arr, size_t length);

#endif /* BUBBLE_SORT_H */