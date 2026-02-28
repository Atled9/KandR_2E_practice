#include "get_string.h"

const unsigned short lim = 1000;

int main()
{
	char s[lim];
	get_string(s);

	fputs(s, stdout);
	printf("\n");
	return 0;
}
