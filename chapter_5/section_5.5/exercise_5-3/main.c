#include <stdio.h>
/* <string.h> will create conflict error with strcat() */

#define MAXLINE 1000

void strcat(char *s, char *t);
char *strcpy(char *restrict dst, const char *restrict src);

int main()
{
	char line[MAXLINE];

	char *msg0 = "hello ";
	char *msg1 = "world";

	strcpy(line, msg0);
	printf("%s\n", line);

	strcat(line, msg1);
	printf("%s\n", line);

	return 0;
}
