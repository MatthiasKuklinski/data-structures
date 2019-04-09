# Compiler settings
CC := gcc
#CC := clang
CFLAGS := -c -Wall

# Directories
SRC_DIR = src

singly-linked-list: singly-linked-list.o main.o
	$(CC) singly-linked-list.o main.o -o singly-linked-list

singly-linked-list.o: $(SRC_DIR)/singly-linked-list.c
	$(CC) $(CFLAGS) $(SRC_DIR)/singly-linked-list.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *o singly-linked-list