#ifndef NODE_H
#define NODE_H

#include "person.h"

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

node_t *create(person_t *film);

node_t *push_back(node_t *head, node_t *to_push);

int init(person_t people[], int num, node_t **head);

void print_one(node_t *node);
void print_all(node_t *head);

int write_all(FILE *f, node_t *head);
int write_one(FILE *f, node_t *to_write);

void free_one(node_t *to_free);
void free_all(node_t *head);

#endif