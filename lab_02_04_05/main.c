#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#define NMAX 10

long input(long *a_begin, long *a_end)
{
    while (a_begin <= a_end)
    {
        if (scanf("%ld", a_begin) != 1)
            return EXIT_FAILURE;
        a_begin++;
    }
    return EXIT_SUCCESS;
}

long selection_sort(long *a_begin, long *a_end)
{
    long *min_index;
    long buf;
    long *temp;
    while (a_begin < a_end)
    {
        min_index = a_begin;
        temp = a_begin + 1;
        while (temp <= a_end)
        {
            if (*temp < *min_index)
                min_index = temp;
            temp++;
        }
        buf = *a_begin;
        *a_begin = *min_index;
        *min_index = buf;
        a_begin++;
    }
    return EXIT_SUCCESS;
}

long various(long *a_begin, long *a_end)
{
    selection_sort(a_begin, a_end);
    long k = 1;
    a_begin++;
    while (a_begin <= a_end)
    {
        if (*a_begin != *(a_begin - 1))
            k++;
        a_begin++;
    }
    return k;
}

int main(void)
{
    setbuf(stdout, NULL);
    size_t n;
    long res = 0;
    printf("Enter n:\n");
    if (scanf("%zu", &n) != 1 || n <= 0 || n > NMAX)
        return EXIT_FAILURE;
    long a[NMAX];
    if (input(a, a + n - 1) == EXIT_FAILURE)
        return EXIT_FAILURE;
    res = various(a, a + n - 1);
    printf("%ld", res);
    return EXIT_SUCCESS;
}
