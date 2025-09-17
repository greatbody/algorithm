"""
Test cases for Bubble Sort implementation
冒泡排序实现的测试用例
"""

import unittest
from bubble_sort import bubble_sort, bubble_sort_verbose, bubble_sort_descending


class TestBubbleSort(unittest.TestCase):
    """Test cases for bubble sort implementation."""
    
    def test_basic_sorting(self):
        """Test basic sorting functionality."""
        # Test case 1: Standard unsorted array
        arr1 = [64, 34, 25, 12, 22, 11, 90]
        expected1 = [11, 12, 22, 25, 34, 64, 90]
        self.assertEqual(bubble_sort(arr1), expected1)
        
        # Test case 2: Small array
        arr2 = [5, 2, 8, 1, 9]
        expected2 = [1, 2, 5, 8, 9]
        self.assertEqual(bubble_sort(arr2), expected2)
    
    def test_edge_cases(self):
        """Test edge cases."""
        # Empty array
        self.assertEqual(bubble_sort([]), [])
        
        # Single element
        self.assertEqual(bubble_sort([42]), [42])
        
        # Two elements
        self.assertEqual(bubble_sort([2, 1]), [1, 2])
        self.assertEqual(bubble_sort([1, 2]), [1, 2])
    
    def test_already_sorted(self):
        """Test with already sorted arrays."""
        arr = [1, 2, 3, 4, 5]
        expected = [1, 2, 3, 4, 5]
        self.assertEqual(bubble_sort(arr), expected)
    
    def test_reverse_sorted(self):
        """Test with reverse sorted arrays."""
        arr = [5, 4, 3, 2, 1]
        expected = [1, 2, 3, 4, 5]
        self.assertEqual(bubble_sort(arr), expected)
    
    def test_duplicates(self):
        """Test with duplicate elements."""
        arr = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3]
        expected = [1, 1, 2, 3, 3, 4, 5, 5, 6, 9]
        self.assertEqual(bubble_sort(arr), expected)
        
        # All same elements
        arr_same = [3, 3, 3, 3]
        expected_same = [3, 3, 3, 3]
        self.assertEqual(bubble_sort(arr_same), expected_same)
    
    def test_negative_numbers(self):
        """Test with negative numbers."""
        arr = [-1, -5, 0, 3, -2]
        expected = [-5, -2, -1, 0, 3]
        self.assertEqual(bubble_sort(arr), expected)
    
    def test_mixed_numbers(self):
        """Test with mixed positive and negative numbers."""
        arr = [10, -1, 5, -10, 0, 15]
        expected = [-10, -1, 0, 5, 10, 15]
        self.assertEqual(bubble_sort(arr), expected)
    
    def test_original_array_unchanged(self):
        """Test that original array is not modified."""
        original = [64, 34, 25, 12, 22, 11, 90]
        original_copy = original.copy()
        
        bubble_sort(original)
        
        # Original array should remain unchanged
        self.assertEqual(original, original_copy)
    
    def test_descending_sort(self):
        """Test descending order sorting."""
        arr = [64, 34, 25, 12, 22, 11, 90]
        expected = [90, 64, 34, 25, 22, 12, 11]
        self.assertEqual(bubble_sort_descending(arr), expected)
    
    def test_verbose_sorting(self):
        """Test verbose sorting returns correct result and step count."""
        arr = [3, 1, 2]
        result, steps = bubble_sort_verbose(arr)
        expected = [1, 2, 3]
        
        self.assertEqual(result, expected)
        self.assertGreater(steps, 0)
    
    def test_performance_characteristics(self):
        """Test performance characteristics."""
        # Best case: already sorted (should terminate early)
        sorted_arr = list(range(100))
        result, steps_best = bubble_sort_verbose(sorted_arr)
        
        # Worst case: reverse sorted
        reverse_arr = list(range(99, -1, -1))
        result_worst, steps_worst = bubble_sort_verbose(reverse_arr)
        
        # Best case should use fewer steps than worst case
        self.assertLess(steps_best, steps_worst)
    
    def test_string_sorting(self):
        """Test sorting with strings."""
        arr = ["banana", "apple", "cherry", "date"]
        expected = ["apple", "banana", "cherry", "date"]
        self.assertEqual(bubble_sort(arr), expected)


if __name__ == '__main__':
    # Run all tests
    unittest.main(verbosity=2)