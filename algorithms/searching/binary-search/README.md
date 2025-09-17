# Binary Search 二分查找

## Description 描述

**English:** Binary Search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing the search interval in half. If the value to be searched is less than the item in the middle of the interval, it narrows the interval to the lower half. Otherwise, it narrows it to the upper half. The search continues until the value is found or the interval is empty.

**中文：** 二分查找是一种在已排序列表中查找特定元素的高效算法。它通过反复将搜索区间分成两半来工作。如果要搜索的值小于区间中间的项，则将区间缩小到下半部分。否则，将其缩小到上半部分。搜索继续进行，直到找到值或区间为空。

## Algorithm Steps 算法步骤

**English:**
1. Initialize two pointers: `left` at the beginning (0) and `right` at the end of the array
2. Calculate the middle index: `mid = (left + right) / 2`
3. Compare the target value with the element at the middle index:
   - If equal, return the index (element found)
   - If target is less than middle element, search the left half: `right = mid - 1`
   - If target is greater than middle element, search the right half: `left = mid + 1`
4. Repeat steps 2-3 until the element is found or `left > right`
5. If `left > right`, the element is not in the array, return -1

**中文：**
1. 初始化两个指针：`left` 在开始位置（0），`right` 在数组末尾
2. 计算中间索引：`mid = (left + right) / 2`
3. 将目标值与中间索引处的元素比较：
   - 如果相等，返回索引（找到元素）
   - 如果目标小于中间元素，搜索左半部分：`right = mid - 1`
   - 如果目标大于中间元素，搜索右半部分：`left = mid + 1`
4. 重复步骤2-3，直到找到元素或 `left > right`
5. 如果 `left > right`，元素不在数组中，返回 -1

## Complexity Analysis 复杂度分析

- **Time Complexity 时间复杂度:** O(log n)
  - Best Case 最佳情况: O(1) - when the target is at the middle
  - Average Case 平均情况: O(log n)
  - Worst Case 最坏情况: O(log n) - when the target is not found or at the end
- **Space Complexity 空间复杂度:** O(1) - iterative implementation, O(log n) - recursive implementation

## Implementations 实现

### Available Languages 可用语言
- [Python](implementations/python/binary_search.py)
- [Java](implementations/java/BinarySearch.java)
- [JavaScript](implementations/javascript/binarySearch.js)
- [C++](implementations/cpp/binary_search.cpp) - See [C++ Compilation Guide](../../../../CPP_COMPILATION_GUIDE.md)
- [Go](implementations/go/binary_search.go)

### Quick Start for C++ 快速开始 (C++)
```bash
# Navigate to C++ implementation
cd implementations/cpp/

# Compile and run
g++ -std=c++17 -o binary_search binary_search.cpp
./binary_search

# Or use the provided Makefile
make run
```

## Example Usage 使用示例

### Input Array (must be sorted)
```
[1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
```

### Search for target = 7
```
Step 1: left=0, right=9, mid=4, arr[4]=9  → 7 < 9, search left half
Step 2: left=0, right=3, mid=1, arr[1]=3  → 7 > 3, search right half  
Step 3: left=2, right=3, mid=2, arr[2]=5  → 7 > 5, search right half
Step 4: left=3, right=3, mid=3, arr[3]=7  → Found! Return index 3
```

### Search for target = 6 (not found)
```
Step 1: left=0, right=9, mid=4, arr[4]=9  → 6 < 9, search left half
Step 2: left=0, right=3, mid=1, arr[1]=3  → 6 > 3, search right half
Step 3: left=2, right=3, mid=2, arr[2]=5  → 6 > 5, search right half
Step 4: left=3, right=3, mid=3, arr[3]=7  → 6 < 7, search left half
Step 5: left=3, right=2 → left > right, element not found, return -1
```

## Test Cases 测试用例

| Input Array | Target | Expected Output | Description |
|-------------|--------|----------------|-------------|
| `[1, 3, 5, 7, 9]` | `5` | `2` | Element in middle |
| `[1, 3, 5, 7, 9]` | `1` | `0` | First element |
| `[1, 3, 5, 7, 9]` | `9` | `4` | Last element |
| `[1, 3, 5, 7, 9]` | `6` | `-1` | Element not found |
| `[42]` | `42` | `0` | Single element found |
| `[42]` | `10` | `-1` | Single element not found |
| `[]` | `5` | `-1` | Empty array |

## Visual Representation 可视化表示

```
Array: [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
Target: 7

Step 1:  [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
          ^        ^              ^
         left     mid           right
         arr[mid] = 9 > 7, search left

Step 2:  [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
          ^     ^  ^
         left  mid right
         arr[mid] = 3 < 7, search right

Step 3:  [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
             ^  ^
         left/mid/right
         arr[mid] = 7 = 7, FOUND!
```

## Applications 应用场景

**English:**
- Searching in sorted databases and datasets
- Finding elements in sorted arrays or lists
- Dictionary lookups and spell checkers
- Game development (collision detection, pathfinding)
- Finding insertion points for maintaining sorted order
- Searching in rotated sorted arrays (with modifications)

**中文：**
- 在排序数据库和数据集中搜索
- 在排序数组或列表中查找元素
- 字典查找和拼写检查器
- 游戏开发（碰撞检测、路径寻找）
- 查找插入点以维护排序顺序
- 在旋转排序数组中搜索（经修改后）

## Prerequisites 前提条件

**English:**
- The array must be sorted in ascending or descending order
- Elements must be comparable (numbers, strings, etc.)
- Random access to array elements (not suitable for linked lists)

**中文：**
- 数组必须按升序或降序排序
- 元素必须可比较（数字、字符串等）
- 能够随机访问数组元素（不适用于链表）

## Advantages and Disadvantages 优缺点

### Advantages 优点
- Very efficient time complexity O(log n)
- Simple to implement and understand
- Works well with large sorted datasets
- Low space complexity for iterative implementation

### Disadvantages 缺点
- Requires sorted input data
- Not suitable for frequently changing datasets
- Requires random access to elements
- May have poor cache performance on very large arrays

## Variants 变体

### Binary Search Variants 二分查找变体
- **Lower Bound**: Find the first occurrence of a target
- **Upper Bound**: Find the position after the last occurrence
- **Binary Search on Answer**: Used in optimization problems
- **Interpolation Search**: Uses value-based estimates instead of middle

## Related Algorithms 相关算法

- [Linear Search](../linear-search/README.md) - Simple search algorithm for unsorted data
- [Ternary Search](../ternary-search/README.md) - Divides search space into three parts
- [Exponential Search](../exponential-search/README.md) - For unbounded or infinite arrays

## References 参考资料

- [Wikipedia - Binary Search Algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)
- [GeeksforGeeks - Binary Search](https://www.geeksforgeeks.org/binary-search/)
- [LeetCode Binary Search Problems](https://leetcode.com/tag/binary-search/)