/**
 * Stack Implementation in C - Source File
 * 栈的C语言实现 - 源文件
 */

#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Initialize a new stack
 * 初始化新栈
 */
StackResult stack_init(Stack* stack, size_t initial_capacity) {
    if (stack == NULL) {
        return STACK_ERROR_NULL_POINTER;
    }

    stack->items = NULL;
    stack->size = 0;
    stack->capacity = initial_capacity;

    if (initial_capacity > 0) {
        stack->items = (void**)malloc(initial_capacity * sizeof(void*));
        if (stack->items == NULL) {
            return STACK_ERROR_MEMORY;
        }
    }

    return STACK_SUCCESS;
}

/**
 * Destroy a stack and free its resources
 * 销毁栈并释放资源
 */
StackResult stack_destroy(Stack* stack) {
    if (stack == NULL) {
        return STACK_ERROR_NULL_POINTER;
    }

    if (stack->items != NULL) {
        free(stack->items);
        stack->items = NULL;
    }

    stack->size = 0;
    stack->capacity = 0;

    return STACK_SUCCESS;
}

/**
 * Push an element onto the stack
 * 将元素压入栈
 */
StackResult stack_push(Stack* stack, void* item) {
    if (stack == NULL) {
        return STACK_ERROR_NULL_POINTER;
    }

    // Check capacity limit
    if (stack->capacity > 0 && stack->size >= stack->capacity) {
        return STACK_ERROR_OVERFLOW;
    }

    // If unlimited capacity or need to expand
    if (stack->capacity == 0 || stack->size >= stack->capacity) {
        size_t new_capacity = (stack->capacity == 0) ? 8 : stack->capacity * 2;
        void** new_items = (void**)realloc(stack->items, new_capacity * sizeof(void*));

        if (new_items == NULL) {
            return STACK_ERROR_MEMORY;
        }

        stack->items = new_items;
        stack->capacity = new_capacity;
    }

    // Add the item
    stack->items[stack->size] = item;
    stack->size++;

    return STACK_SUCCESS;
}

/**
 * Pop an element from the stack
 * 从栈中弹出元素
 */
StackResult stack_pop(Stack* stack, void** item) {
    if (stack == NULL || item == NULL) {
        return STACK_ERROR_NULL_POINTER;
    }

    if (stack->size == 0) {
        return STACK_ERROR_UNDERFLOW;
    }

    stack->size--;
    *item = stack->items[stack->size];

    return STACK_SUCCESS;
}

/**
 * Peek at the top element without removing it
 * 查看栈顶元素但不移除
 */
StackResult stack_peek(const Stack* stack, void** item) {
    if (stack == NULL || item == NULL) {
        return STACK_ERROR_NULL_POINTER;
    }

    if (stack->size == 0) {
        return STACK_ERROR_UNDERFLOW;
    }

    *item = stack->items[stack->size - 1];

    return STACK_SUCCESS;
}

/**
 * Check if the stack is empty
 * 检查栈是否为空
 */
bool stack_is_empty(const Stack* stack) {
    return (stack == NULL) ? true : (stack->size == 0);
}

/**
 * Get the current size of the stack
 * 获取栈的当前大小
 */
size_t stack_size(const Stack* stack) {
    return (stack == NULL) ? 0 : stack->size;
}

/**
 * Get the capacity of the stack
 * 获取栈的容量
 */
size_t stack_capacity(const Stack* stack) {
    return (stack == NULL) ? 0 : stack->capacity;
}

/**
 * Clear all elements from the stack
 * 清空栈中的所有元素
 */
StackResult stack_clear(Stack* stack) {
    if (stack == NULL) {
        return STACK_ERROR_NULL_POINTER;
    }

    stack->size = 0;
    return STACK_SUCCESS;
}

/**
 * Convert stack to array (bottom to top)
 * 将栈转换为数组（从底部到顶部）
 */
StackResult stack_to_array(const Stack* stack, void** array, size_t array_size) {
    if (stack == NULL || array == NULL) {
        return STACK_ERROR_NULL_POINTER;
    }

    if (array_size < stack->size) {
        return STACK_ERROR_INVALID_ARGUMENT;
    }

    // Copy elements from bottom to top
    for (size_t i = 0; i < stack->size; i++) {
        array[i] = stack->items[i];
    }

    return STACK_SUCCESS;
}