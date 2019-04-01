#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *ptr = malloc(argv[1], sizeof(int)); // Reserve memory (size is specified by the user) for the array.
    for (int i = 0; i < 3; i++)              // Iterate through the array.
        *(ptr + i) = i;                      // Initialize each index with the corresponding value.

    free(ptr);
}