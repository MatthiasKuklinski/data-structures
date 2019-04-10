# Compiler settings
CC := gcc
#CC := clang
CFLAGS := -c -Wall

# Directories
SRC_DIR = src

doubly-linked-list: doubly-linked-list.o main.o
	$(CC) doubly-linked-list.o main.o -o doubly-linked-list

doubly-linked-list.o: $(SRC_DIR)/doubly-linked-list.c
	$(CC) $(CFLAGS) $(SRC_DIR)/doubly-linked-list.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *o doubly-linked-list