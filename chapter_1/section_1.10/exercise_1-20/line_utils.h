#ifndef LINE_UTILS
#define LINE_UTILS

#include <stdio.h>

#define MAXLINE 1000	/* maximum input line size */
#define TABSTOP 8	/* '\t' shifts to next tab stop. Typically every 8 spaces */

extern char line[];

int get_line(void);
void copy(void);

#endif
