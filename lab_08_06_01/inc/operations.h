#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "matrix.h"
#include <ctype.h>
#include <math.h>

void min(int **matrix, int m, int n, int *min_row, int *min_col);
void del_row(int **matrix, int *m, int n, int row_pos);
void del_col(int **matrix, int m, int *n, int col_pos);
void square(int **matrix, int *m, int *n);
void append(int **matrix_a, int **matrix_b, int *m, int *n, int *p, int *q);
void append_col(int **matrix, int m, int *n);
void append_row(int **matrix, int *m, int n);
int geom_avg(int **matrix, int m, int col);
int min_in_row(int *a, int size);
void square_prod(int **matrix_a, int **matrix_b, int **ans, int n);
void make_identity(int **matrix, int n);

#endif