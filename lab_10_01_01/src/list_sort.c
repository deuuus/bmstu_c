#include "list_sort.h"

size_t get_count(node_t *head);

void front_back_split(node_t *head, node_t **back)
{
    if (head && back && !(*back))
    {
        size_t n = get_count(head);
        n = n / 2 + n % 2;

        node_t *cur = head;
        if (n > 0)
            n--;
        for (size_t i = 0; i < n; i++)
            cur = cur->next;
        *back = cur->next;
        cur->next = NULL;
    }
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void*, const void*))
{
    if (!head_a || !head_b)
        return NULL;
    node_t *new_head = NULL;
    while (*head_a)
    {
        node_t *cur = create(pop_front(head_a));
        new_head = push_back(new_head, cur);
    }
    if (!new_head && *head_b)
        new_head = create(pop_front(head_b));
    while (*head_b)
    {
        node_t *to_insert = create(pop_front(head_b));
        if (comparator(to_insert->data, new_head->data) < 0)
        {
            node_t *buf = new_head;
            new_head = to_insert;
            new_head->next = buf;
        }
        else
        {
            node_t *cur = new_head;
            node_t *prev = cur;
            while (comparator(to_insert->data, cur->data) >= 0 && cur->next)
            {
                prev = cur;
                cur = cur->next;
            }
            if (comparator(to_insert->data, cur->data) >= 0)
                prev = cur;
            node_t *buf = prev->next;
            prev->next = to_insert;
            to_insert->next = buf;
        }
    }
    return new_head;
}

node_t *sort(node_t *head, int (*comparator)(const void*, const void*))
{
    if (head && head->next)
    {
        node_t *back = NULL;
        front_back_split(head, &back);
        head = sort(head, comparator);
        back = sort(back, comparator);
        return sorted_merge(&head, &back, comparator);
    }
    else
        return head;
}

size_t get_count(node_t *head)
{
    if (!head)
        return 0;
    size_t n = 1;
    node_t *cur = head;
    while (cur->next)
    {
        cur = cur->next;
        n++;
    }
    return n;
}