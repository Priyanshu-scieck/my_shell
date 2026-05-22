CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = bin/myshell

# Find all .c files in src/
SRCS = $(wildcard src/*.c)

# This replaces 'src/filename.c' with 'bin/filename.o'
OBJS = $(patsubst src/%.c, bin/%.o, $(SRCS))

# The default target
all: $(TARGET)

# Link the object files from the bin directory into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation rule: compiles src/%.c directly into bin/%.o
# It makes sure the bin/ directory exists before compiling
bin/%.o: src/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule wipes out the entire bin directory and its contents
clean:
	rm -rf bin

.PHONY: all clean
