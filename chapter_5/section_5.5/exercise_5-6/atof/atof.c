double atof(char *s)
{
	double n = 0.0, sign = 1.0, divisor = 1.0;
	int i, power = 0, negative_exp = 0;

	if (*s == '-') {
		sign = -1.0;
		s++;
	}

	while (*s >= '0' && *s <= '9')
		n = 10.0 * n + (*s++ - '0');
	
	if (*s == '.')
		s++;

	while (*s >= '0' && *s <= '9') {
		n = 10.0 * n + (*s++ - '0');
		divisor *= 10.0;
	}

	if (*s == 'e')
		s++;
	if (*s == '-') {
		negative_exp = 1;
		s++;
	}

	while (*s >= '0' && *s <= '9')
		power = 10 * power + (*s++ - '0');
	if (negative_exp)
		for (i = 0; i < power; i++)
			n /= 10;
	else
		for (i = 0; i < power; i++)
			n *= 10;

	return sign * n / divisor;
}
