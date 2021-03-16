#include "operations.h"

void square(int **matrix, int *m, int *n)
{
    int k = *m;
    int m_i, m_j;
    if (*n < *m)
        k = *n;
    while (*m != k)
    {
        min(matrix, *m, *n, &m_i, &m_j);
        del_row(matrix, m, *n, m_i);
    }
    while (*n != k)
    {
        min(matrix, *m, *n, &m_i, &m_j);
        del_col(matrix, *m, n, m_j);
    }
}

void append(int **matrix_a, int **matrix_b, int *m, int *n, int *p, int *q)
{
    int k = *m;
    if (*p > *m)
        k = *p;
    while (*m != k)
        append_row(matrix_a, m, *n);
    while (*n != k)
        append_col(matrix_a, *m, n);
    while (*p != k)
        append_row(matrix_b, p, *q);
    while (*q != k)
        append_col(matrix_b, *p, q);
}

void square_prod(int **matrix_a, int **matrix_b, int **ans, int n)
{
    int elem;
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            elem = 0;
            for (k = 0; k < n; k++)
                elem += matrix_a[i][k] * matrix_b[k][j];
            ans[i][j] = elem;
        }
}

void make_identity(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
}

void append_col(int **matrix, int m, int *n)
{
    int res;
    *n += 1;
    for (int i = 0; i < m; i++)
    {
        res = min_in_row(matrix[i], *n - 1);
        matrix[i][*n - 1] = res;
    }
}

void append_row(int **matrix, int *m, int n)
{
    int res;
    *m += 1;
    for (int i = 0; i < n; i++)
    {
        res = geom_avg(matrix, *m - 1, i);
        matrix[*m - 1][i] = res;
    }
}

int geom_avg(int **matrix, int m, int col)
{
    int res = 1;
    for (int i = 0; i < m; i++)
        res *= abs(matrix[i][col]);
    return pow(res, 1.0 / m);
}

int min_in_row(int *a, int size)
{
    int ans = a[0];
    for (int i = 1; i < size; i++)  
        if (a[i] < ans)
            ans = a[i];
    return ans;
}

void min(int **matrix, int m, int n, int *min_row, int *min_col)
{
    int min_elem = matrix[0][0];
    *min_row = 0;
    *min_col = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] <= min_elem)
            {
                min_elem = matrix[i][j];
                *min_row = i;
                *min_col = j;
            }
}

void del_row(int **matrix, int *m, int n, int row_pos)
{
    for (int i = row_pos; i < *m - 1; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = matrix[i + 1][j];
    *m -= 1;
}

void del_col(int **matrix, int m, int *n, int col_pos)
{
    for (int i = 0; i < m; i++)
        for (int j = col_pos; j < *n - 1; j++)
            matrix[i][j] = matrix[i][j + 1];
    *n -= 1;
}