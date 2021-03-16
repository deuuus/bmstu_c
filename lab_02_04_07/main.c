#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#define NMAX 10

long input(long a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%ld", &a[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void print(long a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%ld ", a[i]);
}

long selection_sort(long a[], size_t n)
{
    long min_index;
    long buf;
    for (size_t i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (size_t j = i + 1; j < n; j++)
            if (a[j] < a[min_index])
                min_index = j;
        buf = a[i];
        a[i] = a[min_index];
        a[min_index] = buf;
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    setbuf(stdout, NULL);
    size_t n;
    printf("Enter n:\n");
    if (scanf("%zu", &n) != 1 || n <= 0 || n > NMAX)
        return EXIT_FAILURE;
    long a[NMAX];
    printf("Enter data:\n");
    if (input(a, n) == EXIT_FAILURE)
        return EXIT_FAILURE;
    selection_sort(a, n);
    print(a, n);
    return EXIT_SUCCESS;
}