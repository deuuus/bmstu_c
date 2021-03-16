#define __USE_MINGW_ANSI_STDIO 1
#include "utilities.h"

int read(FILE *f, movie *movies, size_t *count)
{
    movie to_read;
    char ch;
    if (!fgets(to_read.title, sizeof(to_read.title), f))
        return READ_ERROR;
    if (to_read.title[strlen(to_read.title) - 1] == '\n')
        to_read.title[strlen(to_read.title) - 1] = '\0';
    else if (fscanf(f, "%c", &ch) == EOF || ch != '\n')
        return VALUE_ERROR;
    if (strlen(to_read.title) == 0)
        return VALUE_ERROR;
    if (!fgets(to_read.name, sizeof(to_read.name), f))
        return READ_ERROR;
    if (to_read.name[strlen(to_read.name) - 1] == '\n')
        to_read.name[strlen(to_read.name) - 1] = '\0';
    else if (fscanf(f, "%c", &ch) == EOF || ch != '\n')
        return VALUE_ERROR;
    if (strlen(to_read.name) == 0)
        return VALUE_ERROR; 
    if (fscanf(f, "%ld", &to_read.year) != 1)
        return READ_ERROR;
    if (to_read.year <= 0)
        return VALUE_ERROR;
    if (fscanf(f, "%c", &ch) != EOF && ch != '\n')
         return READ_ERROR;
    movies[(*count)++] = to_read;
    return EXIT_SUCCESS;
}

int insert(movie *movies, size_t count, const char *attribute)
{
    movie to_sort = movies[count - 1];
    size_t i = 0;
    if (!strcmp("year", attribute))
        while (i != (count - 1) && to_sort.year >= movies[i].year)
            i++;
    else if (!strcmp("title", attribute))
        while (i != (count - 1) && strcmp(to_sort.title, movies[i].title) >= 0)
            i++;
    else
        while (i != (count - 1) && strcmp(to_sort.name, movies[i].name) >= 0)
            i++;
    for (size_t j = count - 1; j > i; j--)
        movies[j] = movies[j - 1];
    movies[i] = to_sort;
    return EXIT_SUCCESS;
}

void print(movie to_print)
{
    printf("%s\n%s\n%ld\n", to_print.title, to_print.name, to_print.year);
}

int binary_search(movie *movies, size_t count, const char *attribute, char *key)
{
    size_t left = 0, right = count - 1, mid = 0;
    long value = 0;
    if (!strcmp("year", attribute))
    {
        char *endptr;
        value = strtol(key, &endptr, 10);
        if (strlen(endptr) != 0 || value <= 0)
            return VALUE_ERROR;
    }
    int flag = 0;
    while (left < right && !flag)
    {
        mid = (left + right) / 2;
        if (!strcmp("title", attribute))
        {
            if (strcmp(movies[mid].title, key) == 0)
                flag = 1;
            else if (strcmp(movies[mid].title, key) > 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
        else if (!strcmp("name", attribute))
        {
            if (strcmp(movies[mid].name, key) == 0)
                flag = 1;
            else if (strcmp(movies[mid].name, key) > 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
        else if (movies[mid].year == value)
            flag = 1;
        else if (movies[mid].year > value)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (flag == 1)
        print(movies[mid]);
    else if (!strcmp("title", attribute) && strcmp(movies[left].title, key) == 0)
        print(movies[left]);
    else if (!strcmp("name", attribute) && strcmp(movies[left].name, key) == 0)
        print(movies[left]);
    else if (!strcmp("year", attribute) && movies[left].year == value)
        print(movies[left]);
    else
        printf("Not found");
    return EXIT_SUCCESS;
}
