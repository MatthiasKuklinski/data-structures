#include <quick_sort.h>

void swap(int *x, int *y)
{
    int temp = *x; // Store the value of pointer x temporarily.
    *x = *y;       // Assign x to the value of pointer y.
    *y = temp;     // Assign y to the temporarly stored former value of pointer x.
}

void partition(int ary[], const unsigned int low, const unsigned int high)
{
    if (low < high)
    {
        int pivot, i;
        pivot = ary[high]; // Set the pivot based on the parameter m (minimum).
        i = low - 1;      // Set the index of the smaller element relative to the pivot.
        for (unsigned int j = low; j < high; ++j)
            if (ary[j] <= pivot)          // Check if the current element is smaller or equal to the pivot.
                swap(&ary[i++], &ary[j]); // Swap the elements and increment i.
        swap(&ary[i + 1], &ary[high - 1]);
        return ++i;
    }
}