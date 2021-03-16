#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#define __USE_MINGW_ANSI_STDIO 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

void test_my_strpbrk(void);
void test_my_strspn(void);
void test_my_strcspn(void);
void test_my_strchr(void);
void test_my_strrchr(void);

#endif