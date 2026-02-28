#include "squeeze.h"

/* squeeze: delete all characters in t from s */
void squeeze (char s[], char t[])
{
	int i, j, k;
	Bool match;

	for (i = k = 0; s[i] != '\n'; i++) {

		match = FALSE;
		for (j = 0; t[j] != '\n'; j++) {
			if (s[i] == t[j])
				match = TRUE;
		}
		if (!match)
			s[k++] = s[i];
	}
	s[k++] = '\n';
	s[k]   = '\0';
	return;
}
