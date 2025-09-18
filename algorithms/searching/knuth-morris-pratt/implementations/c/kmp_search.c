/**
 * Knuth-Morris-Pratt (KMP) String Matching Algorithm Implementation in C - Source File
 * KMP字符串匹配算法的C语言实现 - 源文件
 */

#include "kmp_search.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Build the failure function (LPS array) for the KMP algorithm
 * 构建KMP算法的失败函数（LPS数组）
 */
bool kmp_build_failure_function(const char* pattern, size_t pattern_length,
                               size_t* failure_function) {
    if (pattern == NULL || failure_function == NULL || pattern_length == 0) {
        return false;
    }

    // Initialize first element
    failure_function[0] = 0;

    size_t length = 0;  // Length of the previous longest prefix suffix
    size_t i = 1;       // Start from the second character

    // Build the failure function
    while (i < pattern_length) {
        if (pattern[i] == pattern[length]) {
            length++;
            failure_function[i] = length;
            i++;
        } else {
            // This is tricky. Consider the example "AAACAAAA" and i = 7.
            // The idea is similar to search algorithm.
            if (length != 0) {
                length = failure_function[length - 1];
                // Also, note that we do not increment i here
            } else {
                failure_function[i] = 0;
                i++;
            }
        }
    }

    return true;
}

/**
 * Search for all occurrences of pattern in text using KMP algorithm
 * 使用KMP算法在文本中搜索模式的全部出现位置
 */
bool kmp_search(const char* text, size_t text_length,
               const char* pattern, size_t pattern_length,
               KMPResult* result) {
    if (text == NULL || pattern == NULL || result == NULL) {
        return false;
    }

    // Initialize result first
    if (!kmp_result_init(result, 10)) {  // Start with capacity of 10
        return false;
    }

    if (pattern_length == 0 || text_length == 0 || pattern_length > text_length) {
        return true;  // Empty pattern, empty text, or pattern longer than text
    }

    // Build failure function
    size_t* lps = (size_t*)malloc(pattern_length * sizeof(size_t));
    if (lps == NULL) {
        kmp_result_destroy(result);
        return false;
    }

    if (!kmp_build_failure_function(pattern, pattern_length, lps)) {
        free(lps);
        kmp_result_destroy(result);
        return false;
    }

    size_t i = 0;  // Index for text
    size_t j = 0;  // Index for pattern

    while (i < text_length) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == pattern_length) {
            // Found a match
            if (!kmp_result_add_position(result, i - j)) {
                free(lps);
                kmp_result_destroy(result);
                return false;
            }
            j = lps[j - 1];
        } else if (i < text_length && pattern[j] != text[i]) {
            // Do not match j with lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    free(lps);
    return true;
}

/**
 * Search for the first occurrence of pattern in text using KMP algorithm
 * 使用KMP算法在文本中搜索模式的第一处出现位置
 */
bool kmp_search_first(const char* text, size_t text_length,
                     const char* pattern, size_t pattern_length,
                     size_t* position) {
    if (text == NULL || pattern == NULL || position == NULL) {
        return false;
    }

    *position = (size_t)-1;  // Initialize to -1 (not found)

    if (pattern_length == 0 || text_length == 0 || pattern_length > text_length) {
        return true;  // Empty pattern, empty text, or pattern longer than text
    }

    // Build failure function
    size_t* lps = (size_t*)malloc(pattern_length * sizeof(size_t));
    if (lps == NULL) {
        return false;
    }

    if (!kmp_build_failure_function(pattern, pattern_length, lps)) {
        free(lps);
        return false;
    }

    size_t i = 0;  // Index for text
    size_t j = 0;  // Index for pattern

    while (i < text_length) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == pattern_length) {
            // Found first match
            *position = i - j;
            free(lps);
            return true;
        } else if (i < text_length && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    free(lps);
    return true;
}

/**
 * Initialize a KMP matcher with a pattern
 * 使用模式初始化KMP匹配器
 */
bool kmp_matcher_init(KMPMatcher* matcher, const char* pattern, size_t pattern_length) {
    if (matcher == NULL || pattern == NULL || pattern_length == 0) {
        return false;
    }

    matcher->pattern = pattern;
    matcher->pattern_length = pattern_length;

    // Allocate and build failure function
    matcher->failure_function = (size_t*)malloc(pattern_length * sizeof(size_t));
    if (matcher->failure_function == NULL) {
        return false;
    }

    if (!kmp_build_failure_function(pattern, pattern_length, matcher->failure_function)) {
        free(matcher->failure_function);
        matcher->failure_function = NULL;
        return false;
    }

    return true;
}

/**
 * Destroy a KMP matcher and free its resources
 * 销毁KMP匹配器并释放资源
 */
void kmp_matcher_destroy(KMPMatcher* matcher) {
    if (matcher == NULL) {
        return;
    }

    if (matcher->failure_function != NULL) {
        free(matcher->failure_function);
        matcher->failure_function = NULL;
    }

    matcher->pattern = NULL;
    matcher->pattern_length = 0;
}

