#include <stdio.h>

void swap(int* a_p, int* b_p);

int main()
{
	int a, b;
	a = 4;
	b = 5;

	printf("a: %d, b: %d\n", a, b);
	swap(&a, &b);
	printf("a: %d, b: %d\n", a, b);

	return 0;
}

void swap(int* a_p, int* b_p)
{
	int temp;
	temp = *a_p;
	*a_p = *b_p;
	*b_p = temp;
}
