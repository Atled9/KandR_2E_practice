#include <stdio.h>

int power(int b, int n);

int main()
{
	int i;
	for (i = 0; i < 10; ++i)
		printf("%6d %6d\n", power(2,i), power(3,i));

	return 0;
}
