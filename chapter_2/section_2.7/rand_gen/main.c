#include "rand_gen.h"

int main()
{
	char c;

	srand(1234);

	while ((c = getchar()) != 'q')
		printf("%d\n", rand());
	return 0;
}
