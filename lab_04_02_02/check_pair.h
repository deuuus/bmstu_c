#ifndef CHECK_PAIR_H
#define CHECK_PAIR_H

#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check_pair.h"
#define NMAX 257

void check_pair(char array1[][NMAX], char array2[][NMAX], size_t *n1, size_t *n2);

#endif