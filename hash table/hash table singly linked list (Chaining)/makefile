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
ht: ht_sll_node.o ht_sll.o main.o
	$(CC) $(OBJ_DIR)/ht_sll_node.o $(OBJ_DIR)/ht_sll.o $(OBJ_DIR)/main.o -o $(BIN_DIR)/ht_sll

# Compiling
ht_sll_node.o: $(SRC_DIR)/ht_sll_node.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/ht_sll_node.c -o $(OBJ_DIR)/ht_sll_node.o

ht_sll.o: $(SRC_DIR)/ht_sll.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/ht_sll.c -o $(OBJ_DIR)/ht_sll.o

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c -o $(OBJ_DIR)/main.o

# Utilities
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)