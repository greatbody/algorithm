/**
 * KMP Search Demo Program in C
 * C语言KMP搜索演示程序
 *
 * This program demonstrates the usage of the KMP Search implementation
 * 本程序演示KMP搜索实现的使用方法
 */

#include "kmp_search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Demo function for basic KMP search operations
void demo_basic_search(void) {
    printf("=== Basic KMP Search Operations ===\n");

    const char* text1 = "ABABDABACDABABCABCABCABCABC";
    const char* pattern1 = "ABABCAB";

    printf("Text: %s\n", text1);
    printf("Pattern: %s\n", pattern1);

    KMPResult result;
    if (kmp_search(text1, strlen(text1), pattern1, strlen(pattern1), &result)) {
        printf("Matches found at positions: ");
        for (size_t i = 0; i < result.count; i++) {
            printf("%zu", result.positions[i]);
            if (i < result.count - 1) printf(", ");
        }
        printf("\n");
    } else {
        printf("Search failed\n");
    }
    kmp_result_destroy(&result);

    printf("\n");
}

// Demo function for multiple matches
void demo_multiple_matches(void) {
    printf("=== Multiple Matches Example ===\n");

    const char* text = "AABAACAADAABAABA";
    const char* pattern = "AABA";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    KMPResult result;
    if (kmp_search(text, strlen(text), pattern, strlen(pattern), &result)) {
        printf("Matches found at positions: ");
        for (size_t i = 0; i < result.count; i++) {
            printf("%zu", result.positions[i]);
            if (i < result.count - 1) printf(", ");
        }
        printf(" (%zu matches)\n", result.count);
    }
    kmp_result_destroy(&result);

    printf("\n");
}

// Demo function for failure function
void demo_failure_function(void) {
    printf("=== Failure Function (LPS Array) ===\n");

    const char* patterns[] = {
        "ABABCABAB",
        "AAAA",
        "ABCDABCD",
        "AABAACAABAA"
    };

    size_t num_patterns = sizeof(patterns) / sizeof(patterns[0]);

    for (size_t i = 0; i < num_patterns; i++) {
        const char* pattern = patterns[i];
        size_t len = strlen(pattern);
        size_t* lps = (size_t*)malloc(len * sizeof(size_t));

        if (kmp_build_failure_function(pattern, len, lps)) {
            printf("Pattern: %s\n", pattern);
            printf("LPS: [");
            for (size_t j = 0; j < len; j++) {
                printf("%zu", lps[j]);
                if (j < len - 1) printf(", ");
            }
            printf("]\n");

            // Also show as string
            char buffer[256];
            if (kmp_failure_function_to_string(lps, len, buffer, sizeof(buffer))) {
                printf("As string: %s\n", buffer);
            }
        } else {
            printf("Failed to build failure function for: %s\n", pattern);
        }

        free(lps);
        printf("\n");
    }
}

// Demo function for KMP matcher class
void demo_kmp_matcher(void) {
    printf("=== KMP Matcher Class Demo ===\n");

    const char* pattern = "ana";
    KMPMatcher matcher;

    if (kmp_matcher_init(&matcher, pattern, strlen(pattern))) {
        printf("Initialized KMP matcher with pattern: %s\n", pattern);

        // Show failure function
        printf("Failure function: [");
        for (size_t i = 0; i < matcher.pattern_length; i++) {
            printf("%zu", matcher.failure_function[i]);
            if (i < matcher.pattern_length - 1) printf(", ");
        }
        printf("]\n");

        // Test search
        const char* text = "banana";
        printf("Searching in text: %s\n", text);

        KMPResult result;
        if (kmp_matcher_search(&matcher, text, strlen(text), &result)) {
            printf("Matches found at positions: ");
            for (size_t i = 0; i < result.count; i++) {
                printf("%zu", result.positions[i]);
                if (i < result.count - 1) printf(", ");
            }
            printf(" (%zu matches)\n", result.count);
        }
        kmp_result_destroy(&result);

        // Test search first
        size_t position;
        if (kmp_matcher_search_first(&matcher, text, strlen(text), &position)) {
            if (position != (size_t)-1) {
                printf("First match at position: %zu\n", position);
            } else {
                printf("No match found\n");
            }
        }

        kmp_matcher_destroy(&matcher);
    } else {
        printf("Failed to initialize KMP matcher\n");
    }

    printf("\n");
}

