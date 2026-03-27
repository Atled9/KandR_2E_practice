#include <stdio.h>
#include <string.h>
#include "reverse.h"

#define MAXLINE 1000

int main()
{
	char line[MAXLINE];
	fgets(line, MAXLINE, stdin);

	reverse(line, 0, strlen(line) - 2); /* dont move '\n' to beginning */
	fputs(line, stdout);

	return 0;
}
