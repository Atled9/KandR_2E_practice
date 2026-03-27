#define EOF -1

int getchar(void);

void getline(char *s)
{
	char c;

	while ((c = getchar()) != EOF)
		*s++ = c;
	*s = '\0';
}
