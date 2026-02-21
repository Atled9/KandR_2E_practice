#include <stdio.h>

int main() {
	int c, i, j;
	int nchar[29];

	for (i = 0; i < 29; ++i) {
		nchar[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z') {
			++nchar[c-'a'];
		}
		else if (c == ' ') {
			++nchar[26];
		}
		else if (c == '\n') {
			++nchar[27];
		}
		else if (c == '\t') {
			++nchar[28];
		}
	}
	printf("### Character Frequency Histogram ###\n");
	for (i = 20; i > 0; --i) {
		for (j = 0; j < 29; ++j) {
			if (i - nchar[j] <= 0) {
				printf("#  ");
			}
			else {
				printf("   ");
			}
		}
		printf("\n");
	}

	printf("_______________________________________________________________________________________\n");
	printf("a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  _  \\n \\t \n");
	return 0;
}
