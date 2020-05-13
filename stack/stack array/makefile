# Compiler settings
CC := gcc

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
OBJ_DIR = obj

$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CFLAGS = -c -Wall -g -O0
else
    CFLAGS = -c -Wall
endif

# Linking
stk_ary: stk_ary.o main.o
	$(CC) $(OBJ_DIR)/stk_ary.o $(OBJ_DIR)/main.o -o $(BIN_DIR)/stk_ary

# Compiling
stk_ary.o: $(SRC_DIR)/stk_ary.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/stk_ary.c -o $(OBJ_DIR)/stk_ary.o

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c -o $(OBJ_DIR)/main.o

# Utilities
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)