/**
 * Knuth-Morris-Pratt (KMP) String Matching Algorithm Implementation in C++
 * KMP字符串匹配算法的C++实现
 *
 * Time Complexity: O(n + m) where n is text length and m is pattern length
 * Space Complexity: O(m) for the failure function array
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <chrono>
#include <cassert>

/**
 * Build the failure function (LPS array) for the KMP algorithm.
 *
 * The failure function stores the length of the longest proper prefix 
 * which is also a suffix for each position in the pattern.
 *
 * @param pattern The pattern string for which to build the failure function
 * @return Failure function vector where lps[i] represents the length of 
 *         the longest proper prefix which is also a suffix for pattern[0:i+1]
 */
std::vector<int> buildFailureFunction(const std::string& pattern) {
    if (pattern.empty()) {
        return std::vector<int>();
    }
    
    int m = static_cast<int>(pattern.length());
    std::vector<int> lps(m, 0); // Longest Proper Prefix which is also Suffix
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;      // Start from the second character
    
    // Build the failure function
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            // This is tricky. Consider the example "AAACAAAA" and i = 7.
            // The idea is similar to search algorithm.
            if (length != 0) {
                length = lps[length - 1];
                // Also, note that we do not increment i here
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

/**
 * Search for all occurrences of pattern in text using KMP algorithm.
 *
 * @param text The text string in which to search
 * @param pattern The pattern string to search for
 * @return Vector of starting positions where pattern is found in text
 */
std::vector<int> kmpSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> positions;
    
    if (text.empty() || pattern.empty()) {
        return positions;
    }
    
    int n = static_cast<int>(text.length());
    int m = static_cast<int>(pattern.length());
    
    // Get the failure function for the pattern
    std::vector<int> lps = buildFailureFunction(pattern);
    
    int i = 0; // Index for text
    int j = 0; // Index for pattern
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        
        if (j == m) {
            // Found a match
            positions.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            // Do not match j with lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return positions;
}

/**
 * Search for the first occurrence of pattern in text using KMP algorithm.
 *
 * @param text The text string in which to search
 * @param pattern The pattern string to search for
 * @return Starting position of first match, or -1 if not found
 */
int kmpSearchFirst(const std::string& text, const std::string& pattern) {
    std::vector<int> positions = kmpSearch(text, pattern);
    return positions.empty() ? -1 : positions[0];
}

/**
 * Validate input parameters for KMP search functions.
 *
 * @param text The text string
 * @param pattern The pattern string
 * @throws std::invalid_argument if pattern is empty
 */
void validateInput(const std::string& text, const std::string& pattern) {
    if (pattern.empty()) {
        throw std::invalid_argument("Pattern cannot be empty");
    }
}

/**
 * A class-based implementation of KMP string matching algorithm.
 *
 * This class allows for pattern preprocessing and multiple searches
 * with the same pattern for better performance.
 */
class KMPMatcher {
private:
    std::string pattern;
    std::vector<int> failureFunction;
    
public:
    /**
     * Initialize the KMP matcher with a pattern.
     *
     * @param pat The pattern to search for
     * @throws std::invalid_argument if pattern is empty
     */
    explicit KMPMatcher(const std::string& pat) : pattern(pat) {
        if (pattern.empty()) {
            throw std::invalid_argument("Pattern cannot be empty");
        }
        
        failureFunction = buildFailureFunction(pattern);
    }
    
    /**
     * Search for all occurrences of the pattern in the given text.
     *
     * @param text The text to search in
     * @return Vector of starting positions where pattern is found
     */
    std::vector<int> search(const std::string& text) const {
        return kmpSearch(text, pattern);
    }
    
    /**
     * Search for the first occurrence of the pattern in the given text.
     *
     * @param text The text to search in
     * @return Starting position of first match, or -1 if not found
     */
    int searchFirst(const std::string& text) const {
        std::vector<int> positions = search(text);
        return positions.empty() ? -1 : positions[0];
    }
    
    /**
     * Get the pattern string.
     *
     * @return The pattern string
     */
    const std::string& getPattern() const {
        return pattern;
    }
    
    /**
     * Get the failure function (LPS array) for the pattern.
     *
     * @return The failure function vector
     */
    const std::vector<int>& getFailureFunction() const {
        return failureFunction;
    }
};

/**
 * Utility function to print a vector of integers.
 *
 * @param vec The vector to print
 * @return String representation of the vector
 */
std::string vectorToString(const std::vector<int>& vec) {
    std::string result = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) result += ", ";
        result += std::to_string(vec[i]);
    }
    result += "]";
    return result;
}

/**
 * Run comprehensive tests for the KMP implementation.
 */
