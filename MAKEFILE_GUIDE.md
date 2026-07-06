# Cross-Platform Makefile Guide for Algorithm Implementations

## Overview

This guide provides a standardized approach for creating cross-platform Makefiles for C and C++ algorithm implementations in this repository. The goal is to ensure consistent, easy-to-compile implementations across macOS, Linux, and Windows.

## Makefile Template

Use the following template for all C/C++ implementations:

```makefile
# Makefile for [Algorithm Name] Implementation in [Language]
# Cross-platform makefile for macOS, Linux, and Windows

# =============================================================================
# PLATFORM DETECTION AND CONFIGURATION
# =============================================================================

# Detect operating system
UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)

# Platform-specific configurations
ifeq ($(UNAME_S),Linux)
    # Linux configuration
    CC := gcc
    CXX := g++
    RM := rm -rf
    MKDIR := mkdir -p
    EXECUTABLE_EXT :=
    SHELL := /bin/bash
endif

ifeq ($(UNAME_S),Darwin)
    # macOS configuration
    CC := clang
    CXX := clang++
    RM := rm -rf
    MKDIR := mkdir -p
    EXECUTABLE_EXT :=
    SHELL := /bin/bash
endif

ifeq ($(OS),Windows_NT)
    # Windows configuration (requires Git Bash, WSL, or Cygwin)
    CC := gcc
    CXX := g++
    RM := rm -rf
    MKDIR := mkdir -p
    EXECUTABLE_EXT := .exe
    SHELL := /bin/bash
endif

# =============================================================================
# COMPILER SETTINGS
# =============================================================================

# Common compiler flags
CFLAGS := -std=c99 -Wall -Wextra -g -I.
CXXFLAGS := -std=c++17 -Wall -Wextra -g -I.
RELEASE_FLAGS := -O2 -DNDEBUG

# =============================================================================
# PROJECT STRUCTURE
# =============================================================================

# Directories
SRC_DIR := .
BUILD_DIR := build
TARGET_DIR := bin

# Source files (MODIFY THESE FOR YOUR IMPLEMENTATION)
SOURCES := [algorithm_name].c [test_file].c [unity_file].c
TARGET := [algorithm_name]_test$(EXECUTABLE_EXT)

# Object files
OBJECTS := $(SOURCES:%.c=$(BUILD_DIR)/%.o)

# =============================================================================
# BUILD TARGETS
# =============================================================================

# Default target - build everything
all: $(TARGET_DIR)/$(TARGET)

# Create necessary directories
$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

$(TARGET_DIR):
	$(MKDIR) $(TARGET_DIR)

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link executable
$(TARGET_DIR)/$(TARGET): $(OBJECTS) | $(TARGET_DIR)
	$(CC) $(OBJECTS) -o $@

# =============================================================================
# DEVELOPMENT TARGETS
# =============================================================================

# Build and run tests
test: $(TARGET_DIR)/$(TARGET)
	./$(TARGET_DIR)/$(TARGET)

# Build and run (alias for test)
run: test

# Release build
release: CFLAGS += $(RELEASE_FLAGS)
release: clean $(TARGET_DIR)/$(TARGET)

# Debug build with sanitizers
debug: CFLAGS += -fsanitize=address -fsanitize=undefined
debug: clean $(TARGET_DIR)/$(TARGET)

# Clean build artifacts
clean:
	$(RM) $(BUILD_DIR) $(TARGET_DIR)

# =============================================================================
# HELPER TARGETS
# =============================================================================

# Show help information
help:
	@echo "Available targets:"
	@echo "  all     - Build the executable (default)"
	@echo "  test    - Build and run tests"
	@echo "  run     - Same as test"
	@echo "  release - Build optimized version"
	@echo "  debug   - Build with debug sanitizers"
	@echo "  clean   - Remove build artifacts"
	@echo "  help    - Show this help"

# =============================================================================
# PHONY TARGETS
# =============================================================================

.PHONY: all test run release debug clean help
```

## Template Customization Guide

### For C Implementations

1. **Update source files**: Replace `[algorithm_name].c [test_file].c [unity_file].c` with your actual source files
2. **Update target name**: Replace `[algorithm_name]_test` with appropriate name
3. **Example for Binary Search**:
   ```makefile
   SOURCES := binary_search.c test_binary_search.c unity.c
   TARGET := binary_search_test$(EXECUTABLE_EXT)
   ```

### For C++ Implementations

1. **Change compiler variables**:
   ```makefile
   # Change from C to C++
   SOURCES := [algorithm_name].cpp [test_file].cpp
   TARGET := [algorithm_name]_test$(EXECUTABLE_EXT)
   
   # Update compilation rule
   $(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
       $(CXX) $(CXXFLAGS) -c $< -o $@
   
   # Update linking rule
   $(TARGET_DIR)/$(TARGET): $(OBJECTS) | $(TARGET_DIR)
       $(CXX) $(OBJECTS) -o $@
   ```

## File Structure Requirements

Each implementation directory should follow this structure:
```
algorithm-name/
├── [algorithm_name].c/.cpp      # Main implementation
├── test_[algorithm_name].c/.cpp # Test cases
├── unity.c/.cpp                 # Testing framework (if needed)
├── main.c/.cpp                  # Demo program (optional)
├── Makefile                     # This makefile
└── bin/                         # Generated binaries (created by make)
    └── [algorithm_name]_test
```

## Usage Examples

```bash
# Build the project
make

# Build and run tests
make test

# Clean build artifacts
make clean

# Build optimized release
make release

# Show help
make help
```

## Platform-Specific Notes

### macOS
- Make is pre-installed
- Use `clang` compiler (default)
- No additional setup required

### Linux
- Make is usually pre-installed
- Install GCC if needed: `sudo apt install build-essential` (Ubuntu/Debian)

### Windows
**Option 1: Git Bash (Recommended)**
- Install Git for Windows (includes Git Bash)
- Make is included
- Use the same commands as Linux/macOS

**Option 2: WSL (Windows Subsystem for Linux)**
- Install WSL from Microsoft Store
- Follow Linux instructions

**Option 3: Cygwin**
- Install Cygwin with development tools
- More complex setup

## Testing Framework Integration

For C implementations, include Unity testing framework files:
- `unity.c` - Testing framework implementation
- `unity.h` - Testing framework header
- `test_[algorithm_name].c` - Your test cases

## Best Practices

1. **Always include a `help` target** - Shows available commands
2. **Use `$(MKDIR)` and `$(RM)`** - Platform-safe directory operations
3. **Include both `test` and `run` targets** - User-friendly aliases
4. **Support `release` and `debug` builds** - Different optimization levels
5. **Clean build artifacts properly** - Remove both `build/` and `bin/` directories
6. **Document dependencies** - List required files in comments

## Validation Checklist

Before committing a Makefile, ensure it:
- [ ] Compiles successfully on your platform
- [ ] Runs tests without errors
- [ ] Cleans up properly with `make clean`
- [ ] Includes all necessary source files
- [ ] Follows the template structure
- [ ] Has appropriate target names

## Troubleshooting

**Common Issues:**
- "make: command not found" - Install make for your platform
- Permission errors - Ensure proper file permissions
- Missing dependencies - Include all required source files
- Platform-specific path issues - Use `$(MKDIR)` and `$(RM)` variables

For additional help, refer to the main repository README or contact maintainers.