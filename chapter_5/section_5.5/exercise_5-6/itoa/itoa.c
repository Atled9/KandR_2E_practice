#include <stdio.h>

#define abs(x) ((x) < 0 ? -(x) : (x))
void reverse(char *s);

void itoa(char *s, int n)
{
	char* s_begin = s;
	int sign = n;

	while(n) {
		*s++ = abs(n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		*s++ = '-';
	*s = '\0';

	reverse(s_begin);
}
