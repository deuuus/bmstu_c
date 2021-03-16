#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) 
{
	setbuf(stdout, NULL);
	double x1, y1;
	double x2, y2;
	double x3, y3;
	double side1, side2, side3;
	double perimetr;
	printf("Enter coordinates: \n");
	scanf("%lf", &x1);
	scanf("%lf", &y1);
	scanf("%lf", &x2);
	scanf("%lf", &y2);
	scanf("%lf", &x3);
	scanf("%lf", &y3);
	side1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	side2 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	side3 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	perimetr = side1 + side2 + side3;
	printf("Perimetr: \n");
	printf("%.5lf", perimetr);
	return EXIT_SUCCESS;
}