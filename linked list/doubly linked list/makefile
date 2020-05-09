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
dll: dll_node.o dll.o main.o
	$(CC) $(OBJ_DIR)/dll_node.o $(OBJ_DIR)/dll.o $(OBJ_DIR)/main.o -o $(BIN_DIR)/dll

# Compiling
dll_node.o: $(SRC_DIR)/dll_node.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/dll_node.c -o $(OBJ_DIR)/dll_node.o

dll.o: $(SRC_DIR)/dll.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/dll.c -o $(OBJ_DIR)/dll.o

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c -o $(OBJ_DIR)/main.o

# Utilities
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)