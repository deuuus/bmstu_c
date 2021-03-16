#include "my_string.h"

//проверяет вхождение любого символа из множетсва key в str
char *my_strpbrk(const char *str, const char *key)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        for (size_t j = 0; key[j] != '\0'; j++)
            if (key[j] == str[i])
                return (char*)&str[i];
    return NULL;
}

//Максимальная длина начального участка строки str, содержащего только символы key
size_t my_strspn(const char *str, const char *key)
{
    size_t k, i = 0, j;
    for (i = 0; str[i] != '\0'; i++)
    {
        k = 0;
        for (j = 0; key[j] != '\0'; j++)
            if (str[i] == key[j])
                k++;
        if (k == 0)
            return i;
    }
    return i;
}

//Максимальная длина начального участка строки str, не содержащего только символы key
size_t my_strcspn(const char *str, const char *key)
{
    size_t k, i = 0, j;
    for (i = 0; str[i] != '\0'; i++)
    {
        k = 0;
        for (j = 0; key[j] != '\0'; j++)
            if (str[i] == key[j])
                k++;
        if (k != 0)
            return i;
    }
    return i;
}

//поиск первого вхождения символа symbol в строку str
char *my_strchr(const char *str, int symbol)
{
    size_t i = 0;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == symbol)
            return (char*)&str[i];
    if (symbol == 0)
        return (char*)&str[i];
    return NULL;
}

//поиск последнего вхождения символа symbol в строку str
char *my_strrchr(const char *str, int symbol)
{
    size_t i, n = 0;
    for (i = 0; str[i] != '\0'; i++)
        n++;
    if (symbol == 0)
    {
        return (char*)&str[n];
    }
    for (i = n; i != 0; i--)
        if (str[i] == symbol)
            return (char*)&str[i];
    if (str[0] == symbol)
        return (char*)&str[0];
    return NULL;
}