#include <stdio.h>

int main() {
	int c, i, j, length;
	int nlength[16];

	for (i = 0; i < 16; ++i)
		nlength[i] = 0;

	length = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			++nlength[length];
			length = 0;
		}
		else {
			++length;
		}
	}
	printf("### Word Length Histogram ###\n");
	for (i = 15; i > 0; --i) {
		for (j = 0; j < 16; ++j) {
			if (i - nlength[j] <= 0) {
				printf("#  ");
			}
			else {
				printf("   ");
			}
		}
		printf("\n");
	}
	
	printf("________________________________________________\n");
	printf("0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 \n");
	return 0;
}
