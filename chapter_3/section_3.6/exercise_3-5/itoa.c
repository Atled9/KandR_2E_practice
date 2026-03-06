/* In a two's complement number system, the greatest 
 * negative value an n-bit number can represent is
 * 	-(2^(n-1)). In binary: (100...00)
 *
 *  the greatest positive value an n-bit number can
 *  represent is
 *  	(2^(n-1))-1. In binary: (011...11)
 *
 *  the absolute value of the greatest negative value
 *  is 1 higher than the greatest positive value.
 *  This means a block that flips the sign...
 *  	" if ((sign = n) < 0)	"
 *  	" 	n = -n;		"
 *  ...can cause an overflow condition.
 *
 *  remember, that when converting an integer from a
 *  positive value to a negative value, we take the
 *  bit complement (that is, flip all of the bits),
 *  and add 1.
 *  	Using 4-bit representation:
 *  	6  = (0110)
 *  	-6 = (1010)
 *
 *  the same goes for converting an integer from a
 *  negative value to a positive value.
 *  	(1010) becomes (0110)
 *
 *  so when we try flipping the sign of the greatest
 *  negative value for an n-bit integer, we end up
 *  with the same negative value.
 *  	using the value -8 in 4-bit representation:
 *  	(1000) -> take the complement
 *  	(0111) -> add 1
 *
 *	       (0111)	carry	(the last 2 carry bits are mismatched)
 *  		(0111)	7 
 *      +	(0001)	1
 *      --------------
 *     		(1000)	-8	(sign overflow)
 *
 * It is important to note that the program will not
 * throw an error or a warning for sign overflow.
 *
 * Signed overflow is undefined behavior that must be
 * handled by the developer
 * */

/* to prevent sign overflow, we can use a macro (abs(x))
 * to find the absolute value of n % 10 */
#include "itoa.h"

/* first let's give ourselves atoi: Decimal String TO Decimal */
int dstod(char s[])
{
	int result, sign, i;

	if (s[0] == '-') {
		sign = -1;
		i = 1;
	} else {
		sign = 1;
		i = 0;
	}

	for (result = 0; s[i] != '\n'; i++) {
		result = 10 * result + (s[i] - '0');
	}
	return sign * result;
}

void itoa(int n, char s[])
{
	int i, sign;
	sign = n;
	i = 0;

	do {
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);	/* the value of n could still be negative */

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}

void itob(int n, char s[], int b)
{
	int i, sign;
	sign = n;
	i = 0;

	do {
		if (abs(n % b) > 9)
			s[i++] = abs(n % b) - 10 + 'A';
		else
			s[i++] = abs(n % b) + '0';
	} while ((n /= b) != 0);	/* the value of n could still be negative */

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}
