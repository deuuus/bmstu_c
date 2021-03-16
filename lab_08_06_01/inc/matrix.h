#ifndef MATRIX_H
#define MATRIX_H

#include "codes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_dimension(int *a, int *b);
void free_matrix(int **matrix, int size);
int **allocate_matrix(int m, int n);
int **reallocate_matrix(int **data, int m, int n);
int read(int **matrix, int m, int n);
void print(int **matrix, int m, int n);

#endif