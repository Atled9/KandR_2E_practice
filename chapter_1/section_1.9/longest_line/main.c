#include <stdio.h>
#include "line_utils.h"

/* print longest input line */
int main()
{
	int len;	/* current line length */
	int max;	/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while((len = get_line(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)	/* there was a line */
		printf("%s", longest);
	return 0;
}
