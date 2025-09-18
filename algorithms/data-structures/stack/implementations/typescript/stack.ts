/**
 * Stack Implementation in TypeScript (Deno)
 * 栈的TypeScript实现
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

export class Stack<T> {
  /**
   * A simple stack implementation using TypeScript array.
   *
   * The stack follows the Last In, First Out (LIFO) principle.
   */
  private _items: T[];
  private _capacity?: number;

  constructor(capacity?: number) {
    /**
     * Initialize an empty stack.
     *
     * @param capacity Maximum number of elements the stack can hold.
     *                 If undefined, the stack has unlimited capacity.
     */
    this._items = [];
    this._capacity = capacity;
  }

  push(item: T): void {
    /**
     * Add an element to the top of the stack.
     *
     * @param item Element to be added to the stack
     * @throws Error If stack is at maximum capacity
     */
    if (this._capacity !== undefined && this._items.length >= this._capacity) {
      throw new Error("Stack overflow: Cannot push to full stack");
    }
    this._items.push(item);
  }

  pop(): T {
    /**
     * Remove and return the top element from the stack.
     *
     * @returns The top element of the stack
     * @throws Error If stack is empty
     */
    if (this.isEmpty()) {
      throw new Error("Stack underflow: Cannot pop from empty stack");
    }
    return this._items.pop()!;
  }

  peek(): T {
    /**
     * Return the top element without removing it.
     *
     * @returns The top element of the stack
     * @throws Error If stack is empty
     */
    if (this.isEmpty()) {
      throw new Error("Stack is empty: Cannot peek");
    }
    return this._items[this._items.length - 1];
  }

  isEmpty(): boolean {
    /**
     * Check if the stack is empty.
     *
     * @returns True if stack is empty, false otherwise
     */
    return this._items.length === 0;
  }

  size(): number {
    /**
     * Get the number of elements in the stack.
     *
     * @returns Number of elements in the stack
     */
    return this._items.length;
  }

  clear(): void {
    /**
     * Remove all elements from the stack.
     */
    this._items = [];
  }

  toArray(): T[] {
    /**
     * Return a copy of the stack as an array (bottom to top).
     *
     * @returns Copy of stack elements from bottom to top
     */
    return [...this._items];
  }

  toString(): string {
    /**
     * String representation of the stack.
     *
     * @returns String representation showing stack from bottom to top
     */
    if (this.isEmpty()) {
      return "Stack([])";
    }
    return `Stack([${this._items.join(", ")}])`;
  }

  [Symbol.iterator](): Iterator<T> {
    /**
     * Make the stack iterable (iterates from top to bottom).
     *
     * @returns Iterator over stack elements from top to bottom
     */
    let index = this._items.length;
    return {
      next: (): IteratorResult<T> => {
        if (index > 0) {
          return { value: this._items[--index], done: false };
        }
        return { value: undefined as T, done: true };
      }
    };
  }
}

export class MinStack {
  /**
   * A stack that supports getting the minimum element in O(1) time.
   */
  private _stack: number[];
  private _minStack: number[];

  constructor() {
    this._stack = [];
    this._minStack = [];
  }

  push(item: number): void {
    /**
     * Push element to the stack and update minimum.
     *
     * @param item Element to push
     */
    this._stack.push(item);

    // Update minimum stack
    if (this._minStack.length === 0 || item <= this._minStack[this._minStack.length - 1]) {
      this._minStack.push(item);
    }
  }

  pop(): number {
    /**
     * Pop element from the stack and update minimum.
     *
     * @returns The popped element
     * @throws Error If stack is empty
     */
    if (this._stack.length === 0) {
      throw new Error("Stack is empty");
    }

    const popped = this._stack.pop()!;

    // Update minimum stack
    if (popped === this._minStack[this._minStack.length - 1]) {
      this._minStack.pop();
    }

    return popped;
  }

  peek(): number {
    /**
     * Get the top element without removing it.
     *
     * @returns The top element
     * @throws Error If stack is empty
     */
    if (this._stack.length === 0) {
      throw new Error("Stack is empty");
    }
    return this._stack[this._stack.length - 1];
  }

  getMin(): number {
    /**
     * Get the minimum element in O(1) time.
     *
     * @returns The minimum element in the stack
     * @throws Error If stack is empty
     */
    if (this._minStack.length === 0) {
      throw new Error("Stack is empty");
    }
    return this._minStack[this._minStack.length - 1];
  }

  isEmpty(): boolean {
    /** Check if the stack is empty. */
    return this._stack.length === 0;
  }

  size(): number {
    /** Get the number of elements in the stack. */
    return this._stack.length;
  }
}

export function balancedParentheses(expression: string): boolean {
  /**
   * Check if parentheses are balanced using a stack.
   *
   * @param expression String containing parentheses
   * @returns True if balanced, false otherwise
   */
  const stack = new Stack<string>();
  const opening = new Set(['(', '[', '{']);
  const closing = new Set([')', ']', '}']);
  const pairs: Record<string, string> = { '(': ')', '[': ']', '{': '}' };

  for (const char of expression) {
    if (opening.has(char)) {
      stack.push(char);
    } else if (closing.has(char)) {
      if (stack.isEmpty()) {
        return false;
      }

      const top = stack.pop();
      if (pairs[top] !== char) {
        return false;
      }
    }
  }

  return stack.isEmpty();
}

export function evaluatePostfix(expression: string): number {
  /**
   * Evaluate a postfix expression using a stack.
   *
   * @param expression Postfix expression (space-separated)
   * @returns Result of the expression
   * @throws Error If expression is invalid
   */
  const stack = new Stack<number>();
  const operators = new Set(['+', '-', '*', '/']);

  const tokens = expression.split(/\s+/);

  for (const token of tokens) {
    if (operators.has(token)) {
      if (stack.size() < 2) {
        throw new Error("Invalid postfix expression");
      }

      const operand2 = stack.pop();
      const operand1 = stack.pop();

      let result: number;
      switch (token) {
        case '+':
          result = operand1 + operand2;
          break;
        case '-':
          result = operand1 - operand2;
          break;
        case '*':
          result = operand1 * operand2;
          break;
        case '/':
          if (operand2 === 0) {
            throw new Error("Division by zero");
          }
          result = operand1 / operand2;
          break;
        default:
          throw new Error(`Unknown operator: ${token}`);
      }

      stack.push(result);
    } else {
      const num = parseFloat(token);
      if (isNaN(num)) {
        throw new Error(`Invalid token: ${token}`);
      }
      stack.push(num);
    }
  }

  if (stack.size() !== 1) {
    throw new Error("Invalid postfix expression");
  }

  return stack.pop();
}