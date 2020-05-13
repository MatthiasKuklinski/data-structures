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
sll: sll_node.o sll.o main.o
	$(CC) $(OBJ_DIR)/sll_node.o $(OBJ_DIR)/sll.o $(OBJ_DIR)/main.o -o $(BIN_DIR)/sll

# Compiling
sll_node.o: $(SRC_DIR)/sll_node.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/sll_node.c -o $(OBJ_DIR)/sll_node.o

sll.o: $(SRC_DIR)/sll.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/sll.c -o $(OBJ_DIR)/sll.o

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c -o $(OBJ_DIR)/main.o

# Utilities
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)