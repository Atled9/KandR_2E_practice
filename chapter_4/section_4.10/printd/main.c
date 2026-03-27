#include <stdio.h>
#include <stdlib.h>
#include "printd.h"

#define MAXLINE 1000

int main()
{
	char line[MAXLINE];
	int val;

	fgets(line, MAXLINE, stdin);
	val = atoi(line);

	printd(val);
	printf("\n");

	return 0;
}
