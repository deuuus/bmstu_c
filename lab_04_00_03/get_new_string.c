#include "get_new_string.h"

void del_eql_first(char string[])
{
    char symbol = string[0];
    size_t i, j;
    size_t n = 0;
    for (i = 0; string[i] != '\0'; i++)
        n++;
    n--;
    for (i = 1; string[i] != '\0'; i++)
    {
        while (string[i] == symbol)
        {
            for (j = i + 1; string[j] != '\0'; j++)
                string[j - 1] = string[j];
            string[n--] = '\0';  
        }
    }
}

long get_new_string(char array[][NMAX], char string[], size_t *n)
{
    char last[MAX_LEN + 1];
    size_t i = 0, j;
    size_t count = 0;
    for (i = 0; array[*n - 1][i] != '\0'; i++)
        last[i] = array[*n - 1][i];
    last[i] = '\0';
    for (i = *n - 1; i > 0; i--)
    {
        if (strcmp(last, array[i]) != 0)
        {
            del_eql_first(array[i]);
            for (j = 0; array[i][j] != '\0'; j++)
                string[count++] = array[i][j];
            string[count++] = ' ';
        }
    }
    if (strcmp(last, array[0]) != 0)
    {
        del_eql_first(array[0]);
        for (j = 0; array[0][j] != '\0'; j++)
            string[count++] = array[0][j];
        string[count] = '\0';
    }
    string[count] = '\0';
    if (string[0] == '\0')
    {
        printf("GOT EMPTY STRING");
        return GOT_EMPTY_STRING;
    }
    return EXIT_SUCCESS;
}