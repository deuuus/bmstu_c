#ifndef MOVIE_H
#define MOVIE_H

#define INIT_LEN 16

#define ARGS_ERR               1

#define NO_DATA_ERR            2
#define NOT_ENOUGH_DATA_ERR    3
#define TOO_MUCH_DATA_ERR      4

#define FILE_ERR               5
#define READ_ERR               6

#define ALLOCATE_ERR           7
#define REALLOCATE_ERR         8

#define ATTRIBUTE_ERR          9
#define INTEGER_ERR           10
#define LINE_ERR              11
#define KEY_ERR               12

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char *title;
    char *name;
    long year;
} movie;

int read_one(FILE *f, movie *to_read);
int read_all(FILE *f, movie **movies, int count, const char *attribute);

void print_all(movie *to_print, int count);
void print_one(movie to_print);

void free_all(movie **movies, int count);
void free_one(movie *to_free);

int binary_search(movie *movies, size_t count, const char *attribute, char *key);
int insert(movie **movies, size_t count, int (*cmp)(movie, movie));

int get_count(FILE *f, int *count);
int replace(movie *dst, char *title, char *name, int year);
int my_getline(char **lineptr, FILE *stream);

int is_pos_num(char *str);

int cmp_year(movie a, movie b);
int cmp_title(movie a, movie b);
int cmp_name(movie a, movie b);
int cmp_year_str(movie a, char *str);
int cmp_title_str(movie a, char *str);
int cmp_name_str(movie a, char *str);

#endif