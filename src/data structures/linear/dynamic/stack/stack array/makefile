# Compiler settings
CC := gcc
#CC := clang
CFLAGS := -c -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = include

stk_ary: stk_ary.o main.o
	$(CC) stk_ary.o main.o -o stk_ary

stk_ary.o: $(SRC_DIR)/stk_ary.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/stk_ary.c

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c

clean:
	rm -rf *o stk_ary