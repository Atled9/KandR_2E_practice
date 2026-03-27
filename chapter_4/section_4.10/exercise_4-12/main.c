#include <stdio.h>
#include <stdlib.h>
#include "itoa.h"

#define MAXLINE 1000

int main()
{
	char line[MAXLINE], test_line[MAXLINE];
	int val;

	fgets(line, MAXLINE, stdin);
	val = atoi(line);

	printf("decimal value: %d\n", val);

	itoa(test_line, val);
	printf("string: %s\n", test_line);

	return 0;
}
