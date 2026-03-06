#include "itoa.h"

int main()
{
	char line[MAXLINE];
	int val, field;

	printf("Enter a decimal value: ");
	fgets(line, MAXLINE, stdin);
	val = dstod(line);

	printf("Enter a minimum field value: ");
	fgets(line, MAXLINE, stdin);
	field = dstod(line);

	itoa(val, line, field);
	fputs(line, stdout);
	printf("\n");

	return 0;
}
