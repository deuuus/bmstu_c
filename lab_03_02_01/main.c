#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#define NMAX 10
#define LEN_INPUT_ERR 1
#define LEN_SIZE_ERR 2
#define ELEM_INPUT_ERR 3

long input(long a[][NMAX], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%ld", (a[i] + j)) != 1)
                return ELEM_INPUT_ERR;
    return EXIT_SUCCESS;
}

long change_pos_neg(long ans[], long a[][NMAX], size_t n, size_t m)
{
    long k = 1;
    for (size_t j = 0; j < m; j++)
    {
        k = 1;
        for (size_t i = 1; i < n; i++)
            if (a[i][j] * a[i - 1][j] >= 0)
            {
                k = 0;
                break;
            }
        if (n == 1)
            k = 0;
        *(ans + j) = k;
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    setbuf(stdout, NULL);
    size_t n, m;
    long a[NMAX][NMAX];
    long ans[NMAX];
    printf("Enter rows and columns:\n");
    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1)
        return LEN_INPUT_ERR;
    if (n < 1 || n > NMAX || m < 1 || m > NMAX)
        return LEN_SIZE_ERR;
    printf("Enter data:\n");
    if (input(a, n, m) == ELEM_INPUT_ERR)
        return ELEM_INPUT_ERR;
    change_pos_neg(ans, a, n, m);
    for (size_t j = 0; j < m; j++)
        printf("%ld ", ans[j]);
    return EXIT_SUCCESS;
}