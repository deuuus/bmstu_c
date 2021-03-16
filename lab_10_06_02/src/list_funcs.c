#include "list_funcs.h"

node_t *add(node_t *head_a, node_t *head_b)
{
    head_a = expand(head_a, head_b);
    head_b = expand(head_b, head_a);
    node_t *cur_a = head_a;
    node_t *cur_b = head_b;
    for (; cur_a; cur_a = cur_a->next, cur_b = cur_b->next)
        (cur_a->data).item += (cur_b->data).item;
    return remove_zeros(head_a);
}

node_t *mul(node_t *head_a, node_t *head_b)
{
    node_t *res = NULL, *buf;
    int sum = 0;
    int n = get_num_of_rows(head_a);
    int m = get_num_of_cols(head_b);
    for (int i = 0; i <= n; i++)
        if ((buf = get_firts_elem_of_row(head_a, i)))
            for (int j = 0; j <= m; j++)
            {
                sum = 0;
                node_t *row = buf;
                for (; row && row->data.row == i; row = row->next)
                {
                    node_t *elem_b;
                    if ((elem_b = get_elem_by_pos(head_b, row->data.col, j)))
                        sum += row->data.item * elem_b->data.item;
                }
                if (sum != 0)
                {
                    node_t *new = create(sum, i, j);
                    res = push_back(res, new);
                }
            }
    return res;
}

node_t *remove_line_with_max(node_t *head)
{
    node_t *max = find_max(head);
    node_t *cur = head, *prev = NULL;
    int row = max->data.row;
    while (cur && cur->data.row != row)
    {
        prev = cur;
        cur = cur->next;
    }
    while (cur && cur->data.row == row)
        if (prev)
        {
            node_t *buf = cur;
            prev->next = cur->next;
            free(buf);
            cur = prev->next;
        }
        else
        {
            cur = cur->next;
            node_t *buf = head;
            head = head->next;
            free(buf);
        }
    return head;
}

node_t *find_max(node_t *head)
{
    if (!head)
        return NULL;
    node_t *cur = head;
    node_t *max = head;
    for (; cur; cur = cur->next)
        if (cur->data.item > max->data.item)
            max = cur;
    return max;
}

node_t *get_firts_elem_of_row(node_t *head, int row)
{
    if (!head)
        return NULL;
    node_t *cur = head;
    for (; cur; cur = cur->next)
        if ((cur->data).row == row)
            return cur;
    return NULL;
}

int get_num_of_rows(node_t *head)
{
    if (!head)
        return 0;
    node_t *cur = head;
    while (cur->next)
        cur = cur->next;
    return cur->data.row;
}

int get_num_of_cols(node_t *head)
{
    if (!head)
        return 0;
    node_t *cur = head;
    while (cur->next)
        cur = cur->next;
    return cur->data.col;
}

node_t *get_elem_by_pos(node_t *head, int row, int col)
{
    node_t *cur = head;
    for (; cur; cur = cur->next)
        if ((cur->data).row == row && (cur->data).col == col)
            return cur;
    return NULL;
}

node_t *remove_zeros(node_t *head)
{
    if (!head)
        return NULL;
    node_t *cur = head, *prev = NULL;
    while (cur)
        if (cur->data.item == 0)
        {
            if (prev)
            {
                node_t *buf = cur;
                prev->next = cur->next;
                free(buf);
                cur = prev->next;
            }
            else
            {
                cur = cur->next;
                node_t *buf = head;
                head = head->next;
                free(buf);
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    return head;
}

node_t *insert(node_t *head, node_t *to_insert, node_t *before)
{
    if (!head)
        return to_insert;
    node_t *cur = head, *prev = NULL;
    if (!before)
    {
        while (cur->next)
            cur = cur->next;
        cur->next = to_insert;
        return head;
    }
    while (cur->next && cur != before)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev)
    {
        to_insert->next = prev->next;
        prev->next = to_insert;
    }
    else
    {
        to_insert->next = head;
        head = to_insert;
    }
    return head;
}

node_t *expand(node_t *head_a, node_t *head_b)
{
    node_t *cur = head_b;
    for (; cur; cur = cur->next)
    {
        node_t *f = find(head_a, cur->data);
        if (!f)
        {
            node_t *to_insert = create(0, (cur->data).row, (cur->data).col);
            node_t *temp = head_a, *prev = NULL;
            while (temp->next && cmp_elems(to_insert->data, temp->data) > 0)
            {
                prev = temp;
                temp = temp->next;
            }
            if (cmp_elems(to_insert->data, temp->data) > 0)
                prev = temp;
            if (prev)
            {
                if (cmp_elems(to_insert->data, prev->data) > 0)
                    head_a = insert(head_a, to_insert, prev->next);
                else
                    head_a = insert(head_a, to_insert, prev);
            }
            else
                head_a = insert(head_a, to_insert, head_a);
        }
    }
    return head_a;
}

node_t *find(node_t *head, elem_t data)
{
    if (!head)
        return NULL;
    node_t *cur = head;
    while (cur->next)
    {
        if (!cmp_elems(cur->data, data))
            return cur;
        cur = cur->next;
    }
    if (!cmp_elems(cur->data, data))
        return cur;
    else
        return NULL;
}

int cmp_elems(elem_t a, elem_t b)
{
    if (a.row == b.row)
        return a.col - b.col;
    else
        return a.row - b.row;
}