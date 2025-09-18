# Bubble Sort Makefile
# 冒泡排序Makefile

CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -g -I.
LDFLAGS =

# Source files
SRC = bubble_sort.c
TEST_SRC = test_bubble_sort.c
MAIN_SRC = main.c
UNITY_SRC = unity.c

# Object files
OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)
UNITY_OBJ = $(UNITY_SRC:.c=.o)

# Executables
TEST_EXE = bin/bubble_sort_test
MAIN_EXE = bin/bubble_sort_demo

# Build directories
BUILD_DIR = build
BIN_DIR = bin

.PHONY: all clean test demo run run-demo help

# Default target
all: test demo

# Create directories
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile source files
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build test executable
$(TEST_EXE): $(BUILD_DIR)/$(OBJ) $(BUILD_DIR)/$(TEST_OBJ) $(BUILD_DIR)/$(UNITY_OBJ) | $(BIN_DIR)
	$(CC) $(BUILD_DIR)/$(OBJ) $(BUILD_DIR)/$(TEST_OBJ) $(BUILD_DIR)/$(UNITY_OBJ) $(LDFLAGS) -o $@

# Build demo executable
$(MAIN_EXE): $(BUILD_DIR)/$(OBJ) $(BUILD_DIR)/$(MAIN_OBJ) | $(BIN_DIR)
	$(CC) $(BUILD_DIR)/$(OBJ) $(BUILD_DIR)/$(MAIN_OBJ) $(LDFLAGS) -o $@

# Build and run tests
test: $(TEST_EXE)
	./$(TEST_EXE)

# Build and run demo
demo: $(MAIN_EXE)
	./$(MAIN_EXE)

# Run tests
run: test

# Run demo
run-demo: demo

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Show help
help:
	@echo "Bubble Sort Build System"
	@echo "Usage:"
	@echo "  make all       - Build both test and demo executables"
	@echo "  make test      - Build and run unit tests"
	@echo "  make demo      - Build and run demo program"
	@echo "  make run       - Run unit tests"
	@echo "  make run-demo  - Run demo program"
	@echo "  make clean     - Clean build artifacts"
	@echo "  make help      - Show this help message"

# Dependencies
$(BUILD_DIR)/bubble_sort.o: bubble_sort.h
$(BUILD_DIR)/test_bubble_sort.o: bubble_sort.h unity.h
$(BUILD_DIR)/main.o: bubble_sort.h
$(BUILD_DIR)/unity.o: unity.h