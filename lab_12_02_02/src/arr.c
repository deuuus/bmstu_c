#include "arr.h"

ARR_DLL void ARR_DECL fill_fib(long *arr, int n)
{
    long a = 1, b = 1, c = a + b;
    for (int i = 0; i < n; i++)
    {
        arr[i] = a;
        a = b;
        b = c;
        c = a + b;
    }
}

ARR_DLL int ARR_DECL remove_duplicates(int *src, int *dst, int n)
{
    int tmp[n];
    for (int i = 0; i < n; i++)
        tmp[i] = src[i];
    
    int key, pos;
    for (int i = 1; i < n; i++)
    {
        key = tmp[i];
        pos = i - 1;
        while(pos >= 0 && tmp[pos] > key)
        {
            tmp[pos + 1] = tmp[pos];
            pos--;
        }
        tmp[pos + 1] = key;
    }

    int k = 0;
    dst[k++] = tmp[0];
    for (int i = 1; i < n; i++)
        if (tmp[i] != tmp[i - 1])
            dst[k++] = tmp[i];
    return k;
}

ARR_DLL int ARR_DECL unique_count(int *arr, int n)
{
    int tmp[n];
    for (int i = 0; i < n; i++)
        tmp[i] = arr[i];

    int key, pos;
    for (int i = 1; i < n; i++)
    {
        key = tmp[i];
        pos = i - 1;
        while(pos >= 0 && tmp[pos] > key)
        {
            tmp[pos + 1] = tmp[pos];
            pos--;
        }
        tmp[pos + 1] = key;
    }

    int k = 1;
    for (int i = 0; i < n - 1; i++)
        if (tmp[i] != tmp[i + 1])
            k++;
    return k;
}

ARR_DLL void ARR_DECL print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

ARR_DLL void ARR_DECL lprint(long *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%ld ", arr[i]);
    printf("\n");
}