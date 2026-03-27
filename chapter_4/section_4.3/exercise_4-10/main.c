#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

#define MAXLINE	1000

#define TRUE	1
#define FALSE	0

int main()
{
	char line[MAXLINE], numbuff[MAXLINE], in_number;
	int i, j = 0;
	double r_op;	/* right-operand */

	fgets(line, MAXLINE, stdin);

	for (i = 0; line[i] != '\0'; i++) {

		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '.' || line[i] == 'e') {

			numbuff[j++] = line[i];
			in_number = TRUE;

		} else if (line[i] == '-' && line[i+1] >= '0' && line[i+1] <= '9') {

			numbuff[j++] = line[i];
			continue;		/* '-' is a sign, not an operator */

		} else if (in_number) {

			numbuff[j] = '\0';
			push(atof(numbuff));
			j = 0;

			in_number = FALSE;
		}

		switch(line[i]) {
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				r_op = pop();
				push(pop() - r_op);
				break;
			case '/':
				r_op = pop();
				push(pop() / r_op);
				break;
			case '\n':
				printf("\t%.8lf\n", pop());
				break;
		}
	}
}
