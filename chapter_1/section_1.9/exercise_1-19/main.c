#include <stdio.h>
#include "line_utils.h"

int main()
{
	int len, i;
	char line[MAXLINE];	/* current input line */

	while((len = get_line(line, MAXLINE)) > 0) {
		/* [len] is the index of '\0', and [len - 1] is the index of '\n' */ 
		for (i = len - 2; i >= 0 && (line[i] == ' ' || line[i] == '\t'); --i)
			;
		if (i != -1) {
			while (i >= 0) {
				printf("%c", line[i]);
				--i;
			}
			printf("\n");
		}
	}
	return 0;
}
