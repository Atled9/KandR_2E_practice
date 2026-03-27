int atoi(char *s)
{
	int sign = 1;
	int n = 0;

	if (*s == '-') {
		sign = -1;
		s++;
	}

	while(*s)
		n = 10 * n + (*s++ - '0');
	return sign * n;
}
