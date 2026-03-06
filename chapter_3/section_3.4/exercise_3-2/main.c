#include "escape.h"

int main()
{
	char in[MAXLINE], out[MAXLINE], undo[MAXLINE];
	fgets(in, MAXLINE, stdin);

	escape(in, out);
	fputs(out, stdout);
	printf("\n");

	unescape(out, undo);
	fputs(undo, stdout);
	return 0;
}
