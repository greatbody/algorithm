# Makefile for KMP Search Implementation in C
# C语言KMP搜索实现的Makefile
# Cross-platform makefile

# Compiler settings
CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -g -I.
RELEASE_FLAGS := -O2 -DNDEBUG

# Directories
SRC_DIR := .
BUILD_DIR := build
TARGET_DIR := bin

# Files
TARGET := kmp_search_test
SOURCES := kmp_search.c unity.c test_kmp_search.c
OBJECTS := $(SOURCES:%.c=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET_DIR)/$(TARGET)

# Create directories
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build executable
$(TARGET_DIR)/$(TARGET): $(OBJECTS) | $(TARGET_DIR)
	$(CC) $(OBJECTS) -o $@

# Release build
release: CFLAGS += $(RELEASE_FLAGS)
release: clean $(TARGET_DIR)/$(TARGET)

# Run the tests
run: $(TARGET_DIR)/$(TARGET)
	./$(TARGET_DIR)/$(TARGET)

# Run tests with verbose output
test: run

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET_DIR)

# Install (copy to system directory)
install: $(TARGET_DIR)/$(TARGET)
	cp $(TARGET_DIR)/$(TARGET) /usr/local/bin/

# Debug build with address sanitizer
debug: CFLAGS += -fsanitize=address -fsanitize=undefined
debug: clean $(TARGET_DIR)/$(TARGET)

# Build only the KMP search library (static)
libkmpsearch.a: kmp_search.o
	ar rcs libkmpsearch.a kmp_search.o

kmp_search.o: kmp_search.c kmp_search.h
	$(CC) $(CFLAGS) -c kmp_search.c -o kmp_search.o

# Demo program
demo: kmp_search.c main.c
	$(CC) $(CFLAGS) kmp_search.c main.c -o $(TARGET_DIR)/kmp_search_demo

# Help target
help:
	@echo "Available targets:"
	@echo "  all       - Build the test executable (default)"
	@echo "  release   - Build optimized release version"
	@echo "  debug     - Build with address sanitizer for debugging"
	@echo "  run       - Build and run the tests"
	@echo "  test      - Same as run"
	@echo "  demo      - Build demo program"
	@echo "  clean     - Remove build files"
	@echo "  libkmpsearch.a - Build static library"
	@echo "  install   - Install executable to /usr/local/bin"
	@echo "  help      - Show this help message"

.PHONY: all release run test clean install debug libkmpsearch.a demo help