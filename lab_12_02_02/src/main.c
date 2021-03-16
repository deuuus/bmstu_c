#include <stdio.h>
#include <stdlib.h>
#include "arr.h"

int main(void)
{
    int n = 10;
    long *a = malloc(sizeof(long) * n);
    fill_fib(a, n);
    lprint(a, n);
    free(a);
    return EXIT_SUCCESS;
}