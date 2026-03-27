#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMLINES 3000
#define NUMCHARS 30

/* fill a file with randomly generated lines */
/* lines will contain ascii [32, 126] */
int main()
{
	FILE* file_p = fopen("randlines.txt", "w");
	char line[NUMCHARS + 1];	/* add extra char for newline */

	srand(time(NULL));
	int i, j;

	for (i = 0; i < NUMLINES; i++) {
		for (j = 0; j < NUMCHARS; j++) {
			line[j] = rand() % 95 + 32;
		}
		line[j] = '\n';		/* fgets() appends null terminating char */
		fputs(line, file_p);
	}
	fclose(file_p);
	return 0;
}
