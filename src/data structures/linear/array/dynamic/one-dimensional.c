#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    int *ptr;

    ptr = calloc(3, sizeof(int)); // Reserve memory for the array.
    printf("%p", ptr);

    free(ptr);
}