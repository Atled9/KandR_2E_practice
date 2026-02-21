#include <stdio.h>

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		
		if (c == '\t')
			printf("\\t");
		if (c == '\b')		/* (ctrl + v)(ctrl + h) inputs backspace char */
			printf("\\b");
		if (c == '\\') 
			printf("\\\\");

		if (c != '\t') {
			if (c != '\b') {
				if (c != '\\') {
					putchar(c);
				}
			}
		}
	}
	return 0;
}
