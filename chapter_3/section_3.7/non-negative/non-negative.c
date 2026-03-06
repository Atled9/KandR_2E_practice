#include "non-negative.h"

void non_negative(int in[], int out[], int size)
{
	int i, j;

	for (i = j = 0; i < size; i++) {
		if (in[i] < 0)
			continue;

		out[j++] = in[i];
	}
}

void print_array(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%*d%c", 4, a[i], (i%10==9 || i==size-1) ? '\n' : ' ');
	}
}
