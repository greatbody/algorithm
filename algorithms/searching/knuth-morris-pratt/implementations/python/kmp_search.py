"""
Knuth-Morris-Pratt (KMP) String Matching Algorithm Implementation in Python
KMP字符串匹配算法的Python实现

Time Complexity: O(n + m) where n is text length and m is pattern length
Space Complexity: O(m) for the failure function array
"""

def build_failure_function(pattern):
    """
    Build the failure function (LPS array) for the KMP algorithm.
    
    The failure function stores the length of the longest proper prefix 
    which is also a suffix for each position in the pattern.
    
    Args:
        pattern (str): The pattern string for which to build the failure function
        
    Returns:
        list: Failure function array where lps[i] represents the length of 
              the longest proper prefix which is also a suffix for pattern[0:i+1]
              
    Examples:
        >>> build_failure_function("ABABCABAB")
        [0, 0, 1, 2, 0, 1, 2, 1, 2]
        
        >>> build_failure_function("AAAA")
        [0, 1, 2, 3]
        
        >>> build_failure_function("ABCDABCD")
        [0, 0, 0, 0, 1, 2, 3, 4]
        
        >>> build_failure_function("")
        []
    """
    if not pattern:
        return []
    
    m = len(pattern)
    lps = [0] * m  # Longest Proper Prefix which is also Suffix
    length = 0     # Length of the previous longest prefix suffix
    i = 1          # Start from the second character
    
    # Build the failure function
    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            # This is tricky. Consider the example "AAACAAAA" and i = 7.
            # The idea is similar to search algorithm.
            if length != 0:
                length = lps[length - 1]
                # Also, note that we do not increment i here
            else:
                lps[i] = 0
                i += 1
    
    return lps


def kmp_search(text, pattern):
    """
    Search for all occurrences of pattern in text using KMP algorithm.
    
    Args:
        text (str): The text string in which to search
        pattern (str): The pattern string to search for
        
    Returns:
        list: List of starting positions where pattern is found in text
        
    Examples:
        >>> kmp_search("ABABDABACDABABCABCABCABCABC", "ABABCAB")
        [15]
        
        >>> kmp_search("AABAACAADAABAABA", "AABA")
        [0, 9, 12]
        
        >>> kmp_search("hello world", "world")
        [6]
        
        >>> kmp_search("hello world", "xyz")
        []
        
        >>> kmp_search("", "pattern")
        []
        
        >>> kmp_search("text", "")
        []
    """
    if not text or not pattern:
        return []
    
    n = len(text)
    m = len(pattern)
    
    # Get the failure function for the pattern
    lps = build_failure_function(pattern)
    
    positions = []  # Store all match positions
    i = 0  # Index for text
    j = 0  # Index for pattern
    
    while i < n:
        if pattern[j] == text[i]:
            j += 1
            i += 1
        
        if j == m:
            # Found a match
            positions.append(i - j)
            j = lps[j - 1]
        elif i < n and pattern[j] != text[i]:
            # Do not match j with lps[0..lps[j-1]] characters,
            # they will match anyway
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    
    return positions


def kmp_search_first(text, pattern):
    """
    Search for the first occurrence of pattern in text using KMP algorithm.
    
    Args:
        text (str): The text string in which to search
        pattern (str): The pattern string to search for
        
    Returns:
        int: Starting position of first match, or -1 if not found
        
    Examples:
        >>> kmp_search_first("ABABDABACDABABCABCABCABCABC", "ABABCAB")
        15
        
        >>> kmp_search_first("hello world", "world")
        6
        
        >>> kmp_search_first("hello world", "xyz")
        -1
        
        >>> kmp_search_first("", "pattern")
        -1
    """
    positions = kmp_search(text, pattern)
    return positions[0] if positions else -1


def validate_input(text, pattern):
    """
    Validate input parameters for KMP search functions.
    
    Args:
        text (str): The text string
        pattern (str): The pattern string
        
    Raises:
        TypeError: If inputs are not strings
        ValueError: If pattern is empty
        
    Examples:
        >>> validate_input("hello", "lo")
        True
        
        >>> validate_input(123, "pattern")
        Traceback (most recent call last):
        ...
        TypeError: Text must be a string
        
        >>> validate_input("text", "")
        Traceback (most recent call last):
        ...
        ValueError: Pattern cannot be empty
    """
    if not isinstance(text, str):
        raise TypeError("Text must be a string")
    if not isinstance(pattern, str):
        raise TypeError("Pattern must be a string")
    if not pattern:
        raise ValueError("Pattern cannot be empty")
    return True


class KMPMatcher:
    """
    A class-based implementation of KMP string matching algorithm.
    
    This class allows for pattern preprocessing and multiple searches
    with the same pattern for better performance.
    """
    
    def __init__(self, pattern):
        """
        Initialize the KMP matcher with a pattern.
        
        Args:
            pattern (str): The pattern to search for
            
        Examples:
            >>> matcher = KMPMatcher("ABABCAB")
            >>> matcher.pattern
            'ABABCAB'
        """
        if not isinstance(pattern, str):
            raise TypeError("Pattern must be a string")
        if not pattern:
            raise ValueError("Pattern cannot be empty")
            
        self.pattern = pattern
        self.failure_function = build_failure_function(pattern)
    
    def search(self, text):
        """
        Search for all occurrences of the pattern in the given text.
        
        Args:
            text (str): The text to search in
            
        Returns:
            list: List of starting positions where pattern is found
            
        Examples:
            >>> matcher = KMPMatcher("AB")
            >>> matcher.search("ABABAB")
            [0, 2, 4]
        """
        if not isinstance(text, str):
            raise TypeError("Text must be a string")
        
        return kmp_search(text, self.pattern)
    
    def search_first(self, text):
        """
        Search for the first occurrence of the pattern in the given text.
        
        Args:
            text (str): The text to search in
            
        Returns:
            int: Starting position of first match, or -1 if not found
            
        Examples:
            >>> matcher = KMPMatcher("world")
            >>> matcher.search_first("hello world")
            6
        """
        positions = self.search(text)
        return positions[0] if positions else -1


# Example usage and testing
if __name__ == "__main__":
    import doctest
    doctest.testmod()
    
    # Additional manual testing
    print("KMP String Matching Algorithm Demo")
    print("=" * 40)
    
    # Test case 1
    text1 = "ABABDABACDABABCABCABCABCABC"
    pattern1 = "ABABCAB"
    result1 = kmp_search(text1, pattern1)
    print(f"Text: {text1}")
    print(f"Pattern: {pattern1}")
    print(f"Matches found at positions: {result1}")
    print()
    
    # Test case 2
    text2 = "The quick brown fox jumps over the lazy dog"
    pattern2 = "the"
    result2 = kmp_search(text2.lower(), pattern2)
    print(f"Text: {text2}")
    print(f"Pattern: {pattern2}")
    print(f"Matches found at positions: {result2}")
    print()
    
    # Test case 3 - Using KMPMatcher class
    matcher = KMPMatcher("ana")
    text3 = "banana"
    result3 = matcher.search(text3)
    print(f"Using KMPMatcher class:")
    print(f"Text: {text3}")
    print(f"Pattern: {matcher.pattern}")
    print(f"Matches found at positions: {result3}")
    print(f"Failure function: {matcher.failure_function}")