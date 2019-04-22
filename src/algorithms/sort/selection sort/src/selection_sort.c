#include <selection_sort.h>

void selection_sort(int ary[], const unsigned int n)
{
    int smallest_element_index, temp;
    for (unsigned int i = 0; i < n - 1; ++i)
    {
        smallest_element_index = i; // Set the smallest index to the current iteration index.

        for (unsigned int j = i + 1; j < n; ++j) // Iterate through each successing element.
        {
            if (ary[j] < ary[smallest_element_index]) // Check for smallest element.
                smallest_element_index = j;           // Temporarily store the smallest index.
        }

        if (smallest_element_index != i) // Check if a smaller element was found.
        {
            temp = ary[i];                        // Store the current element temporarily.
            ary[i] = ary[smallest_element_index]; // Assigne the smallest element to the current element.
            ary[smallest_element_index] = temp;   // Swap the smallest element with the current element.
        }
    }
}