/**
 * Search for all occurrences using a pre-initialized KMP matcher
 * 使用预初始化的KMP匹配器搜索全部出现位置
 */
bool kmp_matcher_search(const KMPMatcher* matcher,
                       const char* text, size_t text_length,
                       KMPResult* result) {
    if (matcher == NULL || text == NULL || result == NULL) {
        return false;
    }

    // Initialize result first
    if (!kmp_result_init(result, 10)) {  // Start with capacity of 10
        return false;
    }

    if (matcher->pattern_length == 0 || text_length == 0 || matcher->pattern_length > text_length) {
        return true;  // Empty pattern, empty text, or pattern longer than text
    }

    size_t i = 0;  // Index for text
    size_t j = 0;  // Index for pattern

    while (i < text_length) {
        if (matcher->pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == matcher->pattern_length) {
            // Found a match
            if (!kmp_result_add_position(result, i - j)) {
                kmp_result_destroy(result);
                return false;
            }
            j = matcher->failure_function[j - 1];
        } else if (i < text_length && matcher->pattern[j] != text[i]) {
            if (j != 0) {
                j = matcher->failure_function[j - 1];
            } else {
                i++;
            }
        }
    }

    return true;
}

/**
 * Search for first occurrence using a pre-initialized KMP matcher
 * 使用预初始化的KMP匹配器搜索第一处出现位置
 */
bool kmp_matcher_search_first(const KMPMatcher* matcher,
                             const char* text, size_t text_length,
                             size_t* position) {
    if (matcher == NULL || text == NULL || position == NULL) {
        return false;
    }

    *position = (size_t)-1;  // Initialize to -1 (not found)

    if (matcher->pattern_length == 0 || text_length == 0 || matcher->pattern_length > text_length) {
        return true;  // Empty pattern, empty text, or pattern longer than text
    }

    size_t i = 0;  // Index for text
    size_t j = 0;  // Index for pattern

    while (i < text_length) {
        if (matcher->pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == matcher->pattern_length) {
            // Found first match
            *position = i - j;
            return true;
        } else if (i < text_length && matcher->pattern[j] != text[i]) {
            if (j != 0) {
                j = matcher->failure_function[j - 1];
            } else {
                i++;
            }
        }
    }

    return true;
}

/**
 * Initialize a KMPResult structure
 * 初始化KMPResult结构体
 */
bool kmp_result_init(KMPResult* result, size_t initial_capacity) {
    if (result == NULL) {
        return false;
    }

    result->positions = NULL;
    result->count = 0;
    result->capacity = 0;

    if (initial_capacity > 0) {
        result->positions = (size_t*)malloc(initial_capacity * sizeof(size_t));
        if (result->positions == NULL) {
            return false;
        }
        result->capacity = initial_capacity;
    }

    return true;
}

/**
 * Destroy a KMPResult structure and free its resources
 * 销毁KMPResult结构体并释放资源
 */
void kmp_result_destroy(KMPResult* result) {
    if (result == NULL) {
        return;
    }

    if (result->positions != NULL) {
        free(result->positions);
        result->positions = NULL;
    }

    result->count = 0;
    result->capacity = 0;
}

/**
 * Add a position to the KMPResult
 * 向KMPResult添加位置
 */
bool kmp_result_add_position(KMPResult* result, size_t position) {
    if (result == NULL) {
        return false;
    }

    // Expand capacity if needed
    if (result->count >= result->capacity) {
        size_t new_capacity = (result->capacity == 0) ? 8 : result->capacity * 2;
        size_t* new_positions = (size_t*)realloc(result->positions, new_capacity * sizeof(size_t));

        if (new_positions == NULL) {
            return false;
        }

        result->positions = new_positions;
        result->capacity = new_capacity;
    }

    result->positions[result->count] = position;
    result->count++;

    return true;
}

/**
 * Get the failure function as a string representation
 * 获取失败函数的字符串表示
 */
bool kmp_failure_function_to_string(const size_t* failure_function, size_t length,
                                   char* buffer, size_t buffer_size) {
    if (failure_function == NULL || buffer == NULL || buffer_size == 0) {
        return false;
    }

    size_t offset = 0;
    buffer[offset++] = '[';

    for (size_t i = 0; i < length && offset < buffer_size - 1; i++) {
        if (i > 0) {
            buffer[offset++] = ',';
            if (offset >= buffer_size - 1) break;
            buffer[offset++] = ' ';
        }

        char num_str[32];
        int len = snprintf(num_str, sizeof(num_str), "%zu", failure_function[i]);
        if (len < 0 || (size_t)len >= sizeof(num_str)) {
            return false;
        }

        if (offset + len >= buffer_size - 1) {
            break;
        }

        memcpy(buffer + offset, num_str, len);
        offset += len;
    }

    if (offset < buffer_size - 1) {
        buffer[offset++] = ']';
    }
    buffer[offset] = '\0';

    return true;
}