#include "process.h"

int process(FILE *f, size_t *n)
{
    size_t k, maxk;
    long temp, prev;
    if (fscanf(f, "%ld", &prev) == 1)
    {
        k = maxk = 1;
        while (fscanf(f, "%ld", &temp) == 1)
        {
            if (temp == prev)
                k++;
            else
            {
                if (k > maxk)
                    maxk = k;
                k = 1;
            }
            prev = temp;
        }
        if (k > maxk)
            maxk = k;
        *n = maxk;
        return EXIT_SUCCESS;
    }
    return NO_DATA;
}