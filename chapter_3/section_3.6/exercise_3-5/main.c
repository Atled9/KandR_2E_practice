#include "itoa.h"

int main()
{
	char line[MAXLINE];
	int val, base;

	printf("Enter a decimal value: ");
	fgets(line, MAXLINE, stdin);
	val = dstod(line);

	printf("Enter a base: ");
	fgets(line, MAXLINE, stdin);
	base = dstod(line);

	itob(val, line, base);
	fputs(line, stdout);
	printf("\n");

	return 0;
}
