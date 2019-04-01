#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    int *ptr;

    ptr = calloc(3, sizeof(int));
    free(ptr);
}