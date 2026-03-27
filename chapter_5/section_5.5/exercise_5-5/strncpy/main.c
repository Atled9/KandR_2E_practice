#include <stdio.h>

#define MAXLINE 1000

void strncpy(char *s, char *t, int n);

int main()
{
	char line[MAXLINE];
	strncpy(line, "hello, world", 5);
	printf("%s\n", line);
}
