#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>

int compare_int(const void *p, const void *q);
void swap(char *a, char *b, size_t size);
void mysort(void *base, size_t num, size_t size, int (*compare)(const void*, const void*));

#endif