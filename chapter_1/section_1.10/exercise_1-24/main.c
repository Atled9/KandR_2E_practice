#include <stdio.h>

#define MAXLINE 1000
#define BALCATS	6	/* number balance categories */

#define PAREN	0	/* parentheses */
#define BRACK	1	/* brackets */
#define BRACE	2	/* braces */
#define SQUOT	3	/* single-quotes IN_OUT */
#define DQUOT	4	/* double-quotes IN_OUT */
#define MLCOM	5	/* multi-line comments IN_OUT */

#define	IN	1
#define OUT	0

#define TRUE	1
#define FALSE	0

int main()
{
	char line[MAXLINE];
	int balance[BALCATS];
	int i;
	int has_error;

	has_error = FALSE;

	for (i = 0; i < BALCATS; ++i) {
		balance[i] = 0;
	}
	FILE* file_p = fopen("rsrc/digit_sum.c", "r");

	while(fgets(line, MAXLINE, file_p) != NULL) {
		for (i = 0; line[i] != '\0'; ++i) {

			if (line[i] == '(') 
				++balance[PAREN];	
			if (line[i] == ')') 
				--balance[PAREN];
			
			if (line[i] == '[')
				++balance[BRACK];
			if (line[i] == ']')
				--balance[BRACK];

			if (line[i] == '{')
				++balance[BRACE];
			if (line[i] == '}')
				--balance[BRACE];

			if (line[i] == '\'')
				balance[SQUOT] = !balance[SQUOT];
			if (line[i] == '\"')
				balance[DQUOT] = !balance[DQUOT];

			if (line[i] == '/' && line[i + 1] == '*') {
				if (balance[MLCOM] == IN) {
					printf("ERROR: Nested multi-line comment opening\n");
					has_error = TRUE;
				}
				balance[MLCOM] = IN;
			}
			if (line[i] == '*' && line[i + 1] == '/') {
				if (balance[MLCOM] == OUT) {
					printf("ERROR: Stray multi-line comment closing\n");
					has_error = TRUE;
				}
				balance[MLCOM] = OUT;
			}

			if (line[i] == '\\') {	/* skip escape sequence chars */
				++i;
			}
		}
	}

	if (balance[PAREN] != 0) {
		printf("ERROR: unbalanced parenthesis\n");
		has_error = TRUE;
	}
	if (balance[BRACK] != 0) {
		printf("ERROR: unbalanced brackets\n");
		has_error = TRUE;
	}
	if (balance[BRACE] != 0) {
		printf("ERROR: unbalanced braces\n");
		has_error = TRUE;
	}
	if (balance[SQUOT] == IN) {
		printf("ERROR: unbalanced single-quotes\n");
		has_error = TRUE;
	}
	if (balance[DQUOT] == IN) {
		printf("ERROR: unbalanced double-quotes\n");
		has_error = TRUE;
	}
	if (balance[MLCOM] == IN) {
		printf("ERROR: unbalanced multi-line comments\n");
		has_error = TRUE;
	}

	if (!has_error) {
		printf("There are no detectable errors\n");
	}
	return 0;
}
