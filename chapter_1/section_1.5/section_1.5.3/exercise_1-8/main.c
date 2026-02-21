#include <stdio.h>

/* count lines in input */
int main() {
	int c, n1, tab, bl;

	n1 = tab = bl = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++n1;
		if (c == '\t')
			++tab;
		if (c == ' ')
			++bl;
	}

	printf("newlines: %d\n", n1);
	printf("tabs: %d\n", tab);
	printf("blanks: %d\n", bl);
	return 0;
}
