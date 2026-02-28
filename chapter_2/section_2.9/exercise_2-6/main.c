#include "conversion_utils.h"
#include "setbits.h"

int main()
{
	char bin_s0[MAXLINE], bin_s1[MAXLINE];
	char dec_s0[MAXLINE], dec_s1[MAXLINE];
	unsigned int val0, val1;

	printf("Enter your first decimal value: ");
	fgets(dec_s0, MAXLINE, stdin);

	printf("Enter your second decimal value: ");
	fgets(dec_s1, MAXLINE, stdin);

	val0 = dstod(dec_s0);
	val1 = dstod(dec_s1);

	dtobs(bin_s0, val0);
	dtobs(bin_s1, val1);

	printf("Binary expansion of first decimal: ");
	fputs(bin_s0, stdout);

	printf("Binary expansion of second decimal: ");
	fputs(bin_s1, stdout);

	unsigned int pos, field, result;

	printf("Enter the position of replacement: ");
	fgets(dec_s0, MAXLINE, stdin);

	printf("Enter the field length: ");
	fgets(dec_s1, MAXLINE, stdin);

	pos = dstod(dec_s0);
	field = dstod(dec_s1);
	result = setbits(val0, pos, field, val1);
	dtobs(bin_s0, result);

	printf("The resulting binary value is: ");
	fputs(bin_s0, stdout);

	printf("In decimal form: %d\n", result);
	return 0;
}
