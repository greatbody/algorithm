# Algorithm Collection 算法集合

A professionally curated repository featuring comprehensive algorithm descriptions in Markdown and implementations in multiple programming languages.

一个专业策划的代码库，包含用 Markdown 编写的全面算法描述以及多种编程语言的实现。

## 📚 Table of Contents 目录

- [Sorting Algorithms 排序算法](#sorting-algorithms-排序算法)
- [Searching Algorithms 搜索算法](#searching-algorithms-搜索算法)
- [Data Structures 数据结构](#data-structures-数据结构)
- [Contributing 贡献指南](#contributing-贡献指南)
- [Languages Supported 支持的语言](#languages-supported-支持的语言)

## 🔄 Sorting Algorithms 排序算法

| Algorithm | Description | Time Complexity | Space Complexity | Implementations |
|-----------|-------------|-----------------|------------------|-----------------|
| [Bubble Sort](algorithms/sorting/bubble-sort/README.md) | Simple sorting algorithm that repeatedly steps through the list | O(n²) | O(1) | Python, Java, JavaScript, C++, Go |
| [Quick Sort](algorithms/sorting/quick-sort/README.md) | Efficient divide-and-conquer sorting algorithm | O(n log n) avg | O(log n) | Python, Java, JavaScript, C++, Go |
| [Merge Sort](algorithms/sorting/merge-sort/README.md) | Stable divide-and-conquer sorting algorithm | O(n log n) | O(n) | Python, Java, JavaScript, C++, Go |

## 🔍 Searching Algorithms 搜索算法

| Algorithm | Description | Time Complexity | Space Complexity | Implementations |
|-----------|-------------|-----------------|------------------|-----------------|
| [Binary Search](algorithms/searching/binary-search/README.md) | Efficient search algorithm for sorted arrays | O(log n) | O(1) | Python, Java, JavaScript, C++, Go |
| [Knuth-Morris-Pratt (KMP)](algorithms/searching/knuth-morris-pratt/README.md) | Efficient string matching algorithm with failure function | O(n + m) | O(m) | Python, Java, JavaScript, C++ |
| [Linear Search](algorithms/searching/linear-search/README.md) | Simple search algorithm that checks every element | O(n) | O(1) | Python, Java, JavaScript, C++, Go |

## 🏗️ Data Structures 数据结构

| Data Structure | Description | Operations | Implementations |
|----------------|-------------|------------|-----------------|
| [Linked List](algorithms/data-structures/linked-list/README.md) | Linear data structure with nodes | Insert, Delete, Search | Python, Java, JavaScript, C++, Go |
| [Stack](algorithms/data-structures/stack/README.md) | LIFO (Last In, First Out) data structure | Push, Pop, Peek | Python, Java, JavaScript, C++, Go |
| [Queue](algorithms/data-structures/queue/README.md) | FIFO (First In, First Out) data structure | Enqueue, Dequeue, Peek | Python, Java, JavaScript, C++, Go |

## 💻 Languages Supported 支持的语言

- **Python** 🐍 - Clean, readable implementations with comprehensive comments
- **Java** ☕ - Object-oriented implementations with proper class structures
- **JavaScript** 🌐 - Modern ES6+ implementations suitable for web development
- **C++** ⚡ - High-performance implementations with memory management
- **Go** 🚀 - Concurrent and efficient implementations

## 🔧 Build System & Compilation 构建系统和编译指南

### Cross-Platform Makefile System

This repository uses a standardized cross-platform Makefile system for easy compilation of C and C++ implementations.

**Quick Start:**
```bash
# Navigate to any algorithm implementation directory
cd algorithms/sorting/bubble-sort/implementations/c

# Build and run tests
make test

# Or simply build
make
```

### 📚 Build System Documentation

- **[Makefile Installation Guide](MAKEFILE_INSTALLATION_GUIDE.md)** - How to install Make on macOS, Windows, and Linux
- **[Makefile Template Guide](MAKEFILE_GUIDE.md)** - Standard template for creating cross-platform Makefiles
- **[C++ Compilation Guide](CPP_COMPILATION_GUIDE.md)** - Additional C++-specific compilation instructions

### 跨平台构建系统

本代码库使用标准化的跨平台 Makefile 系统，便于编译 C 和 C++ 实现。

**快速开始:**
```bash
# 进入任意算法实现目录
cd algorithms/sorting/bubble-sort/implementations/c

# 构建并运行测试
make test

# 或仅构建
make
```

### 📚 构建系统文档

- **[Makefile 安装指南](MAKEFILE_INSTALLATION_GUIDE.md)** - 在 macOS、Windows 和 Linux 上安装 Make 的方法
- **[Makefile 模板指南](MAKEFILE_GUIDE.md)** - 创建跨平台 Makefile 的标准模板
- **[C++ 编译指南](CPP_COMPILATION_GUIDE.md)** - 额外的 C++ 特定编译说明

## 🤝 Contributing 贡献指南

We welcome contributions! Please read our [Contributing Guidelines](CONTRIBUTING.md) before submitting pull requests.

欢迎贡献！在提交拉取请求之前，请阅读我们的[贡献指南](CONTRIBUTING.md)。

### How to Add a New Algorithm 如何添加新算法

1. Create a new directory under the appropriate category
2. Add a comprehensive README.md with algorithm description
3. Implement the algorithm in at least 3 different languages
4. Include time and space complexity analysis
5. Add example usage and test cases

## 📄 License 许可证

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

本项目采用 MIT 许可证 - 详情请参阅 [LICENSE](LICENSE) 文件。

## 🎯 Featured Examples 特色示例

This repository includes comprehensive implementations of popular algorithms and data structures:

### ✅ Completed Implementations 已完成的实现

- **Bubble Sort** - Complete with Python (12 tests), Java, JavaScript (21 tests)
- **Binary Search** - Complete with Python, JavaScript, C++ implementations
- **Stack Data Structure** - Complete with Python implementation including MinStack and applications

Each implementation includes:
- 📖 Bilingual documentation (English/Chinese)
- 🧪 Comprehensive test suites
- 📊 Time and space complexity analysis
- 🎯 Real-world applications and examples
- 🔍 Step-by-step visualizations

## 🌟 Star History

[![Star History Chart](https://api.star-history.com/svg?repos=greatbody/algorithm&type=Date)](https://star-history.com/#greatbody/algorithm&Date)
