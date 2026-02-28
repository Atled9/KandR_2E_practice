/* strlen: return length of s */
int string_length(char s[])
{
	int i;

	i = 0;
	while(s[i] != '\0') {
		++i;
	}
	return i;
}

