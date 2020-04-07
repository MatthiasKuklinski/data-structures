#include <merge_sort.h>

void merge(size_t ary[], size_t l_ary[], const size_t l_n, size_t r_ary[], const size_t r_n)
{
    size_t l,r,m = l = r = 0;   // Stores the index of each array(l_ary, r_ary, ary(merged))
    while(l < l_n && r < r_n)
    {
        if(l_ary[l] < r_ary[r])
            ary[m++] = l_ary[l++];
        else
            ary[m++] = r_ary[r++];
    }

    while(l < l_n)
        ary[m++] = l_ary[l++];
    while(r < r_n)
        ary[m++] = r_ary[r++];
}

void merge_sort(size_t ary[], const size_t n)
{
    if (n < 2)
        return; // Exit if the sub-array consists of only a single element.
    const size_t m = n / 2;

    size_t l_ary[m];
    size_t r_ary[n - m];

    for (size_t i = 0; i < m; i++)
        l_ary[i] = ary[i];

    for (size_t i = 0; i < n - m; i++)
        r_ary[i] = ary[m + i];

    merge_sort(l_ary, m);
    merge_sort(r_ary, n - m);
    merge(ary, l_ary, m, r_ary, n-m);
}