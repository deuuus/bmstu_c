#ifndef NODE_FUNCS_H
#define NODE_FUNCS_H

#include "node.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*));
void *pop_front(node_t **head);

int cmp_people(const void *a, const void *b);

#endif