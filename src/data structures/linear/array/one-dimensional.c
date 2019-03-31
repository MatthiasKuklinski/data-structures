#include <stdio.h>

int main()
{
    unsigned int array[3] = {1, 2, 3};               // Allocate memory for five elements of type int and initialize each element with the corresponding value.
    printf("Size: %llu\n", sizeof(array));                 // Print the size (in bytes) of the array.
    printf("Length: %llu\n", sizeof(array) / sizeof(int)); // Print the length (number of elements) of the array.

    for (unsigned int i = 0; i < sizeof(array) / sizeof(int); ++i) // Iterate through the array
    {
        printf("Index: %u, memory address: %p, value: %u\n", i, &array[i], array[i]); // Print each elements index, memory location and value.
    }
}
