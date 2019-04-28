#include <quick_sort.h>

void swap(int *x, int *y)
{
    int temp = *x; // Store the value of pointer x temporarily.
    *x = *y;       // Assign x to the value of pointer y.
    *y = temp;     // Assign y to the temporarly stored former value of pointer x.
}

int partition(int ary[], const unsigned int lm, const unsigned int rm)
{
    if (lm < rm) // Check if leftmark is smaller than rightmark.
    {
        int pivot, i;
        pivot = ary[rm]; // Set the pivot based on the parameter rm (rightmark).
        i = lm - 1;      // Set the index of the smallest element.
        for (unsigned int j = lm; j < rm; ++j)
            if (ary[j] <= pivot)          // Check if the current element is smaller or equal to the pivot.
                swap(&ary[i++], &ary[j]); // Swap the elements and increment i.
        swap(&ary[i + 1], &ary[rm - 1]);
        return ++i;
    }
}