/**
 * Simple Binary Search Implementation in C
 * 
 * A minimal, cross-platform binary search implementation
 */

#include <stdio.h>
#include <stdbool.h>

// Core binary search algorithm
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Not found
}

// Simple test function
void testBinarySearch() {
    printf("Testing Binary Search\n");
    printf("====================\n");
    
    // Test array (must be sorted)
    int testArray[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(testArray) / sizeof(testArray[0]);
    
    printf("Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", testArray[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n\n");
    
    // Test cases
    int testCases[] = {7, 1, 19, 6, 20};
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        int target = testCases[i];
        int result = binarySearch(testArray, size, target);
        
        printf("Searching for %d: ", target);
        if (result != -1) {
            printf("Found at index %d\n", result);
        } else {
            printf("Not found\n");
        }
    }
    
    printf("\n");
}

// Main function
int main() {
    printf("Binary Search Implementation\n");
    printf("===========================\n\n");
    
    testBinarySearch();
    
    printf("Test completed!\n");
    return 0;
}