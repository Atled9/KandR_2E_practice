#include <stdio.h>

static int i = 0;

/* itoa: convert decimal into ascii string */
void itoa_h(char s[], int v);

void itoa(char s[], int v)
{
	itoa_h(s, v);
	s[i] = '\0';
}

void itoa_h(char s[], int v)
{
	if (v < 0) {
		s[i++] = '-';
		v = -v;
	}

	if (v / 10)
		itoa_h(s, v / 10);
	
	s[i++] = v % 10 + '0';
}
