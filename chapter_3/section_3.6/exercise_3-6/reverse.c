#include <string.h>

void reverse(char s[])
{
	int l, r, temp;

	for (l = 0, r = strlen(s)-1; l < r; l++, r--) {
		temp = s[l];
		s[l] = s[r];
		s[r] = temp;
	}
}
