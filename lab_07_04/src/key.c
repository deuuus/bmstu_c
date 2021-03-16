#include "key.h"

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
    *pb_dst = malloc(k * sizeof(int));
    if (!*pb_dst)
        return MEM_ERR;
    *pe_dst = *pb_dst;
    for (int *i = (int*)pb_src; i < (int*)pe_src; i++)
        if (*i > avg)
        {
            **pe_dst = *i;
            *pe_dst += 1;
        }
    return EXIT_SUCCESS;
}