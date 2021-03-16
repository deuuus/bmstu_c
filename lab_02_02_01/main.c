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

double negative_average(long a[], size_t n)
{
    long long s = 0;
    long k = 0;
    for (size_t i = 0; i < n; i++)
        if (a[i] < 0)
        {
            s += a[i];
            k += 1;
        }
    if (k == 0)
        return EXIT_FAILURE;
    else
        return (double)s / k;
}

int main(void)
{
    setbuf(stdout, NULL);
    size_t n;
    long a[NMAX];
    printf("Enter n:\n");
    if (scanf("%zu", &n) != 1 || n <= 0 || n > NMAX)
        return EXIT_FAILURE;
    printf("Enter data:\n");
    if (input(a, n) == EXIT_FAILURE)
        return EXIT_FAILURE;
    double ans;
    ans = negative_average(a, n);
    if (ans != EXIT_FAILURE)
    {
        printf("Result:\n%.6lf", ans);
        return EXIT_SUCCESS;
    }
    else
        return EXIT_FAILURE;
}