// Demo function for case-insensitive search
void demo_case_insensitive(void) {
    printf("=== Case-Insensitive Search Example ===\n");

    const char* text = "The quick brown fox jumps over the lazy dog";
    const char* pattern = "the";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    // Convert both to lowercase for case-insensitive search
    char* text_lower = strdup(text);
    char* pattern_lower = strdup(pattern);

    if (text_lower && pattern_lower) {
        for (size_t i = 0; text_lower[i]; i++) {
            text_lower[i] = tolower(text_lower[i]);
        }
        for (size_t i = 0; pattern_lower[i]; i++) {
            pattern_lower[i] = tolower(pattern_lower[i]);
        }

        KMPResult result;
        if (kmp_search(text_lower, strlen(text_lower), pattern_lower, strlen(pattern_lower), &result)) {
            printf("Case-insensitive matches found at positions: ");
            for (size_t i = 0; i < result.count; i++) {
                printf("%zu", result.positions[i]);
                if (i < result.count - 1) printf(", ");
            }
            printf(" (%zu matches)\n", result.count);
        }
        kmp_result_destroy(&result);
    }

    free(text_lower);
    free(pattern_lower);

    printf("\n");
}

// Demo function for overlapping patterns
void demo_overlapping_patterns(void) {
    printf("=== Overlapping Patterns Example ===\n");

    const char* text = "AAAAA";
    const char* pattern = "AA";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    KMPResult result;
    if (kmp_search(text, strlen(text), pattern, strlen(pattern), &result)) {
        printf("Matches found at positions: ");
        for (size_t i = 0; i < result.count; i++) {
            printf("%zu", result.positions[i]);
            if (i < result.count - 1) printf(", ");
        }
        printf(" (%zu matches)\n", result.count);

        // Show each match
        printf("Matches: ");
        for (size_t i = 0; i < result.count; i++) {
            size_t start = result.positions[i];
            printf("\"%.*s\"", (int)strlen(pattern), text + start);
            if (i < result.count - 1) printf(", ");
        }
        printf("\n");
    }
    kmp_result_destroy(&result);

    printf("\n");
}

// Demo function for edge cases
void demo_edge_cases(void) {
    printf("=== Edge Cases ===\n");

    // Empty text
    KMPResult result;
    if (kmp_search("", 0, "pattern", 7, &result)) {
        printf("Empty text search: %zu matches\n", result.count);
    }
    kmp_result_destroy(&result);

    // Empty pattern
    if (kmp_search("text", 4, "", 0, &result)) {
        printf("Empty pattern search: %zu matches\n", result.count);
    }
    kmp_result_destroy(&result);

    // Pattern longer than text
    if (kmp_search("hi", 2, "hello", 5, &result)) {
        printf("Pattern longer than text: %zu matches\n", result.count);
    }
    kmp_result_destroy(&result);

    // Pattern not found
    const char* text = "hello world";
    const char* pattern = "xyz";
    if (kmp_search(text, strlen(text), pattern, strlen(pattern), &result)) {
        printf("Pattern '%s' in text '%s': %zu matches\n", pattern, text, result.count);
    }
    kmp_result_destroy(&result);

    printf("\n");
}

int main(void) {
    printf("KMP String Matching Algorithm Demo in C\n");
    printf("========================================\n\n");

    demo_basic_search();
    demo_multiple_matches();
    demo_failure_function();
    demo_kmp_matcher();
    demo_case_insensitive();
    demo_overlapping_patterns();
    demo_edge_cases();

    printf("Demo completed successfully!\n");
    return 0;
}