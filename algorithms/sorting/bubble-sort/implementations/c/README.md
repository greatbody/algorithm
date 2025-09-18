# Bubble Sort - C Implementation

## 冒泡排序 - C语言实现

This directory contains a complete C implementation of the Bubble Sort algorithm, following the same patterns and structure as other implementations in the repository.

本目录包含冒泡排序算法的完整C语言实现，遵循仓库中其他实现的相同模式和结构。

## Features

### 功能特性

- **Basic Bubble Sort**: Standard ascending order sorting
- **Descending Sort**: Sort arrays in descending order
- **Result Tracking**: Track comparisons and swaps performed
- **Generic Sort**: Support for any data type with custom comparison
- **Utility Functions**: Array validation and copying utilities
- **Comprehensive Tests**: Full test coverage using Unity framework
- **Demo Program**: Interactive demonstration of all features

- **基础冒泡排序**：标准的升序排序
- **降序排序**：对数组进行降序排序
- **结果跟踪**：跟踪执行的比较和交换次数
- **通用排序**：支持任何数据类型，使用自定义比较函数
- **实用工具函数**：数组验证和复制工具
- **全面测试**：使用Unity框架的完整测试覆盖
- **演示程序**：所有功能的交互式演示

## Algorithm Complexity

### 算法复杂度

- **Time Complexity**: O(n²) - Quadratic time complexity
- **Space Complexity**: O(1) - In-place sorting algorithm
- **Best Case**: O(n) - When array is already sorted (early termination)
- **Worst Case**: O(n²) - When array is reverse sorted

- **时间复杂度**：O(n²) - 二次时间复杂度
- **空间复杂度**：O(1) - 原地排序算法
- **最佳情况**：O(n) - 当数组已排序时（提前终止）
- **最坏情况**：O(n²) - 当数组逆序排序时

## Files Structure

### 文件结构

```
c/
├── bubble_sort.h          # Header file with function declarations
├── bubble_sort.c          # Main implementation
├── test_bubble_sort.c     # Unit tests using Unity framework
├── main.c                 # Demo program
├── Makefile               # Build system
├── unity.h                # Unity testing framework header
├── unity.c                # Unity testing framework implementation
├── unity_internals.h      # Unity internal header
├── build/                 # Build artifacts directory
└── bin/                   # Executable binaries directory
```

## API Reference

### API参考

### Core Functions

#### 核心函数

```c
bool bubble_sort(int* arr, size_t length);
```
Sorts an integer array in ascending order using bubble sort.
使用冒泡排序对整数数组进行升序排序。

```c
bool bubble_sort_descending(int* arr, size_t length);
```
Sorts an integer array in descending order using bubble sort.
使用冒泡排序对整数数组进行降序排序。

```c
bool bubble_sort_with_result(int* arr, size_t length, BubbleSortResult* result);
```
Sorts an array and tracks the number of comparisons and swaps performed.
对数组进行排序并跟踪执行的比较和交换次数。

### Utility Functions

#### 实用工具函数

```c
bool is_sorted_ascending(const int* arr, size_t length);
```
Checks if an array is sorted in ascending order.
检查数组是否按升序排序。

```c
bool is_sorted_descending(const int* arr, size_t length);
```
Checks if an array is sorted in descending order.
检查数组是否按降序排序。

```c
int* array_copy(const int* source, size_t length);
```
Creates a copy of an integer array.
创建整数数组的副本。

```c
void print_array(const int* arr, size_t length);
```
Prints an integer array to stdout.
将整数数组打印到标准输出。

## Building and Running

### 构建和运行

### Prerequisites

#### 先决条件

- GCC compiler with C99 support
- Make build system
- GCC编译器，支持C99标准
- Make构建系统

### Build Commands

#### 构建命令

```bash
# Build all targets (tests and demo)
make all

# Build and run unit tests
make test

# Build and run demo program
make demo

# Clean build artifacts
make clean

# Show help
make help
```

### Run Commands

#### 运行命令

```bash
# Run unit tests
make run

# Run demo program
make run-demo
```

## Test Coverage

### 测试覆盖

The implementation includes comprehensive unit tests covering:

实现包括全面的单元测试，涵盖：

- Basic sorting functionality
- Descending order sorting
- Edge cases (empty arrays, single elements, already sorted)
- Result tracking accuracy
- Generic sorting framework
- Utility function correctness
- Error handling

- 基础排序功能
- 降序排序
- 边界情况（空数组、单个元素、已排序）
- 结果跟踪准确性
- 通用排序框架
- 实用工具函数正确性
- 错误处理

## Example Usage

### 使用示例

```c
#include "bubble_sort.h"
#include <stdio.h>

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    print_array(arr, length);
    printf("\n");

    if (bubble_sort(arr, length)) {
        printf("Sorted:   ");
        print_array(arr, length);
        printf("\n");
    }

    return 0;
}
```

## Memory Management

### 内存管理

- All functions handle NULL inputs gracefully
- Array copying functions allocate memory that must be freed by the caller
- No memory leaks in normal operation
- Functions return false on memory allocation failures

- 所有函数都能优雅地处理NULL输入
- 数组复制函数分配的内存必须由调用者释放
- 正常操作中无内存泄漏
- 内存分配失败时函数返回false

## Error Handling

### 错误处理

- NULL pointer checks for all input parameters
- Memory allocation failure handling
- Invalid input validation
- Consistent error return values (false on error, true on success)

- 对所有输入参数进行NULL指针检查
- 内存分配失败处理
- 无效输入验证
- 一致的错误返回值（错误时返回false，成功时返回true）

## Optimization Features

### 优化特性

- **Early Termination**: Stops when no swaps occur in a pass (array already sorted)
- **In-place Sorting**: No additional memory allocation for sorting
- **Efficient for Small Arrays**: Good performance for small datasets

- **提前终止**：当一轮中没有发生交换时停止（数组已排序）
- **原地排序**：排序不需要额外的内存分配
- **小数组高效**：对小数据集性能良好

## Comparison with Other Implementations

### 与其他实现的比较

| Feature | C | Python | Java | TypeScript |
|---------|---|--------|------|------------|
| In-place | ✓ | ✓ | ✓ | ✓ |
| Generic | ✓ | ✓ | ✓ | ✓ |
| Result Tracking | ✓ | ✓ | ✓ | ✓ |
| Early Termination | ✓ | ✓ | ✓ | ✓ |
| Memory Safe | ✓ | ✓ | ✓ | ✓ |
| Performance | High | Medium | High | Medium |

## Contributing

### 贡献

When contributing to this implementation:

贡献此实现时：

1. Maintain the existing code style and patterns
2. Add comprehensive tests for new features
3. Update documentation for API changes
4. Ensure all tests pass before submitting
5. Follow the established error handling patterns

1. 保持现有的代码风格和模式
2. 为新功能添加全面的测试
3. 为API更改更新文档
4. 提交前确保所有测试通过
5. 遵循既定的错误处理模式