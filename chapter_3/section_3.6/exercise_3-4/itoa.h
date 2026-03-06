#ifndef ITOA_UTILS
#define ITOA_UTILS

#include <stdio.h>

#define MAXLINE 1000
#define abs(x) ((x) < 0 ? -(x) : (x))

void reverse(char s[]);
void itoa(int n, char s[]);

int dstod(char s[]);

#endif
