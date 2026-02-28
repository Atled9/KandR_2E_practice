#include "any.h"

int main()
{
	char s1[MAXLINE], s2[MAXLINE];
	fgets(s1, MAXLINE, stdin);
	fgets(s2, MAXLINE, stdin);

	printf("First index in line 1 that matches with a char from line 2: %d\n", any(s1, s2));
	return 0;
}
