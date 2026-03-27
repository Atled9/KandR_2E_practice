#include <stdio.h>

int strcmp(char *s, char *t);

int main()
{
	char* msg0 = "hello";
	char* msg1 = "hello";
	char* msg2 = "hell";

	printf("left: %s, right: %s, comparison: %d\n", msg0, msg1, strcmp(msg0, msg1));
	printf("left: %s, right: %s, comparison: %d\n", msg1, msg2, strcmp(msg1, msg2));
	printf("left: %s, right: %s, comparison: %d\n", msg2, msg1, strcmp(msg2, msg1));

	return 0;
}
