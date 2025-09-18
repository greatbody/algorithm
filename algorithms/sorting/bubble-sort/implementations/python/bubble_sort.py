"""
Bubble Sort Implementation in Python
冒泡排序的Python实现

Time Complexity: O(n²)
Space Complexity: O(1)
"""

def bubble_sort(arr):
    """
    Sorts an array using the bubble sort algorithm.
    
    Args:
        arr (list): List of comparable elements to be sorted
        
    Returns:
        list: Sorted list in ascending order
        
    Examples:
        >>> bubble_sort([64, 34, 25, 12, 22, 11, 90])
        [11, 12, 22, 25, 34, 64, 90]
        
        >>> bubble_sort([5, 2, 8, 1, 9])
        [1, 2, 5, 8, 9]
        
        >>> bubble_sort([])
        []
    """
    if not arr or len(arr) <= 1:
        return arr.copy()
    
    # Create a copy to avoid modifying the original array
    result = arr.copy()
    n = len(result)
    
    # Traverse through all array elements
    for i in range(n):
        # Flag to optimize by detecting if array is already sorted
        swapped = False
        
        # Last i elements are already in place, so we don't need to check them
        for j in range(0, n - i - 1):
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater than the next element
            if result[j] > result[j + 1]:
                result[j], result[j + 1] = result[j + 1], result[j]
                swapped = True
        
        # If no swapping happened, array is sorted
        if not swapped:
            break
            
    return result


def bubble_sort_verbose(arr):
    """
    Bubble sort with step-by-step visualization.
    
    Args:
        arr (list): List of comparable elements to be sorted
        
    Returns:
        tuple: (sorted_array, steps_taken)
    """
    if not arr or len(arr) <= 1:
        return arr.copy(), 0
    
    result = arr.copy()
    n = len(result)
    steps = 0
    
    print(f"Initial array: {result}")
    
    for i in range(n):
        swapped = False
        print(f"\nPass {i + 1}:")
        
        for j in range(0, n - i - 1):
            steps += 1
            if result[j] > result[j + 1]:
                result[j], result[j + 1] = result[j + 1], result[j]
                swapped = True
                print(f"  Swapped {result[j + 1]} and {result[j]}: {result}")
        
        if not swapped:
            print(f"  No swaps needed. Array is sorted!")
            break
        else:
            print(f"  End of pass {i + 1}: {result}")
    
    print(f"\nFinal sorted array: {result}")
    return result, steps


def bubble_sort_descending(arr):
    """
    Sorts an array in descending order using bubble sort.
    
    Args:
        arr (list): List of comparable elements to be sorted
        
    Returns:
        list: Sorted list in descending order
    """
    if not arr or len(arr) <= 1:
        return arr.copy()
    
    result = arr.copy()
    n = len(result)
    
    for i in range(n):
        swapped = False
        
        for j in range(0, n - i - 1):
            # Change comparison for descending order
            if result[j] < result[j + 1]:
                result[j], result[j + 1] = result[j + 1], result[j]
                swapped = True
        
        if not swapped:
            break
            
    return result


if __name__ == "__main__":
    # Example usage and testing
    test_arrays = [
        [64, 34, 25, 12, 22, 11, 90],
        [5, 2, 8, 1, 9],
        [1, 2, 3, 4, 5],  # Already sorted
        [5, 4, 3, 2, 1],  # Reverse sorted
        [42],             # Single element
        [],               # Empty array
        [3, 3, 3, 3],     # All same elements
    ]
    
    print("=== Bubble Sort Examples ===")
    for i, arr in enumerate(test_arrays, 1):
        print(f"\nTest {i}: {arr}")
        sorted_arr = bubble_sort(arr)
        print(f"Sorted:  {sorted_arr}")
    
    print("\n=== Verbose Example ===")
    bubble_sort_verbose([64, 34, 25, 12, 22, 11, 90])
    
    print("\n=== Descending Order Example ===")
    arr = [64, 34, 25, 12, 22, 11, 90]
    desc_sorted = bubble_sort_descending(arr)
    print(f"Original:   {arr}")
    print(f"Descending: {desc_sorted}")