/**
 * Stack Implementation in C
 * 栈的C语言实现
 *
 * Time Complexity:
 * - Push: O(1)
 * - Pop: O(1)
 * - Peek: O(1)
 * - isEmpty: O(1)
 * - Size: O(1)
 *
 * Space Complexity: O(n) where n is the number of elements
 */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Stack structure
 * 栈结构体
 */
typedef struct {
    void** items;        // Array of void pointers for generic storage
    size_t size;         // Current number of elements
    size_t capacity;     // Maximum capacity (0 = unlimited)
} Stack;

/**
 * Stack operation result codes
 * 栈操作结果码
 */
typedef enum {
    STACK_SUCCESS = 0,
    STACK_ERROR_NULL_POINTER = -1,
    STACK_ERROR_OVERFLOW = -2,
    STACK_ERROR_UNDERFLOW = -3,
    STACK_ERROR_MEMORY = -4,
    STACK_ERROR_INVALID_ARGUMENT = -5
} StackResult;

/**
 * Initialize a new stack
 * 初始化新栈
 *
 * @param stack Pointer to stack structure to initialize
 * @param initial_capacity Initial capacity (0 for unlimited)
 * @return STACK_SUCCESS on success, error code otherwise
 */
StackResult stack_init(Stack* stack, size_t initial_capacity);

/**
 * Destroy a stack and free its resources
 * 销毁栈并释放资源
 *
 * @param stack Pointer to stack to destroy
 * @return STACK_SUCCESS on success, error code otherwise
 */
StackResult stack_destroy(Stack* stack);

/**
 * Push an element onto the stack
 * 将元素压入栈
 *
 * @param stack Pointer to stack
 * @param item Pointer to item to push (will be stored as void*)
 * @return STACK_SUCCESS on success, error code otherwise
 */
StackResult stack_push(Stack* stack, void* item);

/**
 * Pop an element from the stack
 * 从栈中弹出元素
 *
 * @param stack Pointer to stack
 * @param item Pointer to store the popped item
 * @return STACK_SUCCESS on success, error code otherwise
 */
StackResult stack_pop(Stack* stack, void** item);

/**
 * Peek at the top element without removing it
 * 查看栈顶元素但不移除
 *
 * @param stack Pointer to stack
 * @param item Pointer to store the peeked item
 * @return STACK_SUCCESS on success, error code otherwise
 */
StackResult stack_peek(const Stack* stack, void** item);

/**
 * Check if the stack is empty
 * 检查栈是否为空
 *
 * @param stack Pointer to stack
 * @return true if empty, false otherwise
 */
bool stack_is_empty(const Stack* stack);

/**
 * Get the current size of the stack
 * 获取栈的当前大小
 *
 * @param stack Pointer to stack
 * @return Current number of elements
 */
size_t stack_size(const Stack* stack);

/**
 * Get the capacity of the stack
 * 获取栈的容量
 *
 * @param stack Pointer to stack
 * @return Capacity (0 = unlimited)
 */
size_t stack_capacity(const Stack* stack);

/**
 * Clear all elements from the stack
 * 清空栈中的所有元素
 *
 * @param stack Pointer to stack
 * @return STACK_SUCCESS on success, error code otherwise
 */
StackResult stack_clear(Stack* stack);

/**
 * Convert stack to array (bottom to top)
 * 将栈转换为数组（从底部到顶部）
 *
 * @param stack Pointer to stack
 * @param array Output array (must be pre-allocated)
 * @param array_size Size of output array
 * @return STACK_SUCCESS on success, error code otherwise
 */
StackResult stack_to_array(const Stack* stack, void** array, size_t array_size);

#ifdef __cplusplus
}
#endif

#endif /* STACK_H */