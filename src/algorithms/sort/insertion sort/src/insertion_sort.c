#include <insertion_sort.h>

void insertion_sort(size_t ary[], const size_t n)
{
    size_t j;
    for (size_t i = 1; i < n; i++)
    {
        size_t key = ary[i];           // Store the element(key) to be compared temporarily.
        j = i - 1;
        while(key < ary[j] && j >= 0)  // Iterate through the elements until the temporarily stored element(key) is larger than the element it is compared to or smaller than the first element.
        {
            ary[j + 1] = ary[j];       // Move each element one index to the right.
            j--;
        }
        ary[j + 1] = key;              // Place the temporarily stored element(key) into the sorted elements at the corresponding position.
    }
}