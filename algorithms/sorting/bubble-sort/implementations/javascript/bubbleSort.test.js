/**
 * Test cases for Bubble Sort JavaScript implementation
 * 冒泡排序JavaScript实现的测试用例
 */

// Import functions (works with Node.js)
const {
    bubbleSort,
    bubbleSortDescending,
    bubbleSortVerbose,
    bubbleSortBy,
    bubbleSortPerformance
} = require('./bubbleSort');

/**
 * Simple test runner for environments without testing frameworks
 */
class SimpleTestRunner {
    constructor() {
        this.tests = [];
        this.passed = 0;
        this.failed = 0;
    }
    
    test(name, testFn) {
        this.tests.push({ name, testFn });
    }
    
    assertEqual(actual, expected, message = '') {
        const actualStr = JSON.stringify(actual);
        const expectedStr = JSON.stringify(expected);
        
        if (actualStr !== expectedStr) {
            throw new Error(`Expected ${expectedStr}, but got ${actualStr}. ${message}`);
        }
    }
    
    assertTrue(condition, message = '') {
        if (!condition) {
            throw new Error(`Expected true, but got false. ${message}`);
        }
    }
    
    run() {
        console.log('Running Bubble Sort Tests...\n');
        
        for (const { name, testFn } of this.tests) {
            try {
                testFn.call(this);
                console.log(`✓ ${name}`);
                this.passed++;
            } catch (error) {
                console.log(`✗ ${name}: ${error.message}`);
                this.failed++;
            }
        }
        
        console.log(`\nTests completed: ${this.passed} passed, ${this.failed} failed`);
        return this.failed === 0;
    }
}

// Create test runner instance
const runner = new SimpleTestRunner();

// Basic sorting tests
runner.test('should sort basic array', function() {
    const arr = [64, 34, 25, 12, 22, 11, 90];
    const expected = [11, 12, 22, 25, 34, 64, 90];
    this.assertEqual(bubbleSort(arr), expected);
});

runner.test('should sort small array', function() {
    const arr = [5, 2, 8, 1, 9];
    const expected = [1, 2, 5, 8, 9];
    this.assertEqual(bubbleSort(arr), expected);
});

// Edge cases
runner.test('should handle empty array', function() {
    this.assertEqual(bubbleSort([]), []);
});

runner.test('should handle single element', function() {
    this.assertEqual(bubbleSort([42]), [42]);
});

runner.test('should handle two elements', function() {
    this.assertEqual(bubbleSort([2, 1]), [1, 2]);
    this.assertEqual(bubbleSort([1, 2]), [1, 2]);
});

runner.test('should handle null/undefined input', function() {
    this.assertEqual(bubbleSort(null), []);
    this.assertEqual(bubbleSort(undefined), []);
});

// Already sorted array
runner.test('should handle already sorted array', function() {
    const arr = [1, 2, 3, 4, 5];
    const expected = [1, 2, 3, 4, 5];
    this.assertEqual(bubbleSort(arr), expected);
});

// Reverse sorted array
runner.test('should handle reverse sorted array', function() {
    const arr = [5, 4, 3, 2, 1];
    const expected = [1, 2, 3, 4, 5];
    this.assertEqual(bubbleSort(arr), expected);
});

// Duplicates
runner.test('should handle duplicates', function() {
    const arr = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3];
    const expected = [1, 1, 2, 3, 3, 4, 5, 5, 6, 9];
    this.assertEqual(bubbleSort(arr), expected);
});

runner.test('should handle all same elements', function() {
    const arr = [3, 3, 3, 3];
    const expected = [3, 3, 3, 3];
    this.assertEqual(bubbleSort(arr), expected);
});

// Negative numbers
runner.test('should handle negative numbers', function() {
    const arr = [-1, -5, 0, 3, -2];
    const expected = [-5, -2, -1, 0, 3];
    this.assertEqual(bubbleSort(arr), expected);
});

