#include "file_size.h"

int file_size(FILE *f, size_t *size)
{
    long n;
    if (fseek(f, 0L, SEEK_END) != 0)
        return EXIT_FAILURE;
    n = ftell(f);
    if (n < 0)
        return EXIT_FAILURE;
    *size = n;
    if (fseek(f, 0L, SEEK_SET) != 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}