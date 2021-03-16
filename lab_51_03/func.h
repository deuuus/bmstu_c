#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include "file_size.h"
#define READ_ERR 10
#define SIZE_ERR 20

int print_bin_file(FILE *f);
int create_bin(FILE *f);
int sort(FILE *f);
int get_number_by_pos(FILE *f, size_t pos);
void put_number_by_pos(FILE *f, int num, size_t pos);

#endif