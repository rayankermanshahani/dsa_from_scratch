CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SRC = singly_linked_lists.c doubly_linked_lists.c circular_linked_lists.c
BUILD_DIR = build

# Define executables for each source file
EXEC_SINGLY = $(BUILD_DIR)/singly_linked_lists
EXEC_DOUBLY = $(BUILD_DIR)/doubly_linked_lists
EXEC_CIRCULAR = $(BUILD_DIR)/circular_linked_lists

# Build all executables when running make
all: $(EXEC_SINGLY) $(EXEC_DOUBLY) $(EXEC_CIRCULAR)

# Targets for building each executable individually
singly: $(EXEC_SINGLY)

doubly: $(EXEC_DOUBLY)

circular: $(EXEC_CIRCULAR)

# Build rule for singly linked lists
$(EXEC_SINGLY): $(BUILD_DIR)/singly_linked_lists.o
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Build rule for doubly linked lists
$(EXEC_DOUBLY): $(BUILD_DIR)/doubly_linked_lists.o
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Build rule for circular linked lists
$(EXEC_CIRCULAR): $(BUILD_DIR)/circular_linked_lists.o
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Generic rule for building object files in the build directory
$(BUILD_DIR)/%.o: %.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove the build directory and all executables
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean singly doubly circular

