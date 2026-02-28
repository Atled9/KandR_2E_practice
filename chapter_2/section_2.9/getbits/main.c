#include "conversion_utils.h"
#include "getbits.h"

int main()
{
	char dec_s[MAXLINE], bin_s[MAXLINE];

	printf("Enter a decimal number: ");
	fgets(dec_s, MAXLINE, stdin);

	unsigned int val;
	dtobs(bin_s, val = dstod(dec_s));

	printf("The binary expansion is: ");
	fputs(bin_s, stdout);

	unsigned int pos, field;

	printf("Enter the starting bit position: ");
	fgets(dec_s, MAXLINE, stdin);
	pos = dstod(dec_s);

	printf("Enter the field size: ");
	fgets(dec_s, MAXLINE, stdin);
	field = dstod(dec_s);

	int result = getbits(val, pos, field);
	dtobs(bin_s, result);

	printf("The binary field value is: ");
	fputs(bin_s, stdout);

	printf("The decimal field value is: %d\n", result);
	return 0;
}
