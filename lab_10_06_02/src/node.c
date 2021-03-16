#include "node.h"

int read_dimension(int *a, int *b)
{
    if (scanf("%d", a) != 1 || scanf("%d", b) != 1)
        return ERR_READ;
    if (*a <= 0 || *b <= 0)
        return ERR_DIM;
    return EXIT_SUCCESS;
}

int read_matrix(int n, int m, node_t **head)
{
    if (!head)
        return ERR_PTR;
    if (*head)
        free_all(*head);
    *head = NULL;
    int item;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%d", &item) != 1)
                return ERR_READ;
            else if (item != 0)
            {
                node_t *new = create(item, i, j);
                if (new)
                    *head = push_back(*head, new);
                else
                    return ERR_ALLOCATE;
            }
    return EXIT_SUCCESS;
}

node_t *create(int item, int row, int col)
{
    node_t *new = malloc(sizeof(node_t));
    if (new)
    {
        elem_t elem;
        elem.item = item;
        elem.row = row;
        elem.col = col;
        new->data = elem;
        new->next = NULL;
    }
    return new;
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

void print_all(node_t *head)
{
    if (head)
    {
        node_t *cur = head;
        while (cur->next)
        {
            print_one(cur);
            printf(" ");
            cur = cur->next;
        }   
        print_one(cur);
    }
}

void print_one(node_t *node)
{
    printf("%d %d %d", node->data.row, node->data.col, node->data.item); 
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

void free_one(node_t *to_free)
{
    free(to_free);
}