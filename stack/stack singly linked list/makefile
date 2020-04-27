# Compiler settings
CC := gcc
#CC := clang
CFLAGS := -c -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = include

stk_sll: stk_sll.o main.o
	$(CC) stk_sll.o main.o -o stk_sll

stk_sll.o: $(SRC_DIR)/stk_sll.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/stk_sll.c

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c

clean:
	rm -rf *o stk_sll