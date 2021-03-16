#include "movie.h"

int read_one(FILE *f, movie *to_read)
{
    if (!f)
        return FILE_ERR;

    if (feof(f) != 0)
        return NO_DATA_ERR;
    
    char ch;

    to_read->title = malloc(INIT_LEN * sizeof(char));
    if (!to_read->title)
        return ALLOCATE_ERR;
    to_read->name = malloc(INIT_LEN * sizeof(char));
    if (!to_read->name)
    {
        free(to_read->title);
        return ALLOCATE_ERR;
    }

    if (my_getline(&to_read->title, f))
    {
        free(to_read->name);
        return LINE_ERR;
    }
    if (feof(f))
    {
        free_one(to_read);
        return NOT_ENOUGH_DATA_ERR;
    }

    if (my_getline(&to_read->name, f))
    {
        free(to_read->title);
        return LINE_ERR;
    }

    if (feof(f))
    {
        free_one(to_read);
        return NOT_ENOUGH_DATA_ERR;
    }
    
    if (fscanf(f, "%ld", &to_read->year) != 1)
    {
        free_one(to_read);
        return READ_ERR;
    }
    if (to_read->year <= 0)
    {
        free_one(to_read);
        return INTEGER_ERR;
    }
    if (fscanf(f, "%c", &ch) != EOF && ch != '\n')
    {
        free_one(to_read);
        return READ_ERR;
    }
    return EXIT_SUCCESS;
}

int read_all(FILE *f, movie **movies, int count, const char *attribute)
{ 
    int i = 0;
    int rc;
    int (*p)(movie, movie) = cmp_year;
    if (!strcmp(attribute, "title"))
        p = cmp_title;
    if (!strcmp(attribute, "name"))
        p = cmp_name;    
    while (i < count && !read_one(f, *movies + i))
    {
        i++;
        if ((rc = insert(movies, i, p)))
        {
            free_all(movies, i);
            fclose(f);
            return rc;
        }
    }
    if (i != count)
    {
        free_all(movies, i);
        fclose(f);
        return READ_ERR;
    }
    return EXIT_SUCCESS;
}

int insert(movie **movies, size_t count, int (*cmp)(movie, movie))
{
    int rc;
    movie to_sort = { NULL, NULL, 0 };
    if ((rc = replace(&to_sort, (*movies)[count - 1].title, (*movies)[count - 1].name, (*movies)[count - 1].year)))
        return rc;
    size_t i = 0;
    while (i != (count - 1) && cmp(to_sort, (*movies)[i]) >= 0)
        i++;
    for (size_t j = count - 1; j > i; j--)
        if ((rc = replace(&((*movies)[j]), (*movies)[j - 1].title, (*movies)[j - 1].name, (*movies)[j - 1].year)))
            return rc;
    if ((rc = replace(&((*movies)[i]), to_sort.title, to_sort.name, to_sort.year)))
        return rc;
    free_one(&to_sort);
    return EXIT_SUCCESS;
}

