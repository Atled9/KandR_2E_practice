#include <stdio.h>

#define MAXLINE 1000

void itoa(char *s, int n);

int main()
{
	char line0[MAXLINE];
	char line1[MAXLINE];
	char line2[MAXLINE];
	char line3[MAXLINE];
	int n0 = 1970;
	int n1 = 1991;
	int n2 = -273;
	int n3 = -460;

	itoa(line0, n0);
	itoa(line1, n1);
	itoa(line2, n2);
	itoa(line3, n3);
	printf("%s\n", line0);
	printf("%s\n", line1);
	printf("%s\n", line2);
	printf("%s\n", line3);

	return 0;
}
