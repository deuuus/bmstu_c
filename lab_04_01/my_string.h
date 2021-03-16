#ifndef MY_STRING_H
#define MY_STRING_H

#define __USE_MINGW_ANSI_STDIO 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

char *my_strpbrk(const char *str, const char *key);

size_t my_strspn(const char *str, const char *key);

size_t my_strcspn(const char *str, const char *key);

char *my_strchr(const char *str, int symbol);

char *my_strrchr(const char *str, int symbol);

#endif