void runTests() {
    std::cout << "🧪 Running KMP Algorithm Tests" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    int passed = 0;
    int failed = 0;
    
    auto test = [&](const std::string& name, std::function<void()> fn) {
        try {
            fn();
            std::cout << "✅ " << name << std::endl;
            passed++;
        } catch (const std::exception& e) {
            std::cout << "❌ " << name << ": " << e.what() << std::endl;
            failed++;
        }
    };
    
    // Test buildFailureFunction
    test("buildFailureFunction - Basic pattern", []() {
        auto result = buildFailureFunction("ABABCABAB");
        std::vector<int> expected = {0, 0, 1, 2, 0, 1, 2, 1, 2};
        assert(result == expected);
    });
    
    test("buildFailureFunction - All same characters", []() {
        auto result = buildFailureFunction("AAAA");
        std::vector<int> expected = {0, 1, 2, 3};
        assert(result == expected);
    });
    
    test("buildFailureFunction - Empty string", []() {
        auto result = buildFailureFunction("");
        std::vector<int> expected = {};
        assert(result == expected);
    });
    
    // Test kmpSearch
    test("kmpSearch - Basic search", []() {
        auto result = kmpSearch("ABABDABACDABABCABCABCABCABC", "ABABCAB");
        std::vector<int> expected = {15};
        assert(result == expected);
    });
    
    test("kmpSearch - Multiple matches", []() {
        auto result = kmpSearch("AABAACAADAABAABA", "AABA");
        std::vector<int> expected = {0, 9, 12};
        assert(result == expected);
    });
    
    test("kmpSearch - No matches", []() {
        auto result = kmpSearch("hello world", "xyz");
        std::vector<int> expected = {};
        assert(result == expected);
    });
    
    // Test KMPMatcher class
    test("KMPMatcher - Constructor and search", []() {
        KMPMatcher matcher("ana");
        auto result = matcher.search("banana");
        std::vector<int> expected = {1, 3};
        assert(result == expected);
    });
    
    test("KMPMatcher - Invalid empty pattern", []() {
        try {
            KMPMatcher matcher("");
            assert(false); // Should not reach here
        } catch (const std::invalid_argument&) {
            // Expected
        }
    });
    
    // Performance test
    test("Performance test", []() {
        std::string largeText(10000, 'A');
        largeText += "PATTERN";
        largeText += std::string(10000, 'B');
        
        auto start = std::chrono::high_resolution_clock::now();
        auto result = kmpSearch(largeText, "PATTERN");
        auto end = std::chrono::high_resolution_clock::now();
        
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        std::vector<int> expected = {10000};
        assert(result == expected);
        
        std::cout << "    Performance: " << duration.count() << " microseconds" << std::endl;
    });
    
    std::cout << std::endl << std::string(50, '=') << std::endl;
    std::cout << "📊 Test Results: " << passed << " passed, " << failed << " failed" << std::endl;
    std::cout << "✨ Success Rate: " << (100.0 * passed / (passed + failed)) << "%" << std::endl;
    
    if (failed == 0) {
        std::cout << "🎉 All tests passed!" << std::endl;
    } else {
        std::cout << "❗ Some tests failed. Please check the implementation." << std::endl;
    }
}

/**
 * Demonstrate the KMP algorithm with examples.
 */
void demonstrateKMP() {
    std::cout << "KMP String Matching Algorithm Demo" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    
    // Test case 1: Basic search
    std::string text1 = "ABABDABACDABABCABCABCABCABC";
    std::string pattern1 = "ABABCAB";
    auto result1 = kmpSearch(text1, pattern1);
    std::cout << "Text: " << text1 << std::endl;
    std::cout << "Pattern: " << pattern1 << std::endl;
    std::cout << "Matches found at positions: " << vectorToString(result1) << std::endl;
    std::cout << std::endl;
    
    // Test case 2: Multiple matches
    std::string text2 = "AABAACAADAABAABA";
    std::string pattern2 = "AABA";
    auto result2 = kmpSearch(text2, pattern2);
    std::cout << "Text: " << text2 << std::endl;
    std::cout << "Pattern: " << pattern2 << std::endl;
    std::cout << "Matches found at positions: " << vectorToString(result2) << std::endl;
    std::cout << std::endl;
    
    // Test case 3: Using KMPMatcher class
    KMPMatcher matcher("ana");
    std::string text3 = "banana";
    auto result3 = matcher.search(text3);
    std::cout << "Using KMPMatcher class:" << std::endl;
    std::cout << "Text: " << text3 << std::endl;
    std::cout << "Pattern: " << matcher.getPattern() << std::endl;
    std::cout << "Matches found at positions: " << vectorToString(result3) << std::endl;
    std::cout << "Failure function: " << vectorToString(matcher.getFailureFunction()) << std::endl;
    std::cout << std::endl;
    
    // Test case 4: Failure function demonstration
    std::vector<std::string> patterns = {"ABABCABAB", "AAAA", "ABCDABCD"};
    std::cout << "Failure Function Examples:" << std::endl;
    for (const auto& pattern : patterns) {
        auto lps = buildFailureFunction(pattern);
        std::cout << "Pattern: " << pattern << " → LPS: " << vectorToString(lps) << std::endl;
    }
}

/**
 * Main function - entry point of the program.
 *
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 * @return Exit status
 */
int main(int argc, char* argv[]) {
    try {
        if (argc > 1 && std::string(argv[1]) == "--test") {
            runTests();
        } else {
            demonstrateKMP();
        }
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}