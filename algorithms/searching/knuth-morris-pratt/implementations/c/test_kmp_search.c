/**
 * KMP Search Test Suite using Unity Framework
 * 使用Unity框架的KMP搜索测试套件
 */

#include "unity.h"
#include "kmp_search.h"
#include <stdlib.h>
#include <string.h>

// Test setup and teardown
void setUp(void) {
    // Called before each test
}

void tearDown(void) {
    // Called after each test
}

// Test failure function building
void test_kmp_build_failure_function(void) {
    // Test case 1: "ABABCABAB"
    const char* pattern1 = "ABABCABAB";
    size_t len1 = strlen(pattern1);
    size_t* lps1 = (size_t*)malloc(len1 * sizeof(size_t));

    TEST_ASSERT_TRUE(kmp_build_failure_function(pattern1, len1, lps1));
    size_t expected1[] = {0, 0, 1, 2, 0, 1, 2, 3, 4};  // Correct LPS array
    for (size_t i = 0; i < len1; i++) {
        TEST_ASSERT_EQUAL(expected1[i], lps1[i]);
    }
    free(lps1);

    // Test case 2: "AAAA"
    const char* pattern2 = "AAAA";
    size_t len2 = strlen(pattern2);
    size_t* lps2 = (size_t*)malloc(len2 * sizeof(size_t));

    TEST_ASSERT_TRUE(kmp_build_failure_function(pattern2, len2, lps2));
    size_t expected2[] = {0, 1, 2, 3};
    for (size_t i = 0; i < len2; i++) {
        TEST_ASSERT_EQUAL(expected2[i], lps2[i]);
    }
    free(lps2);

    // Test case 3: "ABCDABCD"
    const char* pattern3 = "ABCDABCD";
    size_t len3 = strlen(pattern3);
    size_t* lps3 = (size_t*)malloc(len3 * sizeof(size_t));

    TEST_ASSERT_TRUE(kmp_build_failure_function(pattern3, len3, lps3));
    size_t expected3[] = {0, 0, 0, 0, 1, 2, 3, 4};
    for (size_t i = 0; i < len3; i++) {
        TEST_ASSERT_EQUAL(expected3[i], lps3[i]);
    }
    free(lps3);

    // Test edge cases
    TEST_ASSERT_FALSE(kmp_build_failure_function(NULL, 5, lps1));  // NULL pattern
    TEST_ASSERT_FALSE(kmp_build_failure_function(pattern1, 0, lps1));  // Empty pattern
    TEST_ASSERT_FALSE(kmp_build_failure_function(pattern1, 5, NULL));  // NULL LPS array
}

// Test basic KMP search
void test_kmp_search_basic(void) {
    // Test case 1
    const char* text1 = "ABABDABACDABABCABCABCABCABC";
    const char* pattern1 = "ABABCAB";
    KMPResult result1;

    TEST_ASSERT_TRUE(kmp_search(text1, strlen(text1), pattern1, strlen(pattern1), &result1));
    TEST_ASSERT_EQUAL(1, result1.count);
    TEST_ASSERT_EQUAL(10, result1.positions[0]);  // Correct position
    kmp_result_destroy(&result1);

    // Test case 2: Multiple matches
    const char* text2 = "AABAACAADAABAABA";
    const char* pattern2 = "AABA";
    KMPResult result2;

    TEST_ASSERT_TRUE(kmp_search(text2, strlen(text2), pattern2, strlen(pattern2), &result2));
    TEST_ASSERT_EQUAL(3, result2.count);
    TEST_ASSERT_EQUAL(0, result2.positions[0]);
    TEST_ASSERT_EQUAL(9, result2.positions[1]);
    TEST_ASSERT_EQUAL(12, result2.positions[2]);
    kmp_result_destroy(&result2);

    // Test case 3: Single match
    const char* text3 = "hello world";
    const char* pattern3 = "world";
    KMPResult result3;

    TEST_ASSERT_TRUE(kmp_search(text3, strlen(text3), pattern3, strlen(pattern3), &result3));
    TEST_ASSERT_EQUAL(1, result3.count);
    TEST_ASSERT_EQUAL(6, result3.positions[0]);
    kmp_result_destroy(&result3);

    // Test case 4: No match
    const char* text4 = "hello world";
    const char* pattern4 = "xyz";
    KMPResult result4;

    TEST_ASSERT_TRUE(kmp_search(text4, strlen(text4), pattern4, strlen(pattern4), &result4));
    TEST_ASSERT_EQUAL(0, result4.count);
    kmp_result_destroy(&result4);
}

// Test KMP search first
void test_kmp_search_first(void) {
    // Test case 1
    const char* text1 = "ABABDABACDABABCABCABCABCABC";
    const char* pattern1 = "ABABCAB";
    size_t position1;

    TEST_ASSERT_TRUE(kmp_search_first(text1, strlen(text1), pattern1, strlen(pattern1), &position1));
    TEST_ASSERT_EQUAL(10, position1);  // Correct position

    // Test case 2
    const char* text2 = "hello world";
    const char* pattern2 = "world";
    size_t position2;

    TEST_ASSERT_TRUE(kmp_search_first(text2, strlen(text2), pattern2, strlen(pattern2), &position2));
    TEST_ASSERT_EQUAL(6, position2);

    // Test case 3: No match
    const char* text3 = "hello world";
    const char* pattern3 = "xyz";
    size_t position3;

    TEST_ASSERT_TRUE(kmp_search_first(text3, strlen(text3), pattern3, strlen(pattern3), &position3));
    TEST_ASSERT_EQUAL((size_t)-1, position3);
}

