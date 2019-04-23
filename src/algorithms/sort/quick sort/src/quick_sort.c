#include <quick_sort.h>

void swap(int *x, int *y)
{
    int temp = *x; // Store the value of pointer x temporarily.
    *x = *y;       // Assign x to the value of pointer y.
    *y = temp;     // Assign y to the temporarly stored former value of pointer x.
}

void quick_sort(int ary[], const unsigned int m, const unsigned int n)
{
    if (m < n)
    {
        int pivot, i;
        pivot = ary[n];
        i = m - 1;
        for (unsigned int j = m; j < n - 1; ++j)
            if (ary[j] <= pivot)
                swap(&ary[i], &ary[j]);
    }
}