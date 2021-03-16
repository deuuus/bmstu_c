#include "func.h"

int create_bin(FILE *f)
{
    int num;
    size_t wrote;
    int rc = 0;
    while (rc == 0 && scanf("%d", &num) == 1)
    {
        wrote = fwrite(&num, sizeof(int), 1, f);
        rc = (wrote != 1);
    }
    return rc;
}

int print_bin_file(FILE *f)
{
    size_t size;
    int num;
    if (file_size(f, &size) == EXIT_SUCCESS && size != 0)
    {
        for (size_t i = 0; i < size / sizeof(int); i++)
        {
            if (fread(&num, sizeof(int), 1, f) == 1)
                printf("%d ", num);
            else
                return READ_ERR;
        }
        return EXIT_SUCCESS;
    }
    return SIZE_ERR;
}

int sort(FILE *f)
{
    size_t size;
    int temp, minn, min_index;
    if (file_size(f, &size) == EXIT_SUCCESS && size / sizeof(int) > 0)
    {
        size_t n = size / sizeof(int);
        for (size_t i = 0; i < n - 1; i++)
        {
            if (fread(&temp, sizeof(int), 1, f) != 1)
                return READ_ERR;
            min_index = i;
            for (size_t j = i + 1; j < n; j++)
            {
                if (get_number_by_pos(f, j) < get_number_by_pos(f, min_index))
                    min_index = j;
            }
            temp = get_number_by_pos(f, i);
            minn = get_number_by_pos(f, min_index);
            put_number_by_pos(f, temp, min_index);
            put_number_by_pos(f, minn, i);
        }
        return EXIT_SUCCESS;
    }
    return SIZE_ERR;
}

int get_number_by_pos(FILE *f, size_t pos)
{
    int cur = ftell(f);
    int num;
    fseek(f, pos * (sizeof(int)), SEEK_SET);
    fread(&num, sizeof(int), 1, f);
    fseek(f, cur, SEEK_SET);
    return num;
}

void put_number_by_pos(FILE *f, int num, size_t pos)
{
    int cur = ftell(f);
    fseek(f, pos * (sizeof(int)), SEEK_SET);
    fwrite(&num, sizeof(int), 1, f);
    fseek(f, cur, SEEK_SET);
}