#include "shellsort.h"

int main()
{
	int nums[ASIZE], i;
	srand(time(NULL));

	for (i = 0; i < ASIZE; i++)
		nums[i] = rand() % ASIZE;
	for (i = 0; i < ASIZE; i++)
		printf("%2d%c", nums[i], (i%LSIZE==9 || i==ASIZE-1) ? '\n' : ' ');

	printf("\n");
	shellsort(nums, ASIZE);
	for (i = 0; i < ASIZE; i++)
		printf("%2d%c", nums[i], (i%LSIZE==9 || i==ASIZE-1) ? '\n' : ' ');

	return 0;
}
