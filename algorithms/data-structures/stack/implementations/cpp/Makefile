# Makefile for Stack
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
TARGET := stack
SOURCES := stack.cpp
OBJECTS := $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET_DIR)/$(TARGET)

# Create directories
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build executable
$(TARGET_DIR)/$(TARGET): $(OBJECTS) | $(TARGET_DIR)
	$(CXX) $(OBJECTS) -o $@

# Release build
release: CXXFLAGS += $(RELEASE_FLAGS)
release: clean $(TARGET_DIR)/$(TARGET)

# Run the program
run: $(TARGET_DIR)/$(TARGET)
	./$(TARGET_DIR)/$(TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET_DIR)

# Install (copy to system directory)
install: $(TARGET_DIR)/$(TARGET)
	cp $(TARGET_DIR)/$(TARGET) /usr/local/bin/

# Uninstall
uninstall:
	rm -f /usr/local/bin/$(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  release - Build optimized version"
	@echo "  run     - Build and run the program"
	@echo "  clean   - Remove build files"
	@echo "  install - Install to system"
	@echo "  help    - Show this help"

# Declare phony targets
.PHONY: all release run clean install uninstall help