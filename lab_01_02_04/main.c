#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setbuf(stdout, NULL);
    long n;
    long h, m, s;
    printf("Enter seconds: \n");
    scanf("%ld", &n);
    h = n / 3600;
    m = (n % 3600) / 60;
    s = n % 60;
    printf("Result:\n%ld %ld %ld", h, m, s); 
    return EXIT_SUCCESS;
}