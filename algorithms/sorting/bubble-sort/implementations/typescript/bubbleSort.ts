/** Bubble Sort Implementation in TypeScript (Deno) */
export type PrimitiveComparable = number | string | bigint;
export type CompareFn<T> = (a: T, b: T) => boolean; // true => swap

export function bubbleSort<T extends PrimitiveComparable>(
  arr: T[],
  compareFn: CompareFn<T> = (a, b) => a > b
): T[] {
  if (!Array.isArray(arr) || arr.length <= 1) return Array.isArray(arr) ? [...arr] : [] as T[];
  const result = [...arr];
  for (let i = 0; i < result.length; i++) {
    let swapped = false;
    for (let j = 0; j < result.length - i - 1; j++) {
      if (compareFn(result[j], result[j + 1])) {
        [result[j], result[j + 1]] = [result[j + 1], result[j]];
        swapped = true;
      }
    }
    if (!swapped) break;
  }
  return result;
}

export function bubbleSortDescending<T extends PrimitiveComparable>(arr: T[]): T[] {
  return bubbleSort(arr, (a, b) => a < b);
}

export interface VerboseResult<T> { sortedArray: T[]; steps: number; }

export function bubbleSortVerbose<T extends PrimitiveComparable>(arr: T[]): VerboseResult<T> {
  if (!Array.isArray(arr) || arr.length <= 1) return { sortedArray: Array.isArray(arr) ? [...arr] : [] as T[], steps: 0 };
  const result = [...arr];
  let steps = 0;
  for (let i = 0; i < result.length; i++) {
    let swapped = false;
    for (let j = 0; j < result.length - i - 1; j++) {
      steps++;
      if (result[j] > result[j + 1]) {
        [result[j], result[j + 1]] = [result[j + 1], result[j]];
        swapped = true;
      }
    }
    if (!swapped) break;
  }
  return { sortedArray: result, steps };
}

export async function bubbleSortAsync<T extends PrimitiveComparable>(
  arr: T[],
  delay = 100,
  onStep: ((snapshot: T[], pass: number, index: number) => void) | null = null
): Promise<T[]> {
  if (!Array.isArray(arr) || arr.length <= 1) return Array.isArray(arr) ? [...arr] : [] as T[];
  const result = [...arr];
  for (let i = 0; i < result.length; i++) {
    let swapped = false;
    for (let j = 0; j < result.length - i - 1; j++) {
      if (result[j] > result[j + 1]) {
        [result[j], result[j + 1]] = [result[j + 1], result[j]];
        swapped = true;
        if (onStep) onStep([...result], i, j);
        if (delay > 0) await new Promise(r => setTimeout(r, delay));
      }
    }
    if (!swapped) break;
  }
  return result;
}

export function bubbleSortBy<T extends Record<string, PrimitiveComparable | boolean | null | undefined>>(
  arr: T[],
  key: keyof T,
  ascending = true
): T[] {
  const cmp: CompareFn<T> = ascending
    ? (a, b) => (a[key] as PrimitiveComparable) > (b[key] as PrimitiveComparable)
    : (a, b) => (a[key] as PrimitiveComparable) < (b[key] as PrimitiveComparable);
  return bubbleSort(arr as unknown as PrimitiveComparable[], cmp as unknown as CompareFn<PrimitiveComparable>) as unknown as T[];
}

export interface BubblePerformance<T> { sortedArray: T[]; executionTime: number; arraySize: number; timePerElement: number; }

export function bubbleSortPerformance<T extends PrimitiveComparable>(arr: T[]): BubblePerformance<T> {
  const start = performance.now();
  const sorted = bubbleSort(arr);
  const end = performance.now();
  return {
    sortedArray: sorted,
    executionTime: end - start,
    arraySize: arr.length,
    timePerElement: (end - start) / (arr.length || 1)
  };
}

if (import.meta.main) {
  console.log('Bubble Sort Demo');
  console.log(bubbleSort([64, 34, 25, 12, 22, 11, 90]));
}
