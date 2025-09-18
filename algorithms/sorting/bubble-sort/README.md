# Bubble Sort 冒泡排序

## Description 描述

**English:** Bubble Sort is one of the simplest sorting algorithms to understand and implement. It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted. The algorithm gets its name from the way smaller elements "bubble" to the top of the list.

**中文：** 冒泡排序是最简单易懂的排序算法之一。它重复遍历列表，比较相邻元素，如果顺序错误就交换它们。重复遍历列表直到排序完成。该算法因较小的元素像"气泡"一样浮到列表顶部而得名。

## Algorithm Steps 算法步骤

**English:**
1. Start with the first element of the array
2. Compare adjacent elements and swap if the first is greater than the second
3. Continue this process for the entire array
4. After each complete pass, the largest element will be in its correct position
5. Repeat the process for the remaining unsorted portion
6. Stop when no swaps are made in a complete pass

**中文：**
1. 从数组的第一个元素开始
2. 比较相邻元素，如果第一个大于第二个则交换
3. 对整个数组继续此过程
4. 每次完整遍历后，最大元素将处于正确位置
5. 对剩余未排序部分重复此过程
6. 当完整遍历中没有交换时停止

## Complexity Analysis 复杂度分析

- **Time Complexity 时间复杂度:** O(n²)
  - Best Case 最佳情况: O(n) - when array is already sorted
  - Average Case 平均情况: O(n²)
  - Worst Case 最坏情况: O(n²) - when array is reverse sorted
- **Space Complexity 空间复杂度:** O(1) - only uses a constant amount of additional memory

## Implementations 实现

### Available Languages 可用语言
- [Python](implementations/python/bubble_sort.py)
- [Java](implementations/java/BubbleSort.java)
- [TypeScript (Deno)](implementations/javascript/bubbleSort.ts)
- [C++](implementations/cpp/bubble_sort.cpp)
- [Go](implementations/go/bubble_sort.go)

## Example Usage 使用示例
### TypeScript (Deno) Example
```ts
import { bubbleSort } from './implementations/javascript/bubbleSort.ts';
console.log(bubbleSort([64,34,25,12,22,11,90]));
```

Run tests (运行测试):
```
deno test implementations/javascript
```

### Input Array
```
[64, 34, 25, 12, 22, 11, 90]
```

### Step-by-step Process
```
Pass 1: [34, 25, 12, 22, 11, 64, 90]
Pass 2: [25, 12, 22, 11, 34, 64, 90]
Pass 3: [12, 22, 11, 25, 34, 64, 90]
Pass 4: [12, 11, 22, 25, 34, 64, 90]
Pass 5: [11, 12, 22, 25, 34, 64, 90]
```

### Final Result
```
[11, 12, 22, 25, 34, 64, 90]
```

## Test Cases 测试用例

| Input | Expected Output | Description |
|-------|----------------|-------------|
| `[64, 34, 25, 12, 22, 11, 90]` | `[11, 12, 22, 25, 34, 64, 90]` | Standard unsorted array |
| `[5, 2, 8, 1, 9]` | `[1, 2, 5, 8, 9]` | Small array |
| `[1, 2, 3, 4, 5]` | `[1, 2, 3, 4, 5]` | Already sorted array |
| `[5, 4, 3, 2, 1]` | `[1, 2, 3, 4, 5]` | Reverse sorted array |
| `[42]` | `[42]` | Single element |
| `[]` | `[]` | Empty array |

## Visual Representation 可视化表示

```
Initial: [64, 34, 25, 12, 22, 11, 90]
         
Step 1:   64  34 → Compare and swap
         [34, 64, 25, 12, 22, 11, 90]
         
Step 2:       64  25 → Compare and swap
         [34, 25, 64, 12, 22, 11, 90]
         
Step 3:           64  12 → Compare and swap
         [34, 25, 12, 64, 22, 11, 90]
         
... and so on until sorted
```

## Applications 应用场景

**English:**
- Educational purposes - easy to understand and implement
- Small datasets where simplicity is preferred over efficiency
- When memory usage needs to be minimal
- As a subroutine in more complex algorithms

**中文：**
- 教育目的 - 易于理解和实现
- 简单性比效率更重要的小数据集
- 需要最小内存使用时
- 作为更复杂算法中的子程序

## Advantages and Disadvantages 优缺点

### Advantages 优点
- Simple implementation
- In-place sorting (O(1) space complexity)
- Stable sorting algorithm
- Can detect if the list is already sorted

### Disadvantages 缺点
- Poor time complexity O(n²)
- More swaps compared to other algorithms
- Not suitable for large datasets

## Related Algorithms 相关算法

- [Selection Sort](../selection-sort/README.md) - Another simple O(n²) sorting algorithm
- [Insertion Sort](../insertion-sort/README.md) - More efficient simple sorting algorithm
- [Quick Sort](../quick-sort/README.md) - More efficient divide-and-conquer algorithm

## References 参考资料

- [Wikipedia - Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort)
- [GeeksforGeeks - Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)
- [Algorithm Visualizer](https://algorithm-visualizer.org/brute-force/bubble-sort)