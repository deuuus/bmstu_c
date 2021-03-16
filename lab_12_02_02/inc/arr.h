#ifndef ARR_H
#define ARR_H

#ifndef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

#include <stdio.h>
#include <stdlib.h>

ARR_DLL void ARR_DECL fill_fib(long *arr, int n);
ARR_DLL int ARR_DECL unique_count(int *arr, int n);
ARR_DLL int ARR_DECL remove_duplicates(int *src, int *dst, int n);
ARR_DLL void ARR_DECL print(int *arr, int n);
ARR_DLL void ARR_DECL lprint(long *arr, int n);

#endif