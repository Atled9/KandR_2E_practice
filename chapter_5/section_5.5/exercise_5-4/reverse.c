#include <string.h>

void reverse(char *s)
{
	char *start = s;
	char *end = s + strlen(s) - 1;
	char temp;

	while (start < end) {
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}
