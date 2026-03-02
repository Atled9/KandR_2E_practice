#include "conversion_utils.h"
#include "bitcount.h"

int main()
{
	unsigned char val;

	printf("Enter value: ");
	fgets(dec_s, MAXDEC, stdin);
	dtobs(val = dstod());

	printf("The binary expansion: ");
	fputs(bin_s, stdout);

	printf("The bitcount: %d\n", bitcount(val));
	return 0;
}
