void expand(char s1[], char s2[])
{
	char c;
	int i, j;

	i = j = 0;
	while ((c = s1[i++]) != '\0')			/* i increments at loop condition */
		if (s1[i] == '-' && s1[i+1] >= c) {	/* check for hyphen and valid expansion */
			i++;				/* move past hyphen */
			while (c < s1[i])		/* terminate expansion before upper bound */
				s2[j++] = c++;		/* increment j and c */
		} else
			s2[j++] = c;			/* copy character, including upper bound*/
	s2[j] = '\0';					/* append null terminating character */
}
