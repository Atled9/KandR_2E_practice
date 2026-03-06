#include "expand.h"

int main()
{
	char in[MAXLINE], out[MAXLINE];

	fgets(in, MAXLINE, stdin);
	expand(in, out);

	fputs(out, stdout);
	return 0;
}
