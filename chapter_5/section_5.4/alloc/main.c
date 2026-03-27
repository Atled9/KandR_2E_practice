#include <stdio.h>

char *alloc(int n);
void afree(char *p);

int main()
{
	char *msg0 = alloc(4);
	char *msg1 = alloc(5);

	*(msg0) = 'h';
	*(msg0 + 1) = 'i';
	*(msg0 + 2) = '!';
	*(msg0 + 3) = '\0';

	*(msg1) = 'w';
	*(msg1 + 1) = 'o';
	*(msg1 + 2) = 'w';
	*(msg1 + 3) = '!';
	*(msg1 + 4) = '\0';

	printf("%s\n", msg0);
	printf("%s\n", msg1);

	afree(msg0);
	afree(msg1);
	return 0;
}
