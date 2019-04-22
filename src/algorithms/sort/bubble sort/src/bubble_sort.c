#include <bubble_sort.h>

void bubble_sort(int ary[], int n)
{
    int temp, i, j;
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (i = 0; i < n - 1; ++i)
        {
            j = i + 1;
            if (ary[i] > ary[j]) // Check if the current element is greater than its successing element.
            {
                temp = ary[i];   // Store the current element temporarily.
                ary[i] = ary[j]; // Assigne the successing element to the current element.
                ary[j] = temp;   // Assigne the temporary element to the successing element.
                swapped = 1;     // Set the swapped flag.
            }
        }
    }
}