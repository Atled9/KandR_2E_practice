#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char *s);

int main()
{
	char line[MAXLINE];
	strcpy(line, "The quick brown fox jumps over the lazy dog");

	reverse(line);
	printf("%s\n", line);

	return 0;
}
