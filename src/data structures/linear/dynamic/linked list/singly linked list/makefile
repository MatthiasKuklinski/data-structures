# Compiler settings
CC := gcc
#CC := clang

# Directories
SRC_DIR = src

singly-linked-list: singly-linked-list.o main.o
	$(CC) singly-linked-list.o main.o -o singly-linked-list

singly-linked-list.o: $(SRC_DIR)/singly-linked-list.c
	$(CC) -c $(SRC_DIR)/singly-linked-list.c

main.o: main.c
	$(CC) -c main.c

clean:
	rm -rf *o singly-linked-list