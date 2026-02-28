#include "atoi.h"

#define MAXLINE 1000

int main()
{
	char s[MAXLINE];
	fgets(s, MAXLINE, stdin);

	printf("The numeric value is %d\n", atoi(s));
	return 0;
}
