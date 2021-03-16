#include "get_words.h"
#include "get_new_string.h"

int main(void)
{
    char str[NMAX];
    char new_str[2 * NMAX];
    char words[NMAX][NMAX];
    char ch;
    size_t i = 0;
    size_t n = 0;
    while ((ch = getchar()) != '\n' && ch != EOF && i < (NMAX - 1))
        str[i++] = ch;
    if (i == 0)
    {
        printf("EMPTY STRING");
        return INPUT1_ERR;
    }
    if (ch != '\n' && ch != EOF)
    {
        printf("STRING IS TOO LONG");
        return INPUT1_ERR;
    }
    str[i] = '\0';
    if (get_words(str, words, &n) == WORD_LEN_ERR)
        return WORD_LEN_ERR;
    if (n == 0)
    {   
        printf("THERE ARE NO WORDS");
        return OUTPUT_ERROR;
    }
    new_str[0] = '\0';
    if (get_new_string(words, new_str, &n) == GOT_EMPTY_STRING)
        return GOT_EMPTY_STRING;
    printf("Result: %s\n", new_str);
    return EXIT_SUCCESS;
}