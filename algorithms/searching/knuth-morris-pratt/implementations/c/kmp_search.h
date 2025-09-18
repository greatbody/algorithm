/**
 * Knuth-Morris-Pratt (KMP) String Matching Algorithm Implementation in C
 * KMP字符串匹配算法的C语言实现
 *
 * Time Complexity: O(n + m) where n is text length and m is pattern length
 * Space Complexity: O(m) for the failure function array
 */

#ifndef KMP_SEARCH_H
#define KMP_SEARCH_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * KMP search result structure
 * KMP搜索结果结构体
 */
typedef struct {
    size_t* positions;    // Array of match positions
    size_t count;         // Number of matches found
    size_t capacity;      // Capacity of positions array
} KMPResult;

/**
 * KMP matcher structure (equivalent to Python's KMPMatcher class)
 * KMP匹配器结构体（相当于Python的KMPMatcher类）
 */
typedef struct {
    const char* pattern;        // The pattern string
    size_t pattern_length;      // Length of the pattern
    size_t* failure_function;   // Precomputed failure function (LPS array)
} KMPMatcher;

/**
 * Build the failure function (LPS array) for the KMP algorithm
 * 构建KMP算法的失败函数（LPS数组）
 *
 * @param pattern The pattern string
 * @param pattern_length Length of the pattern
 * @param failure_function Output array for failure function (must be pre-allocated)
 * @return true on success, false on failure
 */
bool kmp_build_failure_function(const char* pattern, size_t pattern_length,
                               size_t* failure_function);

/**
 * Search for all occurrences of pattern in text using KMP algorithm
 * 使用KMP算法在文本中搜索模式的全部出现位置
 *
 * @param text The text string to search in
 * @param text_length Length of the text
 * @param pattern The pattern string to search for
 * @param pattern_length Length of the pattern
 * @param result Pointer to KMPResult structure to store results
 * @return true on success, false on failure
 */
bool kmp_search(const char* text, size_t text_length,
               const char* pattern, size_t pattern_length,
               KMPResult* result);

/**
 * Search for the first occurrence of pattern in text using KMP algorithm
 * 使用KMP算法在文本中搜索模式的第一处出现位置
 *
 * @param text The text string to search in
 * @param text_length Length of the text
 * @param pattern The pattern string to search for
 * @param pattern_length Length of the pattern
 * @param position Pointer to store the position of first match (-1 if not found)
 * @return true on success, false on failure
 */
bool kmp_search_first(const char* text, size_t text_length,
                     const char* pattern, size_t pattern_length,
                     size_t* position);

/**
 * Initialize a KMP matcher with a pattern
 * 使用模式初始化KMP匹配器
 *
 * @param matcher Pointer to KMPMatcher structure
 * @param pattern The pattern string
 * @param pattern_length Length of the pattern
 * @return true on success, false on failure
 */
bool kmp_matcher_init(KMPMatcher* matcher, const char* pattern, size_t pattern_length);

/**
 * Destroy a KMP matcher and free its resources
 * 销毁KMP匹配器并释放资源
 *
 * @param matcher Pointer to KMPMatcher structure
 */
void kmp_matcher_destroy(KMPMatcher* matcher);

/**
 * Search for all occurrences using a pre-initialized KMP matcher
 * 使用预初始化的KMP匹配器搜索全部出现位置
 *
 * @param matcher Pointer to initialized KMPMatcher
 * @param text The text string to search in
 * @param text_length Length of the text
 * @param result Pointer to KMPResult structure to store results
 * @return true on success, false on failure
 */
bool kmp_matcher_search(const KMPMatcher* matcher,
                       const char* text, size_t text_length,
                       KMPResult* result);

/**
 * Search for first occurrence using a pre-initialized KMP matcher
 * 使用预初始化的KMP匹配器搜索第一处出现位置
 *
 * @param matcher Pointer to initialized KMPMatcher
 * @param text The text string to search in
 * @param text_length Length of the text
 * @param position Pointer to store the position of first match (-1 if not found)
 * @return true on success, false on failure
 */
bool kmp_matcher_search_first(const KMPMatcher* matcher,
                             const char* text, size_t text_length,
                             size_t* position);

/**
 * Initialize a KMPResult structure
 * 初始化KMPResult结构体
 *
 * @param result Pointer to KMPResult structure
 * @param initial_capacity Initial capacity for positions array
 * @return true on success, false on failure
 */
bool kmp_result_init(KMPResult* result, size_t initial_capacity);

/**
 * Destroy a KMPResult structure and free its resources
 * 销毁KMPResult结构体并释放资源
 *
 * @param result Pointer to KMPResult structure
 */
void kmp_result_destroy(KMPResult* result);

/**
 * Add a position to the KMPResult
 * 向KMPResult添加位置
 *
 * @param result Pointer to KMPResult structure
 * @param position Position to add
 * @return true on success, false on failure
 */
bool kmp_result_add_position(KMPResult* result, size_t position);

/**
 * Get the failure function as a string representation
 * 获取失败函数的字符串表示
 *
 * @param failure_function The failure function array
 * @param length Length of the failure function array
 * @param buffer Output buffer for string representation
 * @param buffer_size Size of the output buffer
 * @return true on success, false on failure
 */
bool kmp_failure_function_to_string(const size_t* failure_function, size_t length,
                                   char* buffer, size_t buffer_size);

#ifdef __cplusplus
}
#endif

#endif /* KMP_SEARCH_H */