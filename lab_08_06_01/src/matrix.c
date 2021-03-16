#include "matrix.h"

int read_dimension(int *a, int *b)
{
    if (scanf("%d", a) != 1 || scanf("%d", b) != 1)
        return READ_ERR;
    if (*a <= 0 || *b <= 0)
        return SIZE_ERR;
    return EXIT_SUCCESS;
}

int **allocate_matrix(int m, int n)
{
    int **data = calloc(m, sizeof(int*));
    if (!data)
        return NULL;
    for (int i = 0; i < m; i++)
    {
        data[i] = malloc(n * sizeof(int));
        if (!data[i])
        {
            free_matrix(data, m);
            return NULL;
        }
    }
    return data;
}

int read(int **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (scanf("%d", &matrix[i][j]) != 1)
                return READ_ERR;
    return EXIT_SUCCESS;
}

void print(int **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) 
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void free_matrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
        free(matrix[i]);
    free(matrix);
}