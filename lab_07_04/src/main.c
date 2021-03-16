#define __USE_MINGW_ANSI_STDIO 1
#include "sort.h"
#include "key.h"

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4)
        return LINE_ERR;
    FILE *f;
    f = fopen(argv[1], "r");
    if (!f)
        return FOPEN_ERR;
    FILE *f_out;
    f_out = fopen(argv[2], "w");
    size_t n = 0;
    int num;
    while (fscanf(f, "%d", &num) == 1)
        n++;
    if (!feof(f))
    {
        fclose(f);
        fclose(f_out);
        return VALUE_ERR;
    }
    if (!n)
    {
        fclose(f);
        fclose(f_out);
        return NO_DATA;
    }
    int *a = NULL;
    a = malloc(n * sizeof(int));
    if (a == NULL)
    {
        fclose(f);
        fclose(f_out);
        return MEM_ERR;
    }
    rewind(f);
    for (int *i = a; i < (a + n); i++)
        fscanf(f, "%d", i);
    mysort(a, n, sizeof(int), (int (*)(const void *, const void *))compare_int);
    int rc;
    if (argc == 4)
    {
        if (strcmp(argv[3], "f"))
        {
            free(a);
            fclose(f);
            fclose(f_out);
            return LINE_ERR;
        }
        int *b = NULL, *b_end = NULL;
        if ((rc = key(a, a + n, &b, &b_end)) != EXIT_SUCCESS)
        {
            free(a);
            free(b);
            fclose(f);
            fclose(f_out);
            return rc;
        }
        free(a);
        for (int *i = b; i < b_end; i++)
            fprintf(f_out, "%d ", *i);
        free(b);
    }
    else
    {
        for (int *i = a; i < a + n; i++)
            fprintf(f_out, "%d ", *i);
        free(a);
    }
    fclose(f);
    fclose(f_out);
    return EXIT_SUCCESS;
}