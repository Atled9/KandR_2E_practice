/* return the value of the integer x rotated to thr right by n-bit positions */
unsigned char rightrot(unsigned char x, unsigned char n)
{
	unsigned char i, bitmask;
	for (i = 0; i < n; i++) {

		if (x % 2) {

			bitmask = ~0;
			bitmask = ~(bitmask >> 1);

			x = x >> 1;
			x = x | bitmask;
		} else {
			x = x >> 1;
		}
	}
	return x;
}
