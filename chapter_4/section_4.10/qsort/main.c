#include <stdio.h>
#include <time.h>
#include "qsort.h"

#define TESTSIZE 20

/* stdlib function prototypes */
/* #include <stdlib.h> would raise a multi-definition error with qsort() */
int rand(void);
void srand(unsigned int seed);

/* utility func */
void print_array(int a[], int size);

int main()
{
	int test_array[TESTSIZE], i;

	srand(time(NULL));
	for (i = 0; i < TESTSIZE; i++)
		test_array[i] = rand() % TESTSIZE;

	print_array(test_array, TESTSIZE);
	printf("\n");

	qsort(test_array, 0, TESTSIZE-1);
	print_array(test_array, TESTSIZE);

	return 0;
}

void print_array(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%3d%c", a[i], (i%10==9 || i==size-1) ? '\n' : ' ');
}
