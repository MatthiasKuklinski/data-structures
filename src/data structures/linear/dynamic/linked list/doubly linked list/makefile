# Compiler settings
CC := gcc
#CC := clang
CFLAGS := -c -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = include

dll: dll_node.o dll.o main.o
	$(CC) dll_node.o dll.o main.o -o dll

dll_node.o: $(SRC_DIR)/dll_node.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/dll_node.c

dll.o: $(SRC_DIR)/dll.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/dll.c

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c

clean:
	rm -rf *o dll