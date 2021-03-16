#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <stdio.h>
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

long find_max5(long a[][NMAX], size_t n)
{
    long max5 = 3;
    for (size_t i = 1; i < n; i++)
        for (size_t j = n - 1; j > n - i - 1; j--)
            if (abs(a[i][j]) % 10 == 5)
                if (max5 == 3 || (max5 != 3 && a[i][j] > max5))
                    max5 = a[i][j];
    return max5;
}

int main(void)
{
    setbuf(stdout, NULL);
    size_t n, m;
    long a[NMAX][NMAX];
    long ans;
    printf("Enter rows and columns:\n");
    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1)
        return LEN_INPUT_ERR;
    if (n < 1 || n > NMAX || m < 1 || m > NMAX || n != m)
        return LEN_SIZE_ERR;
    printf("Enter data:\n");
    if (input(a, n, m) == ELEM_INPUT_ERR)
        return ELEM_INPUT_ERR;
    ans = find_max5(a, n);
    if (ans != 3)
    {
        printf("%ld", ans);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}