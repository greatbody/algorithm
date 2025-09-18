import { assertEquals, assert, assertStrictEquals } from "https://deno.land/std@0.224.0/assert/mod.ts";
import { bubbleSort, bubbleSortDescending, bubbleSortVerbose, bubbleSortBy, bubbleSortPerformance } from "./bubbleSort.ts";

Deno.test('bubbleSort basic array', () => {
  assertEquals(bubbleSort([64,34,25,12,22,11,90]), [11,12,22,25,34,64,90]);
});

Deno.test('bubbleSort small array', () => {
  assertEquals(bubbleSort([5,2,8,1,9]), [1,2,5,8,9]);
});

Deno.test('bubbleSort empty array', () => {
  assertEquals(bubbleSort([]), []);
});

Deno.test('bubbleSort single element', () => {
  assertEquals(bubbleSort([42]), [42]);
});

Deno.test('bubbleSort two elements', () => {
  assertEquals(bubbleSort([2,1]), [1,2]);
  assertEquals(bubbleSort([1,2]), [1,2]);
});

Deno.test('bubbleSort already sorted', () => {
  assertEquals(bubbleSort([1,2,3,4,5]), [1,2,3,4,5]);
});

Deno.test('bubbleSort reverse sorted', () => {
  assertEquals(bubbleSort([5,4,3,2,1]), [1,2,3,4,5]);
});

Deno.test('bubbleSort duplicates', () => {
  assertEquals(bubbleSort([3,1,4,1,5,9,2,6,5,3]), [1,1,2,3,3,4,5,5,6,9]);
});

Deno.test('bubbleSort all same elements', () => {
  assertEquals(bubbleSort([3,3,3,3]), [3,3,3,3]);
});

Deno.test('bubbleSort negative numbers', () => {
  assertEquals(bubbleSort([-1,-5,0,3,-2]), [-5,-2,-1,0,3]);
});

Deno.test('bubbleSort mixed numbers', () => {
  assertEquals(bubbleSort([10,-1,5,-10,0,15]), [-10,-1,0,5,10,15]);
});

Deno.test('bubbleSort descending', () => {
  assertEquals(bubbleSortDescending([64,34,25,12,22,11,90]), [90,64,34,25,22,12,11]);
});

Deno.test('bubbleSort strings', () => {
  assertEquals(bubbleSort(['banana','apple','cherry','date']), ['apple','banana','cherry','date']);
});

Deno.test('bubbleSort verbose', () => {
  const result = bubbleSortVerbose([3,1,2]);
  assertEquals(result.sortedArray, [1,2,3]);
  assert(result.steps > 0);
});

Deno.test('bubbleSort objects by key', () => {
  const arr = [
    { name: 'Charlie', age: 35 },
    { name: 'Alice', age: 30 },
    { name: 'Bob', age: 25 }
  ];
  const expected = [
    { name: 'Bob', age: 25 },
    { name: 'Alice', age: 30 },
    { name: 'Charlie', age: 35 }
  ];
  assertEquals(bubbleSortBy(arr, 'age'), expected);
});

Deno.test('bubbleSort objects by key descending', () => {
  const arr = [
    { name: 'Alice', score: 85 },
    { name: 'Bob', score: 92 },
    { name: 'Charlie', score: 78 }
  ];
  const expected = [
    { name: 'Bob', score: 92 },
    { name: 'Alice', score: 85 },
    { name: 'Charlie', score: 78 }
  ];
  assertEquals(bubbleSortBy(arr, 'score', false), expected);
});

Deno.test('bubbleSort performance metrics', () => {
  const arr = [5,2,8,1,9];
  const perf = bubbleSortPerformance(arr);
  assertEquals(perf.sortedArray, [1,2,5,8,9]);
  assert(perf.executionTime >= 0);
  assertStrictEquals(perf.arraySize, 5);
});
