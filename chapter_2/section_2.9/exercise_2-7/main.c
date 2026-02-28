#include "conversion_utils.h"
#include "invert.h"

int main()
{
	char s[MAXLINE];
	unsigned int val, pos, field, result;

	printf("Enter a value: ");
	fgets(s, MAXLINE, stdin);
	dtobs(s, val = dstod(s));

	printf("The binary expansion: %s", s);

	printf("Enter the position: ");
	fgets(s, MAXLINE, stdin);
	pos = dstod(s);

	printf("Enter the field length: ");
	fgets(s, MAXLINE, stdin);
	field = dstod(s);

	dtobs(s, result = invert(val, pos, field));
	printf("The binary result: %s", s);
	printf("The decimal value: %d\n", result);

	return 0;
}
