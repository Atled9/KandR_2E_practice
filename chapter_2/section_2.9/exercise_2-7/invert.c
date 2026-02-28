/* return x with n bits that begin at p inverted */
unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{
	/* let temp be a copy of x */
	unsigned int temp = x;

	/* set bits of x from p to (p - n + 1) to 1 */
	x = x | ((~(~0 << n)) << (p - n + 1));

	/* set bits of temp left of n to 0 */
	/* set bits of temp right of (p - n + 1) to 0 */
	/* flip all bits of temp */
	temp = temp & ~((~0 << n) << (p - n + 1));
	temp = temp & (~0 << (p - n + 1));
	temp = ~temp;

	/* rejoin x and temp and return */
	return x & temp;
}
