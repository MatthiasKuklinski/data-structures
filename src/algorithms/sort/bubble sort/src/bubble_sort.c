#include <bubble_sort.h>

void bubble_sort(int ary[], int n)
{
    int temp;
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (unsigned int i = 0; i < n - 1; ++i)
        {
            if (ary[i] > ary[i + 1]) // Check if the current element is greater than its successing element.
            {
                temp = ary[i];       // Store the current element temporarily.
                ary[i] = ary[i + 1]; // Assigne the successing element to the current element.
                ary[i + 1] = temp;   // Assigne the temporary element to the successing element.
                swapped = 1;         // Set the swapped flag.
            }
        }
    }
}