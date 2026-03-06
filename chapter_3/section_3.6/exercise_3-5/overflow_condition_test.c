#include <stdio.h>
#include <limits.h>

int main()
{
	int num0, num1;

	num0 = INT_MIN;
	printf("The value of INT_MIN: %d\n", num0);

	num1 = -num0;
	printf("After attempting to change the sign: %d\n", num1);

	return 0;
}
