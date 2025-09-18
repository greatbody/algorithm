/**
 * Binary Search Implementation in Java
 * 二分查找的Java实现
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1) for iterative, O(log n) for recursive
 */

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

/**
 * Binary Search utility class with various implementations.
 */
class BinarySearch {

    /**
     * Performs binary search on a sorted array using iterative approach.
     *
     * @param arr Sorted array of comparable elements
     * @param target Element to search for
     * @return Index of target if found, -1 otherwise
     */
    public static <T extends Comparable<T>> int binarySearch(T[] arr, T target) {
        if (arr == null || arr.length == 0) {
            return -1;
        }

        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int comparison = arr[mid].compareTo(target);
            if (comparison == 0) {
                return mid;
            } else if (comparison < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    /**
     * Performs binary search on a sorted List using iterative approach.
     *
     * @param arr Sorted list of comparable elements
     * @param target Element to search for
     * @return Index of target if found, -1 otherwise
     */
    public static <T extends Comparable<T>> int binarySearch(List<T> arr, T target) {
        if (arr == null || arr.isEmpty()) {
            return -1;
        }

        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int comparison = arr.get(mid).compareTo(target);
            if (comparison == 0) {
                return mid;
            } else if (comparison < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    /**
     * Performs binary search on a sorted array using recursive approach.
     *
     * @param arr Sorted array of comparable elements
     * @param target Element to search for
     * @param left Left boundary
     * @param right Right boundary
     * @return Index of target if found, -1 otherwise
     */
    public static <T extends Comparable<T>> int binarySearchRecursive(T[] arr, T target, int left, int right) {
        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        int comparison = arr[mid].compareTo(target);
        if (comparison == 0) {
            return mid;
        } else if (comparison < 0) {
            return binarySearchRecursive(arr, target, mid + 1, right);
        } else {
            return binarySearchRecursive(arr, target, left, mid - 1);
        }
    }

    /**
     * Wrapper function for recursive binary search on array.
     */
    public static <T extends Comparable<T>> int binarySearchRecursive(T[] arr, T target) {
        if (arr == null || arr.length == 0) {
            return -1;
        }
        return binarySearchRecursive(arr, target, 0, arr.length - 1);
    }

    /**
     * Binary search with step-by-step visualization.
     *
     * @param arr Sorted array to search in
     * @param target Element to search for
     * @return Index of target if found, -1 otherwise
     */
    public static <T extends Comparable<T>> int binarySearchVerbose(T[] arr, T target) {
        if (arr == null || arr.length == 0) {
            System.out.println("Empty array provided");
            return -1;
        }

        int left = 0;
        int right = arr.length - 1;
        int steps = 0;

        System.out.print("Searching for " + target + " in array: [");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) System.out.print(", ");
        }
        System.out.println("]");

        while (left <= right) {
            steps++;
            int mid = left + (right - left) / 2;

            System.out.println("Step " + steps + ": left=" + left + ", right=" + right + ", mid=" + mid + ", arr[" + mid + "]=" + arr[mid]);

            int comparison = arr[mid].compareTo(target);
            if (comparison == 0) {
                System.out.println("Found at index " + mid + " in " + steps + " steps");
                return mid;
            } else if (comparison < 0) {
                System.out.println("arr[" + mid + "] < " + target + ", searching right half");
                left = mid + 1;
            } else {
                System.out.println("arr[" + mid + "] > " + target + ", searching left half");
                right = mid - 1;
            }
        }

        System.out.println("Not found after " + steps + " steps");
        return -1;
    }

    /**
     * Find the first occurrence of target in a sorted array with duplicates.
     *
     * @param arr Sorted array that may contain duplicates
     * @param target Element to search for
     * @return Index of first occurrence if found, -1 otherwise
     */
    public static <T extends Comparable<T>> int binarySearchFirstOccurrence(T[] arr, T target) {
        if (arr == null || arr.length == 0) {
            return -1;
        }

        int left = 0;
        int right = arr.length - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int comparison = arr[mid].compareTo(target);
            if (comparison == 0) {
                result = mid;
                right = mid - 1; // Continue searching in left half for first occurrence
            } else if (comparison < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

    /**
     * Find the last occurrence of target in a sorted array with duplicates.
     *
     * @param arr Sorted array that may contain duplicates
     * @param target Element to search for
     * @return Index of last occurrence if found, -1 otherwise
     */
    public static <T extends Comparable<T>> int binarySearchLastOccurrence(T[] arr, T target) {
        if (arr == null || arr.length == 0) {
            return -1;
        }

        int left = 0;
        int right = arr.length - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int comparison = arr[mid].compareTo(target);
            if (comparison == 0) {
                result = mid;
                left = mid + 1; // Continue searching in right half for last occurrence
            } else if (comparison < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

    /**
     * Find the range of occurrences of target in a sorted array with duplicates.
     *
     * @param arr Sorted array that may contain duplicates
     * @param target Element to search for
     * @return Array with [firstIndex, lastIndex], or [-1, -1] if not found
     */
    public static <T extends Comparable<T>> int[] binarySearchRange(T[] arr, T target) {
        int first = binarySearchFirstOccurrence(arr, target);
        if (first == -1) {
            return new int[]{-1, -1};
        }
        int last = binarySearchLastOccurrence(arr, target);
        return new int[]{first, last};
    }

    /**
     * Find the insertion point for target in a sorted array.
     * This is the index where target should be inserted to maintain sorted order.
     *
     * @param arr Sorted array
     * @param target Element to find insertion point for
     * @return Index where target should be inserted
     */
    public static <T extends Comparable<T>> int binarySearchInsertionPoint(T[] arr, T target) {
        if (arr == null || arr.length == 0) {
            return 0;
        }

        int left = 0;
        int right = arr.length;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid].compareTo(target) < 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
}

/**
 * Main class with comprehensive test cases.
 */
public class BinarySearchDemo {
    public static void main(String[] args) {
        System.out.println("Binary Search Implementation in Java");
        System.out.println("====================================");

        testBasicOperations();
        testRecursiveSearch();
        testVerboseSearch();
        testDuplicateHandling();
        testInsertionPoint();
        testEdgeCases();
    }

    /**
     * Test function for basic binary search operations.
     */
    public static void testBasicOperations() {
        System.out.println("=== Basic Operations ===");

        Integer[] arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        System.out.println("Array: " + Arrays.toString(arr));

        // Test successful searches
        int[] targets = {1, 7, 15, 19};
        for (int target : targets) {
            int result = BinarySearch.binarySearch(arr, target);
            System.out.println("Search " + target + ": found at index " + result);
        }

        // Test unsuccessful searches
        int[] notFoundTargets = {0, 4, 20};
        for (int target : notFoundTargets) {
            int result = BinarySearch.binarySearch(arr, target);
            System.out.println("Search " + target + ": not found (result: " + result + ")");
        }
    }

    /**
     * Test function for recursive binary search.
     */
    public static void testRecursiveSearch() {
        System.out.println("\n=== Recursive Search ===");

        Integer[] arr = {2, 4, 6, 8, 10, 12, 14, 16};
        System.out.println("Array: " + Arrays.toString(arr));

        int[] targets = {2, 8, 14, 16, 5};
        for (int target : targets) {
            int result = BinarySearch.binarySearchRecursive(arr, target);
            String status = result != -1 ? "found at index " + result : "not found";
            System.out.println("Recursive search " + target + ": " + status);
        }
    }

    /**
     * Test function for verbose binary search.
     */
    public static void testVerboseSearch() {
        System.out.println("\n=== Verbose Search ===");

        Integer[] arr = {1, 3, 5, 7, 9, 11};
        BinarySearch.binarySearchVerbose(arr, 7);
        System.out.println();
        BinarySearch.binarySearchVerbose(arr, 4);
    }

    /**
     * Test function for handling duplicates.
     */
    public static void testDuplicateHandling() {
        System.out.println("\n=== Duplicate Handling ===");

        Integer[] arrWithDups = {1, 2, 2, 2, 2, 3, 4, 5};
        System.out.println("Array with duplicates: " + Arrays.toString(arrWithDups));

        int target = 2;
        int first = BinarySearch.binarySearchFirstOccurrence(arrWithDups, target);
        int last = BinarySearch.binarySearchLastOccurrence(arrWithDups, target);
        int[] range = BinarySearch.binarySearchRange(arrWithDups, target);

        System.out.println("Target: " + target);
        System.out.println("First occurrence: " + first);
        System.out.println("Last occurrence: " + last);
        System.out.println("Range: [" + range[0] + ", " + range[1] + "]");

        // Test with element that doesn't exist
        target = 6;
        first = BinarySearch.binarySearchFirstOccurrence(arrWithDups, target);
        last = BinarySearch.binarySearchLastOccurrence(arrWithDups, target);
        range = BinarySearch.binarySearchRange(arrWithDups, target);

        System.out.println("\nTarget: " + target + " (not found)");
        System.out.println("First occurrence: " + first);
        System.out.println("Last occurrence: " + last);
        System.out.println("Range: [" + range[0] + ", " + range[1] + "]");
    }

    /**
     * Test function for insertion point.
     */
    public static void testInsertionPoint() {
        System.out.println("\n=== Insertion Point ===");

        Integer[] arr = {1, 3, 5, 7, 9};
        System.out.println("Array: " + Arrays.toString(arr));

        int[] targets = {0, 2, 4, 6, 8, 10};
        for (int target : targets) {
            int insertionPoint = BinarySearch.binarySearchInsertionPoint(arr, target);
            System.out.println("Insertion point for " + target + ": " + insertionPoint);
        }
    }

    /**
     * Test function for edge cases.
     */
    public static void testEdgeCases() {
        System.out.println("\n=== Edge Cases ===");

        // Empty array
        Integer[] emptyArr = {};
        int result = BinarySearch.binarySearch(emptyArr, 5);
        System.out.println("Empty array search: " + result);

        // Single element array
        Integer[] singleArr = {42};
        result = BinarySearch.binarySearch(singleArr, 42);
        System.out.println("Single element found: " + result);
        result = BinarySearch.binarySearch(singleArr, 24);
        System.out.println("Single element not found: " + result);

        // String array
        String[] stringArr = {"apple", "banana", "cherry", "date", "elderberry"};
        System.out.println("String array: " + Arrays.toString(stringArr));
        result = BinarySearch.binarySearch(stringArr, "cherry");
        System.out.println("String search 'cherry': " + result);
        result = BinarySearch.binarySearch(stringArr, "fig");
        System.out.println("String search 'fig': " + result);
    }
}