#ifndef PERSON_H
#define PERSON_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "codes.h"
#define MAX_LEN  30
#define MAX_SIZE 50

typedef struct 
{
    int born_year;
    char surname[MAX_LEN + 1];
} person_t;

int read_one(FILE *f, person_t *person);
int read_all(FILE *f, person_t people[], int *num);
void print_people(person_t people[], int num);

#endif