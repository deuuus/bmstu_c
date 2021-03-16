#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

#define BUF_SIZE 300

int my_snprintf(char *str, size_t size, const char *format, ...);
size_t len(long long num);
void convert(long long num, char buf[]);

#endif