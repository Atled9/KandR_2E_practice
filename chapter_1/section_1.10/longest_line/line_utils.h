#ifndef LINE_UTILS
#define LINE_UTILS

#include <stdio.h>

#define MAXLINE 1000	/* maximum input line size */

extern int max;
extern char line[];
extern char longest[];

int get_line(void);
void copy(void);

#endif
