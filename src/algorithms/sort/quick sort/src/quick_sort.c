#include <quick_sort.h>

void swap(int *x, int *y)
{
    int temp = *x; // Store the value of pointer x temporarily.
    *x = *y;       // Assign x to the value of pointer y.
    *y = temp;     // Assign y to the temporarly stored former value of pointer x.
}

int partition(int ary[], const int lm, const int rm)
{
    int pivot, i;
    pivot = ary[rm];                   // Set the pivot based on the parameter rm (rightmark): Lomuto partition scheme.
    i = lm - 1;                        // Set the tracking index based on the leftmark.
    for (int j = lm; j <= rm - 1; ++j) // Iterate through the array.
        if (ary[j] < pivot)            // Check if the current element is smaller than the pivot.
            swap(&ary[++i], &ary[j]);  // Increment i and swap the elements.
    swap(&ary[++i], &ary[rm]);         // Increment i and place the pivot at the correct position.
    return i;
}

void quick_sort(int ary[], const int lm, const int rm)
{
    if (lm < rm)
    {
        int pivot = partition(ary, lm, rm);
        quick_sort(ary, lm, pivot - 1);
        quick_sort(ary, pivot + 1, rm);
    }
}