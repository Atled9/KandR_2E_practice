#include "search_algos.h"

int main()
{
	/* ###### TERMINAL DEMO ###### */
	printf("\n###### TERMINAL DEMO OF ALGORITHM FUNCTIONALITY ######\n\n");
	int demo_array[DSIZE], i, val, ind;
	srand(time(NULL));

	printf("Unmodified Algorithm demo\n");
	for (i = 0; i < DSIZE; i++)
		demo_array[i] = rand() % DSIZE;

	qsort(demo_array, DSIZE, sizeof(int), comp);
	for (i = 0; i < DSIZE; i++)
		printf("%2d %c", demo_array[i], (i%10==9 || i==DSIZE-1) ? '\n': ' ');

	val = demo_array[rand() % DSIZE];
	ind = binsearch(val, demo_array, DSIZE);
	printf("value: %2d, index: %2d\n\n", val, ind);


	printf("Modified Algorithm demo\n");
	for (i = 0; i < DSIZE; i++)
		demo_array[i] = rand() % DSIZE;

	qsort(demo_array, DSIZE, sizeof(int), comp);
	for (i = 0; i < DSIZE; i++)
		printf("%2d %c", demo_array[i], (i%10==9 || i==DSIZE-1) ? '\n': ' ');

	val = demo_array[rand() % DSIZE];
	ind = binsearch_mod(val, demo_array, DSIZE);
	printf("value: %2d, index: %2d\n\n", val, ind);


	/* ###### ALGORITHM TESTS ###### */
	int vals[ASIZE];

	for (i = 0; i < ASIZE; i++)
		vals[i] = rand() % ASIZE;

	qsort(vals, ASIZE, sizeof(int), comp);
	
	clock_t t;
	double time_taken;
	printf("###### COMPUTING RUNTIME FOR UNMODIFIED BINSEARCH ######\n");

	t = clock();
	for (i = 0; i < TESTS; i++) {
		val = vals[rand() % ASIZE];
		ind = binsearch(val, vals, ASIZE);
	}
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("It took %6.3lf seconds to execute %d tests with a %d item array\n\n", time_taken, TESTS, ASIZE);


	printf("###### COMPUTING RUNTIME FOR MODIFIED BINSEARCH ######\n");
	t = clock();
	for (i = 0; i < TESTS; i++) {
		val = vals[rand() % ASIZE];
		ind = binsearch_mod(val, vals, ASIZE);
	}
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("It took %6.3lf seconds to execute %d tests with a %d item array\n\n", time_taken, TESTS, ASIZE);
	return 0;
}
