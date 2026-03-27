#include <stddef.h>

/* return the address of t in s, NULL if none */
char *strindex(char *s, char *t)
{
	char *s_pos;
	char *t_begin;

	while(*s) {
		s_pos = s;
		t_begin = t;

		while(*t && *s++ == *t++)
			;
		if (s != s_pos && !(*t))
			return s_pos;

		s++;
		t = t_begin;
	}
	return NULL;
}
