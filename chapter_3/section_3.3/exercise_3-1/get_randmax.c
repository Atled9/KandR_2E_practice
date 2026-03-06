#include <stdio.h>
#include <stdlib.h>	/* RAND_MAX defined here */
#include <limits.h>	/* INT_MAX defined here  */	/* CHAR_BIT defined here */

#include <math.h>

int main()
{
	printf("The maximum random value: %d\n", RAND_MAX);
	printf("The maximum signed int type value: %d\n", INT_MAX);

	int int_size = sizeof(int) * CHAR_BIT;
	printf("Highest signed 32-bit type value using 2's complement: %lu\n", (long unsigned)pow(2, int_size - 1) - 1);
}
