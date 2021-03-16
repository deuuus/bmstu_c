#include "node.h"
#include "list_funcs.h"

int main()
{
    char cmd[4];
    cmd[0] = '\0';
    if (!fgets(cmd, sizeof(cmd), stdin))
        return ERR_ARGS;
    if (cmd[strlen(cmd) - 1] == '\n')
        cmd[strlen(cmd) - 1] = '\0';
    if (strcmp(cmd, "out") && strcmp(cmd, "add") && strcmp(cmd, "mul") && strcmp(cmd, "lin"))
        return ERR_COMMAND;

    if (!strcmp(cmd, "out"))
    {
        int n, m;
        int rc;
        if ((rc = read_dimension(&n, &m)))
            return rc;
        node_t *head = NULL;
        if ((rc = read_matrix(n, m, &head)))
        {
            free_all(head);
            return rc;
        }
        print_all(head);
        free_all(head);
    }
    else if (!strcmp(cmd, "add"))
    {
        int n, m, p, q;
        int rc;
        if ((rc = read_dimension(&n, &m)))
            return rc;
        node_t *head_a = NULL;
        if ((rc = read_matrix(n, m, &head_a)))
        {
            free_all(head_a);
            return rc;
        }

        if ((rc = read_dimension(&p, &q)))
        {
            free_all(head_a);
            return rc;
        }
        node_t *head_b = NULL;
        if ((rc = read_matrix(p, q, &head_b)))
        {
            free_all(head_a);
            free_all(head_b);
            return rc;
        }
        head_a = add(head_a, head_b);
        print_all(head_a);
        free_all(head_a);
        free_all(head_b);
    }
    else if (!strcmp(cmd, "mul"))
    {
        int n, m, p, q;
        int rc;
        if ((rc = read_dimension(&n, &m)))
            return rc;
        node_t *head_a = NULL;
        if ((rc = read_matrix(n, m, &head_a)))
        {
            free_all(head_a);
            return rc;
        }

        if ((rc = read_dimension(&p, &q)))
        {
            free_all(head_a);
            return rc;
        }
        node_t *head_b = NULL;
        if ((rc = read_matrix(p, q, &head_b)))
        {
            free_all(head_a);
            free_all(head_b);
            return rc;
        }
        node_t *prod = mul(head_a, head_b);
        print_all(prod);
        free_all(prod);
        free_all(head_a);
        free_all(head_b);
    }
    else if (!strcmp(cmd, "lin"))
    {
        int n, m;
        int rc;
        if ((rc = read_dimension(&n, &m)))
            return rc;
        node_t *head = NULL;
        if ((rc = read_matrix(n, m, &head)))
        {
            free_all(head);
            return rc;
        }
        head = remove_line_with_max(head);
        print_all(head);
        free_all(head);
    }
    return EXIT_SUCCESS;
}