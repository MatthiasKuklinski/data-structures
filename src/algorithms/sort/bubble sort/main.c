#include <bubble_sort.h>

#include <stdio.h>

#define LENGTH 12

int main()
{
    size_t array[] = {7, 1, 326, 832, 225, 32323, 45, 1, 36, 43534, 34534, 2};
    bubble_sort(array, LENGTH);
        for (int i = 0; i < LENGTH; ++i)
    {
        printf("%zd\n", array[i]);
    }
}