#include "htod.h"

#define MAXLINE 1000

int main()
{
	char s[MAXLINE];

	printf("Enter hexidecimal value: ");
	fgets(s, MAXLINE, stdin);

	printf("The decimal value is %d\n", htod(s));
	return 0;
}
