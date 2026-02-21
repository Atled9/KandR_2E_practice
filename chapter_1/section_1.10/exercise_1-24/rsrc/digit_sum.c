#include <stdio.h>

#define MAXLINE 1000

int main()
{
	char line[MAXLINE];
	char* return_val;
	int sum, i;

	do {
		printf("Enter Number: ");
		return_val = fgets(line, MAXLINE, stdin);

		if (return_val == NULL) {
			printf("\n");
			return 0;
		}

		sum = 0;
		for (i = 0; line[i] != '\n'; ++i) {
			sum = sum + line[i] - '0';
		}

		printf("Digit Sum: %d\n", sum);
		
	} while (1);
}
