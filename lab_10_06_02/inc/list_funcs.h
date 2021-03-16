#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include "node.h"

node_t *add(node_t *head_a, node_t *head_b);
node_t *mul(node_t *head_a, node_t *head_b);
node_t *remove_line_with_max(node_t *head);

node_t *find_max(node_t *head);

node_t *get_firts_elem_of_row(node_t *head, int row);
int get_num_of_cols(node_t *head);
int get_num_of_rows(node_t *head);
node_t *get_elem_by_pos(node_t *head, int row, int col);

node_t *expand(node_t *head_a, node_t *head_b);
node_t *find(node_t *head, elem_t data);
node_t *insert(node_t *head, node_t *to_insert, node_t *before);
node_t *remove_zeros(node_t *head);

int cmp_elems(elem_t a, elem_t b);

#endif