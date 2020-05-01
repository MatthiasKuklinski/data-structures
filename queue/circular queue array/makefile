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
cir_que_ary: cir_que_ary.o main.o
	$(CC) $(OBJ_DIR)/cir_que_ary.o $(OBJ_DIR)/main.o -o $(BIN_DIR)/cir_que_ary

# Compiling
cir_que_ary.o: $(SRC_DIR)/cir_que_ary.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/cir_que_ary.c -o $(OBJ_DIR)/cir_que_ary.o

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c -o $(OBJ_DIR)/main.o

# Utilities
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)