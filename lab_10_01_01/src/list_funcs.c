#include "list_funcs.h"

void append(node_t **head_a, node_t **head_b)
{
    if (head_a && head_b && *head_b)
    {
        node_t *cur = *head_a;
        if (cur)
            while (cur->next)
                cur = cur->next;
        else
        {
            *head_a = create(pop_front(head_b));
            cur = *head_a;
        }
        if (*head_b)
            for (; (*head_b); cur = cur->next)
                cur->next = create(pop_front(head_b));
    }
}

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*))
{
    if (head && *head)
    {
        node_t *cur = *head;
        while (cur->next)
        {
            if (!comparator(cur->data, (cur->next)->data))
            {
                node_t *buf = cur->next;
                cur->next = cur->next->next;
                free(buf);
            }
            else
                cur = cur->next;
        }
    }
}   