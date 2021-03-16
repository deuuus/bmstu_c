#include "sort.h"

int compare_int(const void *p, const void *q)
{
    return *(int*)p - *(int*)q;
}

void swap(char *a, char *b, size_t size)
{
    char tmp[size];
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

void mysort(void *base, size_t num, size_t size, int (*compare)(const void*, const void*))
{
    for (char *i = (char*)base + size; i < (char*)base + num * size; i += size)
    {
        char *j = i - size;
        while (j >= (char*)base && compare(j + size, j) <= 0)
        {   
            swap(j, j + size, size);
            j -= size;
        }
    }
}