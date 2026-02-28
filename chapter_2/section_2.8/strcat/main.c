#include "strcat.h"

#define MAXLINE 1000

int main()
{
	char s[MAXLINE], t[MAXLINE];

	fgets(s, MAXLINE, stdin);
	fgets(t, MAXLINE, stdin);

	str_cat(s, t);

	fputs(s, stdout);
	return 0;
}
