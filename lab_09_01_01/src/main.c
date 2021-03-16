#include "movie.h"

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4)
        return ARGS_ERR;
    
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        return FILE_ERR;
    if (strcmp("title", argv[2]) && strcmp("name", argv[2]) && strcmp("year", argv[2]))
        return ATTRIBUTE_ERR;
    
    int count = 0;
    int rc = EXIT_SUCCESS;
    if ((rc = get_count(f, &count)))
    {
        fclose(f);
        return rc;
    }

    movie *movies = calloc(count, sizeof(movie));
    if (!movies)
    {
        fclose(f);
        return ALLOCATE_ERR;
    }
    
    if ((rc = read_all(f, &movies, count, argv[2])))
        return rc;
    
    if (argc == 3)
        print_all(movies, count);
    else
        rc = binary_search(movies, count, argv[2], argv[3]);
    
    free_all(&movies, count);
    fclose(f);
    return rc;
}
