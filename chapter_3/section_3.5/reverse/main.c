#include "reverse.h"

int main()
{
	char line[MAXLINE];

	fgets(line, MAXLINE, stdin);
	reverse(line);
	fputs(line, stdout);

	return 0;
}
