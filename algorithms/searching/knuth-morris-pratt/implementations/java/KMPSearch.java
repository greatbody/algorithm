/**
 * Knuth-Morris-Pratt (KMP) String Matching Algorithm Implementation in Java
 * KMP字符串匹配算法的Java实现
 * 
 * Time Complexity: O(n + m) where n is text length and m is pattern length
 * Space Complexity: O(m) for the failure function array
 * 
 * @author Algorithm Collection Repository
 * @version 1.0
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class KMPSearch {
    
    /**
     * Build the failure function (LPS array) for the KMP algorithm.
     * 
     * The failure function stores the length of the longest proper prefix 
     * which is also a suffix for each position in the pattern.
     * 
     * @param pattern The pattern string for which to build the failure function
     * @return Failure function array where lps[i] represents the length of 
     *         the longest proper prefix which is also a suffix for pattern[0:i+1]
     * @throws IllegalArgumentException if pattern is null
     */
    public static int[] buildFailureFunction(String pattern) {
        if (pattern == null) {
            throw new IllegalArgumentException("Pattern cannot be null");
        }
        
        if (pattern.isEmpty()) {
            return new int[0];
        }
        
        int m = pattern.length();
        int[] lps = new int[m]; // Longest Proper Prefix which is also Suffix
        int length = 0; // Length of the previous longest prefix suffix
        int i = 1;      // Start from the second character
        
        // Build the failure function
        while (i < m) {
            if (pattern.charAt(i) == pattern.charAt(length)) {
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
     * @return List of starting positions where pattern is found in text
     * @throws IllegalArgumentException if text or pattern is null
     */
    public static List<Integer> search(String text, String pattern) {
        if (text == null) {
            throw new IllegalArgumentException("Text cannot be null");
        }
        if (pattern == null) {
            throw new IllegalArgumentException("Pattern cannot be null");
        }
        
        List<Integer> positions = new ArrayList<>();
        
        if (text.isEmpty() || pattern.isEmpty()) {
            return positions;
        }
        
        int n = text.length();
        int m = pattern.length();
        
        // Get the failure function for the pattern
        int[] lps = buildFailureFunction(pattern);
        
        int i = 0; // Index for text
        int j = 0; // Index for pattern
        
        while (i < n) {
            if (pattern.charAt(j) == text.charAt(i)) {
                j++;
                i++;
            }
            
            if (j == m) {
                // Found a match
                positions.add(i - j);
                j = lps[j - 1];
            } else if (i < n && pattern.charAt(j) != text.charAt(i)) {
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
     * @throws IllegalArgumentException if text or pattern is null
     */
    public static int searchFirst(String text, String pattern) {
        List<Integer> positions = search(text, pattern);
        return positions.isEmpty() ? -1 : positions.get(0);
    }
    
    /**
     * Validate input parameters for KMP search functions.
     * 
     * @param text The text string
     * @param pattern The pattern string
     * @throws IllegalArgumentException if inputs are null or pattern is empty
     */
    public static void validateInput(String text, String pattern) {
        if (text == null) {
            throw new IllegalArgumentException("Text cannot be null");
        }
        if (pattern == null) {
            throw new IllegalArgumentException("Pattern cannot be null");
        }
        if (pattern.isEmpty()) {
            throw new IllegalArgumentException("Pattern cannot be empty");
        }
    }
    
    /**
     * A matcher class that allows for pattern preprocessing and multiple searches
     * with the same pattern for better performance.
     */
    public static class KMPMatcher {
        private final String pattern;
        private final int[] failureFunction;
        
        /**
         * Initialize the KMP matcher with a pattern.
         * 
         * @param pattern The pattern to search for
         * @throws IllegalArgumentException if pattern is null or empty
         */
        public KMPMatcher(String pattern) {
            if (pattern == null) {
                throw new IllegalArgumentException("Pattern cannot be null");
            }
            if (pattern.isEmpty()) {
                throw new IllegalArgumentException("Pattern cannot be empty");
            }
            
            this.pattern = pattern;
            this.failureFunction = buildFailureFunction(pattern);
        }
        
        /**
         * Search for all occurrences of the pattern in the given text.
         * 
         * @param text The text to search in
         * @return List of starting positions where pattern is found
         * @throws IllegalArgumentException if text is null
         */
        public List<Integer> search(String text) {
            if (text == null) {
                throw new IllegalArgumentException("Text cannot be null");
            }
            
            return KMPSearch.search(text, this.pattern);
        }
        
        /**
         * Search for the first occurrence of the pattern in the given text.
         * 
         * @param text The text to search in
         * @return Starting position of first match, or -1 if not found
         * @throws IllegalArgumentException if text is null
         */
        public int searchFirst(String text) {
            List<Integer> positions = search(text);
            return positions.isEmpty() ? -1 : positions.get(0);
        }
        
        /**
         * Get the pattern string.
         * 
         * @return The pattern string
         */
        public String getPattern() {
            return pattern;
        }
        
        /**
         * Get a copy of the failure function (LPS array) for the pattern.
         * 
         * @return Copy of the failure function array
         */
        public int[] getFailureFunction() {
            return Arrays.copyOf(failureFunction, failureFunction.length);
        }
    }
    
    /**
     * Utility method to print array nicely.
     * 
     * @param array The array to print
     * @return String representation of the array
     */
    private static String arrayToString(int[] array) {
        return Arrays.toString(array);
    }
    
    /**
     * Utility method to print list nicely.
     * 
     * @param list The list to print
     * @return String representation of the list
     */
    private static String listToString(List<Integer> list) {
        return list.toString();
    }
    
    /**
     * Example usage and demonstration of the KMP algorithm.
     * 
     * @param args Command line arguments (not used)
     */
    public static void main(String[] args) {
        System.out.println("KMP String Matching Algorithm Demo");
        System.out.println("=".repeat(40));
        
        // Test case 1: Basic search
        String text1 = "ABABDABACDABABCABCABCABCABC";
        String pattern1 = "ABABCAB";
        List<Integer> result1 = search(text1, pattern1);
        System.out.println("Text: " + text1);
        System.out.println("Pattern: " + pattern1);
        System.out.println("Matches found at positions: " + listToString(result1));
        System.out.println();
        
        // Test case 2: Multiple matches
        String text2 = "AABAACAADAABAABA";
        String pattern2 = "AABA";
        List<Integer> result2 = search(text2, pattern2);
        System.out.println("Text: " + text2);
        System.out.println("Pattern: " + pattern2);
        System.out.println("Matches found at positions: " + listToString(result2));
        System.out.println();
        
        // Test case 3: Using KMPMatcher class
        KMPMatcher matcher = new KMPMatcher("ana");
        String text3 = "banana";
        List<Integer> result3 = matcher.search(text3);
        System.out.println("Using KMPMatcher class:");
        System.out.println("Text: " + text3);
        System.out.println("Pattern: " + matcher.getPattern());
        System.out.println("Matches found at positions: " + listToString(result3));
        System.out.println("Failure function: " + arrayToString(matcher.getFailureFunction()));
        System.out.println();
        
        // Test case 4: Failure function demonstration
        String[] patterns = {"ABABCABAB", "AAAA", "ABCDABCD"};
        System.out.println("Failure Function Examples:");
        for (String pattern : patterns) {
            int[] lps = buildFailureFunction(pattern);
            System.out.println("Pattern: " + pattern + " → LPS: " + arrayToString(lps));
        }
        System.out.println();
        
        // Test case 5: Performance with large text
        StringBuilder largeTextBuilder = new StringBuilder();
        for (int i = 0; i < 1000; i++) {
            largeTextBuilder.append("A");
        }
        largeTextBuilder.append("PATTERN");
        for (int i = 0; i < 1000; i++) {
            largeTextBuilder.append("B");
        }
        String largeText = largeTextBuilder.toString();
        
        long startTime = System.nanoTime();
        List<Integer> largeResult = search(largeText, "PATTERN");
        long endTime = System.nanoTime();
        
        System.out.println("Performance Test:");
        System.out.println("Text length: " + largeText.length());
        System.out.println("Pattern found at: " + listToString(largeResult));
        System.out.println("Time taken: " + ((endTime - startTime) / 1_000_000.0) + " ms");
        
        // Test edge cases
        System.out.println("\\nEdge Cases:");
        try {
            validateInput("text", "pattern");
            System.out.println("✓ Valid input validation passed");
        } catch (IllegalArgumentException e) {
            System.out.println("✗ Valid input validation failed: " + e.getMessage());
        }
        
        try {
            search("text", "");
            System.out.println("✓ Empty pattern handled gracefully");
        } catch (IllegalArgumentException e) {
            System.out.println("✓ Empty pattern correctly rejected: " + e.getMessage());
        }
        
        try {
            search(null, "pattern");
            System.out.println("✗ Null text should throw exception");
        } catch (IllegalArgumentException e) {
            System.out.println("✓ Null text correctly rejected: " + e.getMessage());
        }
    }
}