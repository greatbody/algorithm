/**
 * Bubble Sort Implementation in JavaScript
 * 冒泡排序的JavaScript实现
 * 
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */

/**
 * Sorts an array using the bubble sort algorithm.
 * 
 * @param {Array} arr - Array of comparable elements to be sorted
 * @param {Function} compareFn - Optional compare function for custom sorting
 * @returns {Array} Sorted array in ascending order
 * 
 * @example
 * bubbleSort([64, 34, 25, 12, 22, 11, 90])
 * // Returns: [11, 12, 22, 25, 34, 64, 90]
 * 
 * @example
 * bubbleSort(['banana', 'apple', 'cherry'])
 * // Returns: ['apple', 'banana', 'cherry']
 */
function bubbleSort(arr, compareFn = (a, b) => a > b) {
    if (!Array.isArray(arr) || arr.length <= 1) {
        return Array.isArray(arr) ? [...arr] : [];
    }
    
    // Create a copy to avoid modifying the original array
    const result = [...arr];
    const n = result.length;
    
    // Traverse through all array elements
    for (let i = 0; i < n; i++) {
        // Flag to optimize by detecting if array is already sorted
        let swapped = false;
        
        // Last i elements are already in place
        for (let j = 0; j < n - i - 1; j++) {
            // Compare and swap if elements are in wrong order
            if (compareFn(result[j], result[j + 1])) {
                [result[j], result[j + 1]] = [result[j + 1], result[j]];
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
 * @param {Array} arr - Array of comparable elements to be sorted
 * @returns {Array} Sorted array in descending order
 */
function bubbleSortDescending(arr) {
    return bubbleSort(arr, (a, b) => a < b);
}

/**
 * Bubble sort with step-by-step visualization.
 * 
 * @param {Array} arr - Array to be sorted
 * @returns {Object} Object containing sorted array and steps taken
 */
function bubbleSortVerbose(arr) {
    if (!Array.isArray(arr) || arr.length <= 1) {
        return {
            sortedArray: Array.isArray(arr) ? [...arr] : [],
            steps: 0
        };
    }
    
    const result = [...arr];
    const n = result.length;
    let steps = 0;
    
    console.log(`Initial array: [${result.join(', ')}]`);
    
    for (let i = 0; i < n; i++) {
        let swapped = false;
        console.log(`\nPass ${i + 1}:`);
        
        for (let j = 0; j < n - i - 1; j++) {
            steps++;
            if (result[j] > result[j + 1]) {
                [result[j], result[j + 1]] = [result[j + 1], result[j]];
                swapped = true;
                console.log(`  Swapped ${result[j + 1]} and ${result[j]}: [${result.join(', ')}]`);
            }
        }
        
        if (!swapped) {
            console.log('  No swaps needed. Array is sorted!');
            break;
        } else {
            console.log(`  End of pass ${i + 1}: [${result.join(', ')}]`);
        }
    }
    
    console.log(`\nFinal sorted array: [${result.join(', ')}]`);
    return {
        sortedArray: result,
        steps: steps
    };
}

/**
 * Async version of bubble sort with delays for visualization.
 * 
 * @param {Array} arr - Array to be sorted
 * @param {number} delay - Delay in milliseconds between each step
 * @param {Function} onStep - Callback function called after each step
 * @returns {Promise<Array>} Promise resolving to sorted array
 */
async function bubbleSortAsync(arr, delay = 100, onStep = null) {
    if (!Array.isArray(arr) || arr.length <= 1) {
        return Array.isArray(arr) ? [...arr] : [];
    }
    
    const result = [...arr];
    const n = result.length;
    
    for (let i = 0; i < n; i++) {
        let swapped = false;
        
        for (let j = 0; j < n - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                [result[j], result[j + 1]] = [result[j + 1], result[j]];
                swapped = true;
                
                if (onStep) {
                    onStep([...result], i, j);
                }
                
                if (delay > 0) {
                    await new Promise(resolve => setTimeout(resolve, delay));
                }
            }
        }
        
        if (!swapped) {
            break;
        }
    }
    
    return result;
}

/**
 * Bubble sort for objects with a specified key.
 * 
 * @param {Array} arr - Array of objects to be sorted
 * @param {string} key - Key to sort by
 * @param {boolean} ascending - Sort in ascending order if true
 * @returns {Array} Sorted array of objects
 */
function bubbleSortBy(arr, key, ascending = true) {
    const compareFn = ascending 
        ? (a, b) => a[key] > b[key]
        : (a, b) => a[key] < b[key];
    
    return bubbleSort(arr, compareFn);
}

/**
 * Performance test for bubble sort.
 * 
 * @param {Array} arr - Array to sort
 * @returns {Object} Performance metrics
 */
function bubbleSortPerformance(arr) {
    const startTime = performance.now();
    const result = bubbleSort(arr);
    const endTime = performance.now();
    
    return {
        sortedArray: result,
        executionTime: endTime - startTime,
        arraySize: arr.length,
        timePerElement: (endTime - startTime) / arr.length
    };
}

// Export functions for use in other modules
if (typeof module !== 'undefined' && module.exports) {
    module.exports = {
        bubbleSort,
        bubbleSortDescending,
        bubbleSortVerbose,
        bubbleSortAsync,
        bubbleSortBy,
        bubbleSortPerformance
    };
}

// Example usage and testing (only runs in browser or when file is run directly)
if (typeof window !== 'undefined' || (typeof require !== 'undefined' && require.main === module)) {
    console.log('=== Bubble Sort Examples ===');
    
    const testArrays = [
        [64, 34, 25, 12, 22, 11, 90],
        [5, 2, 8, 1, 9],
        [1, 2, 3, 4, 5],  // Already sorted
        [5, 4, 3, 2, 1],  // Reverse sorted
        [42],             // Single element
        [],               // Empty array
        [3, 3, 3, 3]      // All same elements
    ];
    
    testArrays.forEach((arr, index) => {
        console.log(`\nTest ${index + 1}: [${arr.join(', ')}]`);
        const sorted = bubbleSort(arr);
        console.log(`Sorted:  [${sorted.join(', ')}]`);
    });
    
    console.log('\n=== Verbose Example ===');
    bubbleSortVerbose([64, 34, 25, 12, 22, 11, 90]);
    
    console.log('\n=== Descending Order Example ===');
    const arr = [64, 34, 25, 12, 22, 11, 90];
    const descSorted = bubbleSortDescending(arr);
    console.log(`Original:   [${arr.join(', ')}]`);
    console.log(`Descending: [${descSorted.join(', ')}]`);
    
    console.log('\n=== String Sorting Example ===');
    const strings = ['banana', 'apple', 'cherry', 'date'];
    const sortedStrings = bubbleSort(strings);
    console.log(`Original: [${strings.join(', ')}]`);
    console.log(`Sorted:   [${sortedStrings.join(', ')}]`);
    
    console.log('\n=== Object Sorting Example ===');
    const people = [
        { name: 'Alice', age: 30 },
        { name: 'Bob', age: 25 },
        { name: 'Charlie', age: 35 }
    ];
    const sortedByAge = bubbleSortBy(people, 'age');
    console.log('Sorted by age:', sortedByAge);
    
    console.log('\n=== Performance Test ===');
    const perfArray = Array.from({ length: 1000 }, () => Math.floor(Math.random() * 1000));
    const perfResult = bubbleSortPerformance(perfArray);
    console.log(`Sorted ${perfResult.arraySize} elements in ${perfResult.executionTime.toFixed(2)}ms`);
    console.log(`Average time per element: ${perfResult.timePerElement.toFixed(4)}ms`);
}