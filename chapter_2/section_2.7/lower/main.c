#include "lower.h"

#define MAXLINE 1000

int main()
{
	char s_upper[MAXLINE];
	char s_lower[MAXLINE];
	fgets(s_upper, MAXLINE, stdin);

	int i;
	for (i = 0; s_upper[i] != '\0'; ++i) {
		s_lower[i] = lower(s_upper[i]);
	}

	fputs(s_lower, stdout);
	return 0;
}
