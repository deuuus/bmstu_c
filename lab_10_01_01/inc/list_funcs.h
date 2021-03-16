#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include "node_funcs.h"

void append(node_t **head_a, node_t **head_b);
void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*));

#endif