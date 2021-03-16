#include <string.h>
#include "get_max_min.h"
#include "get_between_average.h"

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    FILE *f;
    char name[MAX_LEN + 1];
    size_t i;
    double max_n, min_n;
    int rc;
    if (argc == 1)
        return NO_NAME_ERR;
    for (i = 0; argv[argc - 1][i] != '\0'; i++)
        name[i] = argv[argc - 1][i];
    name[i] = '\0';
    if ((f = fopen(name, "r")) == NULL)
        return OPEN_ERR;
    if ((rc = get_max_min(f, &max_n, &min_n)) != EXIT_SUCCESS)
        return rc;
    rewind(f);
    printf("Result: %lf", get_between_average(f, &max_n, &min_n));
    fclose(f);
    return EXIT_SUCCESS;
}