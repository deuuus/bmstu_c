#ifndef GET_NEW_STRING_H
#define GET_NEW_STRING_H

#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_new_string.h"
#define NMAX 257
#define MAX_LEN 16
#define GOT_EMPTY_STRING 6

void reform(char string[]);
long get_new_string(char array[][NMAX], char string[], size_t *n);

#endif