#include <stdio.h>

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

int main()
{	
	int i;
	int inside_quote;
	int inside_sl_comment;
	int inside_ml_comment;

	FILE* file_p0;
	FILE* file_p1;
	char line[MAXLINE];

	file_p0 = fopen("rsrc/ftok.c", "r");
	file_p1 = fopen("rsrc/ftok_nocomment.c", "w");

	inside_quote = inside_sl_comment = inside_ml_comment = FALSE;

	while(fgets(line, MAXLINE, file_p0) != NULL) {
		for (i = 0; line[i] != '\0'; ++i) {

			if (line[i] == '"' && !inside_sl_comment && !inside_ml_comment) {
				inside_quote = !inside_quote;
			}

			if (line[i] == '/' && !inside_quote) {
				if (line[i + 1] == '*') {
					inside_ml_comment = TRUE;
				}
				if (line[i + 1] == '/') {
					inside_sl_comment = TRUE;
				}
			}

			if (line[i] == '*' && !inside_quote) {
				if (line[i + 1] == '/') {
					inside_ml_comment = FALSE;
					i = i + 2;
				}
			}
			if (line[i] == '\n' && !inside_quote && inside_sl_comment) {
				inside_sl_comment = FALSE;
			}

			if (!inside_sl_comment && !inside_ml_comment) {
				fputc(line[i], file_p1);
			}
		}
	}
	fclose(file_p0);
	fclose(file_p1);
	return 0;
}
