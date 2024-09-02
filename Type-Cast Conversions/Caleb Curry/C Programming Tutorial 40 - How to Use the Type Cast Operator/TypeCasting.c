#include <stdio.h>

int main()
{
	int slices = 17;
	int people = 2;
	/*2 ways to fix this:
	1) add .0 to a constant
	2) explict type casting*/
	
	double halfThePizza = (double) (slices /  people) ; // (double) -> unary
	
	printf("%f\n", halfThePizza);
	
	double c = 25/2 * 2 ;
	double d = 25/2 * 2.0; 
	
	printf("c: %f\n", c);
	printf("d: %f\n", d);

	return 0;
}