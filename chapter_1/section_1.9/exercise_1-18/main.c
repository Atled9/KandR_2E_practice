#include <stdio.h>
#include "line_utils.h"

int main()
{
	int len, i, j;
	char line[MAXLINE];	/* current input line */

	while((len = get_line(line, MAXLINE)) > 0) {
		/* [len] is the index of '\0', and [len - 1] is the index of '\n' */ 
		for (i = len - 2; i >= 0 && (line[i] == ' ' || line[i] == '\t'); --i)
				;
		for (j = 0; j <= i; ++j)
			printf("%c", line[j]);
		
		if (i != -1)
			printf("\n");

	}
	return 0;
}
