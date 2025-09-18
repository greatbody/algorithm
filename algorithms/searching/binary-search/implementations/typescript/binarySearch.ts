/** Binary Search Implementation in TypeScript (Deno) */
export type Ordered = number | string | bigint;

export function binarySearch<T extends Ordered>(arr: T[], target: T): number {
  if (!Array.isArray(arr) || arr.length === 0) return -1;
  let left = 0, right = arr.length - 1;
  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
  if (arr[mid] === target) return mid;
  if (arr[mid] < target) left = mid + 1; else right = mid - 1;
  }
  return -1;
}

export function binarySearchRecursive<T extends Ordered>(arr: T[], target: T, left = 0, right: number | null = null): number {
  if (!Array.isArray(arr) || arr.length === 0) return -1;
  if (right === null) right = arr.length - 1;
  if (left > right) return -1;
  const mid = left + Math.floor((right - left) / 2);
  if (arr[mid] === target) return mid;
  if (arr[mid] < target) return binarySearchRecursive(arr, target, mid + 1, right);
  return binarySearchRecursive(arr, target, left, mid - 1);
}

export interface VerboseSearchResult { index: number; steps: number; }

export function binarySearchVerbose<T extends Ordered>(arr: T[], target: T): VerboseSearchResult {
  if (!Array.isArray(arr) || arr.length === 0) return { index: -1, steps: 0 };
  let left = 0, right = arr.length - 1, steps = 0;
  while (left <= right) {
    steps++;
    const mid = left + Math.floor((right - left) / 2);
  if (arr[mid] === target) return { index: mid, steps };
  if (arr[mid] < target) left = mid + 1; else right = mid - 1;
  }
  return { index: -1, steps };
}

export function binarySearchFirstOccurrence<T extends Ordered>(arr: T[], target: T): number {
  if (!Array.isArray(arr) || arr.length === 0) return -1;
  let left = 0, right = arr.length - 1, result = -1;
  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
  if (arr[mid] === target) { result = mid; right = mid - 1; }
  else if (arr[mid] < target) left = mid + 1; else right = mid - 1;
  }
  return result;
}

export function binarySearchLastOccurrence<T extends Ordered>(arr: T[], target: T): number {
  if (!Array.isArray(arr) || arr.length === 0) return -1;
  let left = 0, right = arr.length - 1, result = -1;
  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
  if (arr[mid] === target) { result = mid; left = mid + 1; }
  else if (arr[mid] < target) left = mid + 1; else right = mid - 1;
  }
  return result;
}

export function binarySearchRange<T extends Ordered>(arr: T[], target: T): [number, number] {
  const first = binarySearchFirstOccurrence(arr, target);
  if (first === -1) return [-1, -1];
  const last = binarySearchLastOccurrence(arr, target);
  return [first, last];
}

export function binarySearchInsertionPoint<T extends Ordered>(arr: T[], target: T): number {
  if (!Array.isArray(arr) || arr.length === 0) return 0;
  let left = 0, right = arr.length;
  while (left < right) {
    const mid = left + Math.floor((right - left) / 2);
  if (arr[mid] < target) left = mid + 1; else right = mid;
  }
  return left;
}

export interface BinaryPerformance { index: number; executionTime: number; arraySize: number; timeComplexity: string; }

export function binarySearchPerformance<T extends Ordered>(arr: T[], target: T): BinaryPerformance {
  const start = performance.now();
  const index = binarySearch(arr, target);
  const end = performance.now();
  return {
    index,
    executionTime: end - start,
    arraySize: arr.length,
    timeComplexity: `O(log ${arr.length}) ≈ ${arr.length ? Math.ceil(Math.log2(arr.length)) : 0} max steps`
  };
}

export async function binarySearchAsync<T extends Ordered>(arr: T[], target: T, delay = 0, onStep: ((info: { step: number; left: number; right: number; mid: number; value: T; target: T; comparison: string; }) => void) | null = null): Promise<number> {
  if (!Array.isArray(arr) || arr.length === 0) return -1;
  let left = 0, right = arr.length - 1, steps = 0;
  while (left <= right) {
    steps++;
    const mid = left + Math.floor((right - left) / 2);
    // @ts-ignore ordering
  const comparison = arr[mid] === target ? 'equal' : arr[mid] < target ? 'less' : 'greater';
    if (onStep) onStep({ step: steps, left, right, mid, value: arr[mid], target, comparison });
    if (delay > 0) await new Promise(r => setTimeout(r, delay));
    if (arr[mid] === target) return mid;
  if (arr[mid] < target) left = mid + 1; else right = mid - 1;
  }
  return -1;
}

if (import.meta.main) {
  console.log('Binary Search Demo');
  console.log(binarySearch([1,3,5,7,9], 7));
}
