#include "node.h"

node_t *create(person_t *data)
{
    node_t *new = malloc(sizeof(node_t));
    if (new)
    {
        new->data = data;
        new->next = NULL;
    }
    return new;
}

int init(person_t people[], int num, node_t **head)
{
    if (!head)
        return ERR_PTR;
    if (*head)
        free_all(*head);
    *head = NULL;
    for (int i = 0; i < num; i++)
    {
        node_t *new = create(&people[i]);
        if (new)
            *head = push_back(*head, new);
        else
        {
            free_all(*head);
            return ERR_ALLOCATE;
        }
    }
    return EXIT_SUCCESS;
}

void free_all(node_t *head)
{
    node_t *next;
    for (; head; head = next)
    {
        next = head->next;
        free_one(head);
    }
}

void print_all(node_t *head)
{
    if (!head)
        printf("List is empty.\n");
    else
    {
        node_t *cur = head;
        while (cur->next)
        {
            print_one(cur);
            cur = cur->next;
        }   
        print_one(cur);    
    }
}

int write_all(FILE *f, node_t *head)
{
    int rc = EXIT_SUCCESS;
    for (; head; head = head->next)
        if ((rc = write_one(f, head)))
            return rc;
    return rc;
}

void print_one(node_t *node)
{
    printf("Born year: %d\nSurname: %s\n\n", ((person_t*)(node->data))->born_year, ((person_t*)(node->data))->surname); 
}

void free_one(node_t *to_free)
{
    free(to_free);
}

int write_one(FILE *f, node_t *to_write)
{
    return (fprintf(f, "%d%s\n", ((person_t*)(to_write->data))->born_year, ((person_t*)(to_write->data))->surname) == 2);
}

node_t *push_back(node_t *head, node_t *to_push)
{
    if (!head)
        return to_push;
    node_t *cur = head;
    while (cur->next)
        cur = cur->next;
    cur->next = to_push;
    return head;
}