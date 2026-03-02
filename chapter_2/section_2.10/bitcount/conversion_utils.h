#ifndef CONVERSION_UTILS
#define CONVERSION_UTILS

#include <stdio.h>
#define MAXBIN 10	/* 2 elements reserved for \n and \0 */
#define MAXDEC 5	/* 2 elements reserved for \n and \0 */

extern char bin_s[MAXBIN];	/* holds 00000000 through 11111111 */
extern char dec_s[MAXDEC];	/* holds 0 through 255 */

unsigned char dstod();	/* Decimal String TO Decimal */
unsigned char bstod();	/* Binary String TO Decimal */
void dtobs(unsigned char val);	/* Decimal TO Binary String (binary expansion */

#endif
