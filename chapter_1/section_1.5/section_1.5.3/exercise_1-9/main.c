#include <stdio.h>

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);

		while (c == ' ') {
			c = getchar();
			if (c != ' ')
				putchar(c);
		}
	}
	return 0;
}
