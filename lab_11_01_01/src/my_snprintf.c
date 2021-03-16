#include "my_snprintf.h"

size_t len(long long num)
{
    size_t len = 1;
    num = llabs(num);
    if (num < 0)
        num = LONG_MAX - 1;
    while (num >= 10)
    {
        len++;
        num /= 10;
    }
    return len;
}

void convert(long long num, char buf[])
{
    char digits[] = "0123456789";
    size_t n = len(num);
    int i = 0;
    if (num < 0)
        buf[i++] = '-';
    n--;
    size_t pow = 1;
    while (n)
    {
        pow *= 10;
        n--;
    }
    num = llabs(num);
    while (pow >= 1)
    {
        buf[i++] = digits[num / pow];
        num %= pow;
        pow /= 10;
    }
    buf[i] = '\0';
}

int my_snprintf(char *str, size_t size, const char *format, ...)
{
    va_list vl;
    va_start(vl, format);
    size_t cur_size = 0;
    char buf[BUF_SIZE];
    while (*format)
    {
        if (*format != '%')
        {
            if (str && cur_size < size)
                str[cur_size] = *format;
            cur_size++;
            format++;
        }
        else
        {
            format++;
            if (*format == 'c')
            {
                char c = va_arg(vl, int);
                if (str && cur_size < size)
                    str[cur_size] = c;
                cur_size++;
                format++;
            }
            else if (*format == 'd')
            {
                int d = va_arg(vl, int);
                convert(d, buf);
                for (char *cur = buf; *cur; cur++)
                {
                    if (str && cur_size < size)
                        str[cur_size] = *cur;
                    cur_size++;
                }
                format++;
            }
            else if (*format == 'l')
            {
                long d = va_arg(vl, long int);
                convert(d, buf);
                for (char *cur = buf; *cur; cur++)
                {
                    if (str && cur_size < size)
                        str[cur_size] = *cur;
                    cur_size++;
                }
                format += 2;
            }
            else if (*format == 'h')
            {
                short d = va_arg(vl, int);
                convert(d, buf);
                for (char *cur = buf; *cur; cur++)
                {
                    if (str && cur_size < size)
                        str[cur_size] = *cur;
                    cur_size++;
                }
                format += 2;
            }
            else
            {
                char *s = va_arg(vl, char*);
                for (char *cur = s; *cur; cur++)
                {
                    if (str && cur_size < size)
                        str[cur_size] = *cur;
                    cur_size++;
                }
                format++;
            }
        }
    }
    va_end(vl);
    if (str && size)
    {
        if (cur_size < size)
            str[cur_size] = '\0';
        else
            str[size - 1] = '\0';
    }
    return cur_size;
}
