CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SRC = queue_arr.c queue_ll.c 
BUILD_DIR = build

# Define executables for each source file
EXEC_ARR = $(BUILD_DIR)/queue_arr
EXEC_LL = $(BUILD_DIR)/queue_ll

# Build all executables when running make
all: $(EXEC_ARR) $(EXEC_LL)

# Targets for building each executable individually
arr: $(EXEC_ARR)

ll: $(EXEC_LL)

# Build rule for array based queues
$(EXEC_ARR): $(BUILD_DIR)/queue_arr.o
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Build rule for linked list based queues
$(EXEC_LL): $(BUILD_DIR)/queue_ll.o
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^


# Generic rule for building object files in the build directory
$(BUILD_DIR)/%.o: %.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove the build directory and all executables
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean arr ll 

