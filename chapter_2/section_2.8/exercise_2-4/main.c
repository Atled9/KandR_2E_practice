#include "squeeze.h"

int main()
{
	char line[MAXLINE], rm[MAXLINE];

	fgets(line, MAXLINE, stdin);
	fgets(rm, MAXLINE, stdin);

	squeeze(line, rm);

	fputs(line, stdout);
	return 0;
}
