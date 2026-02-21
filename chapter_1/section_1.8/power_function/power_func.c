/* power: raise bast to n-th power; n >= 0; version 2 */

/* Whatever is done to n inside power has npo effect on the argument that power() was originally called with */
int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; --n)
		p = p * base;
	return p;
}
