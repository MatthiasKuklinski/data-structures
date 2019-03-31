#include <stdio.h>

int main()
{
    unsigned int array[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    printf("Size: %llu\n", sizeof(array));                          // Print the size (in bytes) of the array.
    printf("Length: %llu\n", sizeof(array) / sizeof(unsigned int)); // Print the length (number of elements) of the array.

    for (unsigned int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) // Iterate through the outer array.
    {
        for (unsigned j = 0; j < sizeof(array[i]) / sizeof(unsigned int); ++j) // Iterate through the inner array.
        {
            printf("Index: [%u][%u], memory address: %p, value: %u\n", i, j, &array[i][j], array[i][j]); // Print each elements index, memory location and value.
        }
    }
}
