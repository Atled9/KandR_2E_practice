#include <stdio.h>
#define MAXLINE 20

int atoi(char s[]);

int main()
{
	char line[MAXLINE];

	printf("Enter a number: ");
	fgets(line, MAXLINE, stdin);

	printf("The decimal value: %d\n", atoi(line));
	return 0;
}
