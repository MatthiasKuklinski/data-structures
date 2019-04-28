#include <quick_sort.h>

#include <stdio.h>

#define LENGTH 12

int main()
{
    int array[] = {7, 1, 326, 832, 225, 32323, 45, 1, 36, 43534, 34534, 2};
    quick_sort(array, 0, LENGTH - 1);
    for (int i = 0; i < LENGTH; ++i)
        printf("%d\n", array[i]);
}