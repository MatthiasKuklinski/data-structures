#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long length = strtol(argv[1], NULL, 10); // Convert char/string into long
    int *ptr = malloc(length * sizeof(int)); // Reserve memory (size is specified by the user) for the array.
    for (int i = 0; i < length; i++)         // Iterate through the array.
        *(ptr + i) = i;                      // Initialize each index with the corresponding value.

    for (int i = 0; i < length; i++)
        printf("%d", *(ptr + i));

    free(ptr);
}