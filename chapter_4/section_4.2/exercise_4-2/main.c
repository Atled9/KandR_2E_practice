#include "atof.h"

int main()
{
	double sum;
	char line[MAXLINE];

	sum = 0;
	while (fgets(line, MAXLINE, stdin) != NULL)
		printf("\t%lf\n", sum += atof(line));
	return 0;
}
