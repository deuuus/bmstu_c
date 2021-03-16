#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	setbuf(stdout, NULL);
	double r1, r2, r3;
	double r;
	printf("Enter resistances: \n");
	scanf("%lf", &r1);
	scanf("%lf", &r2);
	scanf("%lf", &r3);
	r = r1 * r2 * r3 / (r1 * r2 + r2 * r3 + r3 * r1);
	printf("Total resistance: \n");
	printf("%.5lf", r);
	return EXIT_SUCCESS;
}