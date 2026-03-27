#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int atoi(char *s);

int main()
{
	char line0[MAXLINE];
	char line1[MAXLINE];

	strcpy(line0, "-1215");
	strcpy(line1, "1970");

	printf("%d\n", atoi(line0));
	printf("%d\n", atoi(line1));

	return 0;
}
