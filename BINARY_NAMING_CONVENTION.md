# Binary Naming Convention and Gitignore Configuration

## Overview

This document outlines the standardized naming convention for compiled binaries in the algorithm repository and the corresponding `.gitignore` configuration to prevent committing generated files.

## Binary Naming Convention

### Directory Structure
All compiled binaries should be placed in dedicated output directories:
- `bin/` - For final executable binaries
- `build/` - For intermediate build files and object files

### Binary Naming Patterns

#### C/C++ Binaries
- **Test executables**: `*_test` (e.g., `stack_test`, `binary_search_test`)
- **Demo programs**: `*_demo` (e.g., `stack_demo`, `binary_search_demo`)
- **Simple implementations**: `simple_*` (e.g., `simple_stack`, `simple_binary_search`)
- **Application binaries**: `*_app` (e.g., `stack_app`, `search_app`)

#### Java Binaries
- `.class` files for individual classes
- `.jar` files for packaged applications

#### Python
- Bytecode files (`.pyc`, `.pyo`)
- `__pycache__/` directories

#### TypeScript/JavaScript
- Compiled `.js` files
- Source maps (`.map`)
- `dist/` directories
- `node_modules/` dependencies

## Gitignore Configuration

The `.gitignore` file has been updated with comprehensive patterns to exclude:

### Directory Patterns
```
algorithms/*/implementations/*/bin/
algorithms/*/implementations/*/build/
```

### File Patterns
```
# C/C++ binaries
algorithms/*/implementations/*/*.out
algorithms/*/implementations/*/*.exe
algorithms/*/implementations/*/simple_*
algorithms/*/implementations/*/*_test
algorithms/*/implementations/*/*_demo
algorithms/*/implementations/*/*_app

# Java binaries
algorithms/*/implementations/*/*.class
algorithms/*/implementations/*/*.jar

# Python bytecode
algorithms/*/implementations/*/__pycache__/
algorithms/*/implementations/*/*.pyc
algorithms/*/implementations/*/*.pyo

# TypeScript/JavaScript
algorithms/*/implementations/*/dist/
algorithms/*/implementations/*/node_modules/
algorithms/*/implementations/*/*.js
algorithms/*/implementations/*/*.map

# Build system files
algorithms/*/implementations/*/CMakeFiles/
algorithms/*/implementations/*/cmake_install.cmake
algorithms/*/implementations/*/CMakeCache.txt
algorithms/*/implementations/*/Makefile
```

## Best Practices

### For Makefile Users
1. Always set `TARGET_DIR := bin` and `BUILD_DIR := build`
2. Use descriptive target names with appropriate suffixes
3. Ensure `clean` target removes both `bin/` and `build/` directories

### For CMake Users
1. Set output directories using `set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)`
2. Use descriptive target names following the convention

### For Manual Compilation
1. Always compile to `bin/` directory: `gcc -o bin/my_program source.c`
2. Use appropriate naming suffixes
3. Clean up generated files before committing

## Verification

To verify that no binaries are being tracked by git, run:
```bash
git status
```

If any binaries are still being tracked, you can remove them with:
```bash
git rm --cached algorithms/*/implementations/*/simple_*
git rm --cached algorithms/*/implementations/*/*_test
# etc.
```

## Benefits

1. **Consistency**: Standardized naming across all implementations
2. **Clean Repository**: No compiled binaries in version control
3. **Easy Maintenance**: Clear patterns for future implementations
4. **Cross-Platform**: Works with different build systems and languages

## Future Considerations

When adding new algorithm implementations:
1. Follow the naming convention
2. Update Makefiles/CMakeLists to use `bin/` and `build/` directories
3. Test that generated files are properly ignored by git