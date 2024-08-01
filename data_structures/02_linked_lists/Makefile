CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))
BUILD_DIR = build
EXEC = $(BUILD_DIR)/exec

all: $(EXEC)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

