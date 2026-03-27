#include <stdio.h>

int strncmp(char *s, char *t, int n);

int main()
{
	char* msg0 = "hello";
	char* msg1 = "hello, world";
	char* msg2 = "help";

	printf("left: \"%s\", right: \"%s\", compare 4: %d\n", msg0, msg1, strncmp(msg0, msg1, 4));
	printf("left: \"%s\", right: \"%s\", compare 4: %d\n", msg0, msg2, strncmp(msg0, msg2, 4));
	printf("left: \"%s\", right: \"%s\", compare 4: %d\n", msg2, msg0, strncmp(msg2, msg0, 4));
}
