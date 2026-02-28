#include "squeeze.h"

#define MAXLINE 1000

int main()
{
	char s[MAXLINE], c;

	fgets(s, MAXLINE, stdin);
	c = fgetc(stdin);

	squeeze(s, c);

	fputs(s, stdout);
	return 0;
}
