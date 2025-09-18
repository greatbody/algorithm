/**
 * Stack Demo Program in C
 * C语言栈演示程序
 *
 * This program demonstrates the usage of the Stack implementation
 * 本程序演示栈实现的使用方法
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Utility functions for demonstration
bool balanced_parentheses(const char* expression);
double evaluate_postfix(const char* expression);

// Demo function for basic stack operations
void demo_basic_operations(void) {
    printf("=== Basic Stack Operations ===\n");

    Stack stack;
    if (stack_init(&stack, 0) != STACK_SUCCESS) {
        printf("Failed to initialize stack\n");
        return;
    }

    printf("Empty stack: %s\n", stack_is_empty(&stack) ? "true" : "false");
    printf("Size: %zu\n", stack_size(&stack));

    // Push elements
    int values[] = {10, 20, 30, 40, 50};
    for (size_t i = 0; i < sizeof(values)/sizeof(values[0]); i++) {
        int* val = (int*)malloc(sizeof(int));
        *val = values[i];
        if (stack_push(&stack, val) == STACK_SUCCESS) {
            printf("Pushed %d, size: %zu\n", values[i], stack_size(&stack));
        }
    }

    // Peek at top
    void* peeked;
    if (stack_peek(&stack, &peeked) == STACK_SUCCESS) {
        printf("Top element (peek): %d\n", *(int*)peeked);
    }

    // Pop elements
    printf("Popping elements:\n");
    while (!stack_is_empty(&stack)) {
        void* popped;
        if (stack_pop(&stack, &popped) == STACK_SUCCESS) {
            printf("Popped %d, size: %zu\n", *(int*)popped, stack_size(&stack));
            free(popped);
        }
    }

    stack_destroy(&stack);
    printf("\n");
}

// Demo function for stack with capacity limit
void demo_capacity_limit(void) {
    printf("=== Stack with Capacity Limit ===\n");

    Stack stack;
    if (stack_init(&stack, 3) != STACK_SUCCESS) {
        printf("Failed to initialize stack\n");
        return;
    }

    printf("Stack capacity: %zu\n", stack_capacity(&stack));

    // Try to push more than capacity
    for (int i = 1; i <= 5; i++) {
        int* val = (int*)malloc(sizeof(int));
        *val = i * 10;
        StackResult result = stack_push(&stack, val);
        if (result == STACK_SUCCESS) {
            printf("Pushed %d, size: %zu\n", *val, stack_size(&stack));
        } else if (result == STACK_ERROR_OVERFLOW) {
            printf("Failed to push %d: Stack overflow\n", *val);
            free(val);
        }
    }

    // Clean up
    while (!stack_is_empty(&stack)) {
        void* popped;
        stack_pop(&stack, &popped);
        free(popped);
    }

    stack_destroy(&stack);
    printf("\n");
}

// Demo function for balanced parentheses
void demo_balanced_parentheses(void) {
    printf("=== Balanced Parentheses Check ===\n");

    const char* test_cases[] = {
        "(())",
        "((()))",
        "((())",
        "{[()]}",
        "{[(])}",
        "",
        "(()())",
        "((a + b) * (c - d))"
    };

    for (size_t i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); i++) {
        bool result = balanced_parentheses(test_cases[i]);
        printf("'%s' is %sbalanced\n", test_cases[i],
               result ? "" : "not ");
    }

    printf("\n");
}

// Demo function for postfix evaluation
void demo_postfix_evaluation(void) {
    printf("=== Postfix Expression Evaluation ===\n");

    const char* expressions[] = {
        "3 4 + 2 * 7 /",    // ((3 + 4) * 2) / 7 = 2.0
        "5 2 - 3 *",        // (5 - 2) * 3 = 9.0
        "4 2 / 3 +",        // (4 / 2) + 3 = 5.0
        "2 3 4 * +",        // 2 + (3 * 4) = 14.0
        "6 2 / 3 4 * +",    // (6 / 2) + (3 * 4) = 15.0
    };

    for (size_t i = 0; i < sizeof(expressions)/sizeof(expressions[0]); i++) {
        double result = evaluate_postfix(expressions[i]);
        if (result != -999999.0) {  // Error indicator
            printf("'%s' = %.2f\n", expressions[i], result);
        }
    }

    printf("\n");
}

// Utility function implementations
bool balanced_parentheses(const char* expression) {
    if (expression == NULL) return false;

    Stack stack;
    if (stack_init(&stack, 0) != STACK_SUCCESS) {
        return false;
    }

    bool balanced = true;

    for (size_t i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            char* bracket = (char*)malloc(sizeof(char));
            *bracket = ch;
            if (stack_push(&stack, bracket) != STACK_SUCCESS) {
                balanced = false;
                break;
            }
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack_is_empty(&stack)) {
                balanced = false;
                break;
            }

            void* top;
            if (stack_pop(&stack, &top) != STACK_SUCCESS) {
                balanced = false;
                break;
            }

            char top_char = *(char*)top;
            free(top);

            if ((ch == ')' && top_char != '(') ||
                (ch == ']' && top_char != '[') ||
                (ch == '}' && top_char != '{')) {
                balanced = false;
                break;
            }
        }
    }

    balanced = balanced && stack_is_empty(&stack);

    // Clean up remaining elements
    while (!stack_is_empty(&stack)) {
        void* popped;
        stack_pop(&stack, &popped);
        free(popped);
    }

    stack_destroy(&stack);
    return balanced;
}

double evaluate_postfix(const char* expression) {
    if (expression == NULL) return -999999.0;

    Stack stack;
    if (stack_init(&stack, 0) != STACK_SUCCESS) {
        return -999999.0;
    }

    char* expr_copy = strdup(expression);
    if (expr_copy == NULL) {
        stack_destroy(&stack);
        return -999999.0;
    }

    char* token = strtok(expr_copy, " ");
    double result = -999999.0;

    while (token != NULL) {
        // Check if token is a number
        char* endptr;
        double num = strtod(token, &endptr);

        if (*endptr == '\0') {
            // It's a number
            double* val = (double*)malloc(sizeof(double));
            *val = num;
            if (stack_push(&stack, val) != STACK_SUCCESS) {
                goto cleanup;
            }
        } else if (strlen(token) == 1) {
            // It's an operator
            char op = token[0];

            if (stack_size(&stack) < 2) {
                goto cleanup;
            }

            void* op2_ptr, *op1_ptr;
            if (stack_pop(&stack, &op2_ptr) != STACK_SUCCESS ||
                stack_pop(&stack, &op1_ptr) != STACK_SUCCESS) {
                goto cleanup;
            }

            double op1 = *(double*)op1_ptr;
            double op2 = *(double*)op2_ptr;
            free(op1_ptr);
            free(op2_ptr);

            double* res = (double*)malloc(sizeof(double));

            switch (op) {
                case '+':
                    *res = op1 + op2;
                    break;
                case '-':
                    *res = op1 - op2;
                    break;
                case '*':
                    *res = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        free(res);
                        goto cleanup;
                    }
                    *res = op1 / op2;
                    break;
                default:
                    free(res);
                    goto cleanup;
            }

            if (stack_push(&stack, res) != STACK_SUCCESS) {
                free(res);
                goto cleanup;
            }
        } else {
            // Invalid token
            goto cleanup;
        }

        token = strtok(NULL, " ");
    }

    // Final result should be the only element in stack
    if (stack_size(&stack) == 1) {
        void* res_ptr;
        if (stack_pop(&stack, &res_ptr) == STACK_SUCCESS) {
            result = *(double*)res_ptr;
            free(res_ptr);
        }
    }

cleanup:
    // Clean up stack
    while (!stack_is_empty(&stack)) {
        void* popped;
        stack_pop(&stack, &popped);
        free(popped);
    }

    stack_destroy(&stack);
    free(expr_copy);
    return result;
}

int main(void) {
    printf("Stack Implementation Demo in C\n");
    printf("==============================\n\n");

    demo_basic_operations();
    demo_capacity_limit();
    demo_balanced_parentheses();
    demo_postfix_evaluation();

    printf("Demo completed successfully!\n");
    return 0;
}