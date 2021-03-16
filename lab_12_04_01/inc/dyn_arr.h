#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

ARR_DLL void ARR_DECL print(FILE *f, int *pb, int *pe);
ARR_DLL int ARR_DECL read(FILE *f, size_t n, int *base);

ARR_DLL void ARR_DECL mysort(void *base, size_t num, size_t size, int (*compare)(const void*, const void*));
ARR_DLL int ARR_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

ARR_DLL int ARR_DECL compare_int(const void *p, const void *q);
void swap(char *a, char *b, size_t size);

#endif