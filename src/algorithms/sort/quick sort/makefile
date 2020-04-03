# Compiler settings
CC := gcc
CFLAGS := -c -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = inc
BIN_DIR = bin
OBJ_DIR = obj

$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Linking
quick_sort: quick_sort.o main.o
	$(CC) $(OBJ_DIR)/quick_sort.o $(OBJ_DIR)/main.o -o $(BIN_DIR)/quick_sort

# Compiling
quick_sort.o: $(SRC_DIR)/quick_sort.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/quick_sort.c -o $(OBJ_DIR)/quick_sort.o

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c -o $(OBJ_DIR)/main.o

# Utilities
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
