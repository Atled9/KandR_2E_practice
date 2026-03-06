#include "trim.h"

int main()
{
	char line[MAXLINE];
	int size;

	fgets(line, MAXLINE, stdin);
	size = trim(line);

	fputs(line, stdout);
	printf("\n%d\n", size);

	return 0;
}
