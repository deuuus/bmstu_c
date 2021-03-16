#include "node.h"
#include "node_funcs.h"
#include "list_funcs.h"
#include "list_sort.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
        return ERR_ARGS;
    FILE *f_in, *f_out;
    f_in = fopen(argv[1], "r");
    f_out = fopen(argv[2], "w");
    if (!f_out || !f_in)
        return ERR_FOPEN;
    int rc;
    int num;


    person_t people[MAX_SIZE];
    if ((rc = read_all(f_in, people, &num)))
        return rc;
    
    node_t *head = NULL;
    init(people, num, &head);
    node_t *new = sort(head, cmp_people);
    remove_duplicates(&new, cmp_people);

    if ((rc = write_all(f_out, new)))
        return rc;

    free_all(new);
    fclose(f_out);
    fclose(f_in);
    return EXIT_SUCCESS;
}