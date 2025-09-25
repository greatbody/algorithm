/**
 * Simple Stack Implementation in C
 *
 * A minimal, cross-platform stack implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Initialize stack
void stackInit(SimpleStack* stack) {
    stack->top = -1;
}

// Check if stack is empty
int stackIsEmpty(SimpleStack* stack) {
    return stack->top == -1;
}

// Check if stack is full
int stackIsFull(SimpleStack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

// Push element onto stack
void stackPush(SimpleStack* stack, int item) {
    if (stackIsFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Pop element from stack
int stackPop(SimpleStack* stack) {
    if (stackIsEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Peek at top element
int stackPeek(SimpleStack* stack) {
    if (stackIsEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->items[stack->top];
}