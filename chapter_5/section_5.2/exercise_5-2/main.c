#include <stdio.h>

#define SIZE 100

int main()
{
	int n, getfloat(double* pn);
	double array[SIZE] = {0.0};

	for (n = 0; n < SIZE; n++)
		printf("%4.3lf%c", array[n], (n%10==9 || n==SIZE-1) ? '\n' : ' ');

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;

	for (n = 0; n < SIZE; n++)
		printf("%4.3lf%c", array[n], (n%10==9 || n==SIZE-1) ? '\n' : ' ');

	return 0;
}
