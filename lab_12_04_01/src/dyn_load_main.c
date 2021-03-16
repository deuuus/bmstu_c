#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "return_codes.h"
#include "windows.h"

typedef void (__cdecl *fn_mysort_t)(void*, size_t, size_t, int(*)(const void*, const void*));
typedef int (__cdecl *fn_key_t)(const int *, const int *, int **, int **);
typedef int (__cdecl *fn_compare_int_t)(const void *, const void *);
typedef int (__cdecl *fn_read_t)(FILE *, size_t, int *);
typedef void (__cdecl *fn_print_t)(FILE *, int *, int *);

int main(int argc, char *argv[])
{
    HMODULE hlib;
    hlib = LoadLibrary("arr.dll");
    if (!hlib)
        return LOAD_ERR;
    fn_mysort_t mysort;
    fn_key_t key;
    fn_print_t print;
    fn_read_t read;
    fn_compare_int_t compare_int;
    if (argc < 3 || argc > 4)
    {
        FreeLibrary(hlib);
        return LINE_ERR;
    }
    FILE *f;
    f = fopen(argv[1], "r");
    if (!f)
    {
        FreeLibrary(hlib);
        return FOPEN_ERR;
    }
    FILE *f_out;
    f_out = fopen(argv[2], "w");
    size_t n = 0;
    int num;
    while (fscanf(f, "%d", &num) == 1)
        n++;
    if (!feof(f))
    {
        FreeLibrary(hlib);
        fclose(f);
        fclose(f_out);
        return VALUE_ERR;
    }
    if (!n)
    {
        FreeLibrary(hlib);
        fclose(f);
        fclose(f_out);
        return NO_DATA;
    }
    int *a = NULL;
    a = malloc(n * sizeof(int));
    if (a == NULL)
    {
        FreeLibrary(hlib);
        fclose(f);
        fclose(f_out);
        return MEM_ERR;
    }
    rewind(f);
    read = (fn_read_t) GetProcAddress(hlib, "read");
    if (!read)
    {
        FreeLibrary(hlib);
        free(a);
        fclose(f);
        fclose(f_out);
        return PROC_ERR;
    }
    print = (fn_print_t) GetProcAddress(hlib, "print");
    if (!print)
    {
        FreeLibrary(hlib);
        free(a);
        fclose(f);
        fclose(f_out);
        return PROC_ERR;
    }
    mysort = (fn_mysort_t) GetProcAddress(hlib, "mysort");
    if (!mysort)
    {
        FreeLibrary(hlib);
        free(a);
        fclose(f);
        fclose(f_out);
        return PROC_ERR;
    }
    compare_int = (fn_compare_int_t) GetProcAddress(hlib, "compare_int");
    if (!compare_int)
    {
        FreeLibrary(hlib);
        free(a);
        fclose(f);
        fclose(f_out);
        return PROC_ERR;
    }
    key = (fn_key_t) GetProcAddress(hlib, "key");
    if (!key)
    {
        FreeLibrary(hlib);
        free(a);
        fclose(f);
        fclose(f_out);
        return PROC_ERR;
    }
    read(f, n, a);
    mysort(a, n, sizeof(int), (int (*)(const void *, const void *))compare_int);
    int rc;
    if (argc == 4)
    {
        if (strcmp(argv[3], "f"))
        {
            FreeLibrary(hlib);
            free(a);
            fclose(f);
            fclose(f_out);
            return LINE_ERR;
        }
        int *b = NULL, *b_end = NULL;
        b = malloc(sizeof(int) * n);
        if (!b)
        {
            FreeLibrary(hlib);
            free(a);
            fclose(f);
            fclose(f_out);
            return MEM_ERR;
        }
        if ((rc = key(a, a + n, &b, &b_end)) != EXIT_SUCCESS)
        {
            FreeLibrary(hlib);
            free(a);
            free(b);
            fclose(f);
            fclose(f_out);
            return rc;
        }
        free(a);
        print(f_out, b, b_end);
        free(b);
    }
    else
    {
        for (int *i = a; i < a + n; i++)
            fprintf(f_out, "%d ", *i);
        free(a);
    }
    FreeLibrary(hlib);
    fclose(f);
    fclose(f_out);
    return EXIT_SUCCESS;
}