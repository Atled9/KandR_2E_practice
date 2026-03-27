#include <stdio.h>
#include "stack.h"

#define TEST_SIZE 100
int main()
{
	int i;
	double val = 0.0;

	for (i = 0; i < TEST_SIZE; i++) {
		val += 1.0;
		push(val);
	}
	for (i = 0; i < TEST_SIZE; i++)
		printf("%6.1lf%c", pop(), (i%10==9 || i == TEST_SIZE - 1) ? '\n' : ' ');

	val = 0.0;

	for (i = 0.0; i < TEST_SIZE; i++) {
		val += 1.0;
		push(val);
	}

	print_stack();
}
