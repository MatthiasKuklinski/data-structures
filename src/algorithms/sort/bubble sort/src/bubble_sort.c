#include <bubble_sort.h>

void bubble_sort(size_t ary[], const size_t n)
{
    int temp, i, j;
    unsigned int swapped = 1;
    while (swapped) // Iterate through the elements until each element is sorted.
    {
        swapped = 0; // Set the swapped flag to false. Assume the data structure is sorted before each inner iteration.
        for (i = 0; i < n - 1; ++i)
        {
            j = i + 1;
            if (ary[i] > ary[j]) // Check if the current element is greater than its successor.
            {
                temp = ary[i];   // Store the current element temporarily.
                ary[i] = ary[j]; // Assigne the successor to the current element.
                ary[j] = temp;   // Assigne the temporary element to the successor.
                swapped = 1;     // Set the swapped flag to true(indicate that the data structure was not sorted).
            }
        }
    }
}