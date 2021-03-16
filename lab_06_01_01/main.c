#include "utilities.h"

#define MAX_COUNT      15
#define NOT_ENOUGH_DATA 1
#define TOO_MUCH_DATA   2
#define OPEN_ERROR      3
#define NO_DATA         4
#define KEY_ERROR       5

int main(int argc, char *argv[])
{
    if (argc < 3)
        return NOT_ENOUGH_DATA;
    else if (argc > 4)
        return TOO_MUCH_DATA;
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        return OPEN_ERROR;
    if (strcmp("title", argv[2]) && strcmp("name", argv[2]) && strcmp("year", argv[2]))
        return KEY_ERROR;
    movie movies[MAX_COUNT];
    size_t count = 0;
    while (count < 15 && read(f, movies, &count) == EXIT_SUCCESS)
        insert(movies, count, argv[2]);
    if (feof(f) == 0)
    {
        fclose(f);
        return NOT_ENOUGH_DATA;
    }
    else if (count == 0)
    {
        fclose(f);
        return NO_DATA;
    }
    if (argc == 3)
        for (size_t i = 0; i < count; i++)
            print(movies[i]);
    else
    {   
        int rc = binary_search(movies, count, argv[2], argv[3]);
        if (rc != EXIT_SUCCESS)
        {
            fclose(f);
            return rc;
        }
    }
    fclose(f);
    return EXIT_SUCCESS;
}
