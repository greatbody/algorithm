/**
 * Stack Implementation in C++
 * 栈的C++实现
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

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

/**
 * A simple stack implementation using std::vector.
 *
 * The stack follows the Last In, First Out (LIFO) principle.
 */
template <typename T>
class Stack {
private:
    std::vector<T> _items;
    size_t _capacity;

public:
    /**
     * Initialize an empty stack.
     *
     * @param capacity Maximum number of elements the stack can hold.
     *                 If 0, the stack has unlimited capacity.
     */
    explicit Stack(size_t capacity = 0) : _capacity(capacity) {}

    /**
     * Add an element to the top of the stack.
     *
     * @param item Element to be added to the stack
     * @throws std::overflow_error If stack is at maximum capacity
     */
    void push(const T& item) {
        if (_capacity > 0 && _items.size() >= _capacity) {
            throw std::overflow_error("Stack overflow: Cannot push to full stack");
        }
        _items.push_back(item);
    }

    /**
     * Remove and return the top element from the stack.
     *
     * @return The top element of the stack
     * @throws std::underflow_error If stack is empty
     */
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: Cannot pop from empty stack");
        }
        T top = _items.back();
        _items.pop_back();
        return top;
    }

    /**
     * Return the top element without removing it.
     *
     * @return The top element of the stack
     * @throws std::underflow_error If stack is empty
     */
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty: Cannot peek");
        }
        return _items.back();
    }

    /**
     * Check if the stack is empty.
     *
     * @return True if stack is empty, false otherwise
     */
    bool isEmpty() const {
        return _items.empty();
    }

    /**
     * Get the number of elements in the stack.
     *
     * @return Number of elements in the stack
     */
    size_t size() const {
        return _items.size();
    }

    /**
     * Remove all elements from the stack.
     */
    void clear() {
        _items.clear();
    }

    /**
     * Return a copy of the stack as a vector (bottom to top).
     *
     * @return Copy of stack elements from bottom to top
     */
    std::vector<T> toVector() const {
        return _items;
    }

    /**
     * String representation of the stack.
     *
     * @return String representation showing stack from bottom to top
     */
    std::string toString() const {
        std::ostringstream oss;
        oss << "Stack([";
        for (size_t i = 0; i < _items.size(); ++i) {
            if (i > 0) oss << ", ";
            oss << _items[i];
        }
        oss << "])";
        return oss.str();
    }
};

/**
 * A stack that supports getting the minimum element in O(1) time.
 */
class MinStack {
private:
    std::vector<int> _stack;
    std::vector<int> _minStack;

public:
    MinStack() = default;

    /**
     * Push element to the stack and update minimum.
     *
     * @param item Element to push
     */
    void push(int item) {
        _stack.push_back(item);

        // Update minimum stack
        if (_minStack.empty() || item <= _minStack.back()) {
            _minStack.push_back(item);
        }
    }

    /**
     * Pop element from the stack and update minimum.
     *
     * @return The popped element
     * @throws std::underflow_error If stack is empty
     */
    int pop() {
        if (_stack.empty()) {
            throw std::underflow_error("Stack is empty");
        }

        int popped = _stack.back();
        _stack.pop_back();

        // Update minimum stack
        if (popped == _minStack.back()) {
            _minStack.pop_back();
        }

        return popped;
    }

    /**
     * Get the top element without removing it.
     *
     * @return The top element
     * @throws std::underflow_error If stack is empty
     */
    int peek() const {
        if (_stack.empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return _stack.back();
    }

    /**
     * Get the minimum element in O(1) time.
     *
     * @return The minimum element
     * @throws std::underflow_error If stack is empty
     */
    int getMin() const {
        if (_minStack.empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return _minStack.back();
    }

    /**
     * Check if the stack is empty.
     *
     * @return True if stack is empty, false otherwise
     */
    bool isEmpty() const {
        return _stack.empty();
    }

    /**
     * Get the number of elements in the stack.
     *
     * @return Number of elements in the stack
     */
    size_t size() const {
        return _stack.size();
    }
};

/**
 * Check if parentheses in an expression are balanced.
 *
 * @param expression The expression to check
 * @return True if parentheses are balanced, false otherwise
 */
bool balancedParentheses(const std::string& expression) {
    Stack<char> stack;

    for (char ch : expression) {
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
 * @throws std::invalid_argument If expression is invalid
 */
int evaluatePostfix(const std::string& expression) {
    Stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                throw std::invalid_argument("Invalid postfix expression");
            }

            int b = stack.pop();
            int a = stack.pop();

            if (token == "+") {
                stack.push(a + b);
            } else if (token == "-") {
                stack.push(a - b);
            } else if (token == "*") {
                stack.push(a * b);
            } else if (token == "/") {
                if (b == 0) {
                    throw std::invalid_argument("Division by zero");
                }
                stack.push(a / b);
            }
        } else {
            try {
                int num = std::stoi(token);
                stack.push(num);
            } catch (const std::invalid_argument&) {
                throw std::invalid_argument("Invalid token: " + token);
            }
        }
    }

    if (stack.size() != 1) {
        throw std::invalid_argument("Invalid postfix expression");
    }

    return stack.peek();
}

/**
 * Helper function to print a vector.
 */
template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << vec[i];
    }
    std::cout << "]";
}

