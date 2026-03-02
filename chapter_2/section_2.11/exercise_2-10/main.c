#include "lower.h"

int main()
{
	char line[MAXLINE];
	fgets(line, MAXLINE, stdin);

	for (int i = 0; line[i] != '\0'; i++)
	{
		line[i] = lower(line[i]);
	}
	fputs(line, stdout);
	return 0;
}
