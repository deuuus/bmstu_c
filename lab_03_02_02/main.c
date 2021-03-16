#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NMAX 10
#define LEN_INPUT_ERR 1
#define LEN_SIZE_ERR 2
#define ELEM_INPUT_ERR 3
#define EVEN_DIGITS_SUM_ERR 4

long input(long a[][NMAX], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%ld", (a[i] + j)) != 1)
                return ELEM_INPUT_ERR;
    return EXIT_SUCCESS;
}

long odd_digits_sum(long x)
{
    long sum = 0;
    x = abs(x);
    while (x != 0)
    {
        sum += x % 10;
        x /= 10;
    }
    if (sum % 2 == 0)
        return EVEN_DIGITS_SUM_ERR;
    else
        return EXIT_SUCCESS;
}

long insert(long a[][NMAX], size_t *n, size_t m, size_t place)
{
    *n += 1;
    size_t true_place = place;
    place = place != 0 ? place - 1 : 0;
    for (size_t i = *n - 1; i > place; i--)
        for (size_t j = 0; j < m; j++)
            a[i][j] = a[i - 1][j];
    if (true_place != 0)
        place += 1;
    for (size_t j = 0; j < m; j++)
        a[place][j] = -1;
    return EXIT_SUCCESS;
}

int main(void)
{
    setbuf(stdout, NULL);
    size_t n, m;
    long a[NMAX][NMAX];
    size_t k;
    printf("Enter rows and columns:\n");
    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1)
        return LEN_INPUT_ERR;
    if (n < 1 || n > NMAX || m < 1 || m > NMAX)
        return LEN_SIZE_ERR;
    printf("Enter data:\n");
    if (input(a, n, m) == ELEM_INPUT_ERR)
        return ELEM_INPUT_ERR;
    size_t i = 0;
    while (i < n)
    {
        k = 0;
        for (size_t j = 0; j < m; j++)
            if (odd_digits_sum(a[i][j]) == EXIT_SUCCESS)
                k += 1;
        if (k >= 2)
        {
            insert(a, &n, m, i);
            i += 1;
        }
        i += 1;
    }
    for (i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%ld ", a[i][j]);
        printf("\n");
    }
    return EXIT_SUCCESS;
}