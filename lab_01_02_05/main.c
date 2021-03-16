#include <stdio.h>
#include <stdlib.h>
#define N 46L

long fib(long n)
{
    long f0 = 0;
    long f1 = 1;
    long buf;
    long i = 2;
    while (i <= n)
    {
        buf = f1;
        f1 = f0 + f1;
        f0 = buf;
        i += 1;
    }
    if (n == 0 || n == 1)
        return n;
    else
        return f1;
}

int main(void)
{
    setbuf(stdout, NULL);
    long n;
    long res;
    printf("Enter n: ");
    if (scanf("%ld", &n) != 1 || n < 0 || n > N)
    {
        printf("Error.");
        return EXIT_FAILURE;
    }
    res = fib(n);
    printf("Result: %ld", res);
    return EXIT_SUCCESS;
}