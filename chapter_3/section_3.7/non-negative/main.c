#include "non-negative.h"

int main()
{
	srand(time(NULL));
	int num_array[ASIZE], num_array_positive[ASIZE], i;
	
	for (i = 0; i < ASIZE; i++) {
		num_array[i] = (rand() % ASIZE) - (ASIZE / 2);
		num_array_positive[i] = 0;
	}
	non_negative(num_array, num_array_positive, ASIZE);

	print_array(num_array, ASIZE);
	printf("\n");
	print_array(num_array_positive, ASIZE);

	return 0;
}
