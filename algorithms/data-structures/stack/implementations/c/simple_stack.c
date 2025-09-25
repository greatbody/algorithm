/**
 * Simple Stack Implementation in C
 *
 * A minimal, cross-platform stack implementation
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// Simple stack structure
typedef struct {
    int items[MAX_STACK_SIZE];
    int top;
} SimpleStack;

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

// Simple test function
void testStack() {
    printf("Testing Simple Stack\n");
    printf("===================\n");

    SimpleStack stack;
    stackInit(&stack);

    printf("Pushing elements: 10, 20, 30\n");
    stackPush(&stack, 10);
    stackPush(&stack, 20);
    stackPush(&stack, 30);

    printf("Top element: %d\n", stackPeek(&stack));

    printf("Popping elements:\n");
    while (!stackIsEmpty(&stack)) {
        printf("Popped: %d\n", stackPop(&stack));
    }

    printf("\n");
}

// Main function
int main() {
    printf("Simple Stack Implementation\n");
    printf("==========================\n\n");

    testStack();

    printf("Test completed!\n");
    return 0;
}