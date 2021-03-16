#include "stat_arr.h"

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

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pb_src >= pe_src)
        return KEY_PARAM_ERR;
    int sum = 0;
    for (int *i = (int*)pb_src; i < (int*)pe_src; i++)
        sum += *i;
    int avg = sum / (pe_src - pb_src);
    if (avg * (pe_src - pb_src) != sum && sum < 0)
        avg -= 1;
    int k = 0;
    for (int *i = (int*)pb_src; i < (int*)pe_src; i++)
        if (*i > avg)
            k++;
    if (!k) 
        return NO_DATA;
    *pe_dst = *pb_dst;
    for (int *i = (int*)pb_src; i < (int*)pe_src; i++)
        if (*i > avg)
        {
            **pe_dst = *i;
            *pe_dst += 1;
        }
    return EXIT_SUCCESS;
}

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

int read(FILE *f, size_t n, int *base)
{
    for (int *i = base; i < (base + n); i++)
        if (fscanf(f, "%d", i) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void print(FILE *f, int *pb, int *pe)
{
    for (int *i = pb; i < pe; i++)
        fprintf(f, "%d ", *i);
}