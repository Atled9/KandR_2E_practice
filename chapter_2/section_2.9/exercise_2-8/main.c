#include "conversion_utils.h"
#include "rightrot.h"

int main()
{
	char s[MAXLINE];
	unsigned char val, npos, result;

	printf("Enter value: ");
	fgets(s, MAXLINE, stdin);

	dtobs(s, val = dstod(s));
	printf("Binary expansion: %s", s);

	printf("Enter number of rotations: ");
	fgets(s, MAXLINE, stdin);
	npos = dstod(s);

	dtobs(s, result = rightrot(val, npos));
	printf("The binary result: %s", s);
	printf("The decimal value: %d\n", result);

	return 0;
}
