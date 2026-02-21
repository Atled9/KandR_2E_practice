#include <stdio.h>

/* copy input to output */
int main() {
	int c;					/* c must be big enough to hold input data + EOF */

	while ((c = getchar()) != EOF) {	/* getchar() returns EOF with (ctrl + d).
						 * assignment expressions have the value of
						 * the left hand side after assignment */
		putchar(c);
	}
	return 0;
}
