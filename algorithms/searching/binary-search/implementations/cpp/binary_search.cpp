/**
 * Binary Search Implementation in C++
 * 二分查找的C++实现
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1) for iterative, O(log n) for recursive
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Performs binary search on a sorted vector using iterative approach.
 * 
 * @param arr Sorted vector of comparable elements
 * @param target Element to search for
 * @return Index of target if found, -1 otherwise
 */
int binarySearch(const std::vector<int>& arr, int target) {
    if (arr.empty()) {
        return -1;
    }
    
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        // Avoid potential overflow
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

/**
 * Performs binary search on a sorted vector using recursive approach.
 * 
 * @param arr Sorted vector of comparable elements
 * @param target Element to search for
 * @param left Left boundary
 * @param right Right boundary
 * @return Index of target if found, -1 otherwise
 */
int binarySearchRecursive(const std::vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right);
    } else {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
}

/**
 * Wrapper function for recursive binary search.
 */
int binarySearchRecursive(const std::vector<int>& arr, int target) {
    if (arr.empty()) {
        return -1;
    }
    return binarySearchRecursive(arr, target, 0, arr.size() - 1);
}

/**
 * Binary search with step-by-step visualization.
 * 
 * @param arr Sorted vector to search in
 * @param target Element to search for
 * @return Index of target if found, -1 otherwise
 */
int binarySearchVerbose(const std::vector<int>& arr, int target) {
    if (arr.empty()) {
        std::cout << "Empty array provided" << std::endl;
        return -1;
    }
    
    int left = 0;
    int right = arr.size() - 1;
    int steps = 0;
    
    std::cout << "Searching for " << target << " in array: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Array length: " << arr.size() << std::endl;
    
    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        
        std::cout << "\nStep " << steps << ":" << std::endl;
        std::cout << "  left=" << left << ", right=" << right << ", mid=" << mid << std::endl;
        std::cout << "  arr[" << mid << "] = " << arr[mid] << std::endl;
        
        if (arr[mid] == target) {
            std::cout << "  Target found at index " << mid << "!" << std::endl;
            return mid;
        } else if (arr[mid] < target) {
            std::cout << "  " << arr[mid] << " < " << target << ", search right half" << std::endl;
            left = mid + 1;
        } else {
            std::cout << "  " << arr[mid] << " > " << target << ", search left half" << std::endl;
            right = mid - 1;
        }
    }
    
    std::cout << "\nTarget " << target << " not found in array after " << steps << " steps" << std::endl;
    return -1;
}

/**
 * Find the first occurrence of target in a sorted vector with duplicates.
 * 
 * @param arr Sorted vector that may contain duplicates
 * @param target Element to search for
 * @return Index of first occurrence, -1 if not found
 */
int binarySearchFirstOccurrence(const std::vector<int>& arr, int target) {
    if (arr.empty()) {
        return -1;
    }
    
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Continue searching in left half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

/**
 * Find the last occurrence of target in a sorted vector with duplicates.
 * 
 * @param arr Sorted vector that may contain duplicates
 * @param target Element to search for
 * @return Index of last occurrence, -1 if not found
 */
int binarySearchLastOccurrence(const std::vector<int>& arr, int target) {
    if (arr.empty()) {
        return -1;
    }
    
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; // Continue searching in right half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

/**
 * Template version for any comparable type.
 */
template<typename T>
int binarySearchTemplate(const std::vector<T>& arr, const T& target) {
    if (arr.empty()) {
        return -1;
    }
    
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

// Test function
void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
}

int main() {
    std::cout << "=== Binary Search Examples ===" << std::endl;
    
    // Test cases
    std::vector<std::vector<int>> testArrays = {
        {1, 3, 5, 7, 9, 11, 13, 15, 17, 19},
        {1, 3, 5, 7, 9, 11, 13, 15, 17, 19},
        {1, 3, 5, 7, 9, 11, 13, 15, 17, 19},
        {1, 3, 5, 7, 9, 11, 13, 15, 17, 19},
        {42},
        {42},
        {}
    };
    
    std::vector<int> targets = {7, 1, 19, 6, 42, 10, 5};
    std::vector<std::string> descriptions = {
        "Element in middle",
        "First element", 
        "Last element",
        "Element not found",
        "Single element found",
        "Single element not found",
        "Empty array"
    };
    
    for (size_t i = 0; i < testArrays.size(); ++i) {
        std::cout << "\nTest " << (i + 1) << ": " << descriptions[i] << std::endl;
        std::cout << "Array: ";
        printVector(testArrays[i]);
        std::cout << ", Target: " << targets[i] << std::endl;
        
        int result = binarySearch(testArrays[i], targets[i]);
        if (result != -1) {
            std::cout << "Found at index " << result << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
    }
    
    std::cout << "\n=== Recursive Binary Search ===" << std::endl;
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;
    int recursiveResult = binarySearchRecursive(arr, target);
    std::cout << "Recursive search for " << target << ": ";
    if (recursiveResult != -1) {
        std::cout << "Found at index " << recursiveResult << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    
    std::cout << "\n=== Verbose Example ===" << std::endl;
    binarySearchVerbose({1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, 7);
    
    std::cout << "\n=== Duplicate Handling ===" << std::endl;
    std::vector<int> arrWithDups = {1, 2, 2, 2, 2, 3, 4, 5};
    int dupTarget = 2;
    int first = binarySearchFirstOccurrence(arrWithDups, dupTarget);
    int last = binarySearchLastOccurrence(arrWithDups, dupTarget);
    
    std::cout << "Array: ";
    printVector(arrWithDups);
    std::cout << std::endl;
    std::cout << "Target: " << dupTarget << std::endl;
    std::cout << "First occurrence: " << first << std::endl;
    std::cout << "Last occurrence: " << last << std::endl;
    
    std::cout << "\n=== Template Example with Strings ===" << std::endl;
    std::vector<std::string> strings = {"apple", "banana", "cherry", "date", "elderberry"};
    std::string stringTarget = "cherry";
    int stringResult = binarySearchTemplate(strings, stringTarget);
    
    std::cout << "String array: [";
    for (size_t i = 0; i < strings.size(); ++i) {
        std::cout << "\"" << strings[i] << "\"";
        if (i < strings.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Target: \"" << stringTarget << "\"" << std::endl;
    if (stringResult != -1) {
        std::cout << "Found at index " << stringResult << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    
    return 0;
}