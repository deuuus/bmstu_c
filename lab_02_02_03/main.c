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

long square(long x)
{
    long k = -1;
    while (x > 0)
    {
        k += 2;
        x -= k;
    }
    return x == 0; 
}

long rezise(size_t newsize, size_t *n)
{
    *n = newsize;
    return EXIT_SUCCESS;
}

int main(void)
{
    setbuf(stdout, NULL);
    size_t n;
    size_t k = 0;
    long buf;
    printf("Enter n:\n");
    if (scanf("%zu", &n) != 1 || n <= 0 || n > NMAX)
        return EXIT_FAILURE;
    long a[NMAX];
    printf("Enter data:\n");
    if (input(a, n) == EXIT_FAILURE)
        return EXIT_FAILURE;
    for (size_t i = 0; i < n; i++)
        if (square(abs(a[i])) == 0)
        {
            buf = a[i];
            a[i] = a[k];
            a[k] = buf;
            k++;
        }
    rezise(k, &n);
    if (k == 0)
        return EXIT_FAILURE;
    print(a, n);
    return EXIT_SUCCESS;
}