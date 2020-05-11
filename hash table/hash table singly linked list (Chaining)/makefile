# Compiler settings
CC := gcc
CFLAGS := -c -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
OBJ_DIR = obj

$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Linking
ht: ht_node_sll.o ht_sll.o main.o
	$(CC) $(OBJ_DIR)/ht_node_sll.o $(OBJ_DIR)/ht_sll.o $(OBJ_DIR)/main.o -o $(BIN_DIR)/ht_sll

# Compiling
ht_node_sll.o: $(SRC_DIR)/ht_node_sll.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/ht_node_sll.c -o $(OBJ_DIR)/ht_node_sll.o

ht_sll.o: $(SRC_DIR)/ht_sll.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/ht_sll.c -o $(OBJ_DIR)/ht_sll.o

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c -o $(OBJ_DIR)/main.o

# Utilities
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)