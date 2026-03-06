#ifndef ITOA_UTILS
#define ITOA_UTILS

#include <stdio.h>

#define MAXLINE 20
#define abs(x) ((x) < 0 ? -(x) : (x))

void reverse(char s[]);
void itoa(int n, char s[]);
void itob(int n, char s[], int b);

int dstod(char s[]);

#endif
