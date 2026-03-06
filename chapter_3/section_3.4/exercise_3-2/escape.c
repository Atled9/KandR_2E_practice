void escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
	{
		switch (s[i]) {
			case '\n':
				t[j] = '\\';
				t[j + 1] = 'n';
				j += 2;
				break;
			case '\t':
				t[j] = '\\';
				t[j + 1] = 't';
				j += 2;
				break;
			default:
				t[j] = s[i];
				j++;
				break;
		}
	}
	t[j] = '\0';
}

void unescape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++) 
	{
		switch (s[i]) {
			case '\\':
				if (s[i + 1] == 't') {
					t[j] = '\t';
				} else {
					t[j] = '\n';
				}
				i++;
				j++;
				break;
			default:
				t[j] = s[i];
				j++;
				break;
		}
	}
	t[j] = '\0';
}
