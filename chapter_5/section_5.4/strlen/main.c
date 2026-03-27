#include <stdio.h>

int strlen(char *s);

int main()
{
	char *msg = "Welcome!";
	printf("message: %s, length: %d\n", msg, strlen(msg));
	return 0;
}
