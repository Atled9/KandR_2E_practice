#include <stdio.h>
#include <ctype.h>
#include "getch.h"

/* getint: get next integer from input to *pn */
/* can be used with integer strings separated by whitespace */
int getint(int* pn)
{
	int c, sign;

	while (isspace(c = getch()))	/* skip white space */
		;			/* terminates when non-whitepace assigned to c */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	/* not a number */
		return 0;	/* non-integer or whitespace creates hangup
				 * when function is called multiple times */	
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();	/* read past sign character */
	for (*pn = 0; isdigit(c); c = getch()) /* automatically assigns 0 to *pn */
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c); /* push back last non-number character */
	return c;	/* if c == EOF, it will be returned here */
}
