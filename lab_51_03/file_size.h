#ifndef FILE_SIZE_H
#define FILE_SIZE_H

#include <stdio.h>
#include <stdlib.h>
#define SEEK_ERR 5
#define TELL_ERR 6

int file_size(FILE *f, size_t *size);

#endif