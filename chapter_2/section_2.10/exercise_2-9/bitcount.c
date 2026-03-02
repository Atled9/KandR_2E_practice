/* bitcount: count 1 bits in x */
/*int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 1)
			b++;
	return b;
}*/

/* let's investigate why (x &= (x-1)) deletes the rightmost 1-bit in x. We can use this
 * to write a faster version of bitcount */

/* let's first expand the expression: x = x & (x - 1)
 * (x - 1) will flip the value of the rightmost 1-bit, including all the 0's
 * to the right of the rightmost 1-bit
 * 	1010 becomes 1001 (10 becomes 9)
 * 	1100 becomes 1011 (12 becomes 11)
 * by masking x with (x - 1) using &, all bits to the right of the rightmost 1-bit
 * including the rightmost 1-bit are set to 0
 * 	1010 & 1001 = 1000 (10 & 9 becomes 8)
 * 	1100 & 1011 = 1000 (12 & 11 becomes 8)
 *
 * to improve bitcount, instead of right-shifting x until it reaches 0,
 * we can mask out each rightmost 1-bit of x in turn, until it reaches 0,
 * and we don't need to run a conditional check to increment our bit counter
 *
 * below is an improved version of the function above */

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= (x - 1))
		b++;
	return b;
}
