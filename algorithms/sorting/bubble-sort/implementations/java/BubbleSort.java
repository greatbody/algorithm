/**
 * Bubble Sort Implementation in Java
 * 冒泡排序的Java实现
 * 
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */

import java.util.Arrays;
import java.util.Comparator;

public class BubbleSort {
    
    /**
     * Sorts an array using the bubble sort algorithm.
     * 
     * @param arr Array of integers to be sorted
     * @return Sorted array in ascending order
     */
    public static int[] sort(int[] arr) {
        if (arr == null || arr.length <= 1) {
            return arr == null ? new int[0] : arr.clone();
        }
        
        // Create a copy to avoid modifying the original array
        int[] result = arr.clone();
        int n = result.length;
        
        // Traverse through all array elements
        for (int i = 0; i < n; i++) {
            // Flag to optimize by detecting if array is already sorted
            boolean swapped = false;
            
            // Last i elements are already in place
            for (int j = 0; j < n - i - 1; j++) {
                // Swap if the element found is greater than the next element
                if (result[j] > result[j + 1]) {
                    swap(result, j, j + 1);
                    swapped = true;
                }
            }
            
            // If no swapping happened, array is sorted
            if (!swapped) {
                break;
            }
        }
        
        return result;
    }
    
    /**
     * Sorts an array in descending order using bubble sort.
     * 
     * @param arr Array of integers to be sorted
     * @return Sorted array in descending order
     */
    public static int[] sortDescending(int[] arr) {
        if (arr == null || arr.length <= 1) {
            return arr == null ? new int[0] : arr.clone();
        }
        
        int[] result = arr.clone();
        int n = result.length;
        
        for (int i = 0; i < n; i++) {
            boolean swapped = false;
            
            for (int j = 0; j < n - i - 1; j++) {
                // Change comparison for descending order
                if (result[j] < result[j + 1]) {
                    swap(result, j, j + 1);
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
     * Sorts an array with verbose output showing each step.
     * 
     * @param arr Array of integers to be sorted
     * @return SortResult containing the sorted array and number of steps
     */
    public static SortResult sortVerbose(int[] arr) {
        if (arr == null || arr.length <= 1) {
            return new SortResult(arr == null ? new int[0] : arr.clone(), 0);
        }
        
        int[] result = arr.clone();
        int n = result.length;
        int steps = 0;
        
        System.out.println("Initial array: " + Arrays.toString(result));
        
        for (int i = 0; i < n; i++) {
            boolean swapped = false;
            System.out.println("\nPass " + (i + 1) + ":");
            
            for (int j = 0; j < n - i - 1; j++) {
                steps++;
                if (result[j] > result[j + 1]) {
                    swap(result, j, j + 1);
                    swapped = true;
                    System.out.println("  Swapped " + result[j + 1] + " and " + 
                                     result[j] + ": " + Arrays.toString(result));
                }
            }
            
            if (!swapped) {
                System.out.println("  No swaps needed. Array is sorted!");
                break;
            } else {
                System.out.println("  End of pass " + (i + 1) + ": " + 
                                 Arrays.toString(result));
            }
        }
        
        System.out.println("\nFinal sorted array: " + Arrays.toString(result));
        return new SortResult(result, steps);
    }
    
    /**
     * Generic bubble sort for any Comparable type.
     * 
     * @param <T> Type that implements Comparable
     * @param arr Array of comparable elements
     * @return Sorted array
     */
    @SuppressWarnings("unchecked")
    public static <T extends Comparable<T>> T[] sort(T[] arr) {
        if (arr == null || arr.length <= 1) {
            return arr == null ? (T[]) new Comparable[0] : arr.clone();
        }
        
        T[] result = arr.clone();
        int n = result.length;
        
        for (int i = 0; i < n; i++) {
            boolean swapped = false;
            
            for (int j = 0; j < n - i - 1; j++) {
                if (result[j].compareTo(result[j + 1]) > 0) {
                    T temp = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = temp;
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
     * Helper method to swap two elements in an array.
     * 
     * @param arr Array containing elements to swap
     * @param i First index
     * @param j Second index
     */
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    /**
     * Result class to hold sorted array and performance metrics.
     */
    public static class SortResult {
        public final int[] sortedArray;
        public final int steps;
        
        public SortResult(int[] sortedArray, int steps) {
            this.sortedArray = sortedArray;
            this.steps = steps;
        }
    }
    
    /**
     * Main method for testing and demonstration.
     */
    public static void main(String[] args) {
        System.out.println("=== Bubble Sort Examples ===");
        
        // Test arrays
        int[][] testArrays = {
            {64, 34, 25, 12, 22, 11, 90},
            {5, 2, 8, 1, 9},
            {1, 2, 3, 4, 5},  // Already sorted
            {5, 4, 3, 2, 1},  // Reverse sorted
            {42},             // Single element
            {},               // Empty array
            {3, 3, 3, 3}      // All same elements
        };
        
        for (int i = 0; i < testArrays.length; i++) {
            System.out.println("\nTest " + (i + 1) + ": " + 
                             Arrays.toString(testArrays[i]));
            int[] sorted = sort(testArrays[i]);
            System.out.println("Sorted:  " + Arrays.toString(sorted));
        }
        
        System.out.println("\n=== Verbose Example ===");
        sortVerbose(new int[]{64, 34, 25, 12, 22, 11, 90});
        
        System.out.println("\n=== Descending Order Example ===");
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        int[] descSorted = sortDescending(arr);
        System.out.println("Original:   " + Arrays.toString(arr));
        System.out.println("Descending: " + Arrays.toString(descSorted));
        
        System.out.println("\n=== String Sorting Example ===");
        String[] strings = {"banana", "apple", "cherry", "date"};
        String[] sortedStrings = sort(strings);
        System.out.println("Original: " + Arrays.toString(strings));
        System.out.println("Sorted:   " + Arrays.toString(sortedStrings));
    }
}