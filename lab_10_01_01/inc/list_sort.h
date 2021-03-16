#ifndef LIST_SORT_H
#define LIST_SORT_H

#include "node_funcs.h"

void front_back_split(node_t *head, node_t **back);
node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void*, const void*));
node_t *sort(node_t *head, int (*comparator)(const void*, const void*));

#endif