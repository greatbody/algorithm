# Knuth-Morris-Pratt (KMP) String Matching Algorithm KMP字符串匹配算法

## Description 描述

**English:** The Knuth-Morris-Pratt (KMP) algorithm is an efficient string matching algorithm that searches for occurrences of a pattern within a text string. It uses a failure function (also called partial match table) to avoid unnecessary character comparisons by skipping characters that are known to match. This preprocessing step allows the algorithm to achieve linear time complexity O(n + m) instead of the naive O(n × m) approach.

**中文：** Knuth-Morris-Pratt (KMP) 算法是一种高效的字符串匹配算法，用于在文本字符串中搜索模式串的出现。它使用失效函数（也称为部分匹配表）来避免不必要的字符比较，通过跳过已知匹配的字符来提高效率。这种预处理步骤使算法能够达到线性时间复杂度 O(n + m)，而不是朴素方法的 O(n × m)。

## Algorithm Steps 算法步骤

**English:**
1. **Preprocessing Phase**: Build the failure function (LPS array) for the pattern
   - Initialize LPS array where LPS[i] represents the length of the longest proper prefix which is also a suffix
   - Use two pointers to fill the LPS array efficiently
2. **Searching Phase**: Use the failure function to search efficiently
   - Compare characters from text and pattern
   - When mismatch occurs, use LPS array to determine the next comparison position
   - Continue until the entire text is processed

**中文：**
1. **预处理阶段**: 为模式串构建失效函数（LPS数组）
   - 初始化LPS数组，其中LPS[i]表示既是前缀又是后缀的最长相同子串的长度
   - 使用双指针高效填充LPS数组
2. **搜索阶段**: 使用失效函数进行高效搜索
   - 比较文本和模式中的字符
   - 当出现不匹配时，使用LPS数组确定下一个比较位置
   - 继续处理直到完成整个文本的搜索

## Complexity Analysis 复杂度分析

- **Time Complexity 时间复杂度:** O(n + m)
  - Preprocessing 预处理: O(m) where m is pattern length 其中m是模式串长度
  - Searching 搜索: O(n) where n is text length 其中n是文本长度
  - Best Case 最佳情况: O(n + m)
  - Average Case 平均情况: O(n + m)
  - Worst Case 最坏情况: O(n + m)
- **Space Complexity 空间复杂度:** O(m) for the failure function array 用于失效函数数组

## Implementations 实现

### Available Languages 可用语言
- [Python](implementations/python/kmp_search.py)
- [Java](implementations/java/KMPSearch.java)
- [TypeScript (Deno)](implementations/javascript/kmpSearch.ts)
- [C++](implementations/cpp/kmp_search.cpp)

## Example Usage 使用示例

### Python Example
```python
from kmp_search import kmp_search, build_failure_function

# Example usage
text = "ABABDABACDABABCABCABCABCABC"
pattern = "ABABCABCABCABC"
positions = kmp_search(text, pattern)
print(f"Pattern found at positions: {positions}")
# Output: Pattern found at positions: [15]

# Build failure function separately
failure_function = build_failure_function(pattern)
print(f"Failure function: {failure_function}")
# Output: Failure function: [0, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0]
```

### Java Example
```java
import java.util.List;

public class Example {
    public static void main(String[] args) {
        KMPSearch kmp = new KMPSearch();
        String text = "ABABDABACDABABCABCABCABCABC";
        String pattern = "ABABCABCABCABC";
        
        List<Integer> positions = kmp.search(text, pattern);
        System.out.println("Pattern found at positions: " + positions);
        // Output: Pattern found at positions: [15]
        
        int[] failureFunction = kmp.buildFailureFunction(pattern);
        System.out.println("Failure function: " + Arrays.toString(failureFunction));
    }
}
```

### TypeScript (Deno) Example
```ts
import { kmpSearch, buildFailureFunction } from './implementations/javascript/kmpSearch.ts';

const text = 'ABABDABACDABABCABCABCABCABC';
const pattern = 'ABABCABCABCABC';
const positions = kmpSearch(text, pattern);
console.log(`Pattern found at positions: ${positions}`);
// Output: Pattern found at positions: [15]

const failureFunction = buildFailureFunction(pattern);
console.log(`Failure function: ${failureFunction}`);
// Output: Failure function: [0,0,1,2,0,1,2,0,1,2,0,1,2,0]
```

Run tests (运行测试):
```
deno test implementations/javascript
```

### C++ Example
```cpp
#include "kmp_search.h"
#include <iostream>
#include <vector>

int main() {
    std::string text = "ABABDABACDABABCABCABCABCABC";
    std::string pattern = "ABABCABCABCABC";
    
    std::vector<int> positions = kmpSearch(text, pattern);
    std::cout << "Pattern found at positions: ";
    for (int pos : positions) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    // Output: Pattern found at positions: 15
    
    std::vector<int> failureFunction = buildFailureFunction(pattern);
    std::cout << "Failure function: ";
    for (int val : failureFunction) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

## Applications 应用场景

**English:**
- **Text Processing**: Finding substrings in large documents
- **Bioinformatics**: DNA sequence matching and analysis
- **Data Compression**: Pattern detection in compression algorithms
- **Network Security**: Intrusion detection and pattern matching in network traffic
- **Search Engines**: Efficient text searching in web crawling and indexing

**中文：**
- **文本处理**: 在大型文档中查找子字符串
- **生物信息学**: DNA序列匹配和分析
- **数据压缩**: 压缩算法中的模式检测
- **网络安全**: 网络流量中的入侵检测和模式匹配
- **搜索引擎**: 网络爬虫和索引中的高效文本搜索

## Key Concepts 关键概念

**English:**
- **Failure Function (LPS Array)**: Preprocessed array that stores the length of the longest proper prefix which is also a suffix for each position
- **Border**: A string that is both a prefix and suffix of another string
- **Shift Optimization**: Using the failure function to skip unnecessary comparisons during mismatches

**中文：**
- **失效函数（LPS数组）**: 预处理数组，存储每个位置上既是前缀又是后缀的最长相同子串的长度
- **边界**: 既是另一个字符串的前缀又是后缀的字符串
- **移位优化**: 使用失效函数在不匹配时跳过不必要的比较

## Performance Comparison 性能比较

| Algorithm | Time Complexity | Space Complexity | Best For |
|-----------|-----------------|------------------|----------|
| Naive Search | O(n × m) | O(1) | Small patterns |
| KMP | O(n + m) | O(m) | Long patterns, repeated searches |
| Boyer-Moore | O(n + m) | O(σ + m) | Large alphabets |
| Rabin-Karp | O(n + m) avg | O(1) | Multiple pattern search |

## References 参考文献

- Knuth, Donald E.; Morris, James H.; Pratt, Vaughan R. (1977). "Fast pattern matching in strings"
- Cormen, Thomas H. et al. "Introduction to Algorithms" (CLRS)
- Sedgewick, Robert. "Algorithms in C++"