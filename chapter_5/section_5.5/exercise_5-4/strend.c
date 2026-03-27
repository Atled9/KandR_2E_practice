#include <string.h>

void reverse(char *s);

int strend(char *s, char *t)
{
	char *t_begin = t;
	if (strlen(s) < strlen(t))
		return 0;

	reverse(t);
	s += strlen(s) - 1;

	while (*t) {
		if (*s-- != *t++) {
			reverse(t_begin);
			return 0;
		}
	}
	reverse(t_begin);
	return 1;
}
