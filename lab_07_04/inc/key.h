#ifndef KEY_H
#define KEY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_codes.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void check_key(void);

#endif