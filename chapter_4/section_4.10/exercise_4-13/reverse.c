void reverse(char s[], int left, int right)
{
	if (left >= right)
		return;

	int temp;

	temp = s[left];
	s[left] = s[right];
	s[right] = temp;

	reverse(s, left + 1, right - 1);
}
