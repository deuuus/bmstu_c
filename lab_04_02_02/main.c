#include "get_words.h"
#include "check_pair.h"

int main(void)
{
    char str1[NMAX];
    char str2[NMAX];
    char words1[NMAX][NMAX];
    char words2[NMAX][NMAX];
    char ch;
    size_t i = 0;
    size_t n1 = 0, n2 = 0;
    while ((ch = getchar()) != '\n' && ch != EOF && i < (NMAX - 1))
        str1[i++] = ch;
    if (ch != '\n')
    {
        printf("STRING IS TOO LONG");
        return INPUT1_ERR;
    }
    if (ch == EOF)
    {
        printf("ONLY ONE STRING");
        return NOT_ENOUGH;
    }
    str1[i] = '\0';
    if (i == 0)
    {
        printf("EMPTY STRING");
        return INPUT1_ERR;
    }
    i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF && i < (NMAX - 1))
        str2[i++] = ch;
    if (ch != '\n' && ch != EOF)
    {
        printf("STRING IS TOO LONG");
        return INPUT2_ERR;
    }
    str2[i] = '\0';
    if (i == 0)
    {
        printf("EMPTY STRING");
        return INPUT2_ERR;
    }
    if (get_words(str1, words1, &n1) == WORD_LEN_ERR)
        return WORD_LEN_ERR;
    if (get_words(str2, words2, &n2) == WORD_LEN_ERR)
        return WORD_LEN_ERR;
    if (n1 == 0 || n2 == 0)
        return OUTPUT_ERROR;
    check_pair(words1, words2, &n1, &n2);
    return EXIT_SUCCESS;
}