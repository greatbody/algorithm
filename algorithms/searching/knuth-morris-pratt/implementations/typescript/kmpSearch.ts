/**
 * Knuth-Morris-Pratt (KMP) String Matching Algorithm Implementation in TypeScript (Deno)
 * 时间复杂度: O(n + m)  空间复杂度: O(m)
 */

/**
 * Build the failure function (LPS array) for the KMP algorithm.
 * lps[i] = length of the longest proper prefix which is also a suffix for pattern[0..i]
 */
export function buildFailureFunction(pattern: string): number[] {
  if (!pattern || typeof pattern !== 'string') {
    return [];
  }
  const m = pattern.length;
  const lps: number[] = new Array(m).fill(0);
  let len = 0; // length of previous longest prefix suffix
  let i = 1;
  while (i < m) {
    if (pattern[i] === pattern[len]) {
      len++;
      lps[i] = len;
      i++;
    } else if (len !== 0) {
      len = lps[len - 1];
    } else {
      lps[i] = 0;
      i++;
    }
  }
  return lps;
}

/** Search for all occurrences of pattern in text using KMP. */
export function kmpSearch(text: string, pattern: string): number[] {
  if (!text || !pattern || typeof text !== 'string' || typeof pattern !== 'string') {
    return [];
  }
  const n = text.length;
  const m = pattern.length;
  if (m === 0) return [];
  const lps = buildFailureFunction(pattern);
  const positions: number[] = [];
  let i = 0; // index in text
  let j = 0; // index in pattern
  while (i < n) {
    if (pattern[j] === text[i]) {
      i++; j++;
    }
    if (j === m) {
      positions.push(i - j);
      j = lps[j - 1];
    } else if (i < n && pattern[j] !== text[i]) {
      if (j !== 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
  return positions;
}

/** Return first occurrence index or -1. */
export function kmpSearchFirst(text: string, pattern: string): number {
  const positions = kmpSearch(text, pattern);
  return positions.length > 0 ? positions[0] : -1;
}

/** Validate input parameters. */
export function validateInput(text: unknown, pattern: unknown): void {
  if (typeof text !== 'string') throw new TypeError('Text must be a string');
  if (typeof pattern !== 'string') throw new TypeError('Pattern must be a string');
  if (pattern.length === 0) throw new Error('Pattern cannot be empty');
}

/** Class-based matcher enabling pattern reuse. */
export class KMPMatcher {
  public pattern: string;
  private failureFunction: number[];
  constructor(pattern: string) {
    if (typeof pattern !== 'string') throw new TypeError('Pattern must be a string');
    if (pattern.length === 0) throw new Error('Pattern cannot be empty');
    this.pattern = pattern;
    this.failureFunction = buildFailureFunction(pattern);
  }
  search(text: string): number[] {
    if (typeof text !== 'string') throw new TypeError('Text must be a string');
    return kmpSearch(text, this.pattern);
  }
  searchFirst(text: string): number { return this.search(text)[0] ?? -1; }
  getFailureFunction(): number[] { return [...this.failureFunction]; }
}

// Optional demonstration when run directly with: deno run kmpSearch.ts
if (import.meta.main) {
  console.log('KMP Demo');
  const text = 'ABABDABACDABABCABCABCABCABC';
  const pattern = 'ABABCAB';
  console.log('Matches:', kmpSearch(text, pattern));
}
