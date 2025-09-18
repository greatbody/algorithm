# Stack 栈

## Description 描述

**English:** A Stack is a linear data structure that follows the Last In, First Out (LIFO) principle. Elements are added and removed from the same end, called the "top" of the stack. Think of it as a stack of plates - you can only add a plate to the top and remove a plate from the top.

**中文：** 栈是遵循后进先出（LIFO）原则的线性数据结构。元素从同一端添加和删除，称为栈的"顶部"。可以把它想象成一叠盘子 - 您只能在顶部添加盘子，也只能从顶部取走盘子。

## Basic Operations 基本操作

**English:**
1. **Push**: Add an element to the top of the stack
2. **Pop**: Remove and return the top element from the stack
3. **Peek/Top**: Return the top element without removing it
4. **isEmpty**: Check if the stack is empty
5. **Size**: Get the number of elements in the stack

**中文：**
1. **Push（压栈）**: 向栈顶添加一个元素
2. **Pop（弹栈）**: 移除并返回栈顶元素
3. **Peek/Top（查看栈顶）**: 返回栈顶元素但不移除它
4. **isEmpty（判空）**: 检查栈是否为空
5. **Size（大小）**: 获取栈中元素的数量

## Complexity Analysis 复杂度分析

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Push | O(1) | O(1) |
| Pop | O(1) | O(1) |
| Peek/Top | O(1) | O(1) |
| isEmpty | O(1) | O(1) |
| Size | O(1) | O(1) |

**Overall Space Complexity 总体空间复杂度:** O(n) where n is the number of elements

## Implementations 实现

### Available Languages 可用语言
- [Python](implementations/python/stack.py)
- [Java](implementations/java/Stack.java)
- [JavaScript](implementations/javascript/stack.js)
- [C++](implementations/cpp/stack.cpp)
- [Go](implementations/go/stack.go)

## Example Usage 使用示例

### Basic Operations Example
```
Stack: []

push(10) → [10]
push(20) → [10, 20]
push(30) → [10, 20, 30]

peek() → 30 (stack remains [10, 20, 30])
pop() → 30 (stack becomes [10, 20])
pop() → 20 (stack becomes [10])

isEmpty() → false
size() → 1

pop() → 10 (stack becomes [])
isEmpty() → true
```

## Test Cases 测试用例

| Operation | Expected Result | Description |
|-----------|----------------|-------------|
| `push(5), push(10), peek()` | `10` | Peek returns top element |
| `push(5), push(10), pop()` | `10` | Pop returns and removes top |
| `isEmpty()` on empty stack | `true` | Empty stack check |
| `isEmpty()` on non-empty stack | `false` | Non-empty stack check |
| `pop()` on empty stack | `Exception/Error` | Error handling |
| `peek()` on empty stack | `Exception/Error` | Error handling |

## Visual Representation 可视化表示

```
Stack Growth (Push Operations):
Step 1: push(1)    Step 2: push(2)    Step 3: push(3)
    +---+              +---+              +---+
    | 1 | ← top        | 2 | ← top        | 3 | ← top
    +---+              +---+              +---+
                       | 1 |              | 2 |
                       +---+              +---+
                                          | 1 |
                                          +---+

Stack Shrinkage (Pop Operations):
Step 1: pop() → 3   Step 2: pop() → 2   Step 3: pop() → 1
    +---+              +---+              
    | 2 | ← top        | 1 | ← top        (empty)
    +---+              +---+              
    | 1 |              
    +---+              
```

## Applications 应用场景

**English:**
- **Function Call Management**: Managing function calls and returns in programming languages
- **Expression Evaluation**: Converting infix to postfix notation, evaluating expressions
- **Undo Operations**: Implementing undo functionality in text editors, browsers
- **Balanced Parentheses**: Checking if parentheses, brackets, and braces are balanced
- **Browser History**: Back button functionality in web browsers
- **Recursion**: Converting recursive algorithms to iterative ones
- **Memory Management**: Managing local variables and function parameters

**中文：**
- **函数调用管理**: 管理编程语言中的函数调用和返回
- **表达式求值**: 中缀转后缀记法，表达式求值
- **撤销操作**: 在文本编辑器、浏览器中实现撤销功能
- **括号匹配**: 检查圆括号、方括号和花括号是否匹配
- **浏览器历史**: 网页浏览器中的后退按钮功能
- **递归**: 将递归算法转换为迭代算法
- **内存管理**: 管理局部变量和函数参数

## Implementation Types 实现类型

### Array-based Stack 基于数组的栈
- **Advantages**: Simple implementation, good cache locality
- **Disadvantages**: Fixed size (unless dynamic), potential memory waste

### Linked List-based Stack 基于链表的栈
- **Advantages**: Dynamic size, memory efficient
- **Disadvantages**: Extra memory for pointers, poor cache locality

## Common Algorithms Using Stacks 使用栈的常见算法

1. **Balanced Parentheses Checker 括号匹配检查**
2. **Infix to Postfix Conversion 中缀转后缀**
3. **Postfix Expression Evaluation 后缀表达式求值**
4. **Tower of Hanoi 汉诺塔**
5. **Depth-First Search (DFS) 深度优先搜索**

## Stack vs Other Data Structures 栈与其他数据结构对比

| Feature | Stack | Queue | Array | Linked List |
|---------|-------|-------|--------|-------------|
| Access Pattern | LIFO | FIFO | Random | Sequential |
| Main Operations | Push/Pop | Enqueue/Dequeue | Index Access | Traverse |
| Use Case | Undo, Recursion | Scheduling, BFS | General Purpose | Dynamic Size |

## Error Handling 错误处理

### Stack Underflow 栈下溢
- **Occurs when**: Trying to pop from an empty stack
- **Solutions**: Check isEmpty() before pop, return default value, throw exception

### Stack Overflow 栈上溢
- **Occurs when**: Adding elements beyond stack capacity (array-based)
- **Solutions**: Dynamic resizing, check capacity before push, throw exception

## Advanced Variations 高级变体

### Min Stack 最小栈
- Supports getting minimum element in O(1) time
- Uses auxiliary stack to track minimums

### Two Stacks in One Array 一个数组实现两个栈
- Efficient space usage
- Stacks grow towards each other from opposite ends

## Related Data Structures 相关数据结构

- [Queue](../queue/README.md) - FIFO counterpart to stack's LIFO
- [Deque](../deque/README.md) - Double-ended queue supporting both stack and queue operations
- [Linked List](../linked-list/README.md) - Can be used to implement stack

## References 参考资料

- [Wikipedia - Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [GeeksforGeeks - Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)
- [LeetCode Stack Problems](https://leetcode.com/tag/stack/)