#include "unit_tests.h"
#include <string.h>

void test_my_strpbrk(void)
{
    char str[9][4] = { "ABC", "ABC", "ABC", "ABC", "ABC", "ABC", "", "ABC", "" };
    char key[9][4] = { "A", "C", "AB", "BA", "D", "DA", "ABC", "", "" };

    printf("TESTING MY_STRPBRK:...\n\n");

    for (size_t i = 0; i < 9; i++)
        my_strpbrk(str[i], key[i]) == strpbrk(str[i], key[i]) ? printf("OK\n") : printf("FAIL\n");
}

void test_my_strspn(void)
{
    char str[9][4] = { "ABC", "ABC", "ABC", "ABC", "ABC", "ABC", "", "ABC", "" };
    char key[9][4] = { "A", "AB", "BA", "CBA", "D", "DABC", "ABC", "", "" };

    printf("\nTESTING MY_STRSPN:...\n\n");  

    for (size_t i = 0; i < 9; i++)
        my_strspn(str[i], key[i]) == strspn(str[i], key[i]) ? printf("OK\n") : printf("FAIL\n");
}

void test_my_strcspn(void)
{
    char str[7][4] = { "ABC", "ABC", "ABC", "ABC", "", "ABC", "" };
    char key[7][4] = { "D", "DB", "A", "\0", "ABC", "", "" };

    printf("\nTESTING MY_STRCSPN:...\n\n");

    for (size_t i = 0; i < 7; i++)
        my_strcspn(str[i], key[i]) == strcspn(str[i], key[i]) ? printf("OK\n") : printf("FAIL\n");
}

void test_my_strchr(void)
{
    char str[7][6] = { "ABA", "ABC", "ABC", "ABC", "ABABA", "", "" };
    int symbol[7] = { 65, 67, 0, 68, 66, 0, 66 }; //A, C, \0, D, B, \0, B
    printf("\nTESTING MY_STRCHR:...\n\n"); 
    
    for (size_t i = 0; i < 7; i++)
        my_strchr(str[i], symbol[i]) == strchr(str[i], symbol[i]) ? printf("OK\n") : printf("FAIL\n");
}

void test_my_strrchr(void)
{
    char str[6][4] = { "ABC", "ABA", "ABA", "ABA", "", "" };
    int symbol[6] = { 65, 65, 66, 0, 0, 66 }; //A, A, B, \0, \0, B
    
    printf("\nTESTING MY_STRRCHR:...\n\n"); 

    for (size_t i = 0; i < 6; i++)
        my_strrchr(str[i], symbol[i]) == strrchr(str[i], symbol[i]) ? printf("OK\n") : printf("FAIL\n");
}