# Compiler settings
CC := gcc
#CC := clang
CFLAGS := -c -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = include

que_ary: que_ary.o main.o
	$(CC) que_ary.o main.o -o que_ary

que_ary.o: $(SRC_DIR)/que_ary.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/que_ary.c

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) main.c

clean:
	rm -rf *o que_ary