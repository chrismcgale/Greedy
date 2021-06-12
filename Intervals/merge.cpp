#include "merge.h"

void merge(Interval *&A, int l, int r, int m, int mode)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    Interval* a1 = new Interval[n1];
    Interval* a2 = new Interval[n2];

    //2 temp arrays
    for (int i = 0; i < n1; ++i)
        a1[i] = A[l + i];
    for (int j = 0; j < n2; ++j)
        a2[j] = A[m + 1 + j];

    int k = 0, p = 0, n = l;

    //Actual merge
    while (k < n1 && p < n2)
    {
        if (mode == 0)
        {
            if (a1[k].f <= a2[p].f)
            {
                A[n] = a1[k];
                k++;
            }
            else
            {
                A[n] = a2[p];
                p++;
            }
            n++;
        }
        else if (mode == 1)
        {
            if (a1[k].s <= a2[p].s)
            {
                A[n] = a1[k];
                k++;
            }
            else
            {
                A[n] = a2[p];
                p++;
            }
            n++;
        }
        delete [] a1;
        delete [] a2;
    }

    //incase left over in either array
    while (k < n1)
    {
        A[n] = a1[k];
        n++;
        k++;
    }

    while (p < n2)
    {
        A[n] = a2[p];
        n++;
        p++;
    }
}

void mergeSort(Interval *&A, int l, int r, int mode)
{
    if (r <= l)
        return;
    int m = l + (r - l) / 2;
    mergeSort(A, l, m, mode);
    mergeSort(A, m + 1, r, mode);
    merge(A, l, r, m, mode);
}
