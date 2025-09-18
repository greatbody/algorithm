# Makefile for KMP Search Algorithm
# Cross-platform makefile

# Compiler settings
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
RELEASE_FLAGS := -O2 -DNDEBUG

# Directories
SRC_DIR := .
BUILD_DIR := build
TARGET_DIR := bin

# Files
TARGET := kmp_search
SOURCES := kmp_search.cpp
OBJECTS := $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET_DIR)/$(TARGET)

# Release build
release: CXXFLAGS += $(RELEASE_FLAGS)
release: $(TARGET_DIR)/$(TARGET)

# Debug build (default)
debug: $(TARGET_DIR)/$(TARGET)

# Create directories if they don't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the executable
$(TARGET_DIR)/$(TARGET): $(OBJECTS) | $(TARGET_DIR)
	$(CXX) $(OBJECTS) -o $@

# Run the program
run: $(TARGET_DIR)/$(TARGET)
	./$(TARGET_DIR)/$(TARGET)

# Run tests
test: $(TARGET_DIR)/$(TARGET)
	./$(TARGET_DIR)/$(TARGET) --test

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET_DIR)

# Clean and rebuild
rebuild: clean all

# Install (copy to system path - requires sudo on Unix)
install: $(TARGET_DIR)/$(TARGET)
ifeq ($(OS),Windows_NT)
	copy "$(TARGET_DIR)\$(TARGET).exe" "C:\Windows\System32\"
else
	sudo cp $(TARGET_DIR)/$(TARGET) /usr/local/bin/
endif

# Uninstall
uninstall:
ifeq ($(OS),Windows_NT)
	del "C:\Windows\System32\$(TARGET).exe"
else
	sudo rm -f /usr/local/bin/$(TARGET)
endif

# Help
help:
	@echo "Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  debug    - Build with debug information"
	@echo "  release  - Build optimized version"
	@echo "  run      - Build and run the program"
	@echo "  test     - Build and run tests"
	@echo "  clean    - Remove build artifacts"
	@echo "  rebuild  - Clean and build"
	@echo "  install  - Install to system path"
	@echo "  uninstall- Remove from system path"
	@echo "  help     - Show this help message"

# Performance profiling (requires gprof)
profile: CXXFLAGS += -pg
profile: $(TARGET_DIR)/$(TARGET)
	./$(TARGET_DIR)/$(TARGET)
	gprof $(TARGET_DIR)/$(TARGET) gmon.out > analysis.txt
	@echo "Profile analysis saved to analysis.txt"

# Memory check (requires valgrind)
memcheck: debug
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET_DIR)/$(TARGET)

# Code coverage (requires gcov)
coverage: CXXFLAGS += --coverage
coverage: $(TARGET_DIR)/$(TARGET)
	./$(TARGET_DIR)/$(TARGET) --test
	gcov $(SOURCES)
	@echo "Coverage report generated"

# Static analysis (requires cppcheck)
static-analysis:
	cppcheck --enable=all --std=c++17 $(SRC_DIR)/$(SOURCES)

# Format code (requires clang-format)
format:
	clang-format -i $(SRC_DIR)/$(SOURCES)

# Check if required tools are installed
check-tools:
	@which $(CXX) >/dev/null 2>&1 || (echo "Error: $(CXX) not found" && exit 1)
	@echo "✓ $(CXX) found"
	@which make >/dev/null 2>&1 || (echo "Error: make not found" && exit 1)
	@echo "✓ make found"
	@echo "All required tools are available"

# Phony targets
.PHONY: all debug release run test clean rebuild install uninstall help profile memcheck coverage static-analysis format check-tools

# Default goal
.DEFAULT_GOAL := all