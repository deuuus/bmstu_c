#ifndef STAT_ARR_H
#define STAT_ARR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "return_codes.h"

void print(FILE *f, int *pb, int *pe);
int read(FILE *f, size_t n, int *base);

void mysort(void *base, size_t num, size_t size, int (*compare)(const void*, const void*));
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

int compare_int(const void *p, const void *q);
void swap(char *a, char *b, size_t size);

#endif