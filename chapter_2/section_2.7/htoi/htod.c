#include "htod.h"

/* convert hexidecimal string to decimal */
int htod(char str[])
{
	int i, result;
	int sign = 1;

	if (str[0] == '-') {

		if (str[1] != '0' && str[2] != 'x') {
			printf("Non Hexidecimal Format\n");
			return -1;
		}
		i = 3;
		sign = -1;

	} else if (str[0] == '0' && str[1] == 'x') {

		i = 2;

	} else {
		printf("Non Hexidecimal Format\n");
		return -1;
	}



	for (; str[i] != '\n'; ++i) {

		if (str[i] >= '0' && str[i] <= '9') {
			result = 16 * result + (str[i] - '0');

		} else if (str[i] >= 'a' && str[i] <= 'f') {
			result = 16 * result + (str[i] - 'a') + 10;
		} else if (str[i] >= 'A' && str[i] <= 'F') {
			result = 16 * result + (str[i] - 'A') + 10;
		} else {

			printf("Incorrect Hexidecimal Format\n");
			return -1;
		}
	}
	return sign * result;
}
