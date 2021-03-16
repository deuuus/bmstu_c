#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "codes.h"

typedef struct 
{
    int item;
    int row;
    int col;
} elem_t;

typedef struct node node_t;

struct node
{
    elem_t data;
    node_t *next;
};

int read_dimension(int *a, int *b);
int read_matrix(int n, int m, node_t **head);

node_t *create(int item, int row, int col);
node_t *push_back(node_t *head, node_t *to_push);

void print_all(node_t *head);
void print_one(node_t *node);

void free_all(node_t *head);
void free_one(node_t *to_free);

#endif