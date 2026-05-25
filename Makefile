CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude

TARGET = bin/myshell

# 1. Look for source files across both directories
SRCS = $(wildcard src/*.c) $(wildcard src/builtins/*.c)

# 2. Tell Make where to search for prerequisites automatically
VPATH = src src/builtins

# 3. Strip the directory paths so all objects are flatly named (e.g., bin/cd.o)
OBJS = $(patsubst %.c, bin/%.o, $(notdir $(SRCS)))

all: bin $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# compilation rule that handles ALL directories
bin/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bin:
	mkdir -p bin

clean:
	rm -rf bin

.PHONY: all clean
