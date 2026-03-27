#include <stdio.h>

int strlen(char* a);
/* this will give you a warning for conflics with the build-in
 * strlen in the standard library. Worry not, this will still
 * compile using your own definition */

int main()
{
	char* msg = "Welcome!";
	printf("message: %s, length: %d\n", msg, strlen(msg));
	return 0;
}
