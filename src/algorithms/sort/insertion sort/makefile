# Compiler settings
CC := gcc
#CC := clang
CFLAGS := -c -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = include

insertion_sort: insertion_sort.o main.o
	$(CC) insertion_sort.o main.o -o insertion_sort

insertion_sort.o: $(SRC_DIR)/insertion_sort.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/insertion_sort.c

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c

clean:
	rm -rf *o insertion_sort