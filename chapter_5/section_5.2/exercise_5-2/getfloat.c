#include <stdio.h>
#include <ctype.h>
#include "getch.h"

/* getint: get next integer from input to *pn */
/* can be used with integer strings separated by whitespace */

/* getfloat will return the same type as getint, the only difference
 * between the two is that getfloat will modify the value addressed
 * in a double pointer instead of an int pointer */

int getfloat(double* pn)
{
	int c;
	double divisor, sign;

	while (isspace(c = getch()))	/* skip white space */
		;			/* terminates when non-whitepace assigned to c */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	/* not a number */
		return 0;	/* non-number or whitespace creates hangup
				 * when function is called multiple times */	
	}
	sign = (c == '-') ? -1.0 : 1.0;
	if (c == '+' || c == '-')
		c = getch();	/* read past sign character */

	if (c >= '0' && c <= '9') {
		for (*pn = 0; isdigit(c); c = getch()) /* assign 0 to *pn only if number */
			*pn = 10 * *pn + (c - '0');
		*pn *= sign;
	}

	if (c == '.')
		c = getch();	/* read past decimal point */

	if (c >= '0' && c <= '9') {
		for (divisor = 1.0; isdigit(c); c = getch()) {
			*pn = 10 * *pn + sign*(c - '0');
			divisor *= 10.0;
		}
		*pn /= divisor;
	}
	if (c != EOF)
		ungetch(c); /* push back last non-number character */
	return c;	/* if c == EOF, it will be returned here */
}
