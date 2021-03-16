#include "get_between_average.h"

double get_between_average(FILE *f, double *a, double *b)
{
    double num;
    double sum = 0;
    size_t k = 0;
    fscanf(f, "%lf", &num);
    while (fabs(num - *a) >= EPS && fabs(num - *b) >= EPS)
    {
        fscanf(f, "%lf", &num);
    }
    fscanf(f, "%lf", &num);
    while (fabs(num - *a) >= EPS && fabs(num - *b) >= EPS)
    {
        sum += num;
        k++;
        fscanf(f, "%lf", &num);
    }
    if (k == 0)
        return 0;
    return sum / (double)k;
}