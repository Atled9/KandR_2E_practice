void strncat(char *s, char *t, int n)
{
	int i;

	while(*s)
		s++;

	for (i = 0; i < n && *t; i++)
		*s++ = *t++;
	*s = '\0';
}
