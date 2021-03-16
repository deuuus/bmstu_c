#include "file_size.h"

int file_size(FILE *f, size_t *size)
{
    long n;
    if (fseek(f, 0L, SEEK_END) != 0)
        return SEEK_ERR;
    n = ftell(f);
    *size = n;
    if (n < 0)
        return TELL_ERR;
    if (fseek(f, 0L, SEEK_SET) != 0)
        return SEEK_ERR;
    return EXIT_SUCCESS;
}