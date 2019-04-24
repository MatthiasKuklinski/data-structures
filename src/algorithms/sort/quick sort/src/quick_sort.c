#include <quick_sort.h>

void swap(int *x, int *y)
{
    int temp = *x; // Store the value of pointer x temporarily.
    *x = *y;       // Assign x to the value of pointer y.
    *y = temp;     // Assign y to the temporarly stored former value of pointer x.
}

void partition(int ary[], const unsigned int m, const unsigned int n)
{
    if (m < n)
    {
        int pivot, i;
        pivot = ary[n]; // Set the pivot based on the parameter m (minimum).
        i = m - 1;      // Set the index of the smaller element relative to the pivot.
        for (unsigned int j = m; j < n - 1; ++j)
            if (ary[j] <= pivot)          // Check if the current element is smaller or equal to the pivot.
                swap(&ary[i++], &ary[j]); // Swap the elements and increment i.
    }
}