CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g 

SRC = main.c
OBJ = $(SRC:.c=.o)
BUILD_DIR = build
EXEC = $(BUILD_DIR)/exec

all: $(EXEC)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
