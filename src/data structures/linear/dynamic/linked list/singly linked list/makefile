# Compiler settings
CC := gcc
#CC := clang
CFLAGS := -c -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = include

sll: sll_node.o sll.o main.o
	$(CC) sll_node.o sll.o main.o -o sll

sll_node.o: $(SRC_DIR)/sll_node.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/sll_node.c

sll.o: $(SRC_DIR)/sll.c
	$(CC) $(CFLAGS) $(SRC_DIR)/sll.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *o sll