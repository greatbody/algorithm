import { assertEquals, assertStrictEquals } from "https://deno.land/std@0.224.0/assert/mod.ts";
import { binarySearch, binarySearchRecursive, binarySearchVerbose, binarySearchFirstOccurrence, binarySearchLastOccurrence, binarySearchRange, binarySearchInsertionPoint, binarySearchAsync, binarySearchPerformance } from "./binarySearch.ts";

Deno.test('binarySearch basic', () => {
  assertStrictEquals(binarySearch([1,3,5,7,9], 5), 2);
});

Deno.test('binarySearch not found', () => {
  assertStrictEquals(binarySearch([1,3,5,7,9], 6), -1);
});

Deno.test('binarySearch recursive', () => {
  assertStrictEquals(binarySearchRecursive([1,3,5,7,9], 7), 3);
});

Deno.test('binarySearch verbose', () => {
  const res = binarySearchVerbose([1,3,5,7,9], 7);
  assertStrictEquals(res.index, 3);
  assertEquals(typeof res.steps, 'number');
});

Deno.test('binarySearch first occurrence', () => {
  assertStrictEquals(binarySearchFirstOccurrence([1,2,2,2,3], 2), 1);
});

Deno.test('binarySearch last occurrence', () => {
  assertStrictEquals(binarySearchLastOccurrence([1,2,2,2,3], 2), 3);
});

Deno.test('binarySearch range', () => {
  assertEquals(binarySearchRange([1,2,2,2,3], 2), [1,3]);
});

Deno.test('binarySearch insertion point', () => {
  assertStrictEquals(binarySearchInsertionPoint([1,3,5,7,9], 6), 3);
  assertStrictEquals(binarySearchInsertionPoint([1,3,5,7,9], 0), 0);
});

Deno.test('binarySearch performance', () => {
  const arr = Array.from({length:1000}, (_,i)=>i*2);
  const perf = binarySearchPerformance(arr, 198);
  assertStrictEquals(perf.index, 99);
  assertEquals(perf.arraySize, 1000);
});

Deno.test('binarySearch async', async () => {
  const idx = await binarySearchAsync([1,3,5,7,9], 9, 0);
  assertStrictEquals(idx, 4);
});
