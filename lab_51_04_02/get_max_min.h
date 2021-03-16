#ifndef GET_MAX_MIN_H
#define GET_MAX_MIN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN         256
#define OPEN_ERR         -1
#define NO_NAME_ERR      -2
#define INPUT_ERR        -3
#define NOT_UNIQUE       -4
#define EPS            1e-6

int get_max_min(FILE *f, double *n1, double *n2);

#endif
