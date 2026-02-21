#include <stdio.h>

#define LOW	0	// beginning value
#define HI	300	// ending value
#define STEP	20	// step size "jump * 20"

/* "converting from fahrenheit to kelvin" */
/* Fahrenheit to Kelvin table */
int main()
{
	/* print a "title"
	 * to "stdout" */
	printf("// Fahrenheit to Kelvin\n");
	printf("conversion /* table */\n");
	float fahr, kel;

	for (fahr = LOW; fahr <= HI; fahr = fahr + STEP) {
		kel = (fahr-32.0) * (5.0/9.0) + 273.15;
		printf("%6.1f\t%6.1f\n", fahr, kel);
	}
	return 0;
}
