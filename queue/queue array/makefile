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
que_ary: que_ary.o main.o
	$(CC) $(OBJ_DIR)/que_ary.o $(OBJ_DIR)/main.o -o $(BIN_DIR)/que_ary

# Compiling
que_ary.o: $(SRC_DIR)/que_ary.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/que_ary.c -o $(OBJ_DIR)/que_ary.o

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c -o $(OBJ_DIR)/main.o

# Utilities
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)