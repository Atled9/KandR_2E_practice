#include <stdio.h>

#define MAXLINE 1000

char *strcpy(char *restrict dst, const char *restrict src);
void strncat(char *s, char *t, int n);

int main()
{
	char line[MAXLINE];
	strcpy(line, "hello ");
	printf("%s\n", line);

	strncat(line, "world, nice to meet you!", 5);
	printf("%s\n", line);

	return 0;
}
