#include "increment.h"

void increment_vals(int arr_0[], int arr_1[])
{
	int i;

	for (i = 0; i < SIZE; i++) {
		arr_1[i] = arr_0[i] + 1;
	}
	return;
}
