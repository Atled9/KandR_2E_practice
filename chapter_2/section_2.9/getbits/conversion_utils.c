#include "conversion_utils.h"

/* decimal to binary string (AKA: binary expansion) */
void dtobs(char s[], int n)
{
	char srev[MAXLINE];
	int i = 0;	

	if(!n) {
		srev[i++] = '0';

	} else {
		while (n > 0) {
			srev[i++] = (n % 2) + '0';
			n /= 2;
		}
	}
	int j = 0;
	while (i > 0)
		s[j++] = srev[--i];

	s[j++] = '\n';
	s[j] = '\0';
}

int dstod(char s[])
{
	int i, result = 0;

	for (i = 0; s[i] != '\n'; i++) 
		result = 10 * result + (s[i] - '0');

	return result;
}

