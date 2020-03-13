# Compiler settings
CC := gcc
#CC := clang
CFLAGS := -c -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = include

bubble_sort: bubble_sort.o main.o
	$(CC) bubble_sort.o main.o -o bubble_sort

bubble_sort.o: $(SRC_DIR)/bubble_sort.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/bubble_sort.c

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c

clean:
	rm -rf *o bubble_sort