"""
Stack Implementation in Python
栈的Python实现

Time Complexity:
- Push: O(1)
- Pop: O(1)
- Peek: O(1)
- isEmpty: O(1)
- Size: O(1)

Space Complexity: O(n) where n is the number of elements
"""

class Stack:
    """
    A simple stack implementation using Python list.

    The stack follows the Last In, First Out (LIFO) principle.
    """

    def __init__(self, capacity=None):
        """
        Initialize an empty stack.

        Args:
            capacity (int, optional): Maximum number of elements the stack can hold.
                                    If None, the stack has unlimited capacity.
        """
        self._items = []
        self._capacity = capacity

    def push(self, item):
        """
        Add an element to the top of the stack.

        Args:
            item: Element to be added to the stack

        Raises:
            OverflowError: If stack is at maximum capacity

        Example:
            >>> stack = Stack()
            >>> stack.push(10)
            >>> stack.push(20)
            >>> stack.size()
            2
        """
        if self._capacity is not None and len(self._items) >= self._capacity:
            raise OverflowError("Stack overflow: Cannot push to full stack")

        self._items.append(item)

    def pop(self):
        """
        Remove and return the top element from the stack.

        Returns:
            The top element of the stack

        Raises:
            IndexError: If stack is empty

        Example:
            >>> stack = Stack()
            >>> stack.push(10)
            >>> stack.push(20)
            >>> stack.pop()
            20
            >>> stack.pop()
            10
        """
        if self.is_empty():
            raise IndexError("Stack underflow: Cannot pop from empty stack")

        return self._items.pop()

    def peek(self):
        """
        Return the top element without removing it.

        Returns:
            The top element of the stack

        Raises:
            IndexError: If stack is empty

        Example:
            >>> stack = Stack()
            >>> stack.push(10)
            >>> stack.peek()
            10
            >>> stack.size()  # Size remains the same
            1
        """
        if self.is_empty():
            raise IndexError("Stack is empty: Cannot peek")

        return self._items[-1]

    def is_empty(self):
        """
        Check if the stack is empty.

        Returns:
            bool: True if stack is empty, False otherwise

        Example:
            >>> stack = Stack()
            >>> stack.is_empty()
            True
            >>> stack.push(10)
            >>> stack.is_empty()
            False
        """
        return len(self._items) == 0

    def size(self):
        """
        Get the number of elements in the stack.

        Returns:
            int: Number of elements in the stack

        Example:
            >>> stack = Stack()
            >>> stack.size()
            0
            >>> stack.push(10)
            >>> stack.push(20)
            >>> stack.size()
            2
        """
        return len(self._items)

    def clear(self):
        """
        Remove all elements from the stack.

        Example:
            >>> stack = Stack()
            >>> stack.push(10)
            >>> stack.push(20)
            >>> stack.clear()
            >>> stack.is_empty()
            True
        """
        self._items.clear()

    def to_list(self):
        """
        Return a copy of the stack as a list (bottom to top).

        Returns:
            list: Copy of stack elements from bottom to top

        Example:
            >>> stack = Stack()
            >>> stack.push(10)
            >>> stack.push(20)
            >>> stack.push(30)
            >>> stack.to_list()
            [10, 20, 30]
        """
        return self._items.copy()

    def __str__(self):
        """
        String representation of the stack.

        Returns:
            str: String representation showing stack from bottom to top
        """
        if self.is_empty():
            return "Stack([])"
        return f"Stack({self._items})"

    def __repr__(self):
        """
        Detailed string representation of the stack.

        Returns:
            str: Detailed representation including capacity
        """
        capacity_str = f", capacity={self._capacity}" if self._capacity else ""
        return f"Stack(items={self._items}{capacity_str})"

    def __len__(self):
        """
        Return the number of elements in the stack.
        Allows use of len() function.

        Returns:
            int: Number of elements in the stack
        """
        return len(self._items)

    def __iter__(self):
        """
        Make the stack iterable (iterates from top to bottom).

        Returns:
            iterator: Iterator over stack elements from top to bottom
        """
        return reversed(self._items)


