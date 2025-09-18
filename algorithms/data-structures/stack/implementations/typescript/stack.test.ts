import { assertEquals, assertThrows } from "https://deno.land/std@0.224.0/assert/mod.ts";
import { Stack, MinStack, balancedParentheses, evaluatePostfix } from "./stack.ts";

Deno.test("Stack - basic operations", () => {
  const stack = new Stack<number>();

  // Test empty stack
  assertEquals(stack.isEmpty(), true);
  assertEquals(stack.size(), 0);
  assertEquals(stack.toString(), "Stack([])");

  // Test push
  stack.push(10);
  assertEquals(stack.isEmpty(), false);
  assertEquals(stack.size(), 1);
  assertEquals(stack.peek(), 10);

  stack.push(20);
  stack.push(30);
  assertEquals(stack.size(), 3);
  assertEquals(stack.peek(), 30);
  assertEquals(stack.toString(), "Stack([10, 20, 30])");
});

Deno.test("Stack - pop operations", () => {
  const stack = new Stack<number>();
  stack.push(10);
  stack.push(20);
  stack.push(30);

  // Test pop
  assertEquals(stack.pop(), 30);
  assertEquals(stack.size(), 2);
  assertEquals(stack.peek(), 20);

  assertEquals(stack.pop(), 20);
  assertEquals(stack.pop(), 10);
  assertEquals(stack.isEmpty(), true);
});

Deno.test("Stack - peek operation", () => {
  const stack = new Stack<string>();
  stack.push("hello");
  stack.push("world");

  assertEquals(stack.peek(), "world");
  assertEquals(stack.size(), 2); // Size should remain the same
});

Deno.test("Stack - clear operation", () => {
  const stack = new Stack<number>();
  stack.push(1);
  stack.push(2);
  stack.push(3);

  assertEquals(stack.size(), 3);
  stack.clear();
  assertEquals(stack.isEmpty(), true);
  assertEquals(stack.size(), 0);
});

Deno.test("Stack - toArray operation", () => {
  const stack = new Stack<number>();
  stack.push(10);
  stack.push(20);
  stack.push(30);

  assertEquals(stack.toArray(), [10, 20, 30]);
});

Deno.test("Stack - iterator", () => {
  const stack = new Stack<number>();
  stack.push(10);
  stack.push(20);
  stack.push(30);

  const result = [...stack];
  assertEquals(result, [30, 20, 10]); // Iterator goes from top to bottom
});

Deno.test("Stack - error cases", () => {
  const stack = new Stack<number>();

  // Test pop from empty stack
  assertThrows(() => stack.pop(), Error, "Stack underflow");

  // Test peek from empty stack
  assertThrows(() => stack.peek(), Error, "Stack is empty");
});

Deno.test("Stack - with capacity", () => {
  const stack = new Stack<number>(2);

  stack.push(1);
  stack.push(2);
  assertEquals(stack.size(), 2);

  // Should throw when exceeding capacity
  assertThrows(() => stack.push(3), Error, "Stack overflow");
});

Deno.test("MinStack - basic operations", () => {
  const minStack = new MinStack();

  minStack.push(3);
  assertEquals(minStack.getMin(), 3);

  minStack.push(5);
  assertEquals(minStack.getMin(), 3);

  minStack.push(2);
  assertEquals(minStack.getMin(), 2);

  minStack.push(1);
  assertEquals(minStack.getMin(), 1);

  minStack.push(4);
  assertEquals(minStack.getMin(), 1);
});

Deno.test("MinStack - pop operations", () => {
  const minStack = new MinStack();
  const values = [3, 5, 2, 1, 4];

  for (const val of values) {
    minStack.push(val);
  }

  assertEquals(minStack.getMin(), 1);

  minStack.pop(); // Remove 4
  assertEquals(minStack.getMin(), 1);

  minStack.pop(); // Remove 1
  assertEquals(minStack.getMin(), 2);

  minStack.pop(); // Remove 2
  assertEquals(minStack.getMin(), 3);
});

Deno.test("MinStack - peek operation", () => {
  const minStack = new MinStack();
  minStack.push(10);
  minStack.push(5);

  assertEquals(minStack.peek(), 5);
  assertEquals(minStack.size(), 2); // Size should remain the same
});

Deno.test("MinStack - error cases", () => {
  const minStack = new MinStack();

  assertThrows(() => minStack.pop(), Error, "Stack is empty");
  assertThrows(() => minStack.peek(), Error, "Stack is empty");
  assertThrows(() => minStack.getMin(), Error, "Stack is empty");
});

Deno.test("balancedParentheses - valid cases", () => {
  assertEquals(balancedParentheses("()"), true);
  assertEquals(balancedParentheses("(())"), true);
  assertEquals(balancedParentheses("((()))"), true);
  assertEquals(balancedParentheses("{[()]}"), true);
  assertEquals(balancedParentheses(""), true);
  assertEquals(balancedParentheses("[]{}()"), true);
});

Deno.test("balancedParentheses - invalid cases", () => {
  assertEquals(balancedParentheses("(("), false);
  assertEquals(balancedParentheses("))"), false);
  assertEquals(balancedParentheses("(()"), false);
  assertEquals(balancedParentheses("{[(])}"), false);
  assertEquals(balancedParentheses("([)]"), false);
});

Deno.test("evaluatePostfix - basic operations", () => {
  // ((3 + 4) * 2) / 7 = 14 / 7 = 2
  assertEquals(evaluatePostfix("3 4 + 2 * 7 /"), 2);

  // (5 - 2) * 3 = 9
  assertEquals(evaluatePostfix("5 2 - 3 *"), 9);

  // (4 / 2) + 3 = 5
  assertEquals(evaluatePostfix("4 2 / 3 +"), 5);

  // Simple addition
  assertEquals(evaluatePostfix("2 3 +"), 5);

  // Simple multiplication
  assertEquals(evaluatePostfix("4 5 *"), 20);
});

Deno.test("evaluatePostfix - complex expressions", () => {
  // 2 * (3 + 4) - 5 = 9
  assertEquals(evaluatePostfix("2 3 4 + * 5 -"), 9);

  // (10 + 5) / (3 * 2) = 15 / 6 = 2.5
  assertEquals(evaluatePostfix("10 5 + 3 2 * /"), 2.5);
});

Deno.test("evaluatePostfix - error cases", () => {
  // Invalid expression - not enough operands
  assertThrows(() => evaluatePostfix("+"), Error, "Invalid postfix expression");

  // Invalid expression - too many operands
  assertThrows(() => evaluatePostfix("2 3"), Error, "Invalid postfix expression");

  // Division by zero
  assertThrows(() => evaluatePostfix("4 0 /"), Error, "Division by zero");

  // Invalid token
  assertThrows(() => evaluatePostfix("2 3 + x"), Error, "Invalid token");
});

Deno.test("evaluatePostfix - floating point", () => {
  assertEquals(evaluatePostfix("3.5 2.0 *"), 7.0);
  assertEquals(evaluatePostfix("10.0 4.0 /"), 2.5);
});