# Contributing Guidelines 贡献指南

Thank you for your interest in contributing to the Algorithm Collection! This document provides guidelines for contributing to this repository.

感谢您对算法集合项目的贡献兴趣！本文档为贡献此代码库提供指南。

## 📋 Table of Contents 目录

- [Code of Conduct 行为准则](#code-of-conduct-行为准则)
- [How to Contribute 如何贡献](#how-to-contribute-如何贡献)
- [Algorithm Standards 算法标准](#algorithm-standards-算法标准)
- [File Structure 文件结构](#file-structure-文件结构)
- [Code Style Guidelines 代码风格指南](#code-style-guidelines-代码风格指南)

## 🤝 Code of Conduct 行为准则

- Be respectful and inclusive
- Focus on constructive feedback
- Help others learn and grow
- Maintain professional communication

## 🚀 How to Contribute 如何贡献

### Adding a New Algorithm 添加新算法

1. **Fork the repository** and create a new branch
2. **Choose the appropriate category** (sorting, searching, data-structures)
3. **Create directory structure** following our template
4. **Implement the algorithm** in multiple languages
5. **Write comprehensive documentation**
6. **Submit a pull request**

### Improving Existing Code 改进现有代码

1. **Identify areas for improvement** (performance, readability, bug fixes)
2. **Create a new branch** for your changes
3. **Make your improvements** while maintaining backward compatibility
4. **Update documentation** if necessary
5. **Submit a pull request** with clear description

## 📊 Algorithm Standards 算法标准

### Required Components 必需组件

Each algorithm must include:

- **README.md** with detailed explanation in both English and Chinese
- **At least 3 language implementations** (Python, Java, JavaScript minimum)
- **Time and space complexity analysis**
- **Example usage and test cases**
- **Visual representation** (diagrams, flowcharts when applicable)

### Documentation Template 文档模板

```markdown
# Algorithm Name 算法名称

## Description 描述
[Detailed explanation in English]
[中文详细说明]

## Algorithm Steps 算法步骤
1. Step 1
2. Step 2
...

## Complexity Analysis 复杂度分析
- **Time Complexity:** O(?)
- **Space Complexity:** O(?)

## Implementations 实现
- [Python](implementations/python/)
- [Java](implementations/java/)
- [JavaScript](implementations/javascript/)
- [C++](implementations/cpp/)
- [Go](implementations/go/)

## Example Usage 使用示例
[Code examples and expected outputs]

## Test Cases 测试用例
[Input/Output examples]
```

## 📁 File Structure 文件结构

```
algorithms/
├── category/
│   └── algorithm-name/
│       ├── README.md
│       ├── implementations/
│       │   ├── python/
│       │   │   ├── algorithm_name.py
│       │   │   └── test_algorithm_name.py
│       │   ├── java/
│       │   │   ├── AlgorithmName.java
│       │   │   └── AlgorithmNameTest.java
│       │   ├── javascript/
│       │   │   ├── algorithmName.js
│       │   │   └── algorithmName.test.js
│       │   ├── cpp/
│       │   │   ├── algorithm_name.cpp
│       │   │   └── test_algorithm_name.cpp
│       │   └── go/
│       │       ├── algorithm_name.go
│       │       └── algorithm_name_test.go
│       └── assets/
│           └── diagram.png (if applicable)
```

## 🎨 Code Style Guidelines 代码风格指南

### Python
- Follow PEP 8 style guide
- Use descriptive variable names
- Include docstrings for functions
- Use type hints where appropriate

### Java
- Follow Oracle Java conventions
- Use meaningful class and method names
- Include Javadoc comments
- Follow camelCase naming

### JavaScript
- Use ES6+ features
- Follow Airbnb style guide
- Use JSDoc for documentation
- Use camelCase naming

### C++
- Follow Google C++ style guide
- Use snake_case for variables
- Include proper header guards
- Document complex algorithms

### Go
- Follow official Go style guide
- Use gofmt for formatting
- Include package documentation
- Use snake_case for variables

## ✅ Testing Requirements 测试要求

- Each implementation must include test cases
- Tests should cover edge cases and typical scenarios
- Include performance benchmarks for large datasets
- Ensure all tests pass before submitting

## 📝 Pull Request Guidelines 拉取请求指南

### Title Format
```
[Category] Add/Update Algorithm Name
```

### Description Template
```markdown
## Changes Made
- Description of changes

## Testing
- [ ] All implementations tested
- [ ] Documentation updated
- [ ] Code follows style guidelines

## Languages Implemented
- [ ] Python
- [ ] Java
- [ ] JavaScript
- [ ] C++
- [ ] Go
```

## 🎯 Good First Issues 新手友好问题

Look for issues labeled with `good first issue` to start contributing:
- Adding missing language implementations
- Improving documentation
- Adding test cases
- Fixing typos or formatting

Thank you for contributing to the Algorithm Collection! 感谢您为算法集合做出贡献！