/**
 * Stack Implementation in Java
 * 栈的Java实现
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

import java.util.ArrayList;
import java.util.List;
import java.util.EmptyStackException;

/**
 * A simple stack implementation using ArrayList.
 *
 * The stack follows the Last In, First Out (LIFO) principle.
 */
public class Stack<T> {
    private List<T> items;
    private int capacity;

    /**
     * Initialize an empty stack.
     *
     * @param capacity Maximum number of elements the stack can hold.
     *                 If 0, the stack has unlimited capacity.
     */
    public Stack(int capacity) {
        this.items = new ArrayList<>();
        this.capacity = capacity;
    }

    /**
     * Initialize an empty stack with unlimited capacity.
     */
    public Stack() {
        this(0);
    }

    /**
     * Add an element to the top of the stack.
     *
     * @param item Element to be added to the stack
     * @throws IllegalStateException If stack is at maximum capacity
     */
    public void push(T item) {
        if (capacity > 0 && items.size() >= capacity) {
            throw new IllegalStateException("Stack overflow: Cannot push to full stack");
        }
        items.add(item);
    }

    /**
     * Remove and return the top element from the stack.
     *
     * @return The top element of the stack
     * @throws EmptyStackException If stack is empty
     */
    public T pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return items.remove(items.size() - 1);
    }

    /**
     * Return the top element without removing it.
     *
     * @return The top element of the stack
     * @throws EmptyStackException If stack is empty
     */
    public T peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return items.get(items.size() - 1);
    }

    /**
     * Check if the stack is empty.
     *
     * @return True if stack is empty, false otherwise
     */
    public boolean isEmpty() {
        return items.isEmpty();
    }

    /**
     * Get the number of elements in the stack.
     *
     * @return Number of elements in the stack
     */
    public int size() {
        return items.size();
    }

    /**
     * Remove all elements from the stack.
     */
    public void clear() {
        items.clear();
    }

    /**
     * Return a copy of the stack as a list (bottom to top).
     *
     * @return Copy of stack elements from bottom to top
     */
    public List<T> toList() {
        return new ArrayList<>(items);
    }

    /**
     * String representation of the stack.
     *
     * @return String representation showing stack from bottom to top
     */
    @Override
    public String toString() {
        return "Stack(" + items.toString() + ")";
    }
}

/**
 * A stack that supports getting the minimum element in O(1) time.
 */
class MinStack {
    private List<Integer> stack;
    private List<Integer> minStack;

    public MinStack() {
        this.stack = new ArrayList<>();
        this.minStack = new ArrayList<>();
    }

    /**
     * Push element to the stack and update minimum.
     *
     * @param item Element to push
     */
    public void push(int item) {
        stack.add(item);

        // Update minimum stack
        if (minStack.isEmpty() || item <= minStack.get(minStack.size() - 1)) {
            minStack.add(item);
        }
    }

    /**
     * Pop element from the stack and update minimum.
     *
     * @return The popped element
     * @throws EmptyStackException If stack is empty
     */
    public int pop() {
        if (stack.isEmpty()) {
            throw new EmptyStackException();
        }

        int popped = stack.remove(stack.size() - 1);

        // Update minimum stack
        if (popped == minStack.get(minStack.size() - 1)) {
            minStack.remove(minStack.size() - 1);
        }

        return popped;
    }

    /**
     * Get the top element without removing it.
     *
     * @return The top element
     * @throws EmptyStackException If stack is empty
     */
    public int peek() {
        if (stack.isEmpty()) {
            throw new EmptyStackException();
        }
        return stack.get(stack.size() - 1);
    }

    /**
     * Get the minimum element in O(1) time.
     *
     * @return The minimum element
     * @throws EmptyStackException If stack is empty
     */
    public int getMin() {
        if (minStack.isEmpty()) {
            throw new EmptyStackException();
        }
        return minStack.get(minStack.size() - 1);
    }

    /**
     * Check if the stack is empty.
     *
     * @return True if stack is empty, false otherwise
     */
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    /**
     * Get the number of elements in the stack.
     *
     * @return Number of elements in the stack
     */
    public int size() {
        return stack.size();
    }
}

/**
 * Utility class for stack-based algorithms.
 */
class StackUtils {
    /**
     * Check if parentheses in an expression are balanced.
     *
     * @param expression The expression to check
     * @return True if parentheses are balanced, false otherwise
     */
    public static boolean balancedParentheses(String expression) {
        Stack<Character> stack = new Stack<>();

        for (char ch : expression.toCharArray()) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            } else if (ch == ')' || ch == ']' || ch == '}') {
                if (stack.isEmpty()) {
                    return false;
                }

                char top = stack.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }

    /**
     * Evaluate a postfix expression.
     *
     * @param expression The postfix expression as a string with space-separated tokens
     * @return The result of the evaluation
     * @throws IllegalArgumentException If expression is invalid
     */
    public static int evaluatePostfix(String expression) {
        Stack<Integer> stack = new Stack<>();
        String[] tokens = expression.split("\\s+");

        for (String token : tokens) {
            if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
                if (stack.size() < 2) {
                    throw new IllegalArgumentException("Invalid postfix expression");
                }

                int b = stack.pop();
                int a = stack.pop();

                switch (token) {
                    case "+":
                        stack.push(a + b);
                        break;
                    case "-":
                        stack.push(a - b);
                        break;
                    case "*":
                        stack.push(a * b);
                        break;
                    case "/":
                        if (b == 0) {
                            throw new IllegalArgumentException("Division by zero");
                        }
                        stack.push(a / b);
                        break;
                }
            } else {
                try {
                    int num = Integer.parseInt(token);
                    stack.push(num);
                } catch (NumberFormatException e) {
                    throw new IllegalArgumentException("Invalid token: " + token);
                }
            }
        }

