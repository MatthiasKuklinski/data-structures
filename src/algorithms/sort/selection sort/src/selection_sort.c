#include <selection_sort.h>

void selection_sort(int ary[], const unsigned int n)
{
    int smallest_element_index, temp;
    for (unsigned int i = 0; i < n - 1; ++i)
    {
        smallest_element_index = i;

        for (unsigned int j = i + 1; j < n; ++j)
        {
            if (ary[j] < ary[smallest_element_index])
                smallest_element_index = j;
        }

        if (smallest_element_index != i)
        {
            temp = ary[i];
            ary[i] = ary[smallest_element_index];
            ary[smallest_element_index] = temp;
        }
    }
}