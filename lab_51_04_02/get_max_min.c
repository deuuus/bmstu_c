#include "get_max_min.h"

int get_max_min(FILE *f, double *n1, double *n2)
{
    double num, max_n, min_n;
    size_t max_count, min_count;
    max_count = min_count = 1;
    if (fscanf(f, "%lf", &num) == 1)
        max_n = min_n = num;
    else
        return INPUT_ERR;
    if (feof(f) != 0)
        return INPUT_ERR;
    while (fscanf(f, "%lf", &num) == 1)
    {
        if (num > max_n + EPS)
        {
            max_count = 1;
            max_n = num;
        } 
        else if (fabs(num - max_n) < EPS)
            max_count++;
        if (num < min_n - EPS)
        {
            min_count = 1;
            min_n = num;
        } 
        else if (fabs(num - min_n) < EPS)
            min_count++;
    }
    if (min_count != 1 || max_count != 1)
        return NOT_UNIQUE;
    if (feof(f) == 0 || ferror(f) != 0)
        return INPUT_ERR;
    *n1 = max_n;
    *n2 = min_n;
    return EXIT_SUCCESS;
}