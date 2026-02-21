#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; Using floating-point
 * arithmetic, variables, and format specifiers */

float ftoc(float fahr);

int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	printf("### FAHRENHEIT-CELSIUS CONVERSION TABLE ###\n");

	fahr = lower;
	while (fahr <= upper) {
		celsius = ftoc(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}
