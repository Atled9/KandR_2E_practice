#include <stdio.h>

#define MAXLINE 1000

void strcpy(char *s, char *t);

int main()
{
	char line[MAXLINE];

	char* msg = "Hello, world!";
	strcpy(line, msg);

	printf("%s\n", line);
	return 0;
}
