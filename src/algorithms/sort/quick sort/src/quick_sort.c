#include <quick_sort.h>

void swap(int *x, int *y)
{
    int temp = *x; // Store the value of pointer x temporarily.
    *x = *y;       // Assign x to the value of pointer y.
    *y = temp;     // Assign y to the temporarly stored former value of pointer x.
}

int partition(int ary[], const int lm, const int rm)
{
    if (lm < rm) // Check if leftmark is smaller than rightmark.
    {
        int pivot, i;
        pivot = ary[rm]; // Set the pivot based on the parameter rm (rightmark): Lomuto partition scheme.
        i = lm - 1;      // Set the index for the leftmark.
        for (int j = lm; j <= rm - 1; ++j)
            if (ary[j] < pivot)           // Check if the current element is smaller than the pivot.
                swap(&ary[++i], &ary[j]); // Increment i and swap the elements.
        swap(&ary[i + 1], &ary[rm]);
        return ++i;
    }
}