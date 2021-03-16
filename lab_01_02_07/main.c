#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_sum(double x, long n, double eps)
{
    double s = x;
    double temp = x;
    while (fabs(temp) >= eps) 
    {
        temp *= x * x * n * n / (n + 1) / (n + 2); 
        n += 2;
        s += temp;
    }
    return s;
}

int main(void)
{
    setbuf(stdout, NULL);
    double x;
    double eps;
    long n = 1;
    double s;
    double fx;
    double absolute, relative;
    printf("Enter x and eps: \n");
    if (scanf("%lf", &x) != 1 || scanf("%lf", &eps) != 1 || eps <= 0 || eps >= 1 || fabs(x) >= 1)
    {
        printf("Error.");
        return EXIT_FAILURE;
    }
    s = calculate_sum(x, n, eps);
    fx = asin(x);
    absolute = fabs(fx - s);
    if (fabs(fx) <= eps)
        relative = 0;
    else
        relative = fabs((fx - s) / fx);        
    printf("Results: \n");
    printf("%.6lf \n", s);
    printf("%.6lf \n", fx);
    printf("%.6lf \n", absolute);
    printf("%.6lf \n", relative);
    return EXIT_SUCCESS;
}