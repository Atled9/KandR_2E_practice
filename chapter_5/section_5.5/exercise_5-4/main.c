#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int strend (char *s, char *t);

int main()
{
	char line0[MAXLINE];
	strcpy(line0, "hello, world");

	char line1[MAXLINE];
	strcpy(line1, "world");

	char line2[MAXLINE];
	strcpy(line2, "hello");


	printf("left: \"%s\", right: \"%s\", at_end?: %d\n", line0, line1, strend(line0, line1));
	printf("left: \"%s\", right: \"%s\", at_end?: %d\n", line0, line2, strend(line0, line2));
	return 0;
}
