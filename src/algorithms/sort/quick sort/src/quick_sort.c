#include <quick_sort.h>

void swap(size_t *x, size_t *y)
{
    size_t t = *x; // Store the value of pointer x temporarily.
    *x = *y;       // Assign x to the value of pointer y.
    *y = t;        // Assign y to the temporarly stored former value of pointer x(effectively swap them).
}

size_t partition(size_t ary[], const size_t lm, const size_t rm)
{
    size_t pivot = ary[rm];           // Set the pivot based on the parameter rm (rightmark): Lomuto partition scheme.
    size_t i = lm - 1;                // Set the tracking index based on the leftmark.
    for (size_t j = lm; j < rm; j++)  // Iterate through the array.
        if (ary[j] <= pivot)          // Check if the current element is smaller than the pivot.
            swap(&ary[++i], &ary[j]); // Increment i and swap the elements.
    swap(&ary[++i], &ary[rm]);        // Increment i and place the pivot at the correct position.
    return i;                         // Return the index of the pivot element after it was placed at its correspondig position.
}

void quick_sort(size_t ary[], const size_t lm, const size_t rm)
{
    if (lm < rm) // Check if the leftmark is smaller than the rightmark.
    {
        size_t pivot = partition(ary, lm, rm); // Determine the pivot.
        quick_sort(ary, lm, pivot - 1);        // Quicksort the elements before the pivot.
        quick_sort(ary, pivot + 1, rm);        // Quicksort the elements after the pivot.
    }
}