#include "check_pair.h"

void check_pair(char array1[][NMAX], char array2[][NMAX], size_t *n1, size_t *n2)
{
    long used[NMAX] = { 0 };
    size_t i, j;
    size_t count;
    for (i = 0; i < *n1; i++)
    {
        used[i]++;
        for (j = i + 1; j < *n1; j++)
            if (strcmp(array1[i], array1[j]) == 0)
                used[j]++;
    }
    for (i = 0; i < *n1; i++)
        if (used[i] == 1)
        {
            count = 0;
            for (j = 0; j < *n2; j++)
                if (strcmp(array1[i], array2[j]) == 0)
                {
                    count++;
                    break;
                }
            if (count == 0)
                printf("Result: %s no\n", array1[i]);
            else
                printf("Result: %s yes\n", array1[i]);
        }  
}