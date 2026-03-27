int strncmp(char *s, char *t, int n)
{
	int i;

	for (i = 0; *s == *t && i < n; s++, t++, i++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
