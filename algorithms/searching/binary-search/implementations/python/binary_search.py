"""
Binary Search Implementation in Python
二分查找的Python实现

Time Complexity: O(log n)
Space Complexity: O(1) for iterative, O(log n) for recursive
"""

def binary_search(arr, target):
    """
    Performs binary search on a sorted array using iterative approach.
    
    Args:
        arr (list): Sorted list of comparable elements
        target: Element to search for
        
    Returns:
        int: Index of target if found, -1 otherwise
        
    Examples:
        >>> binary_search([1, 3, 5, 7, 9], 5)
        2
        
        >>> binary_search([1, 3, 5, 7, 9], 6)
        -1
        
        >>> binary_search([], 5)
        -1
    """
    if not arr:
        return -1
    
    left, right = 0, len(arr) - 1
    
    while left <= right:
        # Use (left + right) // 2 to avoid potential overflow
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1


def binary_search_recursive(arr, target, left=None, right=None):
    """
    Performs binary search on a sorted array using recursive approach.
    
    Args:
        arr (list): Sorted list of comparable elements
        target: Element to search for
        left (int): Left boundary (used internally)
        right (int): Right boundary (used internally)
        
    Returns:
        int: Index of target if found, -1 otherwise
    """
    if not arr:
        return -1
    
    if left is None:
        left = 0
    if right is None:
        right = len(arr) - 1
    
    if left > right:
        return -1
    
    mid = left + (right - left) // 2
    
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search_recursive(arr, target, mid + 1, right)
    else:
        return binary_search_recursive(arr, target, left, mid - 1)


def binary_search_verbose(arr, target):
    """
    Binary search with step-by-step visualization.
    
    Args:
        arr (list): Sorted list of comparable elements
        target: Element to search for
        
    Returns:
        tuple: (index, steps_taken)
    """
    if not arr:
        print("Empty array provided")
        return -1, 0
    
    left, right = 0, len(arr) - 1
    steps = 0
    
    print(f"Searching for {target} in array: {arr}")
    print(f"Array length: {len(arr)}")
    
    while left <= right:
        steps += 1
        mid = left + (right - left) // 2
        
        print(f"\nStep {steps}:")
        print(f"  left={left}, right={right}, mid={mid}")
        print(f"  arr[{mid}] = {arr[mid]}")
        
        if arr[mid] == target:
            print(f"  Target found at index {mid}!")
            return mid, steps
        elif arr[mid] < target:
            print(f"  {arr[mid]} < {target}, search right half")
            left = mid + 1
        else:
            print(f"  {arr[mid]} > {target}, search left half")
            right = mid - 1
    
    print(f"\nTarget {target} not found in array after {steps} steps")
    return -1, steps


def binary_search_first_occurrence(arr, target):
    """
    Find the first occurrence of target in a sorted array with duplicates.
    
    Args:
        arr (list): Sorted list that may contain duplicates
        target: Element to search for
        
    Returns:
        int: Index of first occurrence, -1 if not found
    """
    if not arr:
        return -1
    
    left, right = 0, len(arr) - 1
    result = -1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            result = mid
            right = mid - 1  # Continue searching in left half
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return result


def binary_search_last_occurrence(arr, target):
    """
    Find the last occurrence of target in a sorted array with duplicates.
    
    Args:
        arr (list): Sorted list that may contain duplicates
        target: Element to search for
        
    Returns:
        int: Index of last occurrence, -1 if not found
    """
    if not arr:
        return -1
    
    left, right = 0, len(arr) - 1
    result = -1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            result = mid
            left = mid + 1  # Continue searching in right half
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return result


def binary_search_range(arr, target):
    """
    Find the range [first_index, last_index] of target in sorted array.
    
    Args:
        arr (list): Sorted list that may contain duplicates
        target: Element to search for
        
    Returns:
        tuple: (first_index, last_index) or (-1, -1) if not found
    """
    first = binary_search_first_occurrence(arr, target)
    if first == -1:
        return (-1, -1)
    
    last = binary_search_last_occurrence(arr, target)
    return (first, last)


def binary_search_insertion_point(arr, target):
    """
    Find the insertion point for target to maintain sorted order.
    
    Args:
        arr (list): Sorted list
        target: Element to find insertion point for
        
    Returns:
        int: Index where target should be inserted
    """
    if not arr:
        return 0
    
    left, right = 0, len(arr)
    
    while left < right:
        mid = left + (right - left) // 2
        
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid
    
    return left


if __name__ == "__main__":
    # Example usage and testing
    test_arrays = [
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 7),
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 1),
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 19),
        ([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 6),
        ([42], 42),
        ([42], 10),
        ([], 5),
        ([1, 2, 2, 2, 3, 4, 5], 2),  # Duplicates
    ]
    
    print("=== Binary Search Examples ===")
    for i, (arr, target) in enumerate(test_arrays, 1):
        print(f"\nTest {i}: Searching for {target} in {arr}")
        index = binary_search(arr, target)
        if index != -1:
            print(f"Found at index {index}")
        else:
            print("Not found")
    
    print("\n=== Recursive Binary Search ===")
    arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    target = 7
    index = binary_search_recursive(arr, target)
    print(f"Recursive search for {target}: index {index}")
    
    print("\n=== Verbose Example ===")
    binary_search_verbose([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 7)
    
    print("\n=== Duplicate Handling ===")
    arr_with_dups = [1, 2, 2, 2, 2, 3, 4, 5]
    target = 2
    first = binary_search_first_occurrence(arr_with_dups, target)
    last = binary_search_last_occurrence(arr_with_dups, target)
    range_result = binary_search_range(arr_with_dups, target)
    
    print(f"Array: {arr_with_dups}")
    print(f"Target: {target}")
    print(f"First occurrence: {first}")
    print(f"Last occurrence: {last}")
    print(f"Range: {range_result}")
    
    print("\n=== Insertion Point ===")
    arr = [1, 3, 5, 7, 9]
    targets = [0, 2, 4, 6, 8, 10]
    print(f"Array: {arr}")
    for target in targets:
        pos = binary_search_insertion_point(arr, target)
        print(f"Insert {target} at position {pos}")