/**
 * Test function for basic stack operations.
 */
void testBasicOperations() {
    std::cout << "=== Basic Stack Operations ===" << std::endl;

    Stack<int> stack;

    // Test empty stack
    std::cout << "Empty stack: " << stack.toString() << std::endl;
    std::cout << "Is empty: " << (stack.isEmpty() ? "true" : "false") << std::endl;
    std::cout << "Size: " << stack.size() << std::endl;

    // Test push
    std::cout << "\nPushing elements..." << std::endl;
    stack.push(10);
    std::cout << "After push(10): " << stack.toString() << std::endl;
    std::cout << "Size: " << stack.size() << std::endl;

    stack.push(20);
    stack.push(30);
    std::cout << "After push(20), push(30): " << stack.toString() << std::endl;
    std::cout << "Size: " << stack.size() << std::endl;

    // Test peek
    std::cout << "\nPeek: " << stack.peek() << std::endl;
    std::cout << "Size after peek: " << stack.size() << std::endl;

    // Test pop
    std::cout << "\nPopping elements..." << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "After pop: " << stack.toString() << std::endl;

    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "After pop: " << stack.toString() << std::endl;

    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "After pop: " << stack.toString() << std::endl;

    std::cout << "Is empty: " << (stack.isEmpty() ? "true" : "false") << std::endl;
}

/**
 * Test function for stack with strings.
 */
void testStringStack() {
    std::cout << "\n=== String Stack ===" << std::endl;

    Stack<std::string> stack;
    stack.push("hello");
    stack.push("world");
    stack.push("!");

    std::cout << "Stack: " << stack.toString() << std::endl;
    std::cout << "Peek: " << stack.peek() << std::endl;

    while (!stack.isEmpty()) {
        std::cout << "Pop: " << stack.pop() << std::endl;
    }
}

/**
 * Test function for MinStack.
 */
void testMinStack() {
    std::cout << "\n=== MinStack Operations ===" << std::endl;

    MinStack minStack;
    minStack.push(5);
    std::cout << "Push 5, Min: " << minStack.getMin() << std::endl;

    minStack.push(3);
    std::cout << "Push 3, Min: " << minStack.getMin() << std::endl;

    minStack.push(7);
    std::cout << "Push 7, Min: " << minStack.getMin() << std::endl;

    minStack.push(2);
    std::cout << "Push 2, Min: " << minStack.getMin() << std::endl;

    minStack.push(8);
    std::cout << "Push 8, Min: " << minStack.getMin() << std::endl;

    std::cout << "Pop: " << minStack.pop() << ", Min: " << minStack.getMin() << std::endl;
    std::cout << "Pop: " << minStack.pop() << ", Min: " << minStack.getMin() << std::endl;
}

/**
 * Test function for balanced parentheses.
 */
void testBalancedParentheses() {
    std::cout << "\n=== Balanced Parentheses ===" << std::endl;

    std::vector<std::string> testCases = {
        "()", "(())", "(()())", "((()))",
        "([])", "[{()}]", "[({})]",
        "(", ")", "(()", ")(",
        "", "a(b)c", "a(b)c)d"
    };

    for (const auto& expr : testCases) {
        bool result = balancedParentheses(expr);
        std::cout << "\"" << expr << "\" -> " << (result ? "Balanced" : "Not balanced") << std::endl;
    }
}

/**
 * Test function for postfix evaluation.
 */
void testPostfixEvaluation() {
    std::cout << "\n=== Postfix Evaluation ===" << std::endl;

    std::vector<std::string> testCases = {
        "2 3 +",      // 2 + 3 = 5
        "5 3 -",      // 5 - 3 = 2
        "4 5 6 * +",  // 4 + (5 * 6) = 34
        "7 2 /",      // 7 / 2 = 3
        "3 4 * 2 /",  // (3 * 4) / 2 = 6
        "1 2 + 3 *",  // (1 + 2) * 3 = 9
    };

    for (const auto& expr : testCases) {
        try {
            int result = evaluatePostfix(expr);
            std::cout << "\"" << expr << "\" = " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << "\"" << expr << "\" -> Error: " << e.what() << std::endl;
        }
    }
}

/**
 * Test function for error cases.
 */
void testErrorCases() {
    std::cout << "\n=== Error Cases ===" << std::endl;

    Stack<int> stack;

    // Test pop from empty stack
    try {
        stack.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Pop from empty stack: " << e.what() << std::endl;
    }

    // Test peek from empty stack
    try {
        stack.peek();
    } catch (const std::underflow_error& e) {
        std::cout << "Peek from empty stack: " << e.what() << std::endl;
    }

    // Test stack with capacity
    Stack<int> limitedStack(2);
    limitedStack.push(1);
    limitedStack.push(2);

    try {
        limitedStack.push(3);
    } catch (const std::overflow_error& e) {
        std::cout << "Push to full stack: " << e.what() << std::endl;
    }

    // Test invalid postfix
    try {
        evaluatePostfix("2 +");
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid postfix: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Stack Implementation in C++" << std::endl;
    std::cout << "==========================" << std::endl;

    testBasicOperations();
    testStringStack();
    testMinStack();
    testBalancedParentheses();
    testPostfixEvaluation();
    testErrorCases();

    std::cout << "\nAll tests completed!" << std::endl;

    return 0;
}