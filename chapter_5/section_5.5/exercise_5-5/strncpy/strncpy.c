void strncpy(char *s, char *t, int n)
{
	int i;

	for (i = 0; i < n && *t; i++)
		*s++ = *t++;
	*s = '\0';
}
