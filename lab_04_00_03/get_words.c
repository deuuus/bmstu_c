#include "get_words.h"

long get_words(char str[], char words_array[][NMAX], size_t *words)
{
    int temp = 0;
    char temp_string[NMAX];
    char split[8] = ",;:-.!?";
    size_t len = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (len > MAX_LEN)
        {
            printf("WORD IS TOO LONG");
            return WORD_LEN_ERR;
        }
        temp = str[i];
        if ((strchr(split, temp) != NULL || temp == 32) && len != 0)
        {
            temp_string[len] = '\0';
            strcpy(words_array[*words], temp_string);
            *words = *words + 1;
            len = 0;
        }
        if (temp != 32 && strchr(split, temp) == NULL)
        {
            temp_string[len] = temp;
            len++;
        }
    }
    if (strchr(split, temp) == NULL && temp != 32 && len != 0)
    {   
        temp_string[len] = '\0';
        strcpy(words_array[*words], temp_string);
        *words = *words + 1;
    }
    return EXIT_SUCCESS;
}