// Test KMP matcher
void test_kmp_matcher(void) {
    KMPMatcher matcher;
    const char* pattern = "ABABCAB";

    // Initialize matcher
    TEST_ASSERT_TRUE(kmp_matcher_init(&matcher, pattern, strlen(pattern)));

    // Test search
    const char* text = "ABABDABACDABABCABCABCABCABC";
    KMPResult result;
    TEST_ASSERT_TRUE(kmp_matcher_search(&matcher, text, strlen(text), &result));
    TEST_ASSERT_EQUAL(1, result.count);
    TEST_ASSERT_EQUAL(10, result.positions[0]);  // Correct position
    kmp_result_destroy(&result);

    // Test search first
    size_t position;
    TEST_ASSERT_TRUE(kmp_matcher_search_first(&matcher, text, strlen(text), &position));
    TEST_ASSERT_EQUAL(10, position);  // Correct position

    // Destroy matcher
    kmp_matcher_destroy(&matcher);
}

// Test edge cases
void test_kmp_edge_cases(void) {
    KMPResult result;

    // Empty text
    TEST_ASSERT_TRUE(kmp_search("", 0, "pattern", 7, &result));
    TEST_ASSERT_EQUAL(0, result.count);
    kmp_result_destroy(&result);

    // Empty pattern
    TEST_ASSERT_TRUE(kmp_search("text", 4, "", 0, &result));
    TEST_ASSERT_EQUAL(0, result.count);
    kmp_result_destroy(&result);

    // Both empty
    TEST_ASSERT_TRUE(kmp_search("", 0, "", 0, &result));
    TEST_ASSERT_EQUAL(0, result.count);
    kmp_result_destroy(&result);

    // Pattern longer than text
    TEST_ASSERT_TRUE(kmp_search("hi", 2, "hello", 5, &result));
    TEST_ASSERT_EQUAL(0, result.count);
    kmp_result_destroy(&result);

    // NULL inputs
    TEST_ASSERT_FALSE(kmp_search(NULL, 5, "pattern", 7, &result));
    TEST_ASSERT_FALSE(kmp_search("text", 4, NULL, 7, &result));
    TEST_ASSERT_FALSE(kmp_search("text", 4, "pattern", 7, NULL));
}

// Test result management
void test_kmp_result_management(void) {
    KMPResult result;

    // Initialize
    TEST_ASSERT_TRUE(kmp_result_init(&result, 5));
    TEST_ASSERT_EQUAL(0, result.count);
    TEST_ASSERT_EQUAL(5, result.capacity);

    // Add positions
    TEST_ASSERT_TRUE(kmp_result_add_position(&result, 10));
    TEST_ASSERT_TRUE(kmp_result_add_position(&result, 20));
    TEST_ASSERT_TRUE(kmp_result_add_position(&result, 30));
    TEST_ASSERT_EQUAL(3, result.count);

    // Verify positions
    TEST_ASSERT_EQUAL(10, result.positions[0]);
    TEST_ASSERT_EQUAL(20, result.positions[1]);
    TEST_ASSERT_EQUAL(30, result.positions[2]);

    // Destroy
    kmp_result_destroy(&result);
    TEST_ASSERT_NULL(result.positions);
    TEST_ASSERT_EQUAL(0, result.count);
    TEST_ASSERT_EQUAL(0, result.capacity);
}

// Test failure function to string
void test_kmp_failure_function_to_string(void) {
    size_t lps[] = {0, 0, 1, 2, 0, 1, 2, 1, 2};
    size_t len = sizeof(lps) / sizeof(lps[0]);
    char buffer[256];

    TEST_ASSERT_TRUE(kmp_failure_function_to_string(lps, len, buffer, sizeof(buffer)));
    TEST_ASSERT_EQUAL_STRING("[0, 0, 1, 2, 0, 1, 2, 1, 2]", buffer);

    // Test with empty array
    TEST_ASSERT_TRUE(kmp_failure_function_to_string(lps, 0, buffer, sizeof(buffer)));
    TEST_ASSERT_EQUAL_STRING("[]", buffer);

    // Test with single element
    size_t single_lps[] = {0};
    TEST_ASSERT_TRUE(kmp_failure_function_to_string(single_lps, 1, buffer, sizeof(buffer)));
    TEST_ASSERT_EQUAL_STRING("[0]", buffer);
}

// Test complex patterns
void test_kmp_complex_patterns(void) {
    // Test overlapping patterns
    const char* text = "AAAAA";
    const char* pattern = "AA";
    KMPResult result;

    TEST_ASSERT_TRUE(kmp_search(text, strlen(text), pattern, strlen(pattern), &result));
    TEST_ASSERT_EQUAL(4, result.count);  // Should find 4 overlapping matches
    TEST_ASSERT_EQUAL(0, result.positions[0]);
    TEST_ASSERT_EQUAL(1, result.positions[1]);
    TEST_ASSERT_EQUAL(2, result.positions[2]);
    TEST_ASSERT_EQUAL(3, result.positions[3]);
    kmp_result_destroy(&result);

    // Test pattern at end of text
    const char* text2 = "hello world";
    const char* pattern2 = "world";
    size_t position;

    TEST_ASSERT_TRUE(kmp_search_first(text2, strlen(text2), pattern2, strlen(pattern2), &position));
    TEST_ASSERT_EQUAL(6, position);
}

// Main test runner
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_kmp_build_failure_function);
    RUN_TEST(test_kmp_search_basic);
    RUN_TEST(test_kmp_search_first);
    RUN_TEST(test_kmp_matcher);
    RUN_TEST(test_kmp_edge_cases);
    RUN_TEST(test_kmp_result_management);
    RUN_TEST(test_kmp_failure_function_to_string);
    RUN_TEST(test_kmp_complex_patterns);

    return UNITY_END();
}