int binary_search(movie *movies, size_t count, const char *attribute, char *key)
{
    size_t left = 0, right = count - 1, mid = 0;
    if (!strcmp("year", attribute) && is_pos_num(key))
        return KEY_ERR;
    int flag = 0;
    int (*cmpr)(movie, char*) = cmp_title_str;
    if (!strcmp(attribute, "name"))
        cmpr = cmp_name_str;
    if (!strcmp(attribute, "year"))
        cmpr = cmp_year_str;
    while (left < right && !flag)
    {
        mid = (left + right) / 2;
        if (cmpr(movies[mid], key) == 0)
            flag = 1;
        else if (cmpr(movies[mid], key) > 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (flag == 1)
        print_one(movies[mid]);
    else if (!cmpr(movies[left], key))
        print_one(movies[left]);
    else
        printf("Not found");
    return EXIT_SUCCESS;
}

void print_all(movie *to_print, int count)
{
    for (int i = 0; i < count; i++)
        print_one(to_print[i]);
}

void print_one(movie to_print)
{
    printf("%s\n%s\n%ld\n", to_print.title, to_print.name, to_print.year);
}

void free_all(movie **movies, int count)
{
    for (int i = 0; i < count; i++)
    {
        free((*movies)[i].title);
        free((*movies)[i].name);
    }
    free(*movies);
}

void free_one(movie *to_free)
{
    free(to_free->title);
    free(to_free->name);
}

int replace(movie *dst, char *title, char *name, int year)
{
    if (dst->title != NULL)
    {
        free_one(dst);
    }
    dst->title = malloc(strlen(title) + 1);
    if (!dst->title)
        return ALLOCATE_ERR;
    dst->name = malloc(strlen(name) + 1);
    if (!dst->name)
    {
        free(dst->title);
        return ALLOCATE_ERR;
    }
    strcpy(dst->title, title);
    strcpy(dst->name, name);
    dst->year = year;
    return EXIT_SUCCESS;
}

int get_count(FILE *f, int *count)
{
    if (!f)
        return FILE_ERR;
    int rc;
    *count = 0;
    movie to_read;
    while (!(rc = read_one(f, &to_read)))
    {
        free_one(&to_read);
        *count += 1;
    }
    if (feof(f) == 0)
        return NOT_ENOUGH_DATA_ERR;
    if (*count == 0)
        return NO_DATA_ERR;
    rewind(f);
    return EXIT_SUCCESS;
}

int my_getline(char **lineptr, FILE *stream)
{
    if (!lineptr)
        return ALLOCATE_ERR;
    if (!stream)
    {
        free(*lineptr);
        return FILE_ERR;
    }
    int i = 0, tmp_len = INIT_LEN;
    char ch = fgetc(stream);
    char *tmp_line = malloc(tmp_len * sizeof(char));
    if (!tmp_line)
    {
        free(*lineptr);
        return ALLOCATE_ERR;
    }
    while (ch != '\n' && ch != EOF)
    {
        if (i >= tmp_len)
        {
            tmp_len *= 2;
            char *buf = realloc(tmp_line, tmp_len);
            if (!buf)
            {
                free(tmp_line);
                free(*lineptr);
                return REALLOCATE_ERR;
            }
            tmp_line = buf;
        }
        tmp_line[i++] = ch;
        ch = fgetc(stream);
    }
    if (i >= tmp_len)
    {
        tmp_len *= 2;
        char *buf = realloc(tmp_line, tmp_len);
        if (!buf)
        {
            free(tmp_line);
            free(*lineptr);
            return REALLOCATE_ERR;
        }
        tmp_line = buf;
    }
    if (i == 0)
    {
        free(*lineptr);
        free(tmp_line);
        return NO_DATA_ERR;
    }
    tmp_line[i++] = '\0';
    char *buf = realloc(*lineptr, i * sizeof(char));
    if (!buf)
    {
        free(tmp_line);
        free(*lineptr);
        return REALLOCATE_ERR;
    }
    *lineptr = buf;
    memmove(*lineptr, tmp_line, i * sizeof(char));
    free(tmp_line);
    return EXIT_SUCCESS;
}

int is_pos_num(char *str)
{
    long value = 0;
    char *endptr;
    value = strtol(str, &endptr, 10);
    if (strlen(endptr) != 0 || value <= 0)
        return KEY_ERR;
    return EXIT_SUCCESS;
}

int cmp_year(movie a, movie b)
{
    return a.year - b.year;
}

int cmp_title(movie a, movie b)
{
    return strcmp(a.title, b.title);
}

int cmp_name(movie a, movie b)
{
    return strcmp(a.name, b.name);
}

int cmp_year_str(movie a, char *str)
{
    return a.year - atoi(str);
}

int cmp_title_str(movie a, char *str)
{
    return strcmp(a.title, str);
}

int cmp_name_str(movie a, char *str)
{
    return strcmp(a.name, str);
}