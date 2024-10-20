# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable
TARGET = main

# Source files
SRCS = main.c stack.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(TARGET)

# Purge (Clean + remove all .o files and the target)
purge: clean
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
