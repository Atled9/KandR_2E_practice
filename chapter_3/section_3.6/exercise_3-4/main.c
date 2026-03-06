#include "itoa.h"

int main()
{
	char line[MAXLINE], line_out[MAXLINE];
	int val;

	fgets(line, MAXLINE, stdin);
	val = dstod(line);

	itoa(val, line_out);
	fputs(line_out, stdout);
	printf("\n");
	return 0;
}
