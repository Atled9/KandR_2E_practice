#include "conversion_utils.h"

char bin_s[MAXBIN];
char dec_s[MAXDEC];

unsigned char dstod()
{
	unsigned char i, result;

	for (i = result = 0; dec_s[i] != '\n'; i++)
		result = 10 * result + (dec_s[i] - '0');

	return result;
}

unsigned char bstod()
{
	unsigned char i, result;
	
	for (i = result = 0; bin_s[i] != '\n'; i++)
		result = 2 * result + (bin_s[i] - '0');

	return result;
}

void dtobs(unsigned char val)
{
	unsigned char i, j;
	char rev_s[MAXBIN];

	for (i = 0; val > 0; i++) {
		rev_s[i] = (val % 2) + '0';
		val /= 2;
	}
	while (i < MAXBIN - 2) {
		rev_s[i++] = '0';
	}
	i--;
	for (j = 0; i != 255; i--) {
		bin_s[j++] = rev_s[i];
	}
	bin_s[j++] = '\n';
	bin_s[j] = '\0';
}
