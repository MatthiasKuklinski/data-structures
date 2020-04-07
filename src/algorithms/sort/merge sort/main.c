#include <merge_sort.h>

#include <stdio.h>

#define LENGTH 6

int main()
{
    size_t array[] = {7, 1, 4, 11, 8, 6};
    merge_sort(array, LENGTH);
    for (int i = 0; i < LENGTH; ++i)
        printf("%zd\n", array[i]);
}