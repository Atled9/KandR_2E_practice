#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

double atof(char *s);

int main()
{
	char line[MAXLINE];
	strcpy(line, "-1.245e3");

	double f = atof(line);
	printf("%le\n", f);

	return 0;
}
