#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

/* determine the ranges of char, short, int, and long variables, both signed and unsigned
 * by printing appropriate values from standard headers and by direct computation */
int main()
{
	printf("\n");
	printf("###### BYTE SIZES ######\n");
	printf("\n");

	printf("There are %d bits in a byte\n", CHAR_BIT);
	printf("The size of a char is %d byte(s)\n", sizeof(char));
	printf("The size of a short is %d byte(s)\n", sizeof(short));
	printf("The size of an int is %d byte(s)\n", sizeof(int));
	printf("The size of a long is %d bytes(s)\n", sizeof(long));
	printf("\n");

	/* Special note on binary values: 
	 * in decimal, values are represented using powers of 10
	 * 	256 = (2 * 10^2) + (5 * 10^1) + (6 * 10^0) =
	 * 	200 + 50 + 6
	 *
	 * in binary, values are represented using powers of 2
	 * 	(1100) = (1 * 2^3) + (1 * 2^2) + (0 * 2^1) + (0 * 2^0) =
	 * 	8 + 4 + 0 + 0 = 12
	 *
	 * the highest value that an n-bite number can represent goes as follows
	 * 	1-bit -> (1) = (1 * 2^0) = 1 = 2 - 1
	 * 	2-bit -> (11) = (1 * 2^1) + (1 * 2^0) = 3 = 4 - 1
	 *
	 * 	n-bit -> (n 1's) = (1 * 2^(n-1)) + (1 * 2^(n-2)) + ... + (1 * 2^(0)) =
	 * 	(2^n) - 1
	 *
	 * the range for an unsigned n-bit integer is [0, (2^n) - 1]
	 * 	for an 8-bit unsigned integer, the range is from
	 * 	(00000000) to (11111111) -> [0, 255]
	 * */

	/* Special note on 2's complement:
	 * 2's complement is used to represent signed integers on computers.
	 *
	 * 2's complement uses the most significant bit (leftmost) as the sign to indicate
	 * positive (0) or negative (1) numbers.
	 *
	 * non-negative numbers are given their unsigned representation
	 * 	(00000110) = 6
	 * 	(00001100) = 12
	 *
	 * negative numbers are represented by taking the bit complement and adding 1
	 * 	-6 	= (11111001) + (00000001) = (11111010)
	 * 	-12	= (11110011) + (00000001) = (11110100)
	 *
	 * to verify the negative binary representation, we can add the place values
	 * together but subtract the sign value
	 * 	(11110100) = 
	 * 	-(1 * 2^7) + (1 * 2^6) + (1 * 2^5) + (1 * 2^4) +
	 * 	 (0 * 2^3) + (1 * 2^2) + (0 * 2^1) + (0 * 2^0) =
	 * 	-128 + 64 + 32 + 16 + 0 + 4 + 0 + 0 = -12 
	 *
	 * the range for an n-bit number using 2's complement is [-(2^(n-1)), (2^(n-1))-1]
	 * 	for an 8-bit signed integer the range is from
	 * 	(10000000) to (01111111) -> [-128, 127]
	 * */

	/* It follows that if we know the size of a variable and whether it is signed or
	 * unsigned, we can calculate the range. I will calculate the ranges of char, short,
	 * int, and long using the sizeof() operator and verify my results using the
	 * limits.h header file macros */

	/* Calculations are split up to avoid overflow errors 
	 * 2^(n)-1 = (2^(n-1)-1) + 2^(n-1)	*/

	printf("###### UNSIGNED DATA TYPE RANGES ######\n");
	printf("\n");

	unsigned char uchar_max = (unsigned char)pow(2, CHAR_BIT*sizeof(char) - 1) - 1;
	uchar_max += (unsigned char)pow(2, CHAR_BIT*sizeof(char) - 1);

	printf("The range of unsigned char is [0, %u]\n", uchar_max);
	printf("UCHAR_MAX macro value: %u\n", UCHAR_MAX);
	printf("\n");

	unsigned short ushrt_max = (unsigned short)pow(2, CHAR_BIT*sizeof(short) - 1) - 1;
	ushrt_max += (unsigned short)pow(2, CHAR_BIT*sizeof(short) - 1);

	printf("The range of unsigned short is [0, %hu]\n", ushrt_max);
	printf("USHRT_MAX macro value: %hu\n", USHRT_MAX);
	printf("\n");

	unsigned int uint_max = (unsigned int)pow(2, CHAR_BIT*sizeof(int) - 1) - 1;
	uint_max += (unsigned int)pow(2, CHAR_BIT*sizeof(int) - 1);

	printf("The range of unsigned int is [0, %u]\n", uint_max);
	printf("UINT_MAX macro value: %u\n", UINT_MAX);
	printf("\n");

	unsigned long ulong_max = (unsigned long)pow(2, CHAR_BIT*sizeof(long) - 1) - 1;
	ulong_max += (unsigned long)pow(2, CHAR_BIT*sizeof(long) - 1);

	printf("The range of unsigned long is [0, %lu]\n", ulong_max);
	printf("ULONG_MAX macro value: %lu\n", ULONG_MAX);
	printf("\n");

	/* -(2^(n-1)) = - (2^(n-2)) - (2^(n-2)) */
	/*  (2^(n-1))-1 = (2^(n-2))-1 + (2^(n-2)) */

	printf("###### SIGNED DATA TYPE RANGES ######\n");
	printf("\n");

	char char_min = (char)-pow(2, CHAR_BIT*sizeof(char) - 2);
	char_min -= (char)pow(2, CHAR_BIT*sizeof(char) - 2);

	char char_max = (char)pow(2, CHAR_BIT*sizeof(char) - 2) - 1;
	char_max += (char)pow(2, CHAR_BIT*sizeof(char) - 2);

	printf("The range of char is [%d, %d]\n", char_min, char_max);
	printf("CHAR_MIN macro value: %d, CHAR_MAX macro value: %d\n", CHAR_MIN, CHAR_MAX);
	printf("\n");

	short shrt_min = (short)-pow(2, CHAR_BIT*sizeof(short) - 2);
	shrt_min -= (short)pow(2, CHAR_BIT*sizeof(short) - 2);

	short shrt_max = (short)pow(2, CHAR_BIT*sizeof(short) - 2) - 1;
	shrt_max += (short)pow(2, CHAR_BIT*sizeof(short) - 2);

	printf("The range of short is [%hd, %hd]\n", shrt_min, shrt_max);
	printf("SHRT_MIN macro value: %hd, SHRT_MAX macro value: %hd\n", SHRT_MIN, SHRT_MAX);
	printf("\n");

	int int_min = (int)-pow(2, CHAR_BIT*sizeof(int) - 2);
	int_min -= (int)pow(2, CHAR_BIT*sizeof(int) - 2);

	int int_max = (int)pow(2, CHAR_BIT*sizeof(int) - 2) - 1;
	int_max += (int)pow(2, CHAR_BIT*sizeof(int) - 2);

	printf("The range of int is [%d, %d]\n", int_min, int_max);
	printf("INT_MIN macro value: %d, INT_MAX macro value: %d\n", INT_MIN, INT_MAX);
	printf("\n");

	long long_min = (long)-pow(2, CHAR_BIT*sizeof(long) - 2);
	long_min -= (long)pow(2, CHAR_BIT*sizeof(long) - 2);

	long long_max = (long)pow(2, CHAR_BIT*sizeof(long) - 2) - 1;
	long_max += (long)pow(2, CHAR_BIT*sizeof(long) - 2);

	printf("The range of long is [%ld, %ld]\n", long_min, long_max);
	printf("LONG_MIN macro value: %ld, LONG_MAX macro value: %ld\n", LONG_MIN, LONG_MAX);
	printf("\n");

	/* special note on floating-point data types:
	 * floating point is a type of scientific notation. It consists of 3 parts
	 * 	1. a sign bit
	 * 	2. a mantissa (digit string) of a given length in base 2
	 * 	3. a signed exponent 
	 *
	 * its important to note that the rules for 2's complement do not apply to 
	 * floating-point values.
	 *
	 * there is an implied 1st bit in the mantissa with a value of 1. The
	 * actual bits represent fractional powers of 2. The format of a float
	 * will always be of the form
	 * 	1.(mantissa_value) * 2^(exponent)
	 *
	 * The Institute of Electrical and Electronics Engineers defined the standards
	 * for single-precision and double-precision floating-point numbers in IEEE 754. 
	 *
	 * single precision floats are 32-bit numbers. 1 bit is reserved for the sign; (1)
	 * is negative while (0) is positive. 8 bits represent the exponent; the value is
	 * the unsigned 8-bit value minus 127. 23 bits remain for the mantissa, but the
	 * implied 1st bit with a value of 1 gives us 24-bit precision.
	 *
	 * the exponent values of -127 and 128 are reserved for special cases. Only the
	 * range of exponents between -126 and 127 can be used for single-precision
	 * floating-point values. 
	 * 	> if the exponent is -127 and the mantissa is 0, that represents 0
	 * 	> if the exponent is 128 and the mantissa is 0, that represents (+/-)(inf)
	 * 	> if the exponent is -127 and the mantissa is not 0, that represents
	 * 		subnormal numbers
	 * 	> if the exponent is 128 and the mantissa is not 0, that represents (NaN)
	 *
	 * given these rules, the greatest absolute value a 32-bit float can have is
	 * 	(1 + (1/(2^1)) + (1/(2^2)) + ... + (1/(2^23))) * 2^(127)
	 * 	which is very close to the value of 2^(128)
	 *
	 * smallest absolute value a 32-bit float can have is
	 * 	(1 + 0) * 2^(-126)
	 *
	 * using the mantissa digits, the min and the max exponents defined in
	 * float.h, we can calculate the smallest and greatest values for double and
	 * long double
	 * */

	/* I will calculate the ranges of float, double, and long double 
	 * using the float.h header file macros and verify my results
	 * using FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX, LDBL_MIN, and LDBL_MAX
	 * */

	printf("###### FLOAT TYPE BYTE SIZES ######\n");
	printf("\n");

	printf("The size of a float is %d byte(s)\n", sizeof(float));
	printf("The size of a double is %d byte(s)\n", sizeof(double));
	printf("The size of a long double is %d byte(s)\n", sizeof(long double));
	printf("\n");

	printf("###### FLOAT TYPE RANGES ######\n");
	printf("\n");
	int i;


	float flt_max = 1;
	for (i = 1; i <= FLT_MANT_DIG - 1; ++i) {
		flt_max += (float)pow(FLT_RADIX, -1 * i);
	}
	flt_max *= (float)pow(FLT_RADIX, FLT_MAX_EXP - 1);

	float flt_min = (float)pow(FLT_RADIX, FLT_MIN_EXP - 1);
	
	printf("The range of float is [%1.20e, %1.20e]U[%1.20e, %1.20e]\n", -1*flt_max, -1*flt_min, flt_min, flt_max);
	printf("FLT_MIN macro value: %1.20e, FLT_MAX macro value: %1.20e\n", FLT_MIN, FLT_MAX);
	printf("\n");


	double dbl_max = 1;
	for (i = 1; i <= DBL_MANT_DIG - 1; ++i) {
		dbl_max += (double)pow(FLT_RADIX, -1 * i);
	}
	dbl_max *= (double)pow(FLT_RADIX, DBL_MAX_EXP - 1);

	double dbl_min = (double)pow(FLT_RADIX, DBL_MIN_EXP - 1);
	
	printf("The range of double is [%1.20le, %1.20le]U[%1.20le, %1.20le]\n", -1*dbl_max, -1*dbl_min, dbl_min, dbl_max);
	printf("DBL_MIN macro value: %1.20le, DBL_MAX macro value: %1.20le\n", DBL_MIN, DBL_MAX);
	printf("\n");


	/* use powl() in place of pow() to compute long double limits */
	long double ldbl_max = 1;
	for (i = 1; i <= LDBL_MANT_DIG - 1; ++i) {
		ldbl_max += (long double)powl(FLT_RADIX, -1 * i);
	}
	ldbl_max *= (long double)powl(FLT_RADIX, LDBL_MAX_EXP - 1);

	long double ldbl_min = (long double)powl(FLT_RADIX, LDBL_MIN_EXP - 1);
	
	printf("The range of long double is [%1.20Le, %1.20Le]U[%1.20Le, %1.20Le]\n", -1*ldbl_max, -1*ldbl_min, ldbl_min, ldbl_max);
	printf("LDBL_MIN macro value: %1.20Le, LDBL_MAX macro value: %1.20Le\n", LDBL_MIN, LDBL_MAX);
	printf("\n");

	return 0;
}
