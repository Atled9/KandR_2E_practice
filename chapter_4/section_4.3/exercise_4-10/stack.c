#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100

/* other source files will not have access to the external stack buffer or position variable */
double stack[LIMIT];
int pos = 0;

void push(double val)
{
	if (pos >= LIMIT) {
		printf("Stack full\n");
		exit(EXIT_FAILURE);
	} else {
		stack[pos++] = val;
	}
}

double pop()
{
	if (pos <= 0) {
		printf("Stack empty\n");
		exit(EXIT_FAILURE);
	} else {
		return stack[--pos];
	}
}

void print_stack()
{
	printf("All Values in Stack: \n");
	for (int i = 0; i < pos; i++)
		printf("%6.1lf%c", stack[i], (i%10==9 || i==(pos-1)) ? '\n' : ' ');
}