        if (stack.size() != 1) {
            throw new IllegalArgumentException("Invalid postfix expression");
        }

        return stack.peek();
    }
}

/**
 * Main class with comprehensive test cases.
 */
public class StackDemo {
    public static void main(String[] args) {
        System.out.println("Stack Implementation in Java");
        System.out.println("============================");

        testBasicOperations();
        testStringStack();
        testMinStack();
        testBalancedParentheses();
        testPostfixEvaluation();
        testErrorCases();

        System.out.println("\nAll tests completed!");
    }

    /**
     * Test function for basic stack operations.
     */
    public static void testBasicOperations() {
        System.out.println("=== Basic Stack Operations ===");

        Stack<Integer> stack = new Stack<>();

        // Test empty stack
        System.out.println("Empty stack: " + stack.toString());
        System.out.println("Is empty: " + stack.isEmpty());
        System.out.println("Size: " + stack.size());

        // Test push
        System.out.println("\nPushing elements...");
        stack.push(10);
        System.out.println("After push(10): " + stack.toString());
        System.out.println("Size: " + stack.size());

        stack.push(20);
        stack.push(30);
        System.out.println("After push(20), push(30): " + stack.toString());
        System.out.println("Size: " + stack.size());

        // Test peek
        System.out.println("\nPeek: " + stack.peek());
        System.out.println("Size after peek: " + stack.size());

        // Test pop
        System.out.println("\nPopping elements...");
        System.out.println("Pop: " + stack.pop());
        System.out.println("After pop: " + stack.toString());

        System.out.println("Pop: " + stack.pop());
        System.out.println("After pop: " + stack.toString());

        System.out.println("Pop: " + stack.pop());
        System.out.println("After pop: " + stack.toString());

        System.out.println("Is empty: " + stack.isEmpty());
    }

    /**
     * Test function for stack with strings.
     */
    public static void testStringStack() {
        System.out.println("\n=== String Stack ===");

        Stack<String> stack = new Stack<>();
        stack.push("hello");
        stack.push("world");
        stack.push("!");

        System.out.println("Stack: " + stack.toString());
        System.out.println("Peek: " + stack.peek());

        while (!stack.isEmpty()) {
            System.out.println("Pop: " + stack.pop());
        }
    }

    /**
     * Test function for MinStack.
     */
    public static void testMinStack() {
        System.out.println("\n=== MinStack Operations ===");

        MinStack minStack = new MinStack();
        minStack.push(5);
        System.out.println("Push 5, Min: " + minStack.getMin());

        minStack.push(3);
        System.out.println("Push 3, Min: " + minStack.getMin());

        minStack.push(7);
        System.out.println("Push 7, Min: " + minStack.getMin());

        minStack.push(2);
        System.out.println("Push 2, Min: " + minStack.getMin());

        minStack.push(8);
        System.out.println("Push 8, Min: " + minStack.getMin());

        System.out.println("Pop: " + minStack.pop() + ", Min: " + minStack.getMin());
        System.out.println("Pop: " + minStack.pop() + ", Min: " + minStack.getMin());
    }

    /**
     * Test function for balanced parentheses.
     */
    public static void testBalancedParentheses() {
        System.out.println("\n=== Balanced Parentheses ===");

        String[] testCases = {
            "()", "(())", "(()())", "((()))",
            "([])", "[{()}]", "[({})]",
            "(", ")", "(()", ")(",
            "", "a(b)c", "a(b)c)d"
        };

        for (String expr : testCases) {
            boolean result = StackUtils.balancedParentheses(expr);
            System.out.println("\"" + expr + "\" -> " + (result ? "Balanced" : "Not balanced"));
        }
    }

    /**
     * Test function for postfix evaluation.
     */
    public static void testPostfixEvaluation() {
        System.out.println("\n=== Postfix Evaluation ===");

        String[] testCases = {
            "2 3 +",      // 2 + 3 = 5
            "5 3 -",      // 5 - 3 = 2
            "4 5 6 * +",  // 4 + (5 * 6) = 34
            "7 2 /",      // 7 / 2 = 3
            "3 4 * 2 /",  // (3 * 4) / 2 = 6
            "1 2 + 3 *"   // (1 + 2) * 3 = 9
        };

        for (String expr : testCases) {
            try {
                int result = StackUtils.evaluatePostfix(expr);
                System.out.println("\"" + expr + "\" = " + result);
            } catch (Exception e) {
                System.out.println("\"" + expr + "\" -> Error: " + e.getMessage());
            }
        }
    }

    /**
     * Test function for error cases.
     */
    public static void testErrorCases() {
        System.out.println("\n=== Error Cases ===");

        Stack<Integer> stack = new Stack<>();

        // Test pop from empty stack
        try {
            stack.pop();
        } catch (EmptyStackException e) {
            System.out.println("Pop from empty stack: " + e.getMessage());
        }

        // Test peek from empty stack
        try {
            stack.peek();
        } catch (EmptyStackException e) {
            System.out.println("Peek from empty stack: " + e.getMessage());
        }

        // Test stack with capacity
        Stack<Integer> limitedStack = new Stack<>(2);
        limitedStack.push(1);
        limitedStack.push(2);

        try {
            limitedStack.push(3);
        } catch (IllegalStateException e) {
            System.out.println("Push to full stack: " + e.getMessage());
        }

        // Test invalid postfix
        try {
            StackUtils.evaluatePostfix("2 +");
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid postfix: " + e.getMessage());
        }
    }
}