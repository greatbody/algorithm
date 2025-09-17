/**
 * Binary Search Implementation in JavaScript
 * 二分查找的JavaScript实现
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1) for iterative, O(log n) for recursive
 */

/**
 * Performs binary search on a sorted array using iterative approach.
 * 
 * @param {Array} arr - Sorted array of comparable elements
 * @param {*} target - Element to search for
 * @returns {number} Index of target if found, -1 otherwise
 * 
 * @example
 * binarySearch([1, 3, 5, 7, 9], 5)
 * // Returns: 2
 * 
 * @example
 * binarySearch([1, 3, 5, 7, 9], 6)
 * // Returns: -1
 */
function binarySearch(arr, target) {
    if (!Array.isArray(arr) || arr.length === 0) {
        return -1;
    }
    
    let left = 0;
    let right = arr.length - 1;
    
    while (left <= right) {
        // Use Math.floor to avoid potential floating point issues
        const mid = left + Math.floor((right - left) / 2);
        
        if (arr[mid] === target) {
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
 * Performs binary search on a sorted array using recursive approach.
 * 
 * @param {Array} arr - Sorted array of comparable elements
 * @param {*} target - Element to search for
 * @param {number} left - Left boundary (used internally)
 * @param {number} right - Right boundary (used internally)
 * @returns {number} Index of target if found, -1 otherwise
 */
function binarySearchRecursive(arr, target, left = 0, right = null) {
    if (!Array.isArray(arr) || arr.length === 0) {
        return -1;
    }
    
    if (right === null) {
        right = arr.length - 1;
    }
    
    if (left > right) {
        return -1;
    }
    
    const mid = left + Math.floor((right - left) / 2);
    
    if (arr[mid] === target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right);
    } else {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
}

/**
 * Binary search with step-by-step visualization.
 * 
 * @param {Array} arr - Sorted array to search in
 * @param {*} target - Element to search for
 * @returns {Object} Object containing index and steps taken
 */
function binarySearchVerbose(arr, target) {
    if (!Array.isArray(arr) || arr.length === 0) {
        console.log('Empty array provided');
        return { index: -1, steps: 0 };
    }
    
    let left = 0;
    let right = arr.length - 1;
    let steps = 0;
    
    console.log(`Searching for ${target} in array: [${arr.join(', ')}]`);
    console.log(`Array length: ${arr.length}`);
    
    while (left <= right) {
        steps++;
        const mid = left + Math.floor((right - left) / 2);
        
        console.log(`\nStep ${steps}:`);
        console.log(`  left=${left}, right=${right}, mid=${mid}`);
        console.log(`  arr[${mid}] = ${arr[mid]}`);
        
        if (arr[mid] === target) {
            console.log(`  Target found at index ${mid}!`);
            return { index: mid, steps };
        } else if (arr[mid] < target) {
            console.log(`  ${arr[mid]} < ${target}, search right half`);
            left = mid + 1;
        } else {
            console.log(`  ${arr[mid]} > ${target}, search left half`);
            right = mid - 1;
        }
    }
    
    console.log(`\nTarget ${target} not found in array after ${steps} steps`);
    return { index: -1, steps };
}

/**
 * Find the first occurrence of target in a sorted array with duplicates.
 * 
 * @param {Array} arr - Sorted array that may contain duplicates
 * @param {*} target - Element to search for
 * @returns {number} Index of first occurrence, -1 if not found
 */
function binarySearchFirstOccurrence(arr, target) {
    if (!Array.isArray(arr) || arr.length === 0) {
        return -1;
    }
    
    let left = 0;
    let right = arr.length - 1;
    let result = -1;
    
    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);
        
        if (arr[mid] === target) {
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
 * Find the last occurrence of target in a sorted array with duplicates.
 * 
 * @param {Array} arr - Sorted array that may contain duplicates
 * @param {*} target - Element to search for
 * @returns {number} Index of last occurrence, -1 if not found
 */
function binarySearchLastOccurrence(arr, target) {
    if (!Array.isArray(arr) || arr.length === 0) {
        return -1;
    }
    
    let left = 0;
    let right = arr.length - 1;
    let result = -1;
    
    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);
        
        if (arr[mid] === target) {
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
 * Find the range [first_index, last_index] of target in sorted array.
 * 
 * @param {Array} arr - Sorted array that may contain duplicates
 * @param {*} target - Element to search for
 * @returns {Array} [first_index, last_index] or [-1, -1] if not found
 */
function binarySearchRange(arr, target) {
    const first = binarySearchFirstOccurrence(arr, target);
    if (first === -1) {
        return [-1, -1];
    }
    
    const last = binarySearchLastOccurrence(arr, target);
    return [first, last];
}

/**
 * Find the insertion point for target to maintain sorted order.
 * 
 * @param {Array} arr - Sorted array
 * @param {*} target - Element to find insertion point for
 * @returns {number} Index where target should be inserted
 */
function binarySearchInsertionPoint(arr, target) {
    if (!Array.isArray(arr) || arr.length === 0) {
        return 0;
    }
    
    let left = 0;
    let right = arr.length;
    
    while (left < right) {
        const mid = left + Math.floor((right - left) / 2);
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

/**
 * Async version of binary search with delays for visualization.
 * 
 * @param {Array} arr - Sorted array to search in
 * @param {*} target - Element to search for
 * @param {number} delay - Delay in milliseconds between each step
 * @param {Function} onStep - Callback function called after each step
 * @returns {Promise<number>} Promise resolving to index or -1
 */
async function binarySearchAsync(arr, target, delay = 500, onStep = null) {
    if (!Array.isArray(arr) || arr.length === 0) {
        return -1;
    }
    
    let left = 0;
    let right = arr.length - 1;
    let steps = 0;
    
    while (left <= right) {
        steps++;
        const mid = left + Math.floor((right - left) / 2);
        
        if (onStep) {
            onStep({
                step: steps,
                left,
                right,
                mid,
                value: arr[mid],
                target,
                comparison: arr[mid] === target ? 'equal' : 
                           arr[mid] < target ? 'less' : 'greater'
            });
        }
        
        if (delay > 0) {
            await new Promise(resolve => setTimeout(resolve, delay));
        }
        
        if (arr[mid] === target) {
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
 * Performance test for binary search.
 * 
 * @param {Array} arr - Array to search in
 * @param {*} target - Element to search for
 * @returns {Object} Performance metrics
 */
function binarySearchPerformance(arr, target) {
    const startTime = performance.now();
    const result = binarySearch(arr, target);
    const endTime = performance.now();
    
    return {
        index: result,
        executionTime: endTime - startTime,
        arraySize: arr.length,
        timeComplexity: `O(log ${arr.length}) ≈ ${Math.ceil(Math.log2(arr.length))} max steps`
    };
}

// Export functions for use in other modules
if (typeof module !== 'undefined' && module.exports) {
    module.exports = {
        binarySearch,
        binarySearchRecursive,
        binarySearchVerbose,
        binarySearchFirstOccurrence,
        binarySearchLastOccurrence,
        binarySearchRange,
        binarySearchInsertionPoint,
        binarySearchAsync,
        binarySearchPerformance
    };
}

// Example usage and testing (only runs in browser or when file is run directly)
if (typeof window !== 'undefined' || (typeof require !== 'undefined' && require.main === module)) {
    console.log('=== Binary Search Examples ===');
    
    const testCases = [
        { arr: [1, 3, 5, 7, 9, 11, 13, 15, 17, 19], target: 7, description: 'Element in middle' },
        { arr: [1, 3, 5, 7, 9, 11, 13, 15, 17, 19], target: 1, description: 'First element' },
        { arr: [1, 3, 5, 7, 9, 11, 13, 15, 17, 19], target: 19, description: 'Last element' },
        { arr: [1, 3, 5, 7, 9, 11, 13, 15, 17, 19], target: 6, description: 'Element not found' },
        { arr: [42], target: 42, description: 'Single element found' },
        { arr: [42], target: 10, description: 'Single element not found' },
        { arr: [], target: 5, description: 'Empty array' }
    ];
    
    testCases.forEach((testCase, index) => {
        console.log(`\nTest ${index + 1}: ${testCase.description}`);
        console.log(`Array: [${testCase.arr.join(', ')}], Target: ${testCase.target}`);
        const result = binarySearch(testCase.arr, testCase.target);
        console.log(`Result: ${result === -1 ? 'Not found' : `Found at index ${result}`}`);
    });
    
    console.log('\n=== Recursive Binary Search ===');
    const arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19];
    const target = 7;
    const recursiveResult = binarySearchRecursive(arr, target);
    console.log(`Recursive search for ${target}: ${recursiveResult === -1 ? 'Not found' : `Found at index ${recursiveResult}`}`);
    
    console.log('\n=== Verbose Example ===');
    binarySearchVerbose([1, 3, 5, 7, 9, 11, 13, 15, 17, 19], 7);
    
    console.log('\n=== Duplicate Handling ===');
    const arrWithDups = [1, 2, 2, 2, 2, 3, 4, 5];
    const dupTarget = 2;
    const first = binarySearchFirstOccurrence(arrWithDups, dupTarget);
    const last = binarySearchLastOccurrence(arrWithDups, dupTarget);
    const range = binarySearchRange(arrWithDups, dupTarget);
    
    console.log(`Array: [${arrWithDups.join(', ')}]`);
    console.log(`Target: ${dupTarget}`);
    console.log(`First occurrence: ${first}`);
    console.log(`Last occurrence: ${last}`);
    console.log(`Range: [${range.join(', ')}]`);
    
    console.log('\n=== Insertion Point ===');
    const insertArr = [1, 3, 5, 7, 9];
    const insertTargets = [0, 2, 4, 6, 8, 10];
    console.log(`Array: [${insertArr.join(', ')}]`);
    insertTargets.forEach(insertTarget => {
        const pos = binarySearchInsertionPoint(insertArr, insertTarget);
        console.log(`Insert ${insertTarget} at position ${pos}`);
    });
    
    console.log('\n=== Performance Test ===');
    const perfArray = Array.from({ length: 10000 }, (_, i) => i * 2);
    const perfTarget = 9998;
    const perfResult = binarySearchPerformance(perfArray, perfTarget);
    console.log(`Searched array of ${perfResult.arraySize} elements`);
    console.log(`Found ${perfTarget} at index ${perfResult.index}`);
    console.log(`Execution time: ${perfResult.executionTime.toFixed(4)}ms`);
    console.log(`Time complexity: ${perfResult.timeComplexity}`);
}