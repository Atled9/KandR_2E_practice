#include "get_string.h"

void get_string(char str[])
{
	unsigned short 	i;
	unsigned char	c;

	for (i = 0; i < lim - 1; ++i) {
		if ((c = getchar()) == '\n') {
			str[i] = '\0';
			return;
		}
		if (c == EOF) {
			str[i] = '\0';
			return;
		}
		str[i] = c;
	}
	str[i] = '\0';
	return;
}
