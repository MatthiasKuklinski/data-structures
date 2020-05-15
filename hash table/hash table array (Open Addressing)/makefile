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
ht: ht_ary_entry.o ht_ary.o main.o
	$(CC) $(OBJ_DIR)/ht_ary_entry.o $(OBJ_DIR)/ht_ary.o $(OBJ_DIR)/main.o -o $(BIN_DIR)/ht_ary

# Compiling
ht_ary_entry.o: $(SRC_DIR)/ht_ary_entry.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/ht_ary_entry.c -o $(OBJ_DIR)/ht_ary_entry.o

ht_ary.o: $(SRC_DIR)/ht_ary.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/ht_ary.c -o $(OBJ_DIR)/ht_ary.o

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c -o $(OBJ_DIR)/main.o

# Utilities
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)