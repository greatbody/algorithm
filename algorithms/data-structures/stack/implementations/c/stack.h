/**
 * Simple Stack Implementation in C
 *
 * A minimal, cross-platform stack implementation
 */

#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 100

// Simple stack structure
typedef struct {
    int items[MAX_STACK_SIZE];
    int top;
} SimpleStack;

// Initialize stack
void stackInit(SimpleStack* stack);

// Check if stack is empty
int stackIsEmpty(SimpleStack* stack);

// Check if stack is full
int stackIsFull(SimpleStack* stack);

// Push element onto stack
void stackPush(SimpleStack* stack, int item);

// Pop element from stack
int stackPop(SimpleStack* stack);

// Peek at top element
int stackPeek(SimpleStack* stack);

#endif