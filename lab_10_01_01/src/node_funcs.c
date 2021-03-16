#include "node_funcs.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*))
{
    if (!head)
        return NULL;
    node_t *cur = head;
    for (; cur; cur = cur->next)
        if (!comparator(cur->data, data))
            return cur;
    return NULL;
}

void *pop_front(node_t **head)
{
    if (!head || !(*head))
        return NULL;
    node_t *buf = *head;
    void *data = buf->data;
    *head = (*head)->next;
    free(buf);
    return data;
}

int cmp_people(const void *a, const void *b)
{
    person_t *first = (person_t*)((node_t*)a);
    person_t *second = (person_t*)((node_t*)b);
    if (first->born_year == second->born_year)
        return strcmp(first->surname, second->surname);
    else
        return first->born_year - second->born_year;
}