// Mixed numbers
runner.test('should handle mixed positive and negative numbers', function() {
    const arr = [10, -1, 5, -10, 0, 15];
    const expected = [-10, -1, 0, 5, 10, 15];
    this.assertEqual(bubbleSort(arr), expected);
});

// Original array unchanged
runner.test('should not modify original array', function() {
    const original = [64, 34, 25, 12, 22, 11, 90];
    const originalCopy = [...original];
    
    bubbleSort(original);
    
    this.assertEqual(original, originalCopy);
});

// Descending sort
runner.test('should sort in descending order', function() {
    const arr = [64, 34, 25, 12, 22, 11, 90];
    const expected = [90, 64, 34, 25, 22, 12, 11];
    this.assertEqual(bubbleSortDescending(arr), expected);
});

// String sorting
runner.test('should sort strings', function() {
    const arr = ['banana', 'apple', 'cherry', 'date'];
    const expected = ['apple', 'banana', 'cherry', 'date'];
    this.assertEqual(bubbleSort(arr), expected);
});

// Verbose sorting
runner.test('should return correct result with verbose sorting', function() {
    const arr = [3, 1, 2];
    const result = bubbleSortVerbose(arr);
    const expected = [1, 2, 3];
    
    this.assertEqual(result.sortedArray, expected);
    this.assertTrue(result.steps > 0, 'Should have performed at least one step');
});

// Object sorting
runner.test('should sort objects by key', function() {
    const arr = [
        { name: 'Charlie', age: 35 },
        { name: 'Alice', age: 30 },
        { name: 'Bob', age: 25 }
    ];
    const expected = [
        { name: 'Bob', age: 25 },
        { name: 'Alice', age: 30 },
        { name: 'Charlie', age: 35 }
    ];
    
    this.assertEqual(bubbleSortBy(arr, 'age'), expected);
});

runner.test('should sort objects by key in descending order', function() {
    const arr = [
        { name: 'Alice', score: 85 },
        { name: 'Bob', score: 92 },
        { name: 'Charlie', score: 78 }
    ];
    const expected = [
        { name: 'Bob', score: 92 },
        { name: 'Alice', score: 85 },
        { name: 'Charlie', score: 78 }
    ];
    
    this.assertEqual(bubbleSortBy(arr, 'score', false), expected);
});

// Performance test
runner.test('should provide performance metrics', function() {
    const arr = [5, 2, 8, 1, 9];
    const result = bubbleSortPerformance(arr);
    
    this.assertEqual(result.sortedArray, [1, 2, 5, 8, 9]);
    this.assertTrue(typeof result.executionTime === 'number', 'Should provide execution time');
    this.assertTrue(result.executionTime >= 0, 'Execution time should be non-negative');
    this.assertEqual(result.arraySize, 5);
    this.assertTrue(typeof result.timePerElement === 'number', 'Should provide time per element');
});

// Custom compare function
runner.test('should work with custom compare function', function() {
    const arr = [1, 2, 3, 4, 5];
    const expected = [5, 4, 3, 2, 1];
    const result = bubbleSort(arr, (a, b) => a < b); // Reverse comparison
    this.assertEqual(result, expected);
});

// Large array performance characteristics
runner.test('should handle performance characteristics correctly', function() {
    // This test is more about ensuring it completes than specific timing
    const sortedArr = Array.from({ length: 50 }, (_, i) => i);
    const reverseArr = Array.from({ length: 50 }, (_, i) => 49 - i);
    
    const sortedResult = bubbleSortVerbose(sortedArr);
    const reverseResult = bubbleSortVerbose(reverseArr);
    
    // Best case (already sorted) should use fewer steps than worst case (reverse sorted)
    this.assertTrue(sortedResult.steps <= reverseResult.steps, 
                   'Best case should use fewer or equal steps than worst case');
});

// Run all tests
if (typeof module !== 'undefined' && require.main === module) {
    const success = runner.run();
    process.exit(success ? 0 : 1);
}

// Export test runner for external use
if (typeof module !== 'undefined' && module.exports) {
    module.exports = { runner, SimpleTestRunner };
}