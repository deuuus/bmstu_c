#ifndef GET_WORDS_H
#define GET_WORDS_H

#define __USE_MINGW_ANSI_STDIO 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define NMAX 257
#define MAX_LEN 16
#define NOT_ENOUGH 1
#define INPUT1_ERR 2
#define INPUT2_ERR 3
#define WORD_LEN_ERR 4
#define OUTPUT_ERROR 5

#define NMAX 257
#define MAX_LEN 16
#define INPUT1_ERR 2
#define WORD_LEN_ERR 4
#define OUTPUT_ERROR 5

#define INT_SPACE 32
#define INT_EOS 0 

long get_words(char str[], char words_array[][NMAX], size_t *words);

#endif