#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

char *strindex(char *s, char *t);

int main()
{
	char line0[MAXLINE];
	char line1[MAXLINE];
	char *pos;

	strcpy(line0, "The quick brown fox jumps over the lazy dog");
	strcpy(line1, "fox");

	printf("%s\n", line0);
	printf("%s\n", line1);

	if (pos = strindex(line0, line1)) {
		printf("%s\n", pos);
	}

	return 0;
}
