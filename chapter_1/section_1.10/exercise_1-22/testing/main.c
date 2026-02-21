#include "increment.h"

int main()
{
	int in_arr[SIZE];
	int out_arr[SIZE];
	int i;

	for (i = 0; i < SIZE; ++i) {
		in_arr[i] = i + 1;
	}
	for (i = 0; i < SIZE; ++i) {
		printf("%3d ", in_arr[i]);
	}
	printf("\n");

	increment_vals(in_arr, out_arr);

	for (i = 0; i < SIZE; ++i) {
		printf("%3d ", out_arr[i]);
	}
	printf("\n");

	return 0;
}
