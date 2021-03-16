#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NMAX 10
#define LEN_INPUT_ERR 1
#define LEN_SIZE_ERR 2
#define ELEM_INPUT_ERR 3
#define NOTHING_TO_CHANGE_ERR 4
#define NOT_PRIME 5

long input(long a[][NMAX], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%ld", (a[i] + j)) != 1)
                return ELEM_INPUT_ERR;
    return EXIT_SUCCESS;
}

long is_prime(long x)
{
    x = abs(x);
    long count = 0;
    for (long i = 1; i <= sqrt(x); i++)
        if (x % i == 0)
            count += 1;
    if (count < 2 && x > 1)
        return EXIT_SUCCESS;
    return NOT_PRIME;
}

long append(long a[], long k, long x)
{
    *(a + k) = x;
    return EXIT_SUCCESS;
}

long reverse(long a[], long k)
{
    long buf;
    for (long i = 0; i < k / 2; i++)
    {
        buf = a[i];
        a[i] = a[k - i - 1];
        a[k - i - 1] = buf;
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    setbuf(stdout, NULL);
    size_t n, m;
    long a[NMAX][NMAX];
    long arr[NMAX * NMAX + 1];
    long k = 0;
    size_t i, j;
    printf("Enter rows and columns:\n");
    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1)
        return LEN_INPUT_ERR;
    if (n < 1 || n > NMAX || m < 1 || m > NMAX)
        return LEN_SIZE_ERR;
    printf("Enter data:\n");
    if (input(a, n, m) == ELEM_INPUT_ERR)
        return ELEM_INPUT_ERR;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (is_prime(a[i][j]) == EXIT_SUCCESS)
            {
                k += 1;
                append(arr, k - 1, a[i][j]);
            }
    if (k == 0)
        return NOTHING_TO_CHANGE_ERR;
    reverse(arr, k);
    k = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (is_prime(a[i][j]) == EXIT_SUCCESS)
            {
                a[i][j] = arr[k];
                k += 1;
            }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%ld ", a[i][j]);
        printf("\n");
    }
    return EXIT_SUCCESS;
}