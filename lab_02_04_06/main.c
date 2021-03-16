#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

#define N 100L 
#define NMAX 20000L

long input(long *a_begin, long *a_end)
{
    while (a_begin <= a_end)
    {
        if (scanf("%ld", a_begin) != 1)
            return EXIT_FAILURE;
        a_begin++;
    }
    return EXIT_SUCCESS;
}

long selection_sort_1(long a[], size_t n)
{
    size_t min_index;
    long buf;
    for (size_t i = 1; i < n - 1; i++)
    {
        min_index = i;
        for (size_t j = i + 1; j < n; j++)
            if (a[j] < a[min_index])
                min_index = j;
        buf = a[min_index];
        a[min_index] = a[i];
        a[i] = buf;
    }
    return EXIT_SUCCESS;
}

long selection_sort_2(long a[], size_t n)
{
    size_t min_index;
    long buf;
    for (size_t i = 1; i < n - 1; i++)
    {
        min_index = i;
        for (size_t j = i + 1; j < n; j++)
            if (*(a + j) < *(a + min_index))
                min_index = j;
        buf = *(a + min_index);
        *(a + min_index) = *(a + i);
        *(a + i) = buf;
    }
    return EXIT_SUCCESS;
}

long selection_sort_3(long *a_begin, long *a_end)
{
    long *min_index;
    long buf;
    long *temp;
    while (a_begin < a_end)
    {
        min_index = a_begin;
        temp = a_begin + 1;
        while (temp <= a_end)
        {
            if (*temp < *min_index)
                min_index = temp;
            temp++;
        }
        buf = *a_begin;
        *a_begin = *min_index;
        *min_index = buf;
        a_begin++;
    }
    return EXIT_SUCCESS;
}

long various_1(long a[], size_t n)
{
    selection_sort_1(a, n);
    long k = 1;
    for (size_t i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            k++;
    return k;
}

long various_2(long a[], size_t n)
{
    selection_sort_2(a, n);
    long k = 1;
    for (size_t i = 1; i < n; i++)
        if (*(a + i) != *(a + i - 1))
            k++;
    return k;
}

long various_3(long *a_begin, long *a_end)
{
    selection_sort_3(a_begin, a_end);
    long k = 1;
    a_begin++;
    while (a_begin <= a_end)
    {
        if (*a_begin != *(a_begin - 1))
            k++;
        a_begin++;
    }
    return k;
}

int main(void)
{
    setbuf(stdout, NULL);
    size_t n;
    long time1 = 0, time2 = 0, time3 = 0;
    struct timeval tv_start, tv_stop;
    long elapsed_time;

    if (scanf("%zu", &n) != 1 || n <= 0)
        return EXIT_FAILURE;

    long a[NMAX];
    if (input(a, a + n - 1) == EXIT_FAILURE)
        return EXIT_FAILURE;

    printf("|--------------|------------------|--------------|--------------|-------------|\n");
    printf("|  Повторы(N)  |  Размер массива  |     a[i]     |   *(a + i)   |  Указатели  |\n");
    printf("|--------------|------------------|--------------|--------------|-------------|\n");
    for (long i = 0; i < N; i++)
    {
        gettimeofday(&tv_start, NULL);
        various_1(a, n);
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000L + (tv_stop.tv_usec - tv_start.tv_usec);
        time1 += elapsed_time;
        gettimeofday(&tv_start, NULL);
        various_2(a, n);
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000L + (tv_stop.tv_usec - tv_start.tv_usec);
        time2 += elapsed_time;
        gettimeofday(&tv_start, NULL);
        various_3(a, a + n - 1);
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000L + (tv_stop.tv_usec - tv_start.tv_usec);
        time3 += elapsed_time;
    }
    time1 /= N;
    time2 /= N;
    time3 /= N;
    printf("|%14ld|%18zu|%14ld|%14ld|%13ld|\n", N, n, time1, time2, time3);
    printf("|--------------|------------------|--------------|--------------|-------------|\n");
    return EXIT_SUCCESS;
}