/* replace n bits of x starting at position p with the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	/* set bits of x from p to (p - n + 1) to 1 */
	x = x | ((~(~0 << n)) << (p - n + 1));

	/* set bits of y left of n to 1 */
	/* flip bits of y, shift left (p - n + 1), then flip again */
	y = ~(~(y | (~0 << n)) << (p - n + 1));

	/* now that x and y are bitmasked and shifted, recombine them with & */
	return x & y;
}
