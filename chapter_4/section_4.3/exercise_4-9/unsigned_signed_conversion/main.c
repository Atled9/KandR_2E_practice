#include <stdio.h>

int main()
{
	/* if the leftmost bit of an unsigned variable is 1, the value will become negative
	 * when converted to a signed variable */

	unsigned char var0 = 130;
	printf("The converted value is: %d\n", (signed char)var0);

	/* if the sign of the value of a signed variable is negative, the value will become
	 * positive when converted to an unsigned variable */
	
	signed char var1 = -5;
	printf("The converted value is: %d\n", (unsigned char)var1);

	/* let n be the bitsize of the variable
	 * let v be the value of the variable
	 * */

	/* when converting from unsigned to signed
	 * 	if (v >= 2^(n-1)),
	 * 	v becomes -(2^(n-1)) + (v - (2^(n-1)));
	 * 	After simplifying the expression...
	 * 	v becomes -(2^(n)) + v;
	 *
	 * 	if (v < 2^(n-1))
	 * 	v remains the same
	 * */

	/* when converting from signed to unsigned
	 * 	if (v >= 0)
	 * 	v remains the same
	 *
	 * 	if (v < 0)
	 * 	v becomes (2^(n)) + v
	 * */

	/* use the signed and unsigned char type variables above to
	 * test different value conversions
}
