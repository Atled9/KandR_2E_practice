#include <stdio.h>

/* print Fahrenheit-Celsius table */
int main() {
	int fahr;

	/* for loops are a generalization of the while loop
	 * first the initialization is done once before the loop is entered
	 * Then the condition is evaluated
	 * if true, the body of the loop is executed
	 * then the increment step is exectuted and the condition is re-evaluated */
	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

	return 0;
}
