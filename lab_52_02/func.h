#ifndef FUNC_H
#define FUNC_H

#include "file_size.h"
#include <inttypes.h>
#include <string.h>
#define MAX_NAME_LEN       30
#define MAX_PRODUCER_LEN   15
#define GET_ERR             1
#define PUT_ERR             2
#define READ_ERR            3
#define WRITE_ERR           4
#define FILE_ERR            5
#define COPY_ERR            6
#define SEEK_ERR            7
#define SCAN_ERR            8

int sort(FILE *f_in, FILE *f_out, size_t n);
int insert(FILE *f, size_t n);
int end_substr(FILE *f, const char *substr, size_t n);

#endif