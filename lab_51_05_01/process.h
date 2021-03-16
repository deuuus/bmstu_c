#ifndef PROCESS_H
#define PROCESS_H

#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#define NO_DATA -1

int process(FILE *f, size_t *n);

#endif