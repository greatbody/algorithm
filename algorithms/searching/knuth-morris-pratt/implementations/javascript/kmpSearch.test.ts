import { assertEquals, assertStrictEquals, assert } from "https://deno.land/std@0.224.0/assert/mod.ts";
import { buildFailureFunction, kmpSearch, kmpSearchFirst, validateInput, KMPMatcher } from "./kmpSearch.ts";

Deno.test('buildFailureFunction basic pattern', () => {
  // LPS (failure) array for 'ABABCABAB' should grow to 3 then 4 at the end: [0,0,1,2,0,1,2,3,4]
  assertEquals(buildFailureFunction('ABABCABAB'), [0,0,1,2,0,1,2,3,4]);
});

Deno.test('buildFailureFunction all same chars', () => {
  assertEquals(buildFailureFunction('AAAA'), [0,1,2,3]);
});

Deno.test('buildFailureFunction no repeats', () => {
  assertEquals(buildFailureFunction('ABCDEF'), [0,0,0,0,0,0]);
});

Deno.test('buildFailureFunction empty', () => {
  assertEquals(buildFailureFunction(''), []);
});

Deno.test('buildFailureFunction single char', () => {
  assertEquals(buildFailureFunction('A'), [0]);
});

Deno.test('kmpSearch basic', () => {
  // Correct match starts at index 10: text[10..16] = ABABCAB
  assertEquals(kmpSearch('ABABDABACDABABCABCABCABCABC','ABABCAB'), [10]);
});

Deno.test('kmpSearch multiple', () => {
  assertEquals(kmpSearch('AABAACAADAABAABA','AABA'), [0,9,12]);
});

Deno.test('kmpSearch overlapping', () => {
  assertEquals(kmpSearch('AAAAA','AA'), [0,1,2,3]);
});

Deno.test('kmpSearch no matches', () => {
  assertEquals(kmpSearch('hello world','xyz'), []);
});

Deno.test('kmpSearch pattern longer', () => {
  assertEquals(kmpSearch('hi','hello'), []);
});

Deno.test('kmpSearch exact match', () => {
  assertEquals(kmpSearch('hello','hello'), [0]);
});

Deno.test('kmpSearch empty text', () => {
  assertEquals(kmpSearch('','pattern'), []);
});

Deno.test('kmpSearch empty pattern', () => {
  assertEquals(kmpSearch('text',''), []);
});

Deno.test('kmpSearchFirst found', () => {
  assertStrictEquals(kmpSearchFirst('hello world','world'), 6);
});

Deno.test('kmpSearchFirst not found', () => {
  assertStrictEquals(kmpSearchFirst('hello world','xyz'), -1);
});

Deno.test('kmpSearchFirst multiple matches returns first', () => {
  assertStrictEquals(kmpSearchFirst('banana','ana'), 1);
});

Deno.test('validateInput valid', () => {
  validateInput('hello','lo');
});

Deno.test('validateInput invalid text type', () => {
  try {
    // @ts-ignore intentional
    validateInput(123,'pattern');
    throw new Error('Should have thrown');
  } catch (e) {
    assert(e instanceof TypeError);
  }
});

Deno.test('validateInput invalid pattern type', () => {
  try {
    // @ts-ignore intentional
    validateInput('text',123);
    throw new Error('Should have thrown');
  } catch (e) {
    assert(e instanceof TypeError);
  }
});

Deno.test('validateInput empty pattern', () => {
  try {
    validateInput('text','');
    throw new Error('Should have thrown');
  } catch (e) {
    assertStrictEquals((e as Error).message, 'Pattern cannot be empty');
  }
});

Deno.test('KMPMatcher constructor valid', () => {
  const m = new KMPMatcher('test');
  assertStrictEquals(m.pattern, 'test');
});

Deno.test('KMPMatcher constructor invalid type', () => {
  try { // @ts-ignore: intentional wrong type to test validation
    new KMPMatcher(123); throw new Error('Should have thrown');
  } catch (e) { assert(e instanceof TypeError); }
});

Deno.test('KMPMatcher constructor empty', () => {
  try { new KMPMatcher(''); throw new Error('Should have thrown'); }
  catch (e) { assertStrictEquals((e as Error).message, 'Pattern cannot be empty'); }
});

Deno.test('KMPMatcher search', () => {
  const matcher = new KMPMatcher('ana');
  assertEquals(matcher.search('banana'), [1,3]);
});

Deno.test('KMPMatcher searchFirst', () => {
  const matcher = new KMPMatcher('ana');
  assertStrictEquals(matcher.searchFirst('banana'), 1);
});

Deno.test('KMPMatcher searchFirst not found', () => {
  const matcher = new KMPMatcher('xyz');
  assertStrictEquals(matcher.searchFirst('banana'), -1);
});

Deno.test('KMPMatcher getFailureFunction', () => {
  const matcher = new KMPMatcher('ABAB');
  assertEquals(matcher.getFailureFunction(), [0,0,1,2]);
});

Deno.test('KMPMatcher search invalid text type', () => {
  const matcher = new KMPMatcher('test');
  try { // @ts-ignore: intentional wrong type to test validation
    matcher.search(123); throw new Error('Should have thrown');
  } catch (e) { assert(e instanceof TypeError); }
});

Deno.test('kmpSearch large text performance', () => {
  const large = 'A'.repeat(10000) + 'PATTERN' + 'B'.repeat(10000);
  const res = kmpSearch(large,'PATTERN');
  assertEquals(res, [10000]);
});

Deno.test('kmpSearch repeating pattern large text', () => {
  const text = 'AB'.repeat(1000);
  const pattern = 'ABAB';
  const res = kmpSearch(text, pattern);
  assert(res.length > 0);
});

Deno.test('kmpSearch unicode', () => {
  const text = '你好世界，欢迎来到编程世界！';
  const pattern = '世界';
  const res = kmpSearch(text, pattern);
  assertStrictEquals(res.length, 2);
});
