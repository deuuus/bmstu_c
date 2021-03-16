#include "process.h"

int main(void)
{
    setbuf(stdout, NULL);
    FILE *f = stdin;
    size_t n = 0;
    int rc;
    if ((rc = process(f, &n)) != EXIT_SUCCESS)
        return rc;
    printf("Result: %zu", n);
    return EXIT_SUCCESS;
}