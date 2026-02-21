#include <stdio.h>

int main() {
	int c;

	c = getchar();
	printf("%d ", c != EOF);

	while (c != EOF) {
		putchar(c);
		printf("\n");

		c = getchar();
		printf("%d ", c != EOF);
	}
	return 0;
}
