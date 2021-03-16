#ifndef UTILITIES_H
#define UITILTIES_H

#define MAX_LEN        25
#define FIELD_ERROR     6
#define READ_ERROR      7
#define VALUE_ERROR     8

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[MAX_LEN + 1];
    char name[MAX_LEN + 1];
    long year;
} movie;

int read(FILE *f, movie *movies, size_t *count);
int insert(movie *movies, size_t count, const char *attribute);
void print(movie to_print);
int binary_search(movie *movies, size_t count, const char *attribute, char *key);

#endif