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
	for (i = 0; i < 16; ++i) {
		printf("%3d: ", i);
		for (j = 0; j < nlength[i]; ++j) {
			printf("#");
		}
		printf("\n");
	}
	
	printf("\n");
	return 0;
}
