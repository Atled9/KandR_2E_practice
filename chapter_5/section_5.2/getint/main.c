#include <stdio.h>

#define SIZE 100

int main()
{
	int n, array[SIZE] = {0}, getint(int* pn);

	for (n = 0; n < SIZE; n++)
		printf("%4d%c", array[n], (n%10==9 || n==SIZE-1) ? '\n' : ' ');

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;

	for (n = 0; n < SIZE; n++)
		printf("%4d%c", array[n], (n%10==9 || n==SIZE-1) ? '\n' : ' ');

	return 0;
}
