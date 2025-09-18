# C++ Algorithm Compilation Guide

This guide explains how to compile and run C++ algorithm implementations on different operating systems.

## Prerequisites by Operating System

### macOS
- Xcode Command Line Tools: `xcode-select --install`
- Optional: Homebrew for additional tools: `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`

### Linux (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install build-essential
```

### Linux (CentOS/RHEL/Fedora)
```bash
# CentOS/RHEL 7/8:
sudo yum groupinstall "Development Tools"

# Fedora/CentOS Stream/RHEL 9:
sudo dnf groupinstall "Development Tools"
```

### Windows
- **Option 1**: Visual Studio Community (recommended for beginners)
- **Option 2**: MinGW-w64 or MSYS2
- **Option 3**: Windows Subsystem for Linux (WSL)

## Quick Start

### Simple Compilation (All Platforms)

```bash
# Navigate to the directory containing your .cpp file
cd /path/to/your/algorithm.cpp

# Compile with g++ (replace 'algorithm' with your filename)
g++ -std=c++17 -o algorithm algorithm.cpp

# Or compile with clang++
clang++ -std=c++17 -o algorithm algorithm.cpp

# Run the program
./algorithm                        # Linux/macOS
algorithm.exe                      # Windows (MinGW)
```

## Compilation Options

### Basic Compilation
```bash
g++ -std=c++17 your_file.cpp -o output_name
```

### With Debug Information
```bash
g++ -std=c++17 -g your_file.cpp -o output_name
```

### Optimized Release Build
```bash
g++ -std=c++17 -O2 -DNDEBUG your_file.cpp -o output_name
```

### With All Warnings
```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic your_file.cpp -o output_name
```

### Professional Build (Recommended)
```bash
g++ -std=c++17 -Wall -Wextra -g -O2 your_file.cpp -o output_name
```

## Build Automation

Many algorithm directories include build automation files. Look for:

### Makefile
If a `Makefile` is present:
```bash
make run          # Build and run
make              # Just build
make release      # Optimized build
make clean        # Clean build files
make help         # Show all options
```

### CMakeLists.txt
If `CMakeLists.txt` is present:
```bash
mkdir build
cd build
cmake ..
make              # Linux/macOS
cmake --build .   # Cross-platform

# Run the program (check bin/ or build/ directory)
./bin/program_name
```

## Platform-Specific Instructions

### macOS
```bash
# Using Xcode's clang++
clang++ -std=c++17 -stdlib=libc++ your_file.cpp -o output_name

# Using Homebrew's gcc (if installed)
g++-13 -std=c++17 your_file.cpp -o output_name
```

### Linux
```bash
# Standard compilation
g++ -std=c++17 your_file.cpp -o output_name

# With threading support (for multi-threaded algorithms)
g++ -std=c++17 -pthread your_file.cpp -o output_name
```

### Windows

#### Visual Studio (IDE)
1. Open Visual Studio
2. Create a new "Console App" project
3. Replace the default code with your algorithm implementation
4. Press F5 to build and run

#### Command Prompt (MinGW)
```cmd
g++ -std=c++17 your_file.cpp -o output_name.exe
output_name.exe
```

#### PowerShell (MinGW)
```powershell
g++ -std=c++17 your_file.cpp -o output_name.exe
.\output_name.exe
```

#### Windows Subsystem for Linux (WSL)
```bash
# Same as Linux commands
g++ -std=c++17 your_file.cpp -o output_name
./output_name
```

## Common Algorithm Patterns

### Single File Algorithms
Most algorithms in this repository are self-contained single files:
```bash
g++ -std=c++17 -Wall -Wextra algorithm_name.cpp -o algorithm_name
./algorithm_name
```

### Algorithms with Test Files
Some directories contain separate test files:
```bash
# Compile main algorithm
g++ -std=c++17 algorithm.cpp -o algorithm

# Compile and run tests (if present)
g++ -std=c++17 test_algorithm.cpp algorithm.cpp -o test_algorithm
./test_algorithm
```

### Header-Only Implementations
For algorithms split into .h/.hpp and .cpp files:
```bash
g++ -std=c++17 -I. main.cpp algorithm.cpp -o algorithm
```

## Troubleshooting

### Common Issues

1. **"command not found: g++" or "command not found: clang++"**
   - Install the appropriate compiler for your system (see Prerequisites)

2. **"error: 'std::vector' has not been declared"**
   - Make sure you're using C++11 or later: `-std=c++17`

3. **Linking errors on macOS**
   - Use `clang++` instead of `clang`
   - Add `-stdlib=libc++` if needed

4. **Permission denied when running**
   - Make the file executable: `chmod +x your_program`

5. **Windows: "is not recognized as an internal or external command"**
   - Ensure MinGW/MSYS2 is in your PATH
   - Use the full path to the compiler

6. **Undefined reference errors**
   - Link required libraries: `-lm` for math, `-lpthread` for threading
   - Ensure all source files are included in compilation

### Performance Notes

- Use `-O2` or `-O3` for optimized builds when benchmarking
- Include `-g` for debugging symbols during development
- Use `-DNDEBUG` to disable assert statements in release builds
- Consider `-march=native` for CPU-specific optimizations

## Repository Structure

This repository contains algorithms organized by category:

```
algorithms/
├── sorting/
│   ├── bubble-sort/
│   ├── quick-sort/
│   └── merge-sort/
├── searching/
│   ├── binary-search/
│   └── linear-search/
├── data-structures/
│   ├── stack/
│   └── queue/
└── ...
```

Each algorithm directory typically contains:
- Implementation files (`.cpp`)
- Test files (optional)
- README.md with algorithm explanation
- Build files (Makefile, CMakeLists.txt) when applicable

## Contributing

When adding new C++ algorithms:

1. **Maintain C++17 compatibility** for broad platform support
2. **Include a main() function** with example usage and test cases
3. **Add comments and documentation** explaining the algorithm
4. **Test on multiple platforms** if possible
5. **Follow consistent naming conventions**: `algorithm_name.cpp`
6. **Consider adding build automation** (Makefile) for complex projects

## Getting Help

If you encounter compilation issues:

1. Check this guide for your specific platform
2. Verify you have the correct compiler version
3. Look for platform-specific README files in algorithm directories
4. Check the algorithm's individual README for special requirements

## Examples

### Compiling Binary Search
```bash
cd algorithms/searching/binary-search/implementations/cpp/
g++ -std=c++17 -Wall -Wextra binary_search.cpp -o binary_search
./binary_search
```

### Compiling Bubble Sort
```bash
cd algorithms/sorting/bubble-sort/implementations/
g++ -std=c++17 bubble_sort.cpp -o bubble_sort
./bubble_sort
```

### Using Make (if Makefile exists)
```bash
cd algorithms/any-algorithm/implementations/cpp/
make run
```

This guide should work for all C++ algorithm implementations in this repository. For algorithm-specific build instructions or requirements, check the README.md file in each algorithm's directory.