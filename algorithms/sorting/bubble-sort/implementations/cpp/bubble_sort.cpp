/**
 * Bubble Sort Implementation in C++
 * 冒泡排序的C++实现
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

/**
 * Sorts a vector using the bubble sort algorithm.
 *
 * @param arr Vector of integers to be sorted
 * @return Sorted vector in ascending order
 */
std::vector<int> bubbleSort(const std::vector<int>& arr) {
    if (arr.empty() || arr.size() <= 1) {
        return arr;
    }

    std::vector<int> result = arr;
    size_t n = result.size();

    for (size_t i = 0; i < n; i++) {
        bool swapped = false;

        for (size_t j = 0; j < n - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                std::swap(result[j], result[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    return result;
}

/**
 * Sorts a vector in descending order using bubble sort.
 *
 * @param arr Vector of integers to be sorted
 * @return Sorted vector in descending order
 */
std::vector<int> bubbleSortDescending(const std::vector<int>& arr) {
    if (arr.empty() || arr.size() <= 1) {
        return arr;
    }

    std::vector<int> result = arr;
    size_t n = result.size();

    for (size_t i = 0; i < n; i++) {
        bool swapped = false;

        for (size_t j = 0; j < n - i - 1; j++) {
            if (result[j] < result[j + 1]) {
                std::swap(result[j], result[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    return result;
}

/**
 * Helper function to print a vector.
 */
template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << vec[i];
    }
    std::cout << "]";
}

/**
 * Bubble sort with step-by-step visualization.
 *
 * @param arr Vector to be sorted
 * @return Sorted vector
 */
std::vector<int> bubbleSortVerbose(const std::vector<int>& arr) {
    if (arr.empty() || arr.size() <= 1) {
        std::cout << "Array is empty or has only one element" << std::endl;
        return arr;
    }

    std::vector<int> result = arr;
    size_t n = result.size();
    int steps = 0;

    std::cout << "Initial array: ";
    printVector(result);
    std::cout << std::endl;

    for (size_t i = 0; i < n; i++) {
        bool swapped = false;
        std::cout << "Pass " << (i + 1) << ":" << std::endl;

        for (size_t j = 0; j < n - i - 1; j++) {
            steps++;
            std::cout << "  Step " << steps << ": Comparing " << result[j] << " and " << result[j + 1];

            if (result[j] > result[j + 1]) {
                std::swap(result[j], result[j + 1]);
                swapped = true;
                std::cout << " -> Swapped";
            } else {
                std::cout << " -> No swap";
            }

            std::cout << " | Array: ";
            printVector(result);
            std::cout << std::endl;
        }

        if (!swapped) {
            std::cout << "No swaps in this pass, array is sorted!" << std::endl;
            break;
        }

        std::cout << "After pass " << (i + 1) << ": ";
        printVector(result);
        std::cout << std::endl << std::endl;
    }

    std::cout << "Sorting completed in " << steps << " steps" << std::endl;
    return result;
}

/**
 * Generic bubble sort template for any comparable type.
 *
 * @param arr Vector of comparable elements to be sorted
 * @return Sorted vector
 */
template <typename T>
std::vector<T> bubbleSortTemplate(const std::vector<T>& arr) {
    if (arr.empty() || arr.size() <= 1) {
        return arr;
    }

    std::vector<T> result = arr;
    size_t n = result.size();

    for (size_t i = 0; i < n; i++) {
        bool swapped = false;

        for (size_t j = 0; j < n - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                std::swap(result[j], result[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    return result;
}

/**
 * Bubble sort with performance measurement.
 *
 * @param arr Vector to be sorted
 * @return Performance result containing sorted array and timing
 */
struct BubbleSortPerformance {
    std::vector<int> sortedArray;
    long long executionTime; // in microseconds
    size_t arraySize;
    double timePerElement; // in microseconds
};

BubbleSortPerformance bubbleSortPerformance(const std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> sorted = bubbleSort(arr);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return {
        sorted,
        duration.count(),
        arr.size(),
        arr.empty() ? 0.0 : static_cast<double>(duration.count()) / arr.size()
    };
}

/**
 * Test function for basic bubble sort operations.
 */
void testBasicOperations() {
    std::cout << "=== Basic Operations ===" << std::endl;

    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Original array: ";
    printVector(arr1);
    std::cout << std::endl;

    std::vector<int> sorted1 = bubbleSort(arr1);
    std::cout << "Sorted array: ";
    printVector(sorted1);
    std::cout << std::endl;

    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    std::cout << "\nAlready sorted array: ";
    printVector(arr2);
    std::cout << std::endl;

    std::vector<int> sorted2 = bubbleSort(arr2);
    std::cout << "Sorted array: ";
    printVector(sorted2);
    std::cout << std::endl;

    std::vector<int> arr3 = {5, 4, 3, 2, 1};
    std::cout << "\nReverse sorted array: ";
    printVector(arr3);
    std::cout << std::endl;

    std::vector<int> sorted3 = bubbleSort(arr3);
    std::cout << "Sorted array: ";
    printVector(sorted3);
    std::cout << std::endl;
}

/**
 * Test function for descending sort.
 */
void testDescendingSort() {
    std::cout << "\n=== Descending Sort ===" << std::endl;

    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Original array: ";
    printVector(arr);
    std::cout << std::endl;

    std::vector<int> sorted = bubbleSortDescending(arr);
    std::cout << "Sorted descending: ";
    printVector(sorted);
    std::cout << std::endl;
}

/**
 * Test function for verbose sorting.
 */
void testVerboseSort() {
    std::cout << "\n=== Verbose Sort ===" << std::endl;

    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSortVerbose(arr);
}

/**
 * Test function for template version with strings.
 */
void testTemplateSort() {
    std::cout << "\n=== Template Sort (Strings) ===" << std::endl;

    std::vector<std::string> arr = {"banana", "apple", "cherry", "date", "elderberry"};
    std::cout << "Original array: ";
    printVector(arr);
    std::cout << std::endl;

    std::vector<std::string> sorted = bubbleSortTemplate(arr);
    std::cout << "Sorted array: ";
    printVector(sorted);
    std::cout << std::endl;
}

/**
 * Test function for performance measurement.
 */
void testPerformance() {
    std::cout << "\n=== Performance Test ===" << std::endl;

    std::vector<int> smallArr = {64, 34, 25, 12, 22, 11, 90};
    BubbleSortPerformance perf1 = bubbleSortPerformance(smallArr);
    std::cout << "Small array (size " << perf1.arraySize << "): " << perf1.executionTime << " microseconds" << std::endl;
    std::cout << "Time per element: " << perf1.timePerElement << " microseconds" << std::endl;

    // Create a larger array for performance testing
    std::vector<int> largeArr;
    for (int i = 100; i > 0; i--) {
        largeArr.push_back(i);
    }

    BubbleSortPerformance perf2 = bubbleSortPerformance(largeArr);
    std::cout << "Large array (size " << perf2.arraySize << "): " << perf2.executionTime << " microseconds" << std::endl;
    std::cout << "Time per element: " << perf2.timePerElement << " microseconds" << std::endl;
}

/**
 * Test function for edge cases.
 */
void testEdgeCases() {
    std::cout << "\n=== Edge Cases ===" << std::endl;

    // Empty array
    std::vector<int> emptyArr;
    std::vector<int> sortedEmpty = bubbleSort(emptyArr);
    std::cout << "Empty array: ";
    printVector(sortedEmpty);
    std::cout << std::endl;

    // Single element
    std::vector<int> singleArr = {42};
    std::vector<int> sortedSingle = bubbleSort(singleArr);
    std::cout << "Single element: ";
    printVector(sortedSingle);
    std::cout << std::endl;

    // Two elements
    std::vector<int> twoArr = {2, 1};
    std::vector<int> sortedTwo = bubbleSort(twoArr);
    std::cout << "Two elements: ";
    printVector(sortedTwo);
    std::cout << std::endl;

    // Array with duplicates
    std::vector<int> dupArr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::vector<int> sortedDup = bubbleSort(dupArr);
    std::cout << "Array with duplicates: ";
    printVector(sortedDup);
    std::cout << std::endl;
}

/**
 * Test function for optimization (early termination).
 */
void testOptimization() {
    std::cout << "\n=== Optimization Test (Already Sorted) ===" << std::endl;

    std::vector<int> sortedArr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Already sorted array: ";
    printVector(sortedArr);
    std::cout << std::endl;

    std::cout << "Sorting (should terminate early):" << std::endl;
    bubbleSortVerbose(sortedArr);
}

int main() {
    std::cout << "Bubble Sort Implementation in C++" << std::endl;
    std::cout << "==================================" << std::endl;

    testBasicOperations();
    testDescendingSort();
    testVerboseSort();
    testTemplateSort();
    testPerformance();
    testEdgeCases();
    testOptimization();

    std::cout << "\nAll tests completed!" << std::endl;

    return 0;
}