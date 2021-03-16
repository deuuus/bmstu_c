#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-6

double length(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double square(double side1, double side2, double side3)
{
    double half_p = (side1 + side2 + side3) / 2;
    return sqrt(half_p * (half_p - side1) * (half_p - side2) * (half_p - side3));
}

long orientation(double xa, double ya, double xb, double yb, double xt, double yt)
{
    double res = (xb - xa) * (yt - ya) - (yb - ya) * (xt - xa);
    if (res >= EPS)
        return 1;
    if (fabs(res) < EPS)
        return 0;
    if (res <= -EPS)
        return -1;
    return EXIT_SUCCESS;
}

int main(void)
{
    setbuf(stdout, NULL);
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double xa, ya;
    double side1, side2, side3;
    long ans = 2;
    long res1, res2, res3;
    printf("Enter coordinates: \n");
    if (scanf("%lf", &x1) != 1 || scanf("%lf", &y1) != 1)
        return EXIT_FAILURE;
    if (scanf("%lf", &x2) != 1 || scanf("%lf", &y2) != 1)
        return EXIT_FAILURE;
    if (scanf("%lf", &x3) != 1 || scanf("%lf", &y3) != 1)
        return EXIT_FAILURE;
    if (scanf("%lf", &xa) != 1 || scanf("%lf", &ya) != 1) 
        return EXIT_FAILURE;

    side1 = length(x1, y1, x2, y2);
    side2 = length(x1, y1, x3, y3);
    side3 = length(x3, y3, x2, y2);

    if (fabs(side1) < EPS || fabs(side2) < EPS || fabs(side3) < EPS)
        return EXIT_FAILURE;
    if (fabs(square(side1, side2, side3)) < EPS)
        return EXIT_FAILURE;

    res1 = orientation(x1, y1, x2, y2, xa, ya);
    res2 = orientation(x2, y2, x3, y3, xa, ya);
    res3 = orientation(x3, y3, x1, y1, xa, ya);

    if (res1 == 0 && res2 != 0 && res3 != 0)
        ans = 1;
    if (res1 != 0 && res2 == 0 && res3 != 0)
        ans = 1;
    if (res1 != 0 && res2 != 0 && res3 == 0)
        ans = 1;
    if (res1 != 0 && res2 != 0 && res3 != 0 && res1 == res2 && res2 == res3)
        ans = 0;
    if ((fabs(xa - x1)) < EPS && (fabs(ya - y1)) <= EPS)
        ans = 1;
    if ((fabs(xa - x2)) < EPS && (fabs(ya - y2)) < EPS) 
        ans = 1;
    if ((fabs(xa - x3)) < EPS && (fabs(ya - y3)) < EPS) 
        ans = 1;
        
    printf("zero - in, one - on the border, two - outside \n");
    printf("%ld", ans);
    return EXIT_SUCCESS;
}