class MinStack:
    """
    A stack that supports getting the minimum element in O(1) time.
    """

    def __init__(self):
        """Initialize the MinStack."""
        self._stack = []
        self._min_stack = []

    def push(self, item):
        """
        Push element to the stack and update minimum.

        Args:
            item: Element to push
        """
        self._stack.append(item)

        # Update minimum stack
        if not self._min_stack or item <= self._min_stack[-1]:
            self._min_stack.append(item)

    def pop(self):
        """
        Pop element from the stack and update minimum.

        Returns:
            The popped element

        Raises:
            IndexError: If stack is empty
        """
        if not self._stack:
            raise IndexError("Stack is empty")

        popped = self._stack.pop()

        # Update minimum stack
        if popped == self._min_stack[-1]:
            self._min_stack.pop()

        return popped

    def peek(self):
        """
        Get the top element without removing it.

        Returns:
            The top element

        Raises:
            IndexError: If stack is empty
        """
        if not self._stack:
            raise IndexError("Stack is empty")
        return self._stack[-1]

    def get_min(self):
        """
        Get the minimum element in O(1) time.

        Returns:
            The minimum element in the stack

        Raises:
            IndexError: If stack is empty
        """
        if not self._min_stack:
            raise IndexError("Stack is empty")
        return self._min_stack[-1]

    def is_empty(self):
        """Check if the stack is empty."""
        return len(self._stack) == 0

    def size(self):
        """Get the number of elements in the stack."""
        return len(self._stack)


def balanced_parentheses(expression):
    """
    Check if parentheses are balanced using a stack.

    Args:
        expression (str): String containing parentheses

    Returns:
        bool: True if balanced, False otherwise

    Example:
        >>> balanced_parentheses("((()))")
        True
        >>> balanced_parentheses("((())")
        False
    """
    stack = Stack()
    opening = {'(', '[', '{'}
    closing = {')', ']', '}'}
    pairs = {'(': ')', '[': ']', '{': '}'}

    for char in expression:
        if char in opening:
            stack.push(char)
        elif char in closing:
            if stack.is_empty():
                return False

            top = stack.pop()
            if pairs[top] != char:
                return False

    return stack.is_empty()


def evaluate_postfix(expression):
    """
    Evaluate a postfix expression using a stack.

    Args:
        expression (str): Postfix expression (space-separated)

    Returns:
        float: Result of the expression

    Example:
        >>> evaluate_postfix("3 4 + 2 * 7 /")
        2.0
    """
    stack = Stack()
    operators = {'+', '-', '*', '/'}

    tokens = expression.split()

    for token in tokens:
        if token in operators:
            if stack.size() < 2:
                raise ValueError("Invalid postfix expression")

            operand2 = stack.pop()
            operand1 = stack.pop()

            if token == '+':
                result = operand1 + operand2
            elif token == '-':
                result = operand1 - operand2
            elif token == '*':
                result = operand1 * operand2
            elif token == '/':
                if operand2 == 0:
                    raise ValueError("Division by zero")
                result = operand1 / operand2

            stack.push(result)
        else:
            try:
                stack.push(float(token))
            except ValueError:
                raise ValueError(f"Invalid token: {token}")

    if stack.size() != 1:
        raise ValueError("Invalid postfix expression")

    return stack.pop()


if __name__ == "__main__":
    # Example usage and testing
    print("=== Basic Stack Operations ===")
    stack = Stack()

    # Test basic operations
    print(f"Empty stack: {stack}")
    print(f"Is empty: {stack.is_empty()}")

    # Push elements
    for i in [10, 20, 30, 40, 50]:
        stack.push(i)
        print(f"Pushed {i}: {stack}")

    print(f"Size: {stack.size()}")
    print(f"Top element (peek): {stack.peek()}")

    # Pop elements
    while not stack.is_empty():
        popped = stack.pop()
        print(f"Popped {popped}: {stack}")

    print("\n=== Stack with Capacity ===")
    limited_stack = Stack(capacity=3)

    try:
        for i in range(5):
            limited_stack.push(i)
            print(f"Pushed {i}: {limited_stack}")
    except OverflowError as e:
        print(f"Error: {e}")

    print("\n=== MinStack Example ===")
    min_stack = MinStack()

    values = [3, 5, 2, 1, 4]
    for val in values:
        min_stack.push(val)
        print(f"Pushed {val}, min: {min_stack.get_min()}")

    print("Popping elements:")
    while not min_stack.is_empty():
        popped = min_stack.pop()
        min_val = min_stack.get_min() if not min_stack.is_empty() else "N/A"
        print(f"Popped {popped}, min: {min_val}")

    print("\n=== Balanced Parentheses ===")
    test_expressions = [
        "(())",
        "((()))",
        "((())",
        "{[()]}",
        "{[(])}",
        ""
    ]

    for expr in test_expressions:
        result = balanced_parentheses(expr)
        print(f"'{expr}' is {'balanced' if result else 'not balanced'}")

    print("\n=== Postfix Evaluation ===")
    postfix_expressions = [
        "3 4 + 2 * 7 /",  # ((3 + 4) * 2) / 7 = 2.0
        "5 2 - 3 *",      # (5 - 2) * 3 = 9.0
        "4 2 / 3 +",      # (4 / 2) + 3 = 5.0
    ]

    for expr in postfix_expressions:
        try:
            result = evaluate_postfix(expr)
            print(f"'{expr}' = {result}")
        except ValueError as e:
            print(f"Error evaluating '{expr}': {e}")