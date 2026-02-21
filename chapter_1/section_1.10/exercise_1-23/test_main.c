#include <stdio.h>

#define MAXLINE 1000

int main()
{
	FILE* file_p0;
	FILE* file_p1;
	char line[MAXLINE];

	file_p0 = fopen("test_rsrc/test_in.txt", "r");
	file_p1 = fopen("test_rsrc/test_out.txt", "w");

	int i;
	while(fgets(line, MAXLINE, file_p0) != NULL) {
		for (i = 0; line[i] != '\0'; ++i) {
			if (line[i] == ' ') {
				fputc('_', file_p1);
			} else {
				fputc(line[i], file_p1);
			}
		}
	}
	fclose(file_p0);
	fclose(file_p1);
	return 0;
}
