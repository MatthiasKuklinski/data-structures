#include <bubble_sort.h>

void bubble_sort(int ary[], int n)
{
    int temp;
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (ary[i] > ary[i + 1])
            {
                temp = ary[i];
                ary[i] = ary[i + 1];
                ary[i + 1] = temp;
                swapped = 1;
            }
        }
    }
}