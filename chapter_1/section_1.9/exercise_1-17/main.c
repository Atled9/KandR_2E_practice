#include <stdio.h>
#include "line_utils.h"

int main()
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */

	while((len = get_line(line, MAXLINE)) > 0) {
		if (len > 80)
			printf("%s", line);	/* line already contains newline ('\n') character */
		
		printf("Length: %d characters\n", len);

	}
	